#include "trafficlights.h"
#include "QRadioButton"
#include "QLabel"
#include "QPushButton"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "QTimer"
#include <QDebug>


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

    connect(lStartPushButton, SIGNAL(clicked()), this, SLOT(startTrafficLightsWork()));
    connect(lStopPushButton, SIGNAL(clicked()),this, SLOT(stopTrafficLightsWork()));
    connect(mTrafficLightTimer, SIGNAL(timeout()), this, SLOT(trafficLightsSwitch()));
}

void TrafficLights::trafficLightsSwitch()
{
    if(mRedRadioButton->isChecked() == true)
    {
        qDebug()<<"1) Orange button "<<mOrangeRadioButton->isChecked()<<" mNoTraffic is "<<mNoTraffic;
        qDebug()<<"2) Red button "<<mRedRadioButton->isChecked()<<" mNoTraffic is "<<mNoTraffic;
        mOrangeRadioButton->setChecked(true);
        mRedRadioButton->setChecked(false);
        qDebug()<<"3) Orange button "<<mOrangeRadioButton->isChecked()<<" mNoTraffic is "<<mNoTraffic;

    }
    if((true == mOrangeRadioButton->isChecked()) && ( true == mNoTraffic))
    {
        qDebug()<<"4) Orange button "<<mOrangeRadioButton->isChecked()<<" mNoTraffic is "<<mNoTraffic;
        mGreenRadioButton->setChecked(true);
        mNoTraffic=false;
    }
    if(mGreenRadioButton->isChecked())
    {
        mOrangeRadioButton->setChecked(true);
    }
    if((true == mOrangeRadioButton->isChecked()) && (false == mNoTraffic))
    {
         qDebug()<<"3) Orange button "<<mGreenRadioButton->isChecked()<<" mNoTraffic is "<<mNoTraffic;
        mRedRadioButton->setChecked(true);
        mNoTraffic=true;
    }
}

void TrafficLights::startTrafficLightsWork()
{
    mNoTraffic=true;
    mOrangeRadioButton->setChecked(true);
    mTrafficLightTimer->start();
    qDebug()<<"timer start";
}

void TrafficLights::stopTrafficLightsWork()
{
    mTrafficLightTimer->stop();
    mRedRadioButton->setChecked(true);
    qDebug()<<"timer stop";
}
