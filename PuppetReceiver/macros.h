#ifndef MARCOS_H
#define MARCOS_H

#include <QDir>
#include <QUrl>
#include <QSysInfo>

#define SUCCESS       "The command executed successfully"
#define FAILEDTOSTART "The command failed to start"
#define CRASHED       "The command suddenly stopped working (crashed)"
#define TIMEDOUT      "The command stopped executing"
#define WRITEERROR    "The command failed (writing error)"
#define READERROR     "The command failed (reading error)"
#define UNKNOWNERROR  "The command has stopped working (unknown error)"

#define ROOT       QDir::rootPath().remove(2,1)
#define PROGRAM_32 "\\Program Files (x86)"
#define PROGRAM_64 "\\Program Files"
#define CHROME     "\\Google\\Chrome\\Application\\chrome.exe"
#define EDGE       "\\Internet Explorer\\iexplore.exe"
#define FIREFOX    "\\Mozilla Firefox\\firefox.exe"

#define HOME      QUrl(QDir::homePath()).toString()
#define DESKTOP   HOME + "\\Desktop"
#define DOWNLOAD  HOME + "\\Downloads"
#define DOCUMENTS HOME + "\\Documents"

#define PROGRAMS_1  ROOT + "\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs"
#define PROGRAMS_2  HOME + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs"

#define OS_VERSION (QSysInfo::currentCpuArchitecture().contains("64") ? "64" : "32")
#define CMD "cmd.exe"
#define SCRIPT "/c"

#endif // MARCOS_H
