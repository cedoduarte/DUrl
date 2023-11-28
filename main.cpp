#include "durl.h"

#include <QCoreApplication>

/*
 * example of usage:
 *  durl.exe GET https://www.host.com/4
 *  durl.exe GET https://www.host.com/12
 *  durl.exe POST https://www.host.com BODY key1=value1 value1 again;key2=value2;key3=value3
 *  durl.exe PUT https://www.host.com BODY key1=value1 value1 again;key2=value2;key3=value3
*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DUrl durlApplication(argc, argv);
    durlApplication.start();
    return a.exec();
}
