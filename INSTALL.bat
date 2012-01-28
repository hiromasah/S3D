echo off
echo ""
echo GnuPGのインストールを開始します。
echo 入力項目はデフォルトのままでインストールを進めてください。
echo (言語は ja-Japaneseまたはen-Englishを選択してください。)
pause
csrc\gnupg-w32cli-1.4.9.exe
echo .
echo .
echo GUIプログラムのインストールを開始します。
echo デスクトップにショートカットを作成することができます。
echo セキュリティの警告が表示された場合は、「今回は許可」を選択してください。
:LOOP
SET CHECK=
SET/P CHECK="デスクトップにショートカットを作成しますか(Y/N)?:"
IF /i "%CHECK%" == "Y" GOTO LABEL1
IF /i "%CHECK%" == "N" GOTO LABEL2
GOTO LOOP
:LABEL1
makeShortCut.wsf
:LABEL2
echo .
echo .
echo インストールを完了しました。
pause
