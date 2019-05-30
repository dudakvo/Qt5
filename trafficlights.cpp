#include "trafficlights.h"
#include "QRadioButton"
#include "QLabel"
#include "QPushButton"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "QTimer"


TrafficLights::TrafficLights(QWidget *parent) : QWidget(parent)
{
    QLabel *lGreenLable = new QLabel("Green");
    QLabel *lRedLable = new QLabel("Red");
    QLabel *lOrangeLable = new QLabel("Orange");

    mGreenRadioButton = new QRadioButton;
    mRedRadioButton = new QRadioButton;
    mOrangeRadioButton = new QRadioButton;

    QPushButton *lStartPushButton = new QPushButton("Start");
    QPushButton *lStopPushButton = new QPushButton("Stop");

    QHBoxLayout *lHBoxGreenLayout = new QHBoxLayout;
    QHBoxLayout *lHBoxRedLayout = new QHBoxLayout;
    QHBoxLayout *lHBoxOrangeLayout = new QHBoxLayout;
    QHBoxLayout *lHBoxCommandLayout = new QHBoxLayout;
    QVBoxLayout *lVBoxLayout = new QVBoxLayout;

    mTrafficLightTimer = new QTimer;
    mTrafficLightTimer->setInterval(2000);

    lHBoxGreenLayout->addWidget(lGreenLable);
    lHBoxGreenLayout->addWidget(mGreenRadioButton);

    lHBoxRedLayout->addWidget(lRedLable);
    lHBoxRedLayout->addWidget((mRedRadioButton));

    lHBoxOrangeLayout->addWidget(lOrangeLable);
    lHBoxOrangeLayout->addWidget(mOrangeRadioButton);

    lHBoxCommandLayout->addWidget(lStartPushButton);
    lHBoxCommandLayout->addWidget(lStopPushButton);

    lVBoxLayout->addLayout(lHBoxRedLayout);
    lVBoxLayout->addLayout(lHBoxOrangeLayout);
    lVBoxLayout->addLayout(lHBoxGreenLayout);
    lVBoxLayout->addLayout(lHBoxCommandLayout);

    setLayout(lVBoxLayout);
    setWindowTitle("Traffic Light Widget");

    connect(lStartPushButton, SIGNAL(clicked()), this, SLOT(TrafficLightsWork()));
    connect(mTrafficLightTimer, SIGNAL(timeout()), this)


}

void TrafficLights::TrafficLightsWork()
{
    mOrangeRadioButton->setChecked(true);
    mGreenRadioButton->setChecked(true);
    mRedRadioButton->setChecked(true);
}

void TrafficLights::TrafficLightsSwitch()
{

}
