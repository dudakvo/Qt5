#include <QApplication>
#include "trafficlights.h"

int main(int lArgc, char *lArgv[])
{
    QApplication lApplication(lArgc, lArgv);
    TrafficLights trafficLights;

    trafficLights.show();

    return lApplication.exec();
}
