#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cgpgexec.h"
#include "formhelp.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    programVersion = "0.2";
    programName = "S3D";
    formalProgramName = "Simple and Secure Software for Decryption";

    QCoreApplication::setOrganizationName(programName); //Avoid QSettings trouble in Vista x64
    QCoreApplication::addLibraryPath("plugins");

    QTextCodec *codec = QTextCodec::codecForName("Shift-JIS");
    QTextDecoder *decoder = codec->makeDecoder();

    QString iniFname = programName + ".ini";
    QSettings *ini_settings;
    ini_settings = new QSettings(iniFname, QSettings::IniFormat);

    // Get the path to GnuPG
    pathToGnuPG = decoder->toUnicode(ini_settings->value("PathToGnuPG/PathToGnuPG").toByteArray());

    // Get Process Execution Timeout (default 60sec)
    processExecutionTimeoutSeconds = ini_settings->value("Timeout/ProcessExecution").toString();

    // Check the path to GnuPG
    if(! CheckPathToGnuPG(ini_settings)){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::critical(this, tr("Error"),
              "GNU PG : " + pathToGnuPG + " " +
              tr("is not found.") + "\n" +
              tr("Set the path to GNU PG in ini file."),
              QMessageBox::Ok);
    }

    setWindowTitle(tr(formalProgramName.toAscii()) + "(" + programName + ")");

    rewriteFileStatus();

    // Pickup drag and drop files
    if(QCoreApplication::arguments().size() > 1){
        QString firstArgument(QCoreApplication::arguments().at(1));
        if(firstArgument != "-install"){
            QStringList files;
            for(int ii = 1; ii < QCoreApplication::arguments().size(); ii++){
                QString path = QCoreApplication::arguments().at(ii);
                files.append(path);;
            }
            getTargetFiles(files);
        }
    }
    
    // Prepare help widget
    formHelp = new FormHelp(0, tr(formalProgramName.toAscii()) + "(" + programName + ")");
}

