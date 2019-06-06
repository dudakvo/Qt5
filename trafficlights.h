#ifndef TRAFFICLIGHTS_H
#define TRAFFICLIGHTS_H

#include <QWidget>

class QRadioButton;
class QTimer;

class TrafficLights : public QWidget
{
    Q_OBJECT
public:
    explicit TrafficLights(QWidget *parent = nullptr);

signals:

public slots:
    void startTrafficLightsWork();
    void trafficLightsSwitch();
    void stopTrafficLightsWork();


private:
    QRadioButton *mGreenRadioButton;
    QRadioButton *mRedRadioButton;
    QRadioButton *mOrangeRadioButton;
    QTimer *mTrafficLightTimer;
    bool mCicleStatus;
    bool mNoTraffic=true;
};

#endif // TRAFFICLIGHTS_H
