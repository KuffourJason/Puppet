#include "Commands_h/pcstatus.h"

PCStatus::PCStatus()
{

}

bool PCStatus::start()
{
    return true;
}

bool PCStatus::ended()
{
    return true;
}

QString PCStatus::status()
{
    return "true";
}