MainWindow::~MainWindow()
{
    if (formHelp){
        formHelp->close();
    }

    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if (formHelp){
        formHelp->close();
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}
void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls()) {
        QList<QUrl> urlList = mimeData->urls();
        QStringList files;
        for (int ii = 0; ii < urlList.size(); ii++) {
            QString path = urlList.at(ii).path();
            files.append(path.mid(1));;
        }
        getTargetFiles(files);
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

bool MainWindow::CheckPathToGnuPG(QSettings *ini_settings)
{
    bool stat = true;

    QTextCodec *codec = QTextCodec::codecForName("Shift-JIS");
    QTextEncoder *encoder = codec->makeEncoder();

    // Check path to GnuPG
    if(! QFile::exists(pathToGnuPG)){
        // Set path to GnuPG
        pathToGnuPG = "c:/Program Files/gnu/gnupg/gpg.exe";
        if(! QFile::exists(pathToGnuPG)){
            QString pathToGnuPG_os64 = "c:/Program Files (x86)/gnu/gnupg/gpg.exe";
            if(QFile::exists(pathToGnuPG_os64)){
                pathToGnuPG = pathToGnuPG_os64;
            }
        }
        if(QFile::exists(pathToGnuPG)){
            ini_settings->setValue("PathToGnuPG/PathToGnuPG", QString(encoder->fromUnicode(pathToGnuPG)));
        }
        else{
            stat = false;
        }
    }
    return stat;
}

bool MainWindow::isDup(QString fpath)
{
    bool stat = false;

    QFileInfo *fileinfo = new QFileInfo(fpath);
    QString fname = fileinfo->fileName();
    for (int ii = 0; ii < ui->listWidget->count(); ii++) {
        if(ui->listWidget->item(ii)->text() == fpath) {
            stat = true;
            break;
        }
        QFileInfo fi(ui->listWidget->item(ii)->text());
        if(fname == fi.fileName()){
            stat = true;
            break;
        }
    }
    return stat;
}

void MainWindow::rewriteFileStatus()
{
    int fileCount = 0;
    qint64 totalFileSize = 0;
    qint64 tera = Q_INT64_C(1099511627776);
    qint64 peta = Q_INT64_C(1125899906842624);

    for (int ii = 0; ii < ui->listWidget->count(); ii++)
    {
        QString fpath = ui->listWidget->item(ii)->text();
        QFile *file = new QFile(fpath);
        totalFileSize += file->size();
        fileCount++;
    }
    QString fileSizeString = "";
    if (totalFileSize == 0)
    {
        fileSizeString = "0";
    }
    else
    {
        fileSizeString = QString("%L2").arg(totalFileSize);
    }
    QString aboutFileSizeString = "";
    int aboutFileSize;
    if(totalFileSize < 1024){
        aboutFileSizeString = "";
    }
    else if(totalFileSize < 1024 * 1024){
        aboutFileSize = (int)(totalFileSize / 1024);
        aboutFileSizeString = " (" + tr("about") + QString("%1").arg(aboutFileSize) + tr("Kbyte") + ")";
    }
    else if (totalFileSize < 1073741824) // ‚PƒMƒK 1024 * 1024 * 1024
    {
        aboutFileSize = (int)(totalFileSize / (1024 * 1024));
        aboutFileSizeString = " (" + tr("about") + QString("%1").arg(aboutFileSize) + tr("Mbyte") + ")";
    }
    else if (totalFileSize < tera) // ‚Pƒeƒ‰ 1024 * 1024 * 1024 * 1024
    {
        aboutFileSize = (int)(totalFileSize / (1073741824));
        aboutFileSizeString = " (" + tr("about") + QString("%1").arg(aboutFileSize) + tr("Gbyte") + ")";
    }
    else if (totalFileSize < peta) // ‚Pƒyƒ^ 1024 * 1024 * 1024 * 1024 * 1024
    {
        aboutFileSize = (int)(totalFileSize / (tera));
        aboutFileSizeString = " (" + tr("about") + QString("%1").arg(aboutFileSize) + tr("Tbyte") + ")";
    }

    ui->labelFileStatus->setText(tr("Selected File Count : ") + QString("%1").arg(fileCount) + "    " + tr("Total File Size : ") + fileSizeString + aboutFileSizeString);
}

void MainWindow::on_pushButton_Ref_clicked()
{
    QFileDialog::Options options;
    QString selectedFilter;
    options |= QFileDialog::ShowDirsOnly;
    QString folderName = QFileDialog::getExistingDirectory(this,
                                tr("Select output folder"),
                                ui->lineEdit_OutputFolder->text(),
                                options);
    if (!folderName.isEmpty())
        ui->lineEdit_OutputFolder->setText(folderName);
}

void MainWindow::on_pushButton_Exit_clicked()
{
    close();
}

void MainWindow::on_pushButton_Add_clicked()
{
    QFileDialog::Options options;
    QString selectedFilter;
    QStringList files = QFileDialog::getOpenFileNames(
                                this, tr("Select target files."),
                                openFilesPath,
                                tr("GPG Files (*.gpg)"),
                                &selectedFilter,
                                options);
    if (files.count()) {
        getTargetFiles(files);
    }
}

void MainWindow::getTargetFiles(QStringList files)
{
    for (int ii = 0; ii < files.count(); ii++) {
        QFileInfo *fileinfo = new QFileInfo(files[ii]);
        if(fileinfo->isFile()){
            if(! getTargetFile(files[ii])){
                break;
            }
        }
        else{
            QMessageBox::StandardButton reply;
            reply = QMessageBox::information(this, tr("Confirm"),
                     tr("Select all files in the folder?") + "\n\n" + files[ii],
                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Abort);
            if (reply == QMessageBox::Yes){
                if(! getTargetFolder(files[ii])){
                    break;
                }
            }
            else if(reply == QMessageBox::No){
                continue;
            }
            else{
                break;
            }
        }
    }
    rewriteFileStatus();
}

bool MainWindow::getTargetFolder(QString folder)
{
    bool isContinue = true;

    QDir dir(folder);
    QStringList files = dir.entryList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::Readable);
    for( int ii = 0; ii < files.count(); ii++){
        QFileInfo *fileinfo = new QFileInfo(folder + "/" + files[ii]);
        if(fileinfo->isFile()){
            if(!getTargetFile(folder + "/" + files[ii])){
                isContinue = false;
                break;
            }
        }
        else{
            QMessageBox::StandardButton reply;
            reply = QMessageBox::information(this, tr("Confirm"),
                     tr("Select all files in the folder?") + "\n\n" + folder + "/" + files[ii],
                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Abort);
            if (reply == QMessageBox::Yes){
                if(! getTargetFolder(folder + "/" + files[ii])){
                    isContinue = false;
                    break;
                }
            }
            else if (reply == QMessageBox::No){
                continue;
            }
            else{
                isContinue = false;
                break;
            }
        }
    }

    return isContinue;
}

