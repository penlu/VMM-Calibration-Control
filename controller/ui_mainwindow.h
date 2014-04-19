/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Apr 15 14:12:12 2014
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *openConnection;
    QLabel *connectionLabel;
    QGroupBox *groupBox_2;
    QRadioButton *readRB;
    QRadioButton *writeRB;
    QComboBox *setVMMs;
    QLabel *cmdlabel;
    QPushButton *SendConfiguration;
    QGroupBox *groupBox_7;
    QRadioButton *lx9RB;
    QRadioButton *fecRB;
    QRadioButton *spiRB;
    QGroupBox *groupBox_11;
    QComboBox *detectionMode;
    QPushButton *applyDetectionMode;
    QComboBox *edgeSelection;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_2;
    QSpinBox *detectionTime;
    QGroupBox *groupBox_15;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_17;
    QLineEdit *header4LE;
    QLineEdit *header3LE;
    QLineEdit *header2LE;
    QLineEdit *header1LE;
    QPushButton *setHeaderPB;
    QGroupBox *groupBox_22;
    QPushButton *sampleSetPB;
    QComboBox *sampleValue;
    QGroupBox *groupBox_12;
    QComboBox *triggerMode;
    QPushButton *applyTrigger;
    QSpinBox *triggerTimeout;
    QGroupBox *groupBox_14;
    QPushButton *setDaqMode;
    QComboBox *daqModeOutput;
    QGroupBox *groupBox_25;
    QPushButton *onACQ;
    QPushButton *offACQ;
    QGroupBox *groupBox_24;
    QPushButton *startDi;
    QPushButton *stopDi;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *ip1;
    QLineEdit *ip2;
    QLineEdit *ip3;
    QLineEdit *ip4;
    QSpinBox *numbersOfFecs;
    QPushButton *triggerCounter_reset;
    QLabel *label_5;
    QPushButton *asic_reset;
    QPushButton *cdaq_reset;
    QPushButton *lx9Reset;
    QGroupBox *runGroupbox;
    QLineEdit *userComments;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *runNumber;
    QLabel *label_6;
    QLineEdit *runDirectoryField;
    QPushButton *selectDir;
    QLabel *label_7;
    QSpinBox *angle;
    QLabel *label_8;
    QPushButton *stopTriggerCnt;
    QPushButton *clearTriggerCnt;
    QPushButton *checkTriggers;
    QTextEdit *runStatusField;
    QFrame *frame;
    QFrame *frame_3;
    QFrame *frame_2;
    QFrame *frame_4;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_4;
    QLabel *label_9;
    QLabel *triggerCntLabel_fpga;
    QLabel *label_10;
    QLabel *triggerCntLabel;
    QCheckBox *calibration;
    QCheckBox *enableDebugPB;
    QCheckBox *hideChannels;
    QCheckBox *monitoring;
    QCheckBox *readTrigger;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *sgLabel;
    QComboBox *sg;
    QHBoxLayout *horizontalLayout_2;
    QLabel *stLabel;
    QComboBox *st;
    QHBoxLayout *horizontalLayout_6;
    QLabel *sngLabel;
    QComboBox *sng;
    QHBoxLayout *horizontalLayout_3;
    QLabel *stcLabel;
    QComboBox *stc;
    QHBoxLayout *horizontalLayout_7;
    QLabel *sdpLabel;
    QComboBox *sdp;
    QHBoxLayout *horizontalLayout_9;
    QLabel *sfaLabel;
    QComboBox *sfa;
    QLabel *sfamLabel;
    QComboBox *sfam;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *sstpLabel;
    QComboBox *sstp;
    QHBoxLayout *horizontalLayout_11;
    QLabel *sshLabel;
    QComboBox *ssh;
    QHBoxLayout *horizontalLayout_12;
    QLabel *stttLabel;
    QComboBox *sttt;
    QLabel *stotLabel;
    QComboBox *stot;
    QHBoxLayout *horizontalLayout_13;
    QLabel *s16Label;
    QComboBox *s16;
    QHBoxLayout *horizontalLayout_14;
    QLabel *srstLabel;
    QComboBox *srst;
    QHBoxLayout *horizontalLayout_16;
    QLabel *sdtLabel;
    QSpinBox *sdt;
    QHBoxLayout *horizontalLayout_15;
    QLabel *sdpLabel_2;
    QSpinBox *sdp_2;
    QLabel *dacmvLabel;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *sbfmLabel;
    QComboBox *sbfm;
    QLabel *sbfpLabel;
    QComboBox *sbfp;
    QLabel *sbftLabel;
    QComboBox *sbft;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *sm5_sm0Label;
    QComboBox *sm5_sm0;
    QLabel *scmxLabel;
    QComboBox *scmx;
    QCheckBox *loadCalibDataCB;
    QCheckBox *loadThrCB;
    QSpinBox *abovePed;
    QGroupBox *calibRunSettings;
    QFrame *frameCalib2;
    QHBoxLayout *horizontalLayout_calibRun;
    QCheckBox *calibTime;
    QCheckBox *calibGain;
    QGroupBox *groupBox_8;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_18;
    QLineEdit *ip1_tr;
    QLineEdit *ip2_tr;
    QLineEdit *ip3_tr;
    QLineEdit *ip4_tr;
    QLabel *connectionLabel_tr;
    QPushButton *openConnection_tr;
    QGroupBox *groupBox_9;
    QPushButton *offAcq_fpga;
    QPushButton *onAcq_fpga;
    QGroupBox *groupBox_10;
    QPushButton *triggerCnt_fpga_clear;
    QPushButton *triggerCnt_fpga_enable;
    QPushButton *triggerCnt_fpga_read;
    QGroupBox *groupBox_16;
    QPushButton *triggerDisable_fpga;
    QPushButton *triggerEnable_fpga;
    QGroupBox *groupBox_17;
    QPushButton *realData_fpga;
    QPushButton *testData_fpga;
    QGroupBox *groupBox_20;
    QSpinBox *fa_maxCnt;
    QPushButton *timeWindow_fpgaPB;
    QPushButton *trigger_fpga_init;
    QPushButton *closeConnection_tr;
    QGroupBox *groupBox_18;
    QTextEdit *debugScreen;
    QPushButton *clearDebugScreenPB;
    QGroupBox *groupBox_19;
    QTextEdit *debugScreen_fpga;
    QPushButton *clearDebugScreenPB_fpga;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1154, 874);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(9);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 261, 391));
        groupBox->setFont(font);
        openConnection = new QPushButton(groupBox);
        openConnection->setObjectName(QString::fromUtf8("openConnection"));
        openConnection->setGeometry(QRect(10, 45, 121, 31));
        openConnection->setFont(font);
        connectionLabel = new QLabel(groupBox);
        connectionLabel->setObjectName(QString::fromUtf8("connectionLabel"));
        connectionLabel->setGeometry(QRect(130, 50, 121, 16));
        connectionLabel->setFont(font);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(80, 70, 101, 91));
        groupBox_2->setFont(font);
        readRB = new QRadioButton(groupBox_2);
        readRB->setObjectName(QString::fromUtf8("readRB"));
        readRB->setGeometry(QRect(10, 40, 51, 20));
        readRB->setFont(font);
        writeRB = new QRadioButton(groupBox_2);
        writeRB->setObjectName(QString::fromUtf8("writeRB"));
        writeRB->setGeometry(QRect(10, 20, 51, 20));
        writeRB->setFont(font);
        setVMMs = new QComboBox(groupBox_2);
        setVMMs->setObjectName(QString::fromUtf8("setVMMs"));
        setVMMs->setGeometry(QRect(1, 66, 51, 21));
        setVMMs->setFont(font);
        setVMMs->setMinimumContentsLength(1);
        cmdlabel = new QLabel(groupBox_2);
        cmdlabel->setObjectName(QString::fromUtf8("cmdlabel"));
        cmdlabel->setEnabled(false);
        cmdlabel->setGeometry(QRect(54, 48, 41, 16));
        cmdlabel->setFont(font);
        cmdlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SendConfiguration = new QPushButton(groupBox_2);
        SendConfiguration->setObjectName(QString::fromUtf8("SendConfiguration"));
        SendConfiguration->setEnabled(true);
        SendConfiguration->setGeometry(QRect(54, 64, 51, 31));
        SendConfiguration->setFont(font);
        groupBox_7 = new QGroupBox(groupBox);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 70, 61, 91));
        groupBox_7->setFont(font);
        lx9RB = new QRadioButton(groupBox_7);
        lx9RB->setObjectName(QString::fromUtf8("lx9RB"));
        lx9RB->setGeometry(QRect(10, 20, 51, 20));
        lx9RB->setFont(font);
        fecRB = new QRadioButton(groupBox_7);
        fecRB->setObjectName(QString::fromUtf8("fecRB"));
        fecRB->setGeometry(QRect(10, 40, 51, 20));
        fecRB->setFont(font);
        spiRB = new QRadioButton(groupBox_7);
        spiRB->setObjectName(QString::fromUtf8("spiRB"));
        spiRB->setGeometry(QRect(10, 60, 51, 20));
        spiRB->setFont(font);
        groupBox_11 = new QGroupBox(groupBox);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(10, 270, 241, 61));
        groupBox_11->setFont(font);
        detectionMode = new QComboBox(groupBox_11);
        detectionMode->setObjectName(QString::fromUtf8("detectionMode"));
        detectionMode->setGeometry(QRect(120, 17, 61, 21));
        detectionMode->setFont(font);
        detectionMode->setMinimumContentsLength(1);
        applyDetectionMode = new QPushButton(groupBox_11);
        applyDetectionMode->setObjectName(QString::fromUtf8("applyDetectionMode"));
        applyDetectionMode->setEnabled(true);
        applyDetectionMode->setGeometry(QRect(183, 26, 51, 31));
        applyDetectionMode->setFont(font);
        edgeSelection = new QComboBox(groupBox_11);
        edgeSelection->setObjectName(QString::fromUtf8("edgeSelection"));
        edgeSelection->setGeometry(QRect(120, 37, 61, 21));
        edgeSelection->setFont(font);
        edgeSelection->setMinimumContentsLength(1);
        layoutWidget = new QWidget(groupBox_11);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 24, 106, 27));
        horizontalLayout_19 = new QHBoxLayout(layoutWidget);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(9);
        label_2->setFont(font1);

        horizontalLayout_19->addWidget(label_2);

        detectionTime = new QSpinBox(layoutWidget);
        detectionTime->setObjectName(QString::fromUtf8("detectionTime"));
        detectionTime->setFont(font);
        detectionTime->setMinimum(50);
        detectionTime->setMaximum(65535);
        detectionTime->setSingleStep(25);

        horizontalLayout_19->addWidget(detectionTime);

        groupBox_15 = new QGroupBox(groupBox);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setGeometry(QRect(10, 220, 241, 51));
        layoutWidget1 = new QWidget(groupBox_15);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 22, 221, 34));
        horizontalLayout_17 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        header4LE = new QLineEdit(layoutWidget1);
        header4LE->setObjectName(QString::fromUtf8("header4LE"));
        header4LE->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(header4LE);

        header3LE = new QLineEdit(layoutWidget1);
        header3LE->setObjectName(QString::fromUtf8("header3LE"));
        header3LE->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(header3LE);

        header2LE = new QLineEdit(layoutWidget1);
        header2LE->setObjectName(QString::fromUtf8("header2LE"));
        header2LE->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(header2LE);

        header1LE = new QLineEdit(layoutWidget1);
        header1LE->setObjectName(QString::fromUtf8("header1LE"));
        header1LE->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(header1LE);

        setHeaderPB = new QPushButton(layoutWidget1);
        setHeaderPB->setObjectName(QString::fromUtf8("setHeaderPB"));
        setHeaderPB->setFont(font1);

        horizontalLayout_17->addWidget(setHeaderPB);

        groupBox_22 = new QGroupBox(groupBox);
        groupBox_22->setObjectName(QString::fromUtf8("groupBox_22"));
        groupBox_22->setGeometry(QRect(10, 160, 41, 61));
        groupBox_22->setFont(font1);
        sampleSetPB = new QPushButton(groupBox_22);
        sampleSetPB->setObjectName(QString::fromUtf8("sampleSetPB"));
        sampleSetPB->setGeometry(QRect(3, 40, 31, 16));
        sampleSetPB->setFont(font);
        sampleValue = new QComboBox(groupBox_22);
        sampleValue->setObjectName(QString::fromUtf8("sampleValue"));
        sampleValue->setGeometry(QRect(-2, 15, 41, 21));
        sampleValue->setFont(font);
        sampleValue->setMinimumContentsLength(1);
        groupBox_12 = new QGroupBox(groupBox);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(190, 70, 61, 91));
        groupBox_12->setFont(font);
        triggerMode = new QComboBox(groupBox_12);
        triggerMode->setObjectName(QString::fromUtf8("triggerMode"));
        triggerMode->setGeometry(QRect(4, 17, 51, 21));
        triggerMode->setFont(font);
        triggerMode->setMinimumContentsLength(1);
        applyTrigger = new QPushButton(groupBox_12);
        applyTrigger->setObjectName(QString::fromUtf8("applyTrigger"));
        applyTrigger->setEnabled(true);
        applyTrigger->setGeometry(QRect(3, 64, 51, 31));
        applyTrigger->setFont(font);
        triggerTimeout = new QSpinBox(groupBox_12);
        triggerTimeout->setObjectName(QString::fromUtf8("triggerTimeout"));
        triggerTimeout->setGeometry(QRect(6, 42, 51, 25));
        triggerTimeout->setFont(font);
        triggerTimeout->setMinimum(25);
        triggerTimeout->setMaximum(65535);
        triggerTimeout->setSingleStep(25);
        triggerTimeout->setValue(1275);
        groupBox_14 = new QGroupBox(groupBox);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(60, 160, 71, 61));
        groupBox_14->setFont(font1);
        setDaqMode = new QPushButton(groupBox_14);
        setDaqMode->setObjectName(QString::fromUtf8("setDaqMode"));
        setDaqMode->setGeometry(QRect(-1, 35, 71, 31));
        setDaqMode->setFont(font1);
        daqModeOutput = new QComboBox(groupBox_14);
        daqModeOutput->setObjectName(QString::fromUtf8("daqModeOutput"));
        daqModeOutput->setGeometry(QRect(0, 16, 71, 21));
        daqModeOutput->setFont(font);
        daqModeOutput->setMinimumContentsLength(1);
        groupBox_25 = new QGroupBox(groupBox);
        groupBox_25->setObjectName(QString::fromUtf8("groupBox_25"));
        groupBox_25->setGeometry(QRect(140, 160, 51, 61));
        groupBox_25->setFont(font1);
        onACQ = new QPushButton(groupBox_25);
        onACQ->setObjectName(QString::fromUtf8("onACQ"));
        onACQ->setGeometry(QRect(-1, 14, 51, 31));
        onACQ->setFont(font1);
        offACQ = new QPushButton(groupBox_25);
        offACQ->setObjectName(QString::fromUtf8("offACQ"));
        offACQ->setGeometry(QRect(-1, 35, 51, 31));
        offACQ->setFont(font1);
        groupBox_24 = new QGroupBox(groupBox);
        groupBox_24->setObjectName(QString::fromUtf8("groupBox_24"));
        groupBox_24->setGeometry(QRect(200, 160, 51, 61));
        groupBox_24->setFont(font1);
        startDi = new QPushButton(groupBox_24);
        startDi->setObjectName(QString::fromUtf8("startDi"));
        startDi->setGeometry(QRect(0, 15, 51, 31));
        startDi->setFont(font1);
        stopDi = new QPushButton(groupBox_24);
        stopDi->setObjectName(QString::fromUtf8("stopDi"));
        stopDi->setGeometry(QRect(0, 35, 51, 31));
        stopDi->setFont(font1);
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(3, 20, 251, 29));
        horizontalLayout_22 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_22->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ip1 = new QLineEdit(layoutWidget2);
        ip1->setObjectName(QString::fromUtf8("ip1"));
        ip1->setFont(font);
        ip1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(ip1);

        ip2 = new QLineEdit(layoutWidget2);
        ip2->setObjectName(QString::fromUtf8("ip2"));
        ip2->setFont(font);
        ip2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(ip2);

        ip3 = new QLineEdit(layoutWidget2);
        ip3->setObjectName(QString::fromUtf8("ip3"));
        ip3->setFont(font);
        ip3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(ip3);

        ip4 = new QLineEdit(layoutWidget2);
        ip4->setObjectName(QString::fromUtf8("ip4"));
        ip4->setFont(font);
        ip4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(ip4);

        numbersOfFecs = new QSpinBox(layoutWidget2);
        numbersOfFecs->setObjectName(QString::fromUtf8("numbersOfFecs"));
        numbersOfFecs->setFont(font);
        numbersOfFecs->setMinimum(0);
        numbersOfFecs->setMaximum(16);

        horizontalLayout_4->addWidget(numbersOfFecs);


        horizontalLayout_22->addLayout(horizontalLayout_4);

        triggerCounter_reset = new QPushButton(groupBox);
        triggerCounter_reset->setObjectName(QString::fromUtf8("triggerCounter_reset"));
        triggerCounter_reset->setEnabled(true);
        triggerCounter_reset->setGeometry(QRect(156, 340, 51, 32));
        triggerCounter_reset->setFont(font);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(11, 344, 29, 16));
        label_5->setFont(font1);
        asic_reset = new QPushButton(groupBox);
        asic_reset->setObjectName(QString::fromUtf8("asic_reset"));
        asic_reset->setEnabled(true);
        asic_reset->setGeometry(QRect(48, 340, 52, 32));
        asic_reset->setFont(font);
        cdaq_reset = new QPushButton(groupBox);
        cdaq_reset->setObjectName(QString::fromUtf8("cdaq_reset"));
        cdaq_reset->setEnabled(true);
        cdaq_reset->setGeometry(QRect(102, 340, 52, 32));
        cdaq_reset->setFont(font);
        lx9Reset = new QPushButton(groupBox);
        lx9Reset->setObjectName(QString::fromUtf8("lx9Reset"));
        lx9Reset->setEnabled(true);
        lx9Reset->setGeometry(QRect(209, 340, 52, 32));
        lx9Reset->setFont(font);
        triggerCounter_reset->raise();
        label_5->raise();
        asic_reset->raise();
        cdaq_reset->raise();
        lx9Reset->raise();
        openConnection->raise();
        connectionLabel->raise();
        groupBox_2->raise();
        groupBox_7->raise();
        groupBox_11->raise();
        groupBox_15->raise();
        groupBox_22->raise();
        groupBox_12->raise();
        groupBox_14->raise();
        groupBox_25->raise();
        groupBox_24->raise();
        layoutWidget->raise();
        runGroupbox = new QGroupBox(centralWidget);
        runGroupbox->setObjectName(QString::fromUtf8("runGroupbox"));
        runGroupbox->setGeometry(QRect(10, 570, 601, 121));
        runGroupbox->setFont(font);
        userComments = new QLineEdit(runGroupbox);
        userComments->setObjectName(QString::fromUtf8("userComments"));
        userComments->setEnabled(true);
        userComments->setGeometry(QRect(67, 84, 163, 21));
        userComments->setFont(font);
        userComments->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(runGroupbox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(11, 27, 55, 16));
        label_3->setFont(font1);
        label_4 = new QLabel(runGroupbox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(11, 86, 48, 16));
        label_4->setFont(font1);
        runNumber = new QSpinBox(runGroupbox);
        runNumber->setObjectName(QString::fromUtf8("runNumber"));
        runNumber->setGeometry(QRect(74, 23, 62, 25));
        runNumber->setFont(font);
        runNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        runNumber->setMaximum(1000000);
        runNumber->setValue(8000);
        label_6 = new QLabel(runGroupbox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(11, 57, 40, 16));
        label_6->setFont(font1);
        runDirectoryField = new QLineEdit(runGroupbox);
        runDirectoryField->setObjectName(QString::fromUtf8("runDirectoryField"));
        runDirectoryField->setEnabled(true);
        runDirectoryField->setGeometry(QRect(68, 55, 111, 21));
        runDirectoryField->setFont(font);
        runDirectoryField->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        selectDir = new QPushButton(runGroupbox);
        selectDir->setObjectName(QString::fromUtf8("selectDir"));
        selectDir->setGeometry(QRect(175, 51, 62, 32));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/directory.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectDir->setIcon(icon);
        label_7 = new QLabel(runGroupbox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(434, 20, 161, 51));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/logo.png")));
        label_7->setScaledContents(true);
        angle = new QSpinBox(runGroupbox);
        angle->setObjectName(QString::fromUtf8("angle"));
        angle->setGeometry(QRect(185, 23, 39, 25));
        angle->setFont(font);
        angle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        angle->setMinimum(-90);
        angle->setMaximum(90);
        angle->setValue(0);
        label_8 = new QLabel(runGroupbox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(146, 27, 31, 16));
        label_8->setFont(font1);
        stopTriggerCnt = new QPushButton(runGroupbox);
        stopTriggerCnt->setObjectName(QString::fromUtf8("stopTriggerCnt"));
        stopTriggerCnt->setGeometry(QRect(334, 58, 91, 31));
        stopTriggerCnt->setFont(font);
        clearTriggerCnt = new QPushButton(runGroupbox);
        clearTriggerCnt->setObjectName(QString::fromUtf8("clearTriggerCnt"));
        clearTriggerCnt->setGeometry(QRect(243, 24, 91, 31));
        clearTriggerCnt->setFont(font);
        checkTriggers = new QPushButton(runGroupbox);
        checkTriggers->setObjectName(QString::fromUtf8("checkTriggers"));
        checkTriggers->setGeometry(QRect(240, 58, 91, 31));
        checkTriggers->setFont(font);
        runStatusField = new QTextEdit(runGroupbox);
        runStatusField->setObjectName(QString::fromUtf8("runStatusField"));
        runStatusField->setGeometry(QRect(243, 85, 91, 21));
        runStatusField->setFont(font1);
        frame = new QFrame(runGroupbox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(240, 20, 191, 41));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(runGroupbox);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(240, 60, 191, 51));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(runGroupbox);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(6, 20, 231, 91));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(runGroupbox);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(436, 70, 161, 41));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        layoutWidget3 = new QWidget(runGroupbox);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(340, 23, 81, 32));
        gridLayout_4 = new QGridLayout(layoutWidget3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        gridLayout_4->addWidget(label_9, 0, 0, 1, 1);

        triggerCntLabel_fpga = new QLabel(layoutWidget3);
        triggerCntLabel_fpga->setObjectName(QString::fromUtf8("triggerCntLabel_fpga"));
        triggerCntLabel_fpga->setFont(font);

        gridLayout_4->addWidget(triggerCntLabel_fpga, 0, 1, 1, 1);

        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);

        gridLayout_4->addWidget(label_10, 1, 0, 1, 1);

        triggerCntLabel = new QLabel(layoutWidget3);
        triggerCntLabel->setObjectName(QString::fromUtf8("triggerCntLabel"));
        triggerCntLabel->setFont(font);

        gridLayout_4->addWidget(triggerCntLabel, 1, 1, 1, 1);

        calibration = new QCheckBox(runGroupbox);
        calibration->setObjectName(QString::fromUtf8("calibration"));
        calibration->setGeometry(QRect(440, 92, 68, 18));
        calibration->setFont(font);
        enableDebugPB = new QCheckBox(runGroupbox);
        enableDebugPB->setObjectName(QString::fromUtf8("enableDebugPB"));
        enableDebugPB->setGeometry(QRect(509, 92, 82, 18));
        enableDebugPB->setFont(font);
        hideChannels = new QCheckBox(runGroupbox);
        hideChannels->setObjectName(QString::fromUtf8("hideChannels"));
        hideChannels->setGeometry(QRect(509, 73, 88, 18));
        hideChannels->setFont(font);
        monitoring = new QCheckBox(runGroupbox);
        monitoring->setObjectName(QString::fromUtf8("monitoring"));
        monitoring->setGeometry(QRect(440, 73, 67, 18));
        monitoring->setFont(font);
        readTrigger = new QCheckBox(runGroupbox);
        readTrigger->setObjectName(QString::fromUtf8("readTrigger"));
        readTrigger->setGeometry(QRect(350, 86, 71, 18));
        readTrigger->setFont(font);
        label_7->raise();
        frame_4->raise();
        calibration->raise();
        enableDebugPB->raise();
        hideChannels->raise();
        monitoring->raise();
        frame_2->raise();
        frame->raise();
        frame_3->raise();
        userComments->raise();
        label_3->raise();
        label_4->raise();
        runNumber->raise();
        layoutWidget->raise();
        label_6->raise();
        runDirectoryField->raise();
        selectDir->raise();
        angle->raise();
        label_8->raise();
        stopTriggerCnt->raise();
        clearTriggerCnt->raise();
        checkTriggers->raise();
        runStatusField->raise();
        readTrigger->raise();
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(280, 0, 331, 571));
        groupBox_4->setFont(font);
        layoutWidget4 = new QWidget(groupBox_4);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 20, 301, 178));
        layoutWidget4->setFont(font);
        verticalLayout_4 = new QVBoxLayout(layoutWidget4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sgLabel = new QLabel(layoutWidget4);
        sgLabel->setObjectName(QString::fromUtf8("sgLabel"));
        sgLabel->setFont(font);

        horizontalLayout->addWidget(sgLabel);

        sg = new QComboBox(layoutWidget4);
        sg->setObjectName(QString::fromUtf8("sg"));
        sg->setFont(font);

        horizontalLayout->addWidget(sg);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        stLabel = new QLabel(layoutWidget4);
        stLabel->setObjectName(QString::fromUtf8("stLabel"));
        stLabel->setFont(font);

        horizontalLayout_2->addWidget(stLabel);

        st = new QComboBox(layoutWidget4);
        st->setObjectName(QString::fromUtf8("st"));
        st->setFont(font);

        horizontalLayout_2->addWidget(st);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        sngLabel = new QLabel(layoutWidget4);
        sngLabel->setObjectName(QString::fromUtf8("sngLabel"));
        sngLabel->setFont(font);

        horizontalLayout_6->addWidget(sngLabel);

        sng = new QComboBox(layoutWidget4);
        sng->setObjectName(QString::fromUtf8("sng"));
        sng->setFont(font);

        horizontalLayout_6->addWidget(sng);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        stcLabel = new QLabel(layoutWidget4);
        stcLabel->setObjectName(QString::fromUtf8("stcLabel"));
        stcLabel->setFont(font);

        horizontalLayout_3->addWidget(stcLabel);

        stc = new QComboBox(layoutWidget4);
        stc->setObjectName(QString::fromUtf8("stc"));
        stc->setFont(font);
        stc->setMaxVisibleItems(16);

        horizontalLayout_3->addWidget(stc);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        sdpLabel = new QLabel(layoutWidget4);
        sdpLabel->setObjectName(QString::fromUtf8("sdpLabel"));
        sdpLabel->setFont(font);

        horizontalLayout_7->addWidget(sdpLabel);

        sdp = new QComboBox(layoutWidget4);
        sdp->setObjectName(QString::fromUtf8("sdp"));
        sdp->setFont(font);

        horizontalLayout_7->addWidget(sdp);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        sfaLabel = new QLabel(layoutWidget4);
        sfaLabel->setObjectName(QString::fromUtf8("sfaLabel"));
        sfaLabel->setFont(font);

        horizontalLayout_9->addWidget(sfaLabel);

        sfa = new QComboBox(layoutWidget4);
        sfa->setObjectName(QString::fromUtf8("sfa"));
        sfa->setFont(font);

        horizontalLayout_9->addWidget(sfa);

        sfamLabel = new QLabel(layoutWidget4);
        sfamLabel->setObjectName(QString::fromUtf8("sfamLabel"));
        sfamLabel->setFont(font);

        horizontalLayout_9->addWidget(sfamLabel);

        sfam = new QComboBox(layoutWidget4);
        sfam->setObjectName(QString::fromUtf8("sfam"));
        sfam->setFont(font);

        horizontalLayout_9->addWidget(sfam);


        verticalLayout_4->addLayout(horizontalLayout_9);

        layoutWidget5 = new QWidget(groupBox_4);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(7, 270, 311, 216));
        layoutWidget5->setFont(font);
        verticalLayout_5 = new QVBoxLayout(layoutWidget5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        sstpLabel = new QLabel(layoutWidget5);
        sstpLabel->setObjectName(QString::fromUtf8("sstpLabel"));
        sstpLabel->setFont(font);

        horizontalLayout_10->addWidget(sstpLabel);

        sstp = new QComboBox(layoutWidget5);
        sstp->setObjectName(QString::fromUtf8("sstp"));
        sstp->setFont(font);

        horizontalLayout_10->addWidget(sstp);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        sshLabel = new QLabel(layoutWidget5);
        sshLabel->setObjectName(QString::fromUtf8("sshLabel"));
        sshLabel->setFont(font);

        horizontalLayout_11->addWidget(sshLabel);

        ssh = new QComboBox(layoutWidget5);
        ssh->setObjectName(QString::fromUtf8("ssh"));
        ssh->setFont(font);

        horizontalLayout_11->addWidget(ssh);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        stttLabel = new QLabel(layoutWidget5);
        stttLabel->setObjectName(QString::fromUtf8("stttLabel"));
        stttLabel->setFont(font);

        horizontalLayout_12->addWidget(stttLabel);

        sttt = new QComboBox(layoutWidget5);
        sttt->setObjectName(QString::fromUtf8("sttt"));
        sttt->setFont(font);

        horizontalLayout_12->addWidget(sttt);

        stotLabel = new QLabel(layoutWidget5);
        stotLabel->setObjectName(QString::fromUtf8("stotLabel"));
        stotLabel->setFont(font);

        horizontalLayout_12->addWidget(stotLabel);

        stot = new QComboBox(layoutWidget5);
        stot->setObjectName(QString::fromUtf8("stot"));
        stot->setFont(font);

        horizontalLayout_12->addWidget(stot);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        s16Label = new QLabel(layoutWidget5);
        s16Label->setObjectName(QString::fromUtf8("s16Label"));
        s16Label->setFont(font);

        horizontalLayout_13->addWidget(s16Label);

        s16 = new QComboBox(layoutWidget5);
        s16->setObjectName(QString::fromUtf8("s16"));
        s16->setFont(font);

        horizontalLayout_13->addWidget(s16);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        srstLabel = new QLabel(layoutWidget5);
        srstLabel->setObjectName(QString::fromUtf8("srstLabel"));
        srstLabel->setFont(font);

        horizontalLayout_14->addWidget(srstLabel);

        srst = new QComboBox(layoutWidget5);
        srst->setObjectName(QString::fromUtf8("srst"));
        srst->setFont(font);

        horizontalLayout_14->addWidget(srst);


        verticalLayout_5->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        sdtLabel = new QLabel(layoutWidget5);
        sdtLabel->setObjectName(QString::fromUtf8("sdtLabel"));
        sdtLabel->setFont(font);

        horizontalLayout_16->addWidget(sdtLabel);

        sdt = new QSpinBox(layoutWidget5);
        sdt->setObjectName(QString::fromUtf8("sdt"));
        sdt->setFont(font);
        sdt->setMaximum(1023);
        sdt->setValue(205);

        horizontalLayout_16->addWidget(sdt);


        verticalLayout_5->addLayout(horizontalLayout_16);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        sdpLabel_2 = new QLabel(layoutWidget5);
        sdpLabel_2->setObjectName(QString::fromUtf8("sdpLabel_2"));
        sdpLabel_2->setFont(font);

        horizontalLayout_15->addWidget(sdpLabel_2);

        sdp_2 = new QSpinBox(layoutWidget5);
        sdp_2->setObjectName(QString::fromUtf8("sdp_2"));
        sdp_2->setFont(font);
        sdp_2->setMaximum(1023);
        sdp_2->setValue(700);

        horizontalLayout_15->addWidget(sdp_2);


        verticalLayout_5->addLayout(horizontalLayout_15);

        dacmvLabel = new QLabel(groupBox_4);
        dacmvLabel->setObjectName(QString::fromUtf8("dacmvLabel"));
        dacmvLabel->setGeometry(QRect(92, 427, 62, 20));
        dacmvLabel->setFont(font1);
        layoutWidget6 = new QWidget(groupBox_4);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 210, 301, 26));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        sbfmLabel = new QLabel(layoutWidget6);
        sbfmLabel->setObjectName(QString::fromUtf8("sbfmLabel"));
        sbfmLabel->setFont(font);

        horizontalLayout_5->addWidget(sbfmLabel);

        sbfm = new QComboBox(layoutWidget6);
        sbfm->setObjectName(QString::fromUtf8("sbfm"));
        sbfm->setFont(font);

        horizontalLayout_5->addWidget(sbfm);

        sbfpLabel = new QLabel(layoutWidget6);
        sbfpLabel->setObjectName(QString::fromUtf8("sbfpLabel"));
        sbfpLabel->setFont(font);

        horizontalLayout_5->addWidget(sbfpLabel);

        sbfp = new QComboBox(layoutWidget6);
        sbfp->setObjectName(QString::fromUtf8("sbfp"));
        sbfp->setFont(font);

        horizontalLayout_5->addWidget(sbfp);

        sbftLabel = new QLabel(layoutWidget6);
        sbftLabel->setObjectName(QString::fromUtf8("sbftLabel"));
        sbftLabel->setFont(font);

        horizontalLayout_5->addWidget(sbftLabel);

        sbft = new QComboBox(layoutWidget6);
        sbft->setObjectName(QString::fromUtf8("sbft"));
        sbft->setFont(font);

        horizontalLayout_5->addWidget(sbft);

        layoutWidget7 = new QWidget(groupBox_4);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(10, 240, 301, 26));
        layoutWidget7->setFont(font);
        horizontalLayout_8 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        sm5_sm0Label = new QLabel(layoutWidget7);
        sm5_sm0Label->setObjectName(QString::fromUtf8("sm5_sm0Label"));
        sm5_sm0Label->setFont(font);

        horizontalLayout_8->addWidget(sm5_sm0Label);

        sm5_sm0 = new QComboBox(layoutWidget7);
        sm5_sm0->setObjectName(QString::fromUtf8("sm5_sm0"));
        sm5_sm0->setFont(font);

        horizontalLayout_8->addWidget(sm5_sm0);

        scmxLabel = new QLabel(layoutWidget7);
        scmxLabel->setObjectName(QString::fromUtf8("scmxLabel"));
        scmxLabel->setFont(font);

        horizontalLayout_8->addWidget(scmxLabel);

        scmx = new QComboBox(layoutWidget7);
        scmx->setObjectName(QString::fromUtf8("scmx"));
        scmx->setFont(font);

        horizontalLayout_8->addWidget(scmx);

        loadCalibDataCB = new QCheckBox(groupBox_4);
        loadCalibDataCB->setObjectName(QString::fromUtf8("loadCalibDataCB"));
        loadCalibDataCB->setGeometry(QRect(10, 490, 121, 20));
        loadThrCB = new QCheckBox(groupBox_4);
        loadThrCB->setObjectName(QString::fromUtf8("loadThrCB"));
        loadThrCB->setGeometry(QRect(130, 490, 87, 20));
        abovePed = new QSpinBox(groupBox_4);
        abovePed->setObjectName(QString::fromUtf8("abovePed"));
        abovePed->setGeometry(QRect(230, 490, 52, 25));
        abovePed->setFont(font);
        abovePed->setMinimum(5);
        abovePed->setMaximum(25);
        abovePed->setSingleStep(5);
        abovePed->setValue(5);
        calibRunSettings = new QGroupBox(centralWidget);
        calibRunSettings->setObjectName(QString::fromUtf8("calibRunSettings"));
        calibRunSettings->setGeometry(QRect(280, 518, 310, 55));
        calibRunSettings->setFont(font);
        frameCalib2 = new QFrame(calibRunSettings);
        frameCalib2->setObjectName(QString::fromUtf8("frameCalib2"));
        frameCalib2->setGeometry(QRect(5, 18, 300, 35));
        frameCalib2->setFrameShape(QFrame::StyledPanel);
        frameCalib2->setFrameShadow(QFrame::Raised);
        horizontalLayout_calibRun = new QHBoxLayout(calibRunSettings);
        horizontalLayout_calibRun->setSpacing(6);
        horizontalLayout_calibRun->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_calibRun->setObjectName(QString::fromUtf8("horizontalLayout_calibRun"));
        calibTime = new QCheckBox(calibRunSettings);
        calibTime->setObjectName(QString::fromUtf8("calibTime"));
        calibTime->setGeometry(QRect(10, 0, 190, 90));

        horizontalLayout_calibRun->addWidget(calibTime);

        calibGain = new QCheckBox(calibRunSettings);
        calibGain->setObjectName(QString::fromUtf8("calibGain"));
        calibGain->setGeometry(QRect(200, 0, 190, 90));

        horizontalLayout_calibRun->addWidget(calibGain);

        groupBox_8 = new QGroupBox(centralWidget);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 375, 261, 188));
        groupBox_8->setFont(font);
        layoutWidget_3 = new QWidget(groupBox_8);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 16, 201, 27));
        layoutWidget_3->setFont(font);
        horizontalLayout_18 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        ip1_tr = new QLineEdit(layoutWidget_3);
        ip1_tr->setObjectName(QString::fromUtf8("ip1_tr"));
        ip1_tr->setFont(font);
        ip1_tr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_18->addWidget(ip1_tr);

        ip2_tr = new QLineEdit(layoutWidget_3);
        ip2_tr->setObjectName(QString::fromUtf8("ip2_tr"));
        ip2_tr->setFont(font);
        ip2_tr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_18->addWidget(ip2_tr);

        ip3_tr = new QLineEdit(layoutWidget_3);
        ip3_tr->setObjectName(QString::fromUtf8("ip3_tr"));
        ip3_tr->setFont(font);
        ip3_tr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_18->addWidget(ip3_tr);

        ip4_tr = new QLineEdit(layoutWidget_3);
        ip4_tr->setObjectName(QString::fromUtf8("ip4_tr"));
        ip4_tr->setFont(font);
        ip4_tr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_18->addWidget(ip4_tr);

        connectionLabel_tr = new QLabel(groupBox_8);
        connectionLabel_tr->setObjectName(QString::fromUtf8("connectionLabel_tr"));
        connectionLabel_tr->setGeometry(QRect(172, 45, 81, 20));
        connectionLabel_tr->setFont(font);
        openConnection_tr = new QPushButton(groupBox_8);
        openConnection_tr->setObjectName(QString::fromUtf8("openConnection_tr"));
        openConnection_tr->setGeometry(QRect(10, 41, 71, 31));
        openConnection_tr->setFont(font);
        groupBox_9 = new QGroupBox(groupBox_8);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 70, 51, 61));
        groupBox_9->setFont(font);
        offAcq_fpga = new QPushButton(groupBox_9);
        offAcq_fpga->setObjectName(QString::fromUtf8("offAcq_fpga"));
        offAcq_fpga->setGeometry(QRect(-1, 38, 51, 31));
        offAcq_fpga->setFont(font);
        onAcq_fpga = new QPushButton(groupBox_9);
        onAcq_fpga->setObjectName(QString::fromUtf8("onAcq_fpga"));
        onAcq_fpga->setGeometry(QRect(-1, 14, 51, 31));
        onAcq_fpga->setFont(font);
        groupBox_10 = new QGroupBox(groupBox_8);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(200, 70, 51, 81));
        groupBox_10->setFont(font);
        triggerCnt_fpga_clear = new QPushButton(groupBox_10);
        triggerCnt_fpga_clear->setObjectName(QString::fromUtf8("triggerCnt_fpga_clear"));
        triggerCnt_fpga_clear->setGeometry(QRect(1, 36, 51, 31));
        triggerCnt_fpga_clear->setFont(font);
        triggerCnt_fpga_enable = new QPushButton(groupBox_10);
        triggerCnt_fpga_enable->setObjectName(QString::fromUtf8("triggerCnt_fpga_enable"));
        triggerCnt_fpga_enable->setGeometry(QRect(1, 14, 51, 31));
        triggerCnt_fpga_enable->setFont(font);
        triggerCnt_fpga_read = new QPushButton(groupBox_10);
        triggerCnt_fpga_read->setObjectName(QString::fromUtf8("triggerCnt_fpga_read"));
        triggerCnt_fpga_read->setGeometry(QRect(1, 58, 51, 31));
        triggerCnt_fpga_read->setFont(font);
        groupBox_16 = new QGroupBox(groupBox_8);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        groupBox_16->setGeometry(QRect(130, 70, 61, 61));
        groupBox_16->setFont(font);
        triggerDisable_fpga = new QPushButton(groupBox_16);
        triggerDisable_fpga->setObjectName(QString::fromUtf8("triggerDisable_fpga"));
        triggerDisable_fpga->setGeometry(QRect(2, 38, 61, 31));
        triggerDisable_fpga->setFont(font);
        triggerEnable_fpga = new QPushButton(groupBox_16);
        triggerEnable_fpga->setObjectName(QString::fromUtf8("triggerEnable_fpga"));
        triggerEnable_fpga->setGeometry(QRect(2, 14, 61, 31));
        triggerEnable_fpga->setFont(font);
        groupBox_17 = new QGroupBox(groupBox_8);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        groupBox_17->setGeometry(QRect(70, 70, 51, 61));
        groupBox_17->setFont(font);
        realData_fpga = new QPushButton(groupBox_17);
        realData_fpga->setObjectName(QString::fromUtf8("realData_fpga"));
        realData_fpga->setGeometry(QRect(0, 15, 51, 31));
        realData_fpga->setFont(font);
        testData_fpga = new QPushButton(groupBox_17);
        testData_fpga->setObjectName(QString::fromUtf8("testData_fpga"));
        testData_fpga->setGeometry(QRect(0, 38, 51, 31));
        testData_fpga->setFont(font);
        groupBox_20 = new QGroupBox(groupBox_8);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        groupBox_20->setGeometry(QRect(10, 140, 141, 51));
        groupBox_20->setFont(font1);
        fa_maxCnt = new QSpinBox(groupBox_20);
        fa_maxCnt->setObjectName(QString::fromUtf8("fa_maxCnt"));
        fa_maxCnt->setGeometry(QRect(12, 20, 71, 21));
        fa_maxCnt->setFont(font);
        fa_maxCnt->setMaximum(255);
        fa_maxCnt->setValue(255);
        timeWindow_fpgaPB = new QPushButton(groupBox_20);
        timeWindow_fpgaPB->setObjectName(QString::fromUtf8("timeWindow_fpgaPB"));
        timeWindow_fpgaPB->setGeometry(QRect(90, 17, 51, 31));
        timeWindow_fpgaPB->setFont(font);
        trigger_fpga_init = new QPushButton(groupBox_8);
        trigger_fpga_init->setObjectName(QString::fromUtf8("trigger_fpga_init"));
        trigger_fpga_init->setGeometry(QRect(196, 158, 61, 31));
        trigger_fpga_init->setFont(font);
        closeConnection_tr = new QPushButton(groupBox_8);
        closeConnection_tr->setObjectName(QString::fromUtf8("closeConnection_tr"));
        closeConnection_tr->setGeometry(QRect(82, 41, 71, 31));
        closeConnection_tr->setFont(font);
        groupBox_18 = new QGroupBox(centralWidget);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        groupBox_18->setGeometry(QRect(10, 690, 271, 151));
        debugScreen = new QTextEdit(groupBox_18);
        debugScreen->setObjectName(QString::fromUtf8("debugScreen"));
        debugScreen->setGeometry(QRect(10, 50, 251, 91));
        debugScreen->setFont(font1);
        clearDebugScreenPB = new QPushButton(groupBox_18);
        clearDebugScreenPB->setObjectName(QString::fromUtf8("clearDebugScreenPB"));
        clearDebugScreenPB->setGeometry(QRect(10, 30, 41, 16));
        clearDebugScreenPB->setFont(font);
        groupBox_19 = new QGroupBox(centralWidget);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        groupBox_19->setGeometry(QRect(290, 690, 321, 151));
        debugScreen_fpga = new QTextEdit(groupBox_19);
        debugScreen_fpga->setObjectName(QString::fromUtf8("debugScreen_fpga"));
        debugScreen_fpga->setGeometry(QRect(10, 50, 301, 91));
        debugScreen_fpga->setFont(font1);
        clearDebugScreenPB_fpga = new QPushButton(groupBox_19);
        clearDebugScreenPB_fpga->setObjectName(QString::fromUtf8("clearDebugScreenPB_fpga"));
        clearDebugScreenPB_fpga->setGeometry(QRect(10, 30, 41, 16));
        clearDebugScreenPB_fpga->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        sampleValue->setCurrentIndex(2);
        triggerMode->setCurrentIndex(1);
        daqModeOutput->setCurrentIndex(1);
        sg->setCurrentIndex(3);
        st->setCurrentIndex(2);
        sng->setCurrentIndex(1);
        stc->setCurrentIndex(2);
        sfa->setCurrentIndex(1);
        sbfm->setCurrentIndex(1);
        sbfp->setCurrentIndex(1);
        sbft->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "FEC - LX9 Control", 0, QApplication::UnicodeUTF8));
        openConnection->setText(QApplication::translate("MainWindow", "Open Communication", 0, QApplication::UnicodeUTF8));
        connectionLabel->setText(QApplication::translate("MainWindow", "  N/A", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Command", 0, QApplication::UnicodeUTF8));
        readRB->setText(QApplication::translate("MainWindow", "Read", 0, QApplication::UnicodeUTF8));
        writeRB->setText(QApplication::translate("MainWindow", "Write", 0, QApplication::UnicodeUTF8));
        cmdlabel->setText(QApplication::translate("MainWindow", "count", 0, QApplication::UnicodeUTF8));
        SendConfiguration->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Mode", 0, QApplication::UnicodeUTF8));
        lx9RB->setText(QApplication::translate("MainWindow", "LX9", 0, QApplication::UnicodeUTF8));
        fecRB->setText(QApplication::translate("MainWindow", "FEC", 0, QApplication::UnicodeUTF8));
        spiRB->setText(QApplication::translate("MainWindow", "SPI", 0, QApplication::UnicodeUTF8));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "Detect Mode-Time-Edge", 0, QApplication::UnicodeUTF8));
        detectionMode->clear();
        detectionMode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "flag", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "pulse", 0, QApplication::UnicodeUTF8)
        );
        applyDetectionMode->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        edgeSelection->clear();
        edgeSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "rising", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "falling", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("MainWindow", "Wait Time", 0, QApplication::UnicodeUTF8));
        groupBox_15->setTitle(QApplication::translate("MainWindow", "Data Header", 0, QApplication::UnicodeUTF8));
        header4LE->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        header3LE->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        header2LE->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        header1LE->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        setHeaderPB->setText(QApplication::translate("MainWindow", "Set", 0, QApplication::UnicodeUTF8));
        groupBox_22->setTitle(QApplication::translate("MainWindow", "Sample", 0, QApplication::UnicodeUTF8));
        sampleSetPB->setText(QApplication::translate("MainWindow", "Set", 0, QApplication::UnicodeUTF8));
        sampleValue->clear();
        sampleValue->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1X", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4X", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8X", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16X", 0, QApplication::UnicodeUTF8)
        );
        groupBox_12->setTitle(QApplication::translate("MainWindow", "Trigger", 0, QApplication::UnicodeUTF8));
        triggerMode->clear();
        triggerMode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Int", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Ext", 0, QApplication::UnicodeUTF8)
        );
        applyTrigger->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        groupBox_14->setTitle(QApplication::translate("MainWindow", "ACQ", 0, QApplication::UnicodeUTF8));
        setDaqMode->setText(QApplication::translate("MainWindow", "Set", 0, QApplication::UnicodeUTF8));
        daqModeOutput->clear();
        daqModeOutput->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Disabled", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "VMM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ADC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "UDP Test", 0, QApplication::UnicodeUTF8)
        );
        groupBox_25->setTitle(QApplication::translate("MainWindow", "DAQ", 0, QApplication::UnicodeUTF8));
        onACQ->setText(QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8));
        offACQ->setText(QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8));
        groupBox_24->setTitle(QApplication::translate("MainWindow", "Pulser", 0, QApplication::UnicodeUTF8));
        startDi->setText(QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8));
        stopDi->setText(QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", " IPs", 0, QApplication::UnicodeUTF8));
        ip1->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        ip2->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ip3->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ip4->setText(QApplication::translate("MainWindow", "16", 0, QApplication::UnicodeUTF8));
        triggerCounter_reset->setText(QApplication::translate("MainWindow", "Tr. Cnt", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Resets", 0, QApplication::UnicodeUTF8));
        asic_reset->setText(QApplication::translate("MainWindow", "ASIC", 0, QApplication::UnicodeUTF8));
        cdaq_reset->setText(QApplication::translate("MainWindow", "CDAQ", 0, QApplication::UnicodeUTF8));
        lx9Reset->setText(QApplication::translate("MainWindow", "lx9", 0, QApplication::UnicodeUTF8));
        runGroupbox->setTitle(QApplication::translate("MainWindow", "Run Control", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Run Number", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Comments", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Directory", 0, QApplication::UnicodeUTF8));
        selectDir->setText(QString());
        label_7->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "  Angle", 0, QApplication::UnicodeUTF8));
        stopTriggerCnt->setText(QApplication::translate("MainWindow", "Stop Run", 0, QApplication::UnicodeUTF8));
        clearTriggerCnt->setText(QApplication::translate("MainWindow", "Clear Counters", 0, QApplication::UnicodeUTF8));
        checkTriggers->setText(QApplication::translate("MainWindow", "Start Run", 0, QApplication::UnicodeUTF8));
        runStatusField->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">NA</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Triggers", 0, QApplication::UnicodeUTF8));
        triggerCntLabel_fpga->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Hits", 0, QApplication::UnicodeUTF8));
        triggerCntLabel->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        calibration->setText(QApplication::translate("MainWindow", "IntTrig", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        calibration->setToolTip(QApplication::translate("MainWindow", "Enable DAQ mode for internal triggers", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        enableDebugPB->setText(QApplication::translate("MainWindow", "Enable Debug", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        enableDebugPB->setToolTip(QApplication::translate("MainWindow", "Enable Debug panel below", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        hideChannels->setText(QApplication::translate("MainWindow", "Show Channels", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        hideChannels->setToolTip(QApplication::translate("MainWindow", "Show channels in right panel", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        monitoring->setText(QApplication::translate("MainWindow", "Monitoring", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        monitoring->setToolTip(QApplication::translate("MainWindow", "Not functional", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        readTrigger->setText(QApplication::translate("MainWindow", "Trigger Data", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        readTrigger->setToolTip(QApplication::translate("MainWindow", "Trigger Data", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Global Registers", 0, QApplication::UnicodeUTF8));
        sgLabel->setText(QApplication::translate("MainWindow", "Gain (sg)", 0, QApplication::UnicodeUTF8));
        sg->clear();
        sg->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0.5 mV/fC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1.0 mV/fC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3.0 mV/fC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9.0 mV/fC", 0, QApplication::UnicodeUTF8)
        );
        stLabel->setText(QApplication::translate("MainWindow", "Peak time (st)", 0, QApplication::UnicodeUTF8));
        st->clear();
        st->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "200 ns", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "100 ns", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "50 ns", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "25 ns", 0, QApplication::UnicodeUTF8)
        );
        sngLabel->setText(QApplication::translate("MainWindow", "Neighbor Trigger (sng)", 0, QApplication::UnicodeUTF8));
        sng->clear();
        sng->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8)
        );
        stcLabel->setText(QApplication::translate("MainWindow", "TAC Slop Adj (stc)", 0, QApplication::UnicodeUTF8));
        stc->clear();
        stc->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "125 ns", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "250 ns", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "500 ns", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1000 ns", 0, QApplication::UnicodeUTF8)
        );
        sdpLabel->setText(QApplication::translate("MainWindow", "Disable At Peak", 0, QApplication::UnicodeUTF8));
        sdp->clear();
        sdp->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8)
        );
        sfaLabel->setText(QApplication::translate("MainWindow", "ART", 0, QApplication::UnicodeUTF8));
        sfa->clear();
        sfa->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8)
        );
        sfamLabel->setText(QApplication::translate("MainWindow", "Mode", 0, QApplication::UnicodeUTF8));
        sfam->clear();
        sfam->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Timing At Threshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Timing At Peak", 0, QApplication::UnicodeUTF8)
        );
        sstpLabel->setText(QApplication::translate("MainWindow", "TAC Stop Setting (sstp)", 0, QApplication::UnicodeUTF8));
        sstp->clear();
        sstp->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ena-low", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "stp-low", 0, QApplication::UnicodeUTF8)
        );
        sshLabel->setText(QApplication::translate("MainWindow", "Sub Hysterisis Discrimination", 0, QApplication::UnicodeUTF8));
        ssh->clear();
        ssh->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8)
        );
        stttLabel->setText(QApplication::translate("MainWindow", "Time Output", 0, QApplication::UnicodeUTF8));
        sttt->clear();
        sttt->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8)
        );
        stotLabel->setText(QApplication::translate("MainWindow", "Mode", 0, QApplication::UnicodeUTF8));
        stot->clear();
        stot->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Time Over Threshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Threshold To Peak", 0, QApplication::UnicodeUTF8)
        );
        s16Label->setText(QApplication::translate("MainWindow", "Make Channel 7 Neighbor to 56", 0, QApplication::UnicodeUTF8));
        s16->clear();
        s16->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8)
        );
        srstLabel->setText(QApplication::translate("MainWindow", "ACQ self resets 40 ns after", 0, QApplication::UnicodeUTF8));
        srst->clear();
        srst->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8)
        );
        sdtLabel->setText(QApplication::translate("MainWindow", "Threshold DAC", 0, QApplication::UnicodeUTF8));
        sdpLabel_2->setText(QApplication::translate("MainWindow", "Test Pulse DAC", 0, QApplication::UnicodeUTF8));
        dacmvLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        sbfmLabel->setText(QApplication::translate("MainWindow", "sbfm", 0, QApplication::UnicodeUTF8));
        sbfm->clear();
        sbfm->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8)
        );
        sbfpLabel->setText(QApplication::translate("MainWindow", "sbfp", 0, QApplication::UnicodeUTF8));
        sbfp->clear();
        sbfp->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8)
        );
        sbftLabel->setText(QApplication::translate("MainWindow", "sbft", 0, QApplication::UnicodeUTF8));
        sbft->clear();
        sbft->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8)
        );
        sm5_sm0Label->setText(QApplication::translate("MainWindow", "Channel Monitoring (sm)", 0, QApplication::UnicodeUTF8));
        sm5_sm0->clear();
        sm5_sm0->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "27", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "28", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "29", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "31", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "33", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "34", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "35", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "36", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "37", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "38", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "39", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "41", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "42", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "43", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "44", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "45", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "46", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "47", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "48", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "49", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "51", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "52", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "53", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "54", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "55", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "56", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "57", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "58", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "59", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "60", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "61", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "62", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "63", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "64", 0, QApplication::UnicodeUTF8)
        );
        scmxLabel->setText(QApplication::translate("MainWindow", "SCMX", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        scmxLabel->setToolTip(QApplication::translate("MainWindow", "On:MonitorCharge; Off:MonitorPulse(squareWave)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        scmx->clear();
        scmx->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8)
        );
        loadCalibDataCB->setText(QApplication::translate("MainWindow", "Load Calibration Data", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        loadCalibDataCB->setToolTip(QApplication::translate("MainWindow", "Load Calibration Data from file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        loadThrCB->setText(QApplication::translate("MainWindow", "Load Thresholds", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        loadThrCB->setToolTip(QApplication::translate("MainWindow", "Load Thresholds Data from file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        abovePed->setToolTip(QApplication::translate("MainWindow", "abovePed for thresholds (in mV)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        calibRunSettings->setTitle(QApplication::translate("MainWindow", "Settings for taking calibration data", 0, QApplication::UnicodeUTF8));
        calibTime->setText(QApplication::translate("MainWindow", "Time calib", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        calibTime->setToolTip(QApplication::translate("MainWindow", "Do automated loop over timing to record data for calibration", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        calibGain->setText(QApplication::translate("MainWindow", "Gain calib", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        calibGain->setToolTip(QApplication::translate("MainWindow", "Do automated loop over gains to record data for calibration", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Trigger FPGA", 0, QApplication::UnicodeUTF8));
        ip1_tr->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        ip2_tr->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ip3_tr->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ip4_tr->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        connectionLabel_tr->setText(QApplication::translate("MainWindow", "  N/A", 0, QApplication::UnicodeUTF8));
        openConnection_tr->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "DAC", 0, QApplication::UnicodeUTF8));
        offAcq_fpga->setText(QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8));
        onAcq_fpga->setText(QApplication::translate("MainWindow", "On", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Counter", 0, QApplication::UnicodeUTF8));
        triggerCnt_fpga_clear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        triggerCnt_fpga_enable->setText(QApplication::translate("MainWindow", "Enable", 0, QApplication::UnicodeUTF8));
        triggerCnt_fpga_read->setText(QApplication::translate("MainWindow", "Read", 0, QApplication::UnicodeUTF8));
        groupBox_16->setTitle(QApplication::translate("MainWindow", "Trigger", 0, QApplication::UnicodeUTF8));
        triggerDisable_fpga->setText(QApplication::translate("MainWindow", "Disable", 0, QApplication::UnicodeUTF8));
        triggerEnable_fpga->setText(QApplication::translate("MainWindow", "Enable", 0, QApplication::UnicodeUTF8));
        groupBox_17->setTitle(QApplication::translate("MainWindow", "Data", 0, QApplication::UnicodeUTF8));
        realData_fpga->setText(QApplication::translate("MainWindow", "Real", 0, QApplication::UnicodeUTF8));
        testData_fpga->setText(QApplication::translate("MainWindow", "test", 0, QApplication::UnicodeUTF8));
        groupBox_20->setTitle(QApplication::translate("MainWindow", "Time Window", 0, QApplication::UnicodeUTF8));
        timeWindow_fpgaPB->setText(QApplication::translate("MainWindow", "Set", 0, QApplication::UnicodeUTF8));
        trigger_fpga_init->setText(QApplication::translate("MainWindow", "Init", 0, QApplication::UnicodeUTF8));
        closeConnection_tr->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        groupBox_18->setTitle(QApplication::translate("MainWindow", "CDAQ", 0, QApplication::UnicodeUTF8));
        clearDebugScreenPB->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        groupBox_19->setTitle(QApplication::translate("MainWindow", "Trigger", 0, QApplication::UnicodeUTF8));
        clearDebugScreenPB_fpga->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
