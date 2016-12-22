#ifndef BROWSERDOWNLOAD_H
#define BROWSERDOWNLOAD_H

#include "Commands_h/commands.h"

class BrowserDownload : public Commands
{
    public:
        BrowserDownload(int id);
        bool start(QStringList *args);
};

#endif // BROWSERDOWNLOAD_H