bool MainWindow::getTargetFile(QString fpath)
{
    bool isContinue = true;

    if (isDup(fpath)) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(this, tr("Confirm"),
                tr("Duplicate file name.") + "\n\n" + fpath,
                QMessageBox::Ignore | QMessageBox::Abort);
        if (reply == QMessageBox::Abort){
            isContinue = false;
        }
    }
    else{
        ui->listWidget->addItem(fpath);
    }
    return isContinue;
}

bool MainWindow::moveFilesFromFolderToFolder(QString sfolder, QString dfolder)
{
    bool isContinue = true;

    QDir dir(sfolder);
    QStringList files = dir.entryList(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::Readable);
    for( int ii = 0; ii < files.count(); ii++){
        QFileInfo *fileinfo = new QFileInfo(sfolder + "/" + files[ii]);
        if(fileinfo->isFile()){
            if(!moveFileToFolderWithConfirm(sfolder + "/" + files[ii], dfolder)){
                isContinue = false;
                break;
            }
        }
    }

    return isContinue;
}

bool MainWindow::removeFolderAndFiles(QString folder)
{
    bool isContinue = true;
    QMessageBox::StandardButton reply;

    QDir dir(folder);
    QStringList files = dir.entryList(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::Writable);
    for( int ii = 0; ii < files.count(); ii++){
        QString dpath = folder + "/" + files[ii];
        if(! QFile::remove(dpath)){
            reply = QMessageBox::information(this, tr("Confirm"),
                    dpath + "\n\n" + tr("Remove failed."),
                    QMessageBox::Ignore | QMessageBox::Abort);
            if (reply == QMessageBox::Abort){
                isContinue = false;
                break;
            }
        }
    }

    if(isContinue){
        QDir *dir = new QDir(".");
        if(! dir->rmdir(folder)){
            reply = QMessageBox::information(this, tr("Confirm"),
                    folder + "\n\n" + tr("Remove failed."),
                    QMessageBox::Ignore | QMessageBox::Abort);
            if (reply == QMessageBox::Abort){
                isContinue = false;
            }
        }
    }
    return isContinue;
}

bool MainWindow::moveFileToFolderWithConfirm(QString spath, QString dfolder)
{
    bool isContinue = true;
    QMessageBox::StandardButton reply;

    QFileInfo *fileinfo = new QFileInfo(spath);
    QString fname = fileinfo->fileName();
    QString dpath = dfolder + "/" + fname;
    if(QFile::exists(dpath)){
        reply = QMessageBox::information(this, tr("Confirm"),
                dpath + "\n\n" + tr("File is already exists.") + "\n" + tr("Over write?"),
                QMessageBox::Yes | QMessageBox::No | QMessageBox::Abort);
        if (reply == QMessageBox::Yes){
            isContinue = copyFileToFile(spath, dpath);
        }
        else if (reply == QMessageBox::Abort){
            isContinue = false;
        }
    }
    else{
        isContinue = copyFileToFile(spath, dpath);
    }

    if(isContinue){
        if(! QFile::remove(spath)){
            reply = QMessageBox::information(this, tr("Confirm"),
                    spath + "\n\n" + tr("Remove failed."),
                    QMessageBox::Ignore | QMessageBox::Abort);
            if (reply == QMessageBox::Abort){
                isContinue = false;
            }
        }
    }
    return isContinue;
}

