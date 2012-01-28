#ifndef CGPGIF_H
#define CGPGIF_H

#include <QObject>

class CGpgIf : public QObject
{
public:
    CGpgIf();
    QString gpgExecute(QStringList *parameterList);
};

#endif // CGPGIF_H