bool MainWindow::copyFileToFile(QString spath, QString dpath)
{
    bool isContinue = true;
    QMessageBox::StandardButton reply;

    if(QFile::exists(dpath)){
        if(QFile::remove(dpath)){
            if(! QFile::copy(spath, dpath)){
                reply = QMessageBox::information(this, tr("Confirm"),
                        spath + "\nto" + dpath + "\n\n" + tr("Copy failed."),
                        QMessageBox::Ignore | QMessageBox::Abort);
                if (reply == QMessageBox::Abort){
                    isContinue = false;
                }
            }
        }
        else{
            reply = QMessageBox::information(this, tr("Confirm"),
                    dpath + "\n\n" + tr("Remove failed."),
                    QMessageBox::Ignore | QMessageBox::Abort);
            if (reply == QMessageBox::Abort){
                isContinue = false;
            }
        }
    }
    else{
        if(! QFile::copy(spath, dpath)){
            reply = QMessageBox::information(this, tr("Confirm"),
                    spath + "\nto" + dpath + "\n\n" + tr("Copy failed."),
                    QMessageBox::Ignore | QMessageBox::Abort);
            if (reply == QMessageBox::Abort){
                isContinue = false;
            }
        }
    }
    return isContinue;
}

void MainWindow::on_pushButton_Delete_clicked()
{
    QStringList wlist;
    for (int ii = 0; ii < ui->listWidget->count(); ii++) {
        if (! ui->listWidget->item(ii)->isSelected()) {
            wlist.append(ui->listWidget->item(ii)->text());
        }
    }
    ui->listWidget->clear();
    ui->listWidget->addItems(wlist);

    rewriteFileStatus();
}

void MainWindow::on_action_Exit_triggered()
{
    close();
}

void MainWindow::on_pushButton_Encrypt_clicked()
{
    bool stat = false;
    QTextCodec *codec = QTextCodec::codecForName("Shift-JIS");
    QTextDecoder *decoder = codec->makeDecoder();
    QMessageBox::StandardButton reply;

    if(ui->listWidget->count()){
        QString gpgFpath;
        QString decFpath;

        // Check if the output folder is selected.
        if(ui->lineEdit_OutputFolder->text() == ""){
            QMessageBox::information(this, tr("Confirm"), tr("Select the output folder."));
            return;
        }

        // Get current date-time string.
        QString yyyymmddhhmmss = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");

        // Make the working folder.
        workingFolder = yyyymmddhhmmss;
        QDir *dir = new QDir(".");
        if(dir->mkdir(workingFolder)){
            // input passphrase
            bool ok;
            passphrase = QInputDialog::getText(this, tr("Passphrase of your secret key"),
                                         tr("Passphrase:"), QLineEdit::Password,
                                         "", &ok);
            if (ok && !passphrase.isEmpty()){

                setCursor(Qt::WaitCursor);
                this->update();

                CGpgExec *gpgif = new CGpgExec(this);

                // Load tar32.dll.
                typedef int (StrFunc)(const HWND,const char *,char *,const int);
                QLibrary lib("tar32"); //tar32.dll
                StrFunc *func = (StrFunc *) lib.resolve("Tar");
                if (func){
                    // Copy target files into the working folder.
                    int fileCount = 0;
                    for (int ii = 0; ii < ui->listWidget->count(); ii++)
                    {
                        QString fpath = ui->listWidget->item(ii)->text();
                        QFile *file = new QFile(fpath);
                        QFileInfo *fileinfo = new QFileInfo(fpath);
                        gpgFpath = workingFolder + "/" + fileinfo->fileName();
                        file->copy(gpgFpath);
                        fileCount++;

                        // Make file and path names.
                        decFpath = workingFolder + "/" + fileinfo->fileName().mid(0, fileinfo->fileName().length() - 4);

                        // Decrypt the file.
                        QString msg;
                        stat = gpgif->gpgExecute("decrypt", gpgFpath, decFpath, &msg);

                        // Remove gpg file.
                        QFile::remove(gpgFpath);

                        if(stat){
                            //QMessageBox::information(this, tr("Confirm"), decoder->toUnicode(msg.toAscii()));
                            if(decFpath.rightRef(4) == ".tgz"){
                                // Uncompress target tgz file.
                                QString param = "--use-directory=0 xfz \"" + decFpath + "\" -o " + workingFolder;
                                char rbuf[1024];
                                rbuf[0] = '\0';
                                int tstat = func(NULL, param.toAscii(), rbuf, 1024);

                                if(tstat == 0){
                                    // Remove tgz file.
                                    QFile::remove(decFpath);

                                    // Copy files from working folder to the target folder.
                                    if(! moveFilesFromFolderToFolder(workingFolder, ui->lineEdit_OutputFolder->text())){
                                        stat = false;
                                        break;
                                    }
                                }
                                else{
                                    // tar32.dll returned error.
                                    reply = QMessageBox::information(this, tr("Confirm"),
                                            decFpath + "\n\n" + decoder->toUnicode(rbuf),
                                            QMessageBox::Ignore | QMessageBox::Abort);
                                    if (reply == QMessageBox::Abort){
                                        stat = false;
                                        break;
                                    }
                                }
                            }
                            else{
                                // Copy file to the target folder.
                                if(! moveFileToFolderWithConfirm(decFpath, ui->lineEdit_OutputFolder->text())){
                                    stat = false;
                                    break;
                                }
                            }

                            // Remove tgz file.
                            QFile::remove(decFpath);
                        }
                        else{
                            // gpg returned some error.
                            reply = QMessageBox::information(this, tr("Confirm"),
                                    gpgFpath + "\n\n" + decoder->toUnicode(msg.toAscii()),
                                    QMessageBox::Ignore | QMessageBox::Abort);
                            if (reply == QMessageBox::Abort){
                                stat = false;
                                break;
                            }
                        }
                    }
                }
                else{
                    // tar32.dll load error.
                    reply = QMessageBox::critical(this, tr("Error"),
                                                    tr("Can't load tar32.dll"),
                                                    QMessageBox::Abort);
                    if (reply == QMessageBox::Abort){
                        close();
                    }
                }
                setCursor(Qt::ArrowCursor);

                removeFolderAndFiles(workingFolder);

                if(stat){
                    QMessageBox::information(this, tr("Confirm"), tr("Completed."));

                    // Clear the main form
                    ui->listWidget->clear();
                    ui->lineEdit_OutputFolder->setText("");
                    rewriteFileStatus();
                }
            }
        }
        else{
            // Can't make working folder.
            reply = QMessageBox::critical(this, tr("Error"),
                                            tr("Can't mkdir ") + workingFolder,
                                            QMessageBox::Abort);
            if (reply == QMessageBox::Abort){
                close();
            }
        }
    }
}

void MainWindow::on_action_Add_triggered()
{
    on_pushButton_Add_clicked();
}

void MainWindow::on_actionDelete_triggered()
{
    on_pushButton_Delete_clicked();
}

void MainWindow::on_action_About_triggered()
{
    QMessageBox::about(this, "About " + tr(formalProgramName.toAscii()) + "(" + programName + ")",
        tr(formalProgramName.toAscii()) + "(" + programName + ")" + "    Version : " + programVersion + "\n\n\n" +
        tr(formalProgramName.toAscii()) + "(" + programName + ")" + tr(" is a helper tool for decrypt files using GnuPG.") + "\n\n" +
        tr("Selected files are decripted using GnuPG, and unpacked if decripted file is tar.gz format.") + "\n\n");
}

void MainWindow::on_actionHelp_triggered()
{
    formHelp->show();
    formHelp->activateWindow();
}
