#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "sleeper.h"
#include "tcphandler.h"
#include "tcphandlerthread.h"
#include <QDir>

//_________________________________________________________________________________________

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow) {
    idForCustomCommands = 0;
    multicastingFlag = 0;
    FECPort = 6008;
    DAQPort = 6006;
    daqFile_fpga = 0;
    FPGAPort = 65000;
    headerSet = 0;
    pulserDi = 0;
    Font.setFamily("Arial");
    Font.setPixelSize(9);
    ui->setupUi(this);
    SetChambersMapping();
    spiSent = 0;

    for (int i = 0; i <= 19; i++) {
        boardThreshold[i] = 220;
    }
    ui->sdt->setValue(220);
    //********************** Sub Classing TCP for FPGA Trigger Data *******************************
    tcpHandler tcpData;
    tcpHandlerThread tcpThread;
    tcpData.moveToThread(&tcpThread);
    tcpThread.start();

    //*********************************************************************************************
    connect(ui->numbersOfFecs, SIGNAL(valueChanged(int)), this, SLOT(SetNumberOfFecs(int)));
    connect(ui->openConnection, SIGNAL(pressed()), this, SLOT(Connect()));
    connect(ui->openConnection_tr, SIGNAL(pressed()), this, SLOT(ConnectTCP()));
    connect(ui->closeConnection_tr, SIGNAL(pressed()), this, SLOT(ConnectTCP()));

    connect(ui->SendConfiguration, SIGNAL(clicked()), this, SLOT(HandleRecipe()));
    //    connect(ui->SendConfiguration_tr, SIGNAL(clicked()), this , SLOT(MergerFPGA()));
    connect(ui->onAcq_fpga, SIGNAL(clicked()), this, SLOT(MergerFPGA()));
    connect(ui->offAcq_fpga, SIGNAL(clicked()), this, SLOT(MergerFPGA()));
    connect(ui->triggerEnable_fpga, SIGNAL(clicked()), this, SLOT(MergerFPGA()));
    connect(ui->triggerDisable_fpga, SIGNAL(clicked()), this, SLOT(MergerFPGA()));
    connect(ui->triggerCnt_fpga_clear, SIGNAL(clicked()), this, SLOT(MergerFPGA()));
    connect(ui->triggerCnt_fpga_enable, SIGNAL(clicked()), this, SLOT(MergerFPGA()));
    connect(ui->realData_fpga, SIGNAL(clicked()), this, SLOT(MergerFPGA()));
    connect(ui->testData_fpga, SIGNAL(clicked()), this, SLOT(MergerFPGA()));
    connect(ui->triggerCnt_fpga_read, SIGNAL(clicked()), this, SLOT(MergerFPGA()));
    connect(ui->timeWindow_fpgaPB, SIGNAL(clicked()), this, SLOT(MergerFPGA()));
    connect(ui->trigger_fpga_init, SIGNAL(clicked()), this, SLOT(MergerFPGA()));

    connect(ui->hideChannels, SIGNAL(stateChanged(int)), this, SLOT(hideChannels(int)));
    connect(ui->enableDebugPB, SIGNAL(stateChanged(int)), this, SLOT(showDebugScreen(int)));
    connect(ui->clearDebugScreenPB, SIGNAL(clicked()), this, SLOT(clearDebugScreen()));
    connect(ui->clearDebugScreenPB_fpga, SIGNAL(clicked()), this, SLOT(clearDebugScreen()));

    connect(ui->onACQ, SIGNAL(clicked()), this, SLOT(customCommandHandler()));
    connect(ui->offACQ, SIGNAL(clicked()), this, SLOT(customCommandHandler()));
    //    connect(ui->applyDetectionMode, SIGNAL(clicked()), this , SLOT(customCommandHandler()));
    connect(ui->applyDetectionMode, SIGNAL(clicked()), this, SLOT(customCommandWithoutResponse()));
    connect(ui->applyTrigger, SIGNAL(clicked()), this, SLOT(customCommandHandler()));
    connect(ui->asic_reset, SIGNAL(clicked()), this, SLOT(customCommandHandler()));
    connect(ui->triggerCounter_reset, SIGNAL(clicked()), this, SLOT(customCommandHandler()));
    connect(ui->cdaq_reset, SIGNAL(clicked()), this, SLOT(customCommandHandler()));
    connect(ui->lx9Reset, SIGNAL(clicked()), this, SLOT(customCommandWithoutResponse()));
    connect(ui->setDaqMode, SIGNAL(clicked()), this, SLOT(customCommandWithoutResponse()));
    connect(ui->setHeaderPB, SIGNAL(clicked()), this, SLOT(customCommandWithoutResponse()));
    connect(ui->sampleSetPB, SIGNAL(clicked()), this, SLOT(customCommandWithoutResponse()));

    connect(ui->setVMMs, SIGNAL(currentIndexChanged(int)), this, SLOT(constructHeader(int)));
    connect(ui->sdt, SIGNAL(valueChanged(int)), this, SLOT(changeDACtoMVs(int)));
    QString tempstring;
    ui->dacmvLabel->setText(tempstring.number((0.6862 * ui->sdt->value() + 63.478), 'f', 2) + " mV");

    int intervalDi = 110; //msec
    threadDi = new MyThread(intervalDi, this);
    connect(threadDi, SIGNAL(valueChanged(int)), this, SLOT(sendDis(int)));
    connect(ui->startDi, SIGNAL(clicked()), this, SLOT(threadHandler()));
    connect(ui->stopDi, SIGNAL(clicked()), this, SLOT(threadHandler()));

    int intervalRefreshHistos = 5000; //5 sec
    threadFill = new MyThread(intervalRefreshHistos, this);
    connect(threadFill, SIGNAL(valueChanged(int)), this, SLOT(updateCanvas(int)));

    connect(ui->checkTriggers, SIGNAL(clicked()), this, SLOT(triggerHandler()));
    connect(ui->checkTriggers, SIGNAL(clicked()), this, SLOT(customCommandHandler()));
    connect(ui->clearTriggerCnt, SIGNAL(clicked()), this, SLOT(triggerHandler()));
    connect(ui->stopTriggerCnt, SIGNAL(clicked()), this, SLOT(triggerHandler()));

    connect(ui->checkTriggers, SIGNAL(clicked()), this, SLOT(triggerHandler_fpga()));
    connect(ui->clearTriggerCnt, SIGNAL(clicked()), this, SLOT(triggerHandler_fpga()));
    connect(ui->stopTriggerCnt, SIGNAL(clicked()), this, SLOT(triggerHandler_fpga()));

    connect(ui->monitoring, SIGNAL(stateChanged(int)), this, SLOT(openMonitoring(int)));

    connect(ui->loadCalibDataCB, SIGNAL(stateChanged(int)), this, SLOT(loadCalibrationConstants(int)));
    connect(ui->loadThrCB, SIGNAL(stateChanged(int)), this, SLOT(LoadThresholds(int)));

    CreateChannelsField();
    initializePlots();

    ui->runDirectoryField->setText("/Users/gio/Desktop");
    runDirectory.setPath(ui->runDirectoryField->text());
    connect(ui->selectDir, SIGNAL(clicked()), this, SLOT(selectWorkingDirectory()));
    //    ui->runGroupbox->setStyleSheet("background-: white; padding: 1px; border-style: outset");

    ui->spiRB->setChecked(true);
    ui->writeRB->setChecked(true);
    this->setFixedSize(1204, 725);
    ui->hideChannels->setChecked(1);
    commandCounter = 0;
    QString temp;
    ui->cmdlabel->setText(temp.number(commandCounter));
    ui->stopTriggerCnt->setEnabled(0);
    //    ui->startDi->setText("Start\nPulser");
    //    ui->stopDi->setText("Stop\nPulser");

}
//_________________________________________________________________________________________

void MainWindow::SetChambersMapping() {
    T1Chips[1] = 16;
    T1Chips[2] = 17;
    T2Chips[1] = 18;
    T2Chips[2] = 19;
    T3Chips[1] = 20;
    T3Chips[2] = 21;
    T4Chips[1] = 22;
    T4Chips[2] = 23;
    T5Chips[1] = 24;
    T5Chips[2] = 25;
    T6Chips[1] = 26;
    T6Chips[2] = 27;
    T7Chips[1] = 28;
    T7Chips[2] = 29;
    T8Chips[1] = 30;
    T8Chips[2] = 31;
}

//_________________________________________________________________________________________

MainWindow::~MainWindow() {
    delete ui;
}
//_________________________________________________________________________________________________

void MainWindow::PingFec() {
    for (int i = 0; i < ui->numbersOfFecs->value(); i++) {
        int exitCode = QProcess::execute("ping", QStringList() << "-c2" << ips[i]);
        //int exitCode =0;
        if (0 == exitCode) {
            communicationAlive[i] = true;
        } else {
            communicationAlive[i] = false;
        }
        Sleeper::msleep(100);
    }
}
//_________________________________________________________________________________________________

void MainWindow::PingFPGA() {
    int exitCode = QProcess::execute("ping", QStringList() << "-c1" << ips_tr);
    if (0 == exitCode) {
        communicationAliveFPGA = true;
    } else {
        communicationAliveFPGA = false;
    }
    Sleeper::msleep(1000);
}
//_________________________________________________________________________________________________

void MainWindow::SetNumberOfFecs(int) {
    ui->setVMMs->clear();
    QString counter;
    for (int i = 0; i < ui->numbersOfFecs->value(); i++) {
        ips[i] = ui->ip1->text() + "." + ui->ip2->text() + "." + ui->ip3->text() + "." + counter.setNum(ui->ip4->text().toInt() + i);
        ui->setVMMs->addItem(counter.setNum(i + 1));
        ui->setVMMs->setCurrentIndex(i);
    }
    ui->setVMMs->addItem("All");
    ui->setVMMs->setCurrentIndex(ui->setVMMs->currentIndex() + 1);
    if (ui->setVMMs->currentText() == "All") ui->header4LE->setText(ui->ip4->text());
    if (ui->connectionLabel->text() == " All Alive") {
        bnd = false;
        ui->connectionLabel->setText("Re-Establish Connection");
        socket->close();
        socket->disconnectFromHost();
        ui->connectionLabel->setStyleSheet("background-color: light");
    }
}
//_________________________________________________________________________________________________

void MainWindow::SetFPGAIP() {
    ips_tr = ui->ip1_tr->text() + "." + ui->ip2_tr->text() + "." + ui->ip3_tr->text() + "." + ui->ip4_tr->text();
}
//_________________________________________________________________________________________________

void MainWindow::Connect() {
    PingFec();
    QString deads = "";
    int numFECS = 0;
    socket = new QUdpSocket(this);
    bnd = socket->bind(FECPort); //, QUdpSocket::ShareAddress);
    if (bnd) {
        connect(socket, SIGNAL(readyRead()), this, SLOT(dataPending()));
        if (ui->numbersOfFecs->value() == 0) {
            ui->connectionLabel->setText("Select number of FECs");
            ui->connectionLabel->setStyleSheet("background-color: light");
        }

        for (int i = 0; i < ui->numbersOfFecs->value(); i++) {
            //connect( socket, SIGNAL(readyRead()), this, SLOT(dataPending()) );
            if (communicationAlive[i] == 1) {
                QString temp;
                ui->connectionLabel->setText("  " + temp.number(i + 1) + "  is :Alive");
                ui->connectionLabel->setStyleSheet("background-color: green");
                numFECS++;
            } else {
                QString temp;
                deads = deads + temp.number(i + 1) + ",";
                ui->connectionLabel->setText("  " + deads + "  is/are :Dead");
                ui->connectionLabel->setStyleSheet("background-color: red");
            }
            if (numFECS == ui->numbersOfFecs->value()) {
                ui->connectionLabel->setText(" All Alive");
                ui->connectionLabel->setStyleSheet("background-color: green");
            }
        }
    } else {
        ui->connectionLabel->setText(" error on Socket");
        ui->connectionLabel->setStyleSheet("background-color: gray");
        std::cout << "Error on socket: " << socket->error() << std::endl;
        socket->close();
        socket->disconnectFromHost();
    }
}
//_________________________________________________________________________________________________

void MainWindow::dataPending() {
    while (socket->hasPendingDatagrams()) {
        buffer.resize(socket->pendingDatagramSize());
        socket->readDatagram(buffer.data(), buffer.size());
        packageHandler(buffer);
    }
}
//_________________________________________________________________________________________

int MainWindow::packageHandler(QByteArray package) {
    if (ui->enableDebugPB->isChecked()) {
        bool ok;
        QString sizeOfPackageReceived;
        ui->debugScreen->append("************************ NEW PACKET RECEIVED **************************");
        ui->debugScreen->append("Data Received Size: " + sizeOfPackageReceived.number(package.size(), 10) + " bytes");
        QString datagramBin, datagramHex;
        for (int i = 0; i < package.size() / 4; i++) {
            datagramHex = package.mid(i * 4, 4).toHex();
            quint32 temp32 = datagramHex.toUInt(&ok, 16);
            if (i == 0) ui->debugScreen->append("Req ID :" + datagramBin.number(temp32, 10));
            else ui->debugScreen->append("Data    :" + datagramBin.number(temp32, 2));
        }
        ui->debugScreen->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
    }
    customCommandHandler();

    return 0; //Added by hugh skottowe 20140212 to fix compile warning
}
//_________________________________________________________________________________________________

void MainWindow::ConnectTCP() {
    if (ui->openConnection_tr == QObject::sender()) {
        SetFPGAIP();
        PingFPGA();
        socketTCP = new QTcpSocket();
        socketTCP->connectToHost(ips_tr, FPGAPort, QTcpSocket::ReadWrite);
        connect(socketTCP, SIGNAL(error(QAbstractSocket::SocketError)),
                this, SLOT(displayError(QAbstractSocket::SocketError)));
        connect(socketTCP, SIGNAL(readyRead()), this, SLOT(readTCP()));
        if (socketTCP->waitForConnected(2000)) {
            //connect( socket, SIGNAL(readyRead()), this, SLOT(dataPending()) );
            ui->connectionLabel_tr->setText("      Alive");
            ui->connectionLabel_tr->setStyleSheet("background-color: green");
        } else {
            ui->connectionLabel_tr->setText("   Problem");
            ui->connectionLabel_tr->setStyleSheet("background-color: gray");
        }
    } else if (ui->closeConnection_tr == QObject::sender()) {
        socketTCP->close();
        socketTCP->disconnect();
        ui->connectionLabel_tr->setText("      Disconnected");
        ui->connectionLabel_tr->setStyleSheet("background-color: red");
    }
}
//_________________________________________________________________________________________________

void MainWindow::readTCP() {
    if (ui->readTrigger->isChecked()) {
        bool ok;
        QString tempString;
        while (socketTCP->bytesAvailable() > 0) {
            //        ui->debugScreen_fpga->append("************************ NEW DCS PACKET RECEIVED **************************");
            daqCnt_fpga++;
            ui->triggerCntLabel_fpga->setText(tempString.number(daqCnt_fpga, 10));
            //        QString inputPacket =  socketTCP->readAll().toHex();
            QByteArray trInfo = socketTCP->readAll();
            //        qDebug()<<"Everything:"<<trInfo.toHex();
            //ui->debugScreen_fpga->append(inputPacket);
            //new thread to write the file
            //writeFPGAFile(inputPacket);
            QString eventString = trInfo.toHex().left(8);
            qint32 eventTrigger = eventString.toInt(&ok, 16);
            //        qDebug()<<eventTrigger<<"   "<<eventString;
            triggerEventVariable = eventTrigger;
            triggerTimeVariable.clear();
            triggerChannelVariable.clear();
            triggerBoardVariable.clear();
            for (int i = 0; i < 8; i++) {
                vector<double> chTrinfo = bytesTobitsTrigger(trInfo.mid(12 + i * 4, 4));
                triggerChannelVariable.push_back(chTrinfo.at(0));
                triggerChannelVariable.push_back(chTrinfo.at(2));
                triggerTimeVariable.push_back(chTrinfo.at(1));
                triggerTimeVariable.push_back(chTrinfo.at(3));
                triggerBoardVariable.push_back((i * 2) + 1);
                triggerBoardVariable.push_back((i * 2) + 2);
            }
            if (fileDaqRoot->IsOpen())
                vmm1Trigger->Fill();
            if (fileDaqText.is_open()) {
                //fileDaqText << ;
            }
            if (ui->monitoring->isChecked())
                EventNumberTrigger->Fill(eventTrigger);
        }
        ui->debugScreen_fpga->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
    }
}
//_________________________________________________________________________________________________

void MainWindow::ConnectFPGA() {
    SetFPGAIP();
    PingFPGA();
    socketFPGA = new QUdpSocket(this);
    bndFPGA = socketFPGA->bind(FPGAPort, QUdpSocket::ShareAddress);
    if (bndFPGA && communicationAliveFPGA) {
        connect(socketFPGA, SIGNAL(readyRead()), this, SLOT(dataPending()));
        ui->connectionLabel_tr->setText("      Alive");
        ui->connectionLabel_tr->setStyleSheet("background-color: green");
    } else {
        ui->connectionLabel_tr->setText("   Problem");
        ui->connectionLabel_tr->setStyleSheet("background-color: gray");
    }
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError) {
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, tr("Fortune Client"),
                    tr("The host was not found. Please check the "
                    "host name and port settings."));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, tr("Fortune Client"),
                    tr("The connection was refused by the peer. "
                    "Make sure the fortune server is running, "
                    "and check that the host name and port "
                    "settings are correct."));
            break;
        default:
            QMessageBox::information(this, tr("Fortune Client"),
                    tr("The following error occurred: %1.")
                    .arg(socketTCP->errorString()));
    }

}
//_________________________________________________________________________________________________

void MainWindow::Disconnect() {
    ui->connectionLabel->setText("Disconnected");
    ui->connectionLabel->setStyleSheet("background-color: red");
    socket->disconnectFromHost();
    bnd = false;
}
//_________________________________________________________________________________________________

void MainWindow::CreateChannelsField() {

    QGroupBox *groupModify = new QGroupBox(tr("VMM1 Channels"), this);
    QGridLayout *grid = new QGridLayout(this);
    grid->setHorizontalSpacing(2);
    grid->setVerticalSpacing(2);
    QString initialValueRadio = "";
    QString counter;


    SPLabel = new QPushButton("SP");
    SCLabel = new QPushButton("SC");
    SLLabel = new QPushButton("SL");
    STLabel = new QPushButton("ST");
    SMLabel = new QPushButton("SM");
    SDLabel = new QComboBox();
    SMXLabel = new QPushButton("SMX");
    SPLabel2 = new QPushButton("SP");
    SCLabel2 = new QPushButton("SC");
    SLLabel2 = new QPushButton("SL");
    STLabel2 = new QPushButton("ST");
    SMLabel2 = new QPushButton("SM");
    SDLabel2 = new QComboBox();
    SMXLabel2 = new QPushButton("SMX");

    for (int j = 0; j < 16; j++) {
        SDLabel->addItem(counter.setNum(j) + " mV");
        SDLabel2->addItem(counter.setNum(j) + " mV");
    }
    VMM1SPBoolAll = 0;
    VMM1SCBoolAll = 0;
    VMM1SLBoolAll = 0;
    VMM1STBoolAll = 0;
    VMM1SMBoolAll = 0;
    VMM1SMXBoolAll = 0;
    VMM1SPBoolAll2 = 0;
    VMM1SCBoolAll2 = 0;
    VMM1SLBoolAll2 = 0;
    VMM1STBoolAll2 = 0;
    VMM1SMBoolAll2 = 0;
    VMM1SMXBoolAll2 = 0;

    SPLabel->setFixedSize(20, 15);
    SCLabel->setFixedSize(20, 15);
    SLLabel->setFixedSize(20, 15);
    STLabel->setFixedSize(20, 15);
    SMLabel->setFixedSize(20, 15);
    SDLabel->setFixedSize(40, 20);
    SMXLabel->setFixedSize(30, 15);
    SPLabel2->setFixedSize(20, 15);
    SCLabel2->setFixedSize(20, 15);
    SLLabel2->setFixedSize(20, 15);
    STLabel2->setFixedSize(20, 15);
    SMLabel2->setFixedSize(20, 15);
    SDLabel2->setFixedSize(40, 20);
    SMXLabel2->setFixedSize(30, 15);

    SPLabel->setFont(Font);
    SCLabel->setFont(Font);
    SLLabel->setFont(Font);
    STLabel->setFont(Font);
    SMLabel->setFont(Font);
    SDLabel->setFont(Font);
    SMXLabel->setFont(Font);
    SPLabel2->setFont(Font);
    SCLabel2->setFont(Font);
    SLLabel2->setFont(Font);
    STLabel2->setFont(Font);
    SMLabel2->setFont(Font);
    SDLabel2->setFont(Font);
    SMXLabel2->setFont(Font);

    connect(SPLabel, SIGNAL(pressed()), this, SLOT(updateChannelState()));
    connect(SDLabel, SIGNAL(currentIndexChanged(int)), this, SLOT(updateChannelVoltages(int)));
    connect(SCLabel, SIGNAL(pressed()), this, SLOT(updateChannelState()));
    connect(SLLabel, SIGNAL(pressed()), this, SLOT(updateChannelState()));
    connect(STLabel, SIGNAL(pressed()), this, SLOT(updateChannelState()));
    connect(SMLabel, SIGNAL(pressed()), this, SLOT(updateChannelState()));
    connect(SMXLabel, SIGNAL(pressed()), this, SLOT(updateChannelState()));
    connect(SPLabel2, SIGNAL(pressed()), this, SLOT(updateChannelState()));
    connect(SCLabel2, SIGNAL(pressed()), this, SLOT(updateChannelState()));
    connect(SDLabel2, SIGNAL(currentIndexChanged(int)), this, SLOT(updateChannelVoltages(int)));
    connect(SLLabel2, SIGNAL(pressed()), this, SLOT(updateChannelState()));
    connect(STLabel2, SIGNAL(pressed()), this, SLOT(updateChannelState()));
    connect(SMLabel2, SIGNAL(pressed()), this, SLOT(updateChannelState()));
    connect(SMXLabel2, SIGNAL(pressed()), this, SLOT(updateChannelState()));

    for (int i = 0; i < 64; i++) {
        VMM1Channel[i] = new QLineEdit(counter.setNum(i + 1), groupModify);

        VMM1SC[i] = new QPushButton(initialValueRadio, groupModify);
        VMM1SL[i] = new QPushButton(initialValueRadio, groupModify);
        VMM1ST[i] = new QPushButton(initialValueRadio, groupModify);
        VMM1SM[i] = new QPushButton(initialValueRadio, groupModify);
        VMM1SMX[i] = new QPushButton(initialValueRadio, groupModify);


        VMM1SC[i]->setFixedSize(15, 15);
        VMM1ST[i]->setFixedSize(15, 15);
        VMM1SL[i]->setFixedSize(15, 15);
        VMM1SM[i]->setFixedSize(15, 15);
        VMM1SMX[i]->setFixedSize(15, 15);

        VMM1SC[i]->setStyleSheet("background-color: gray");
        VMM1SM[i]->setStyleSheet("background-color: gray");
        VMM1ST[i]->setStyleSheet("background-color: gray");
        VMM1SL[i]->setStyleSheet("background-color: gray");
        VMM1SMX[i]->setStyleSheet("background-color: gray");

        connect(VMM1SC[i], SIGNAL(pressed()), this, SLOT(updateChannelState()));
        connect(VMM1SM[i], SIGNAL(pressed()), this, SLOT(updateChannelState()));
        connect(VMM1ST[i], SIGNAL(pressed()), this, SLOT(updateChannelState()));
        connect(VMM1SL[i], SIGNAL(pressed()), this, SLOT(updateChannelState()));
        connect(VMM1SMX[i], SIGNAL(pressed()), this, SLOT(updateChannelState()));

        VMM1SPBool[i] = 0;
        VMM1SCBool[i] = 0;
        VMM1SMBool[i] = 0;
        VMM1STBool[i] = 0;
        VMM1SLBool[i] = 0;
        VMM1SMXBool[i] = 0;


        VMM1Channel[i]->setEnabled(0);
        VMM1SDVoltage[i] = new QComboBox(groupModify);
        VMM1SDVoltage[i]->setFixedSize(40, 20);
        connect(VMM1SDVoltage[i], SIGNAL(currentIndexChanged(int)), this, SLOT(updateChannelVoltages(int)));
        VMM1SDVoltage[i]->setFont(Font);

        for (int j = 0; j < 16; j++) {
            VMM1SDVoltage[i]->addItem(counter.setNum(j) + " mV");
        }

        VMM1NegativeButton[i] = new QPushButton(groupModify);
        VMM1NegativeButton[i]->setText("negative");
        connect(VMM1NegativeButton[i], SIGNAL(pressed()), this, SLOT(updateChannelState()));

        VMM1Channel[i]->setFixedSize(20, 18);
        VMM1NegativeButton[i]->setFixedSize(40, 18);
        VMM1NegativeButton[i]->setFont(Font);
        QLabel *spacer = new QLabel("   ");

        if (i < 32) {
            if (i == 0) {
                grid->addWidget(SPLabel, i, 2, Qt::AlignCenter);
                grid->addWidget(SCLabel, i, 3, Qt::AlignCenter);
                grid->addWidget(SLLabel, i, 4, Qt::AlignCenter);
                grid->addWidget(STLabel, i, 5, Qt::AlignCenter);
                grid->addWidget(SMLabel, i, 6, Qt::AlignCenter);
                grid->addWidget(SDLabel, i, 7, Qt::AlignCenter);
                grid->addWidget(SMXLabel, i, 8, Qt::AlignCenter);
                grid->addWidget(SPLabel2, i, 11, Qt::AlignCenter);
                grid->addWidget(SCLabel2, i, 12, Qt::AlignCenter);
                grid->addWidget(SLLabel2, i, 13, Qt::AlignCenter);
                grid->addWidget(STLabel2, i, 14, Qt::AlignCenter);
                grid->addWidget(SMLabel2, i, 15, Qt::AlignCenter);
                grid->addWidget(SDLabel2, i, 16, Qt::AlignCenter);
                grid->addWidget(SMXLabel2, i, 17, Qt::AlignCenter);
            }
            grid->addWidget(VMM1Channel[i], i + 1, 1, Qt::AlignCenter);
            grid->addWidget(VMM1NegativeButton[i], i + 1, 2, Qt::AlignCenter);
            grid->addWidget(VMM1SC[i], i + 1, 3, Qt::AlignCenter);
            grid->addWidget(VMM1SL[i], i + 1, 4, Qt::AlignCenter);
            grid->addWidget(VMM1ST[i], i + 1, 5, Qt::AlignCenter);
            grid->addWidget(VMM1SM[i], i + 1, 6, Qt::AlignCenter);
            grid->addWidget(VMM1SDVoltage[i], i + 1, 7, Qt::AlignCenter);
            grid->addWidget(VMM1SMX[i], i + 1, 8, Qt::AlignCenter);
            grid->addWidget(spacer, i + 1, 9, Qt::AlignCenter);
        } else {
            grid->addWidget(VMM1Channel[i], i - 32 + 1, 10, Qt::AlignCenter);
            grid->addWidget(VMM1NegativeButton[i], i - 32 + 1, 11, Qt::AlignCenter);
            grid->addWidget(VMM1SC[i], i - 32 + 1, 12, Qt::AlignCenter);
            grid->addWidget(VMM1SL[i], i - 32 + 1, 13, Qt::AlignCenter);
            grid->addWidget(VMM1ST[i], i - 32 + 1, 14, Qt::AlignCenter);
            grid->addWidget(VMM1SM[i], i - 32 + 1, 15, Qt::AlignCenter);
            grid->addWidget(VMM1SDVoltage[i], i - 32 + 1, 16, Qt::AlignCenter);
            grid->addWidget(VMM1SMX[i], i - 32 + 1, 17, Qt::AlignCenter);
        }
    }
    groupModify->setGeometry(QRect(620, 12, 530, 700));
    groupModify->setLayout(grid);
}
//_________________________________________________________________________________________

void MainWindow::updateChannelVoltages(int index) {
    // ***********************  SD  *********************************************
    if (SDLabel == QObject::sender()) {
        for (int j = 0; j < 32; j++) {
            VMM1SDVoltage[j]->setCurrentIndex(index);
            VMM1SDValue[j] = index;
        }
    }
    if (SDLabel2 == QObject::sender()) {
        for (int j = 32; j < 64; j++) {
            VMM1SDVoltage[j]->setCurrentIndex(index);
            VMM1SDValue[j] = index;
        }
    }
    for (int i = 0; i < 64; i++) {
        if (VMM1SDVoltage[i] == QObject::sender()) {
            VMM1SDValue[i] = index;
        }
    }
}
//_________________________________________________________________________________________

void MainWindow::updateChannelState() {
    // ***********************  SC  *********************************************
    if (SCLabel == QObject::sender()) {
        if (VMM1SCBoolAll == 0) {
            for (int j = 0; j < 32; j++) {
                VMM1SC[j]->setStyleSheet("background-color: green");
                VMM1SCBool[j] = true;
            }
            VMM1SCBoolAll = 1;
        } else {
            for (int j = 0; j < 32; j++) {
                VMM1SC[j]->setStyleSheet("background-color: gray");
                VMM1SCBool[j] = 0;
            }
            VMM1SCBoolAll = 0;
        }
    } else if (SCLabel2 == QObject::sender()) {
        if (VMM1SCBoolAll2 == 0) {
            for (int j = 32; j < 64; j++) {
                VMM1SC[j]->setStyleSheet("background-color: green");
                VMM1SCBool[j] = true;
            }
            VMM1SCBoolAll2 = 1;
        } else {
            for (int j = 32; j < 64; j++) {
                VMM1SC[j]->setStyleSheet("background-color: gray");
                VMM1SCBool[j] = 0;
            }
            VMM1SCBoolAll2 = 0;
        }
    }

    // ***********************  SL  *********************************************
    if (SLLabel == QObject::sender()) {
        if (VMM1SLBoolAll == 0) {
            for (int j = 0; j < 32; j++) {
                VMM1SL[j]->setStyleSheet("background-color: green");
                VMM1SLBool[j] = true;
            }
            VMM1SLBoolAll = 1;
        } else {
            for (int j = 0; j < 32; j++) {
                VMM1SL[j]->setStyleSheet("background-color: gray");
                VMM1SLBool[j] = 0;
            }
            VMM1SLBoolAll = 0;
        }
    } else if (SLLabel2 == QObject::sender()) {
        if (VMM1SLBoolAll2 == 0) {
            for (int j = 32; j < 64; j++) {
                VMM1SL[j]->setStyleSheet("background-color: green");
                VMM1SLBool[j] = true;
            }
            VMM1SLBoolAll2 = 1;
        } else {
            for (int j = 32; j < 64; j++) {
                VMM1SL[j]->setStyleSheet("background-color: gray");
                VMM1SLBool[j] = 0;
            }
            VMM1SLBoolAll2 = 0;
        }
    }
    // ***********************  ST  *********************************************
    if (STLabel == QObject::sender()) {
        if (VMM1STBoolAll == 0) {
            for (int j = 0; j < 32; j++) {
                VMM1ST[j]->setStyleSheet("background-color: green");
                VMM1STBool[j] = true;
            }
            VMM1STBoolAll = 1;
        } else {
            for (int j = 0; j < 32; j++) {
                VMM1ST[j]->setStyleSheet("background-color: gray");
                VMM1STBool[j] = 0;
            }
            VMM1STBoolAll = 0;
        }
    } else if (STLabel2 == QObject::sender()) {
        if (VMM1STBoolAll2 == 0) {
            for (int j = 32; j < 64; j++) {
                VMM1ST[j]->setStyleSheet("background-color: green");
                VMM1STBool[j] = true;
            }
            VMM1STBoolAll2 = 1;
        } else {
            for (int j = 32; j < 64; j++) {
                VMM1ST[j]->setStyleSheet("background-color: gray");
                VMM1STBool[j] = 0;
            }
            VMM1STBoolAll2 = 0;
        }
    }
    // ***********************  SM  *********************************************
    if (SMLabel == QObject::sender()) {
        if (VMM1SMBoolAll == 0) {
            for (int j = 0; j < 32; j++) {
                VMM1SM[j]->setStyleSheet("background-color: green");
                VMM1SMBool[j] = true;
            }
            VMM1SMBoolAll = 1;
        } else {
            for (int j = 0; j < 32; j++) {
                VMM1SM[j]->setStyleSheet("background-color: gray");
                VMM1SMBool[j] = 0;
            }
            VMM1SMBoolAll = 0;
        }
    } else if (SMLabel2 == QObject::sender()) {
        if (VMM1SMBoolAll2 == 0) {
            for (int j = 32; j < 64; j++) {
                VMM1SM[j]->setStyleSheet("background-color: green");
                VMM1SMBool[j] = true;
            }
            VMM1SMBoolAll2 = 1;
        } else {
            for (int j = 32; j < 64; j++) {
                VMM1SM[j]->setStyleSheet("background-color: gray");
                VMM1SMBool[j] = 0;
            }
            VMM1SMBoolAll2 = 0;
        }
    }
    // ***********************  SMX  *********************************************
    if (SMXLabel == QObject::sender()) {
        if (VMM1SMXBoolAll == 0) {
            for (int j = 0; j < 32; j++) {
                VMM1SMX[j]->setStyleSheet("background-color: green");
                VMM1SMXBool[j] = true;
            }
            VMM1SMXBoolAll = 1;
        } else {
            for (int j = 0; j < 32; j++) {
                VMM1SMX[j]->setStyleSheet("background-color: gray");
                VMM1SMXBool[j] = 0;
            }
            VMM1SMXBoolAll = 0;
        }
    } else if (SMXLabel2 == QObject::sender()) {
        if (VMM1SMXBoolAll2 == 0) {
            for (int j = 32; j < 64; j++) {
                VMM1SMX[j]->setStyleSheet("background-color: green");
                VMM1SMXBool[j] = true;
            }
            VMM1SMXBoolAll2 = 1;
        } else {
            for (int j = 32; j < 64; j++) {
                VMM1SMX[j]->setStyleSheet("background-color: gray");
                VMM1SMXBool[j] = 0;
            }
            VMM1SMXBoolAll2 = 0;
        }
    }

    // ***********************  SP (negative buttons)  *********************************************
    if (SPLabel == QObject::sender()) {
        if (VMM1SPBoolAll == 0) {
            for (int j = 0; j < 32; j++) {
                VMM1NegativeButton[j]->setStyleSheet("background-color: green");
                VMM1SPBool[j] = true;
            }
            VMM1SPBoolAll = 1;
        } else {
            for (int j = 0; j < 32; j++) {
                VMM1NegativeButton[j]->setStyleSheet("background-color: light");
                VMM1SPBool[j] = 0;
            }
            VMM1SPBoolAll = 0;
        }
    } else if (SPLabel2 == QObject::sender()) {
        if (VMM1SPBoolAll2 == 0) {
            for (int j = 32; j < 64; j++) {
                VMM1NegativeButton[j]->setStyleSheet("background-color: green");
                VMM1SPBool[j] = true;
            }
            VMM1SPBoolAll2 = 1;
        } else {
            for (int j = 32; j < 64; j++) {
                VMM1NegativeButton[j]->setStyleSheet("background-color: light");
                VMM1SPBool[j] = 0;
            }
            VMM1SPBoolAll2 = 0;
        }
    }
    // ***********************  Loop Individually  *********************************************
    for (int i = 0; i < 64; i++) {
        if (VMM1SC[i] == QObject::sender()) {
            if (VMM1SCBool[i] == 0) {
                VMM1SC[i]->setStyleSheet("background-color: green");
                VMM1SCBool[i] = true;
            } else if (VMM1SCBool[i] == 1) {
                VMM1SC[i]->setStyleSheet("background-color: gray");
                VMM1SCBool[i] = false;
            }
        } else if (VMM1ST[i] == QObject::sender()) {
            if (VMM1STBool[i] == 0) {
                VMM1ST[i]->setStyleSheet("background-color: green");
                VMM1STBool[i] = true;
            } else if (VMM1STBool[i] == 1) {
                VMM1ST[i]->setStyleSheet("background-color: gray");
                VMM1STBool[i] = false;
            }
        } else if (VMM1SL[i] == QObject::sender()) {
            if (VMM1SLBool[i] == 0) {
                VMM1SL[i]->setStyleSheet("background-color: green");
                VMM1SLBool[i] = true;
            } else if (VMM1SLBool[i] == 1) {
                VMM1SL[i]->setStyleSheet("background-color: gray");
                VMM1SLBool[i] = false;
            }
        } else if (VMM1SM[i] == QObject::sender()) {
            if (VMM1SMBool[i] == 0) {
                VMM1SM[i]->setStyleSheet("background-color: green");
                VMM1SMBool[i] = true;
            } else if (VMM1SMBool[i] == 1) {
                VMM1SM[i]->setStyleSheet("background-color: gray");
                VMM1SMBool[i] = false;
            }
        } else if (VMM1SMX[i] == QObject::sender()) {
            if (VMM1SMXBool[i] == 0) {
                VMM1SMX[i]->setStyleSheet("background-color: green");
                VMM1SMXBool[i] = true;
            } else if (VMM1SMXBool[i] == 1) {
                VMM1SMX[i]->setStyleSheet("background-color: gray");
                VMM1SMXBool[i] = false;
            }
        } else if (VMM1NegativeButton[i] == QObject::sender()) {
            if (VMM1SPBool[i] == 0) {
                VMM1NegativeButton[i]->setStyleSheet("background-color: green");
                VMM1SPBool[i] = true;
            } else if (VMM1SPBool[i] == 1) {
                VMM1NegativeButton[i]->setStyleSheet("background-color: light");
                VMM1SPBool[i] = false;
            }
        }
    }
}
//_________________________________________________________________________________________

void MainWindow::HandleRecipe() {
    bool ok;

    if (ui->loadCalibDataCB->isChecked() && ui->setVMMs->currentText() == "All") {
        for (int i = 0; i < ui->numbersOfFecs->value(); i++) {
            spiSent = 1;
            currentAddressForRecipe = ips[i];
            QStringList list = currentAddressForRecipe.split(".");
            int boardToSendData = list.at(3).toInt(&ok, 10);
            for (int l = 0; l < calibConstants[boardToSendData - 16].size(); l++) {
                VMM1SDVoltage[l]->setCurrentIndex(calibConstants[boardToSendData - 16][l]);
                emit VMM1SDVoltage[l]->setCurrentIndex(calibConstants[boardToSendData - 16][l]);
                VMM1SDValue[l] = calibConstants[boardToSendData - 16][l];
            }
            ui->sdt->setValue(boardThreshold[boardToSendData - 15]);
            Merger();
            Sleeper::msleep(5);
        }
    } else if (ui->loadCalibDataCB->isChecked()) {
        spiSent = 1;
        QString address = ips[ui->setVMMs->currentIndex()];
        currentAddressForRecipe = address;
        QStringList list = currentAddressForRecipe.split(".");
        int boardToSendData = list.at(3).toInt(&ok, 10);
        for (int l = 0; l < calibConstants[boardToSendData - 16].size(); l++) {
            VMM1SDVoltage[l]->setCurrentIndex(calibConstants[boardToSendData - 16][l]);
            emit VMM1SDVoltage[l]->setCurrentIndex(calibConstants[boardToSendData - 16][l]);
            VMM1SDValue[l] = calibConstants[boardToSendData - 16][l];
        }
        ui->sdt->setValue(boardThreshold[boardToSendData - 15]);
        Merger();
    } else {
        Merger();
    }
}

//_________________________________________________________________________________________

void MainWindow::Merger() {
    bool ok;

    //QDataStream::BigEndian	QSysInfo::BigEndian
    //out.device()->seek(4);
    int headerLenght = 0; //2*32;
    QBitArray channelRegisters(1088 + headerLenght, false);

    QString sdp0_9 = "0000000000";
    sdp0_9 = sdp0_9.number(ui->sdp_2->value(), 2);
    for (int j = 0; j < sdp0_9.size(); j++) {
        QString bitTmp = sdp0_9.at(sdp0_9.size() - 1 - j);
        channelRegisters.setBit(j + 1024 + headerLenght, bitTmp.toUInt(&ok, 10));
    }

    QString sdt0_9 = "0000000000";
    sdt0_9 = sdt0_9.number(ui->sdt->value(), 2);
    for (int j = 0; j < sdt0_9.size(); j++) {
        QString bitTmp2 = sdt0_9.at(sdt0_9.size() - 1 - j);
        channelRegisters.setBit(j + 1034 + headerLenght, bitTmp2.toUInt(&ok, 10));
    }

    QString stc0_2 = "00";
    stc0_2 = stc0_2.number(ui->stc->currentIndex(), 2);
    for (int j = 0; j < stc0_2.size(); j++) {
        QString bitTmp3 = stc0_2.at(stc0_2.size() - 1 - j);
        channelRegisters.setBit(j + 1044 + headerLenght, bitTmp3.toUInt(&ok, 10));
    }
    channelRegisters.setBit(1046 + headerLenght, ui->ssh->currentIndex());
    channelRegisters.setBit(1047 + headerLenght, ui->sttt->currentIndex());
    channelRegisters.setBit(1048 + headerLenght, ui->stot->currentIndex());
    channelRegisters.setBit(1049 + headerLenght, ui->sng->currentIndex());

    QString sg0_1 = "00";
    sg0_1 = sg0_1.number(ui->sg->currentIndex(), 2);
    for (int j = 0; j < sg0_1.size(); j++) {
        QString bitTmp4 = sg0_1.at(sg0_1.size() - 1 - j);
        channelRegisters.setBit(j + 1050 + headerLenght, bitTmp4.toUInt(&ok, 10));
    }
    QString st0_1 = "00";
    st0_1 = st0_1.number(ui->st->currentIndex(), 2);
    for (int j = 0; j < st0_1.size(); j++) {
        QString bitTmp5 = st0_1.at(st0_1.size() - 1 - j);
        channelRegisters.setBit(j + 1052 + headerLenght, bitTmp5.toUInt(&ok, 10));
    }
    channelRegisters.setBit(1054 + headerLenght, ui->sfam->currentIndex());
    channelRegisters.setBit(1055 + headerLenght, ui->sfa->currentIndex());


    channelRegisters.setBit(1056 + headerLenght, ui->scmx->currentIndex());

    QString sm0_5 = "000000";
    sm0_5 = sm0_5.number(ui->sm5_sm0->currentIndex(), 2);
    for (int j = 0; j < sm0_5.size(); j++) {
        QString bitTmp6 = sm0_5.at(sm0_5.size() - 1 - j);
        channelRegisters.setBit(j + 1057 + headerLenght, bitTmp6.toUInt(&ok, 10));
    }
    channelRegisters.setBit(1063 + headerLenght, ui->s16->currentIndex());
    channelRegisters.setBit(1064 + headerLenght, ui->sbfm->currentIndex());
    channelRegisters.setBit(1065 + headerLenght, ui->sbfp->currentIndex());
    channelRegisters.setBit(1066 + headerLenght, ui->sbft->currentIndex());
    channelRegisters.setBit(1067 + headerLenght, ui->srst->currentIndex());
    channelRegisters.setBit(1068 + headerLenght, ui->sstp->currentIndex());
    channelRegisters.setBit(1069 + headerLenght, ui->sdp->currentIndex());

    for (int i = 63; i >= 0; i--) {
        //        qDebug()<<"##################################### NEW CHANNEL: "<<63-i<<",  ##################################";
        channelRegisters.fill(false, i * 16 + headerLenght + 10, (i * 16 + headerLenght) + 16); //first 6 bits empty of each channel
        channelRegisters.setBit((i * 16) + 9 + headerLenght, VMM1SMXBool[63 - i]);

        QString sd0_3 = "0000";
        sd0_3 = sd0_3.number(VMM1SDVoltage[63 - i]->currentIndex(), 2);
        //        qDebug()<<"Current index:"<<VMM1SDVoltage[63-i]->currentIndex()<<", and String:"<<sd0_3<<", with size: "<<sd0_3.size();
        for (int j = 0; j < sd0_3.size(); j++) {
            QString bit = sd0_3.at(sd0_3.size() - 1 - j);
            //            channelRegisters.setBit((i*16)+8-j+headerLenght,bit.toUInt(&ok,10));
            channelRegisters.setBit((i * 16) + 5 + j + headerLenght, bit.toUInt(&ok, 10));
            //            qDebug()<<"Set to bit: "<< (i*16)+7+3-j+headerLenght<< ", and is: "<<bit.toUInt(&ok,10);
        }

        channelRegisters.setBit((i * 16) + 4 + headerLenght, VMM1SMBool[63 - i]);
        channelRegisters.setBit((i * 16) + 3 + headerLenght, VMM1STBool[63 - i]);
        channelRegisters.setBit((i * 16) + 2 + headerLenght, VMM1SLBool[63 - i]);
        channelRegisters.setBit((i * 16) + 1 + headerLenght, VMM1SCBool[63 - i]);
        channelRegisters.setBit((i * 16) + 0 + headerLenght, VMM1SPBool[63 - i]);
    }

    UpdateCounter();
    //__________ Writing _______________
    if (ui->writeRB->isChecked()) {
        if (ui->lx9RB->isChecked()) {
            QByteArray datagramAll;
            QDataStream out(&datagramAll, QIODevice::WriteOnly);
            out.device()->seek(0);
            QString header = "FEAD";
            out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 0;
            if (ui->SendConfiguration == QObject::sender()) {
                Sender(datagramAll);
                //qDebug()<<"Data:"<<datagramAll.toHex()<<", size:"<<datagramAll.size();
            }
        }
        if (ui->fecRB->isChecked()) {
            QByteArray datagramAll;
            QDataStream out(&datagramAll, QIODevice::WriteOnly);
            out.device()->seek(0);
            QString header = "FEAD";
            out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 2;
            if (ui->SendConfiguration == QObject::sender()) {
                Sender(datagramAll);
                //qDebug()<<"Data:"<<datagramAll.toHex()<<", size:"<<datagramAll.size();
            }
        }
        if (ui->spiRB->isChecked()) {
            QByteArray datagramAll = bitsToBytes(channelRegisters);
            QString datagramBin, datagramHex, datagramHex_2;
            //            for(int i=0;i<34;i++){
            //                datagramHex = datagramAll.mid(i*4,4).toHex();
            //                qDebug()<<"Splitted:"<<i<<", is:"<<datagramBin.number(datagramHex.toUInt(&ok,16),2);
            //            }
            QByteArray datagramSPI;
            QDataStream out(&datagramSPI, QIODevice::WriteOnly);
            out.device()->seek(0);
            QString header = "FEAD";
            out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 2;
            quint32 startingRegister = 16;
            for (int i = 0; i < 32; i++) {
                datagramHex = datagramAll.mid(i * 4, 2).toHex();
                datagramHex_2 = datagramAll.mid(i * 4 + 2, 2).toHex();
                quint16 temp32 = datagramHex.toUInt(&ok, 16);
                quint16 temp32_2 = datagramHex_2.toUInt(&ok, 16);
                out << (quint32) (startingRegister + i) << temp32_2 << temp32;
                //qDebug()<<"Address:"<<startingRegister+i<<", value:"<<datagramBin.number(datagramHex.toUInt(&ok,16),2);
            }
            datagramHex = datagramAll.mid(32 * 4, 4).toHex();
            quint32 temp_reverse = reverse32(datagramHex);
            out << (quint32) (32 + startingRegister) << temp_reverse;
            datagramHex = datagramAll.mid(33 * 4, 4).toHex();
            temp_reverse = reverse32(datagramHex);
            out << (quint32) (33 + startingRegister) << temp_reverse;

            if (ui->SendConfiguration == QObject::sender()) {
                Sender(datagramSPI);
                if (ui->loadCalibDataCB->isChecked())spiSent = 1;
                downloadSPI();
                //qDebug()<<"Data:"<<datagramAll.toHex()<<", size:"<<datagramAll.size()<<", spi size:"<<channelRegisters.size()-headerLenght;
            }
        }
    }
    //__________ Reading _______________
    if (ui->readRB->isChecked()) {
        if (ui->lx9RB->isChecked()) {
            QByteArray datagramAll;
            QDataStream out(&datagramAll, QIODevice::WriteOnly);
            out.device()->seek(0);
            QString header = "FEAD";
            out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 1;
            if (ui->SendConfiguration == QObject::sender()) {
                Sender(datagramAll);
                //qDebug()<<"Data:"<<datagramAll.toHex()<<", size:"<<datagramAll.size();
            }
        }
        if (ui->fecRB->isChecked()) {
            QByteArray datagramAll;
            QDataStream out(&datagramAll, QIODevice::WriteOnly);
            out.device()->seek(0);
            QString header = "FEAD";
            out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 3;
            if (ui->SendConfiguration == QObject::sender()) {
                Sender(datagramAll);
                //qDebug()<<"Data:"<<datagramAll.toHex()<<", size:"<<datagramAll.size();
            }
        }
        if (ui->spiRB->isChecked()) {
            QByteArray datagramSPI;
            QDataStream out(&datagramSPI, QIODevice::WriteOnly);
            out.device()->seek(0);
            QString header = "FEAD";
            out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 3;
            quint32 startingRegister = 16;
            for (int i = 0; i < 34; i++) {
                out << (quint32) (startingRegister + i) << (quint32) 0;
            }
            if (ui->SendConfiguration == QObject::sender()) {
                Sender(datagramSPI);
            }
        }
    }
}
//_________________________________________________________________________________________

void MainWindow::downloadSPI() {//if to be called from datapending - responce = 1
    bool ok;
    UpdateCounter();
    QByteArray datagramAll;
    QDataStream out(&datagramAll, QIODevice::WriteOnly);
    QString header = "FEAD";
    out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16);
    out << (quint16) 2 << (quint32) 9 << (quint32) 1;
    Sender(datagramAll);

    UpdateCounter();
    out.device()->seek(0);
    out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16);
    out << (quint16) 2 << (quint32) 9 << (quint32) 0;
    Sleeper::msleep(10);
    if (ui->loadCalibDataCB->isChecked())spiSent = 1;
    Sender(datagramAll);

    // ADC Start Dly
    UpdateCounter();
    out.device()->seek(0);
    out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16);
    out << (quint16) 2 << (quint32) 6 << (quint32) 15;
    Sleeper::msleep(10);
    if (ui->loadCalibDataCB->isChecked())spiSent = 1;
    Sender(datagramAll);

    //Start Dly
    UpdateCounter();
    out.device()->seek(0);
    out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16);
    out << (quint16) 2 << (quint32) 7 << (quint32) 6;
    Sleeper::msleep(10);
    if (ui->loadCalibDataCB->isChecked())spiSent = 1;
    Sender(datagramAll);
}
//_________________________________________________________________________________________

void MainWindow::customCommandHandler() {//if to be called from datapending - responce = 1
    bool ok;

    //idForCustomCommands = 1 onACQ,
    //                      2 offACQ
    //                      3 detection time mode + edge detection
    //                      4 trigger mode
    //                      5 trigger counter
    //                      6 asic
    //                      7 cdaq reset
    //                      8

    if (ui->onACQ == QObject::sender() || ui->offACQ == QObject::sender() ||
            ui->asic_reset == QObject::sender() || ui->cdaq_reset == QObject::sender() ||
            ui->triggerCounter_reset == QObject::sender() || ui->checkTriggers == QObject::sender()) {
        UpdateCounter();
        QByteArray datagramAll;
        QDataStream out(&datagramAll, QIODevice::WriteOnly);
        QString header = "FEAD";
        out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16);
        out << (quint16) 3 << (quint32) 0 << (quint32) 0;
        Sender(datagramAll);
        if (ui->onACQ == QObject::sender())idForCustomCommands = 1;
        else if (ui->offACQ == QObject::sender())idForCustomCommands = 2;
        else if (ui->triggerCounter_reset == QObject::sender() || ui->checkTriggers == QObject::sender())idForCustomCommands = 5;
        else if (ui->asic_reset == QObject::sender()) idForCustomCommands = 6;
        else if (ui->cdaq_reset == QObject::sender()) idForCustomCommands = 7;
    }
    if (ui->applyDetectionMode == QObject::sender()) {
        UpdateCounter();
        QByteArray datagramAll;
        QDataStream out(&datagramAll, QIODevice::WriteOnly);
        QString header = "FEAD";
        out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16);
        out << (quint16) 3 << (quint32) 0 << (quint32) 0 << (quint32) 4 << (quint32) 0;
        Sender(datagramAll);
        idForCustomCommands = 3;
    }
    if (ui->applyTrigger == QObject::sender()) {
        UpdateCounter();
        QByteArray datagramAll;
        QDataStream out(&datagramAll, QIODevice::WriteOnly);
        QString header = "FEAD";
        out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16);
        out << (quint16) 3 << (quint32) 0 << (quint32) 0 << (quint32) 3 << (quint32) 0;
        Sender(datagramAll);
        idForCustomCommands = 4;
    } else {
        if (idForCustomCommands != 0) {
            QString datagramBin, datagramHex;
            datagramHex = buffer.mid(0, 4).toHex();
            quint32 reqReceived = datagramHex.toUInt(&ok, 16);
            if (reqReceived == commandCounter) {
                QDataStream out(&buffer, QIODevice::WriteOnly);
                if (idForCustomCommands == 1) {
                    datagramHex = buffer.mid(12, 4).toHex();
                    quint32 temp32 = ValueToReplace(datagramHex, 0, true);
                    out.device()->seek(12);
                    out << temp32;
                } else if (idForCustomCommands == 2) {
                    datagramHex = buffer.mid(12, 4).toHex();
                    quint32 temp32 = ValueToReplace(datagramHex, 0, false);
                    out.device()->seek(12);
                    out << temp32;
                } else if (idForCustomCommands == 3) {
                    QString tempString;
                    datagramHex = buffer.mid(12, 4).toHex();
                    quint32 temp32 = ValueToReplace(datagramHex, 2, ui->edgeSelection->currentIndex());
                    QString tempStr = tempString.number(temp32, 10);
                    temp32 = ValueToReplace(tempStr, 1, ui->detectionMode->currentIndex());

                    //                    datagramHex.replace(6,1,tempString.number(ui->detectionMode->currentIndex()));
                    //                    datagramHex.replace(5,1,tempString.number(ui->edgeSelection->currentIndex()));
                    //                    quint32 temp32 = datagramHex.toUInt(&ok,2);
                    //                    datagramBin.number(temp32,2);
                    out.device()->seek(12);
                    out << temp32;
                    out.device()->seek(20);
                    temp32 = (ui->detectionTime->value() - 50) / 25;
                    out << temp32;
                } else if (idForCustomCommands == 4) {
                    QString tempString;
                    datagramHex = buffer.mid(12, 4).toHex();
                    quint32 temp32;
                    if (ui->triggerMode->currentIndex() == 1)
                        temp32 = ValueToReplace(datagramHex, 3, true);
                    else if (ui->triggerMode->currentIndex() == 0)
                        temp32 = ValueToReplace(datagramHex, 3, false);
                    datagramBin.number(temp32, 2);
                    out.device()->seek(12);
                    out << temp32;
                    out.device()->seek(20);
                    temp32 = (ui->triggerTimeout->value() - 25) / 25;
                    out << temp32;
                } else if (idForCustomCommands == 5) {
                    datagramHex = buffer.mid(12, 4).toHex();
                    quint32 temp32 = ValueToReplace(datagramHex, 13, true);
                    out.device()->seek(12);
                    out << temp32;
                } else if (idForCustomCommands == 6) {
                    datagramHex = buffer.mid(12, 4).toHex();
                    quint32 temp32 = ValueToReplace(datagramHex, 14, true);
                    out.device()->seek(12);
                    out << temp32;
                } else if (idForCustomCommands == 7) {
                    datagramHex = buffer.mid(12, 4).toHex();
                    quint32 temp32 = ValueToReplace(datagramHex, 15, true);
                    out.device()->seek(12);
                    out << temp32;
                }

                out.device()->seek(6);
                out << (quint16) 2; //change to write mode

                UpdateCounter();
                Sender(buffer);

                // Clear Bits
                if (idForCustomCommands == 5) {
                    datagramHex = buffer.mid(12, 4).toHex();
                    quint32 temp32 = ValueToReplace(datagramHex, 13, false);
                    out.device()->seek(12);
                    out << temp32;
                    UpdateCounter();
                    Sender(buffer);
                } else if (idForCustomCommands == 6) {
                    datagramHex = buffer.mid(12, 4).toHex();
                    quint32 temp32 = ValueToReplace(datagramHex, 14, false);
                    out.device()->seek(12);
                    out << temp32;
                    UpdateCounter();
                    Sender(buffer);
                }

                idForCustomCommands = 0;
            }
        }
    }
}
//_________________________________________________________________________________________

void MainWindow::customCommandWithoutResponse() {
    if (ui->setDaqMode == QObject::sender()) {
        bool ok;
        UpdateCounter();
        QByteArray datagramAll;
        QDataStream out(&datagramAll, QIODevice::WriteOnly);
        QString header = "FEAD";
        out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16);
        out << (quint16) 2 << (quint32) 12 << (quint32) ui->daqModeOutput->currentIndex();
        Sender(datagramAll);
    } else if (ui->setHeaderPB == QObject::sender()) {
        bool ok;
        UpdateCounter();
        QByteArray datagramAll;
        QDataStream out(&datagramAll, QIODevice::WriteOnly);
        QString header = "FEAD";
        if (ui->setVMMs->currentText() != "All") {
            out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 2;
            out << (quint32) 13 << (quint8) ui->header4LE->text().toUInt(&ok, 10) << (quint8) ui->header3LE->text().toUInt(&ok, 10);
            out << (quint8) ui->header2LE->text().toUInt(&ok, 10) << (quint8) ui->header1LE->text().toUInt(&ok, 10);
            Sender(datagramAll);
        } else {
            headerSet = 1;
            for (int i = 0; i < ui->setVMMs->count() - 1; i++) {
                UpdateCounter();
                ui->setVMMs->setCurrentIndex(i);
                QString tempString;
                out.device()->seek(0);
                ui->header4LE->setText(tempString.number(i + ui->ip4->text().toUInt(&ok, 10), 10));
                out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 2;
                out << (quint32) 13 << (quint8) ui->header4LE->text().toUInt(&ok, 10) << (quint8) ui->header3LE->text().toUInt(&ok, 10);
                out << (quint8) ui->header2LE->text().toUInt(&ok, 10) << (quint8) ui->header1LE->text().toUInt(&ok, 10);
                Sender(datagramAll);
            }
            headerSet = 0;
            ui->header4LE->setText(ui->ip4->text() + 1);
            ui->setVMMs->setCurrentIndex(ui->setVMMs->currentIndex() + 1);
        }
    } else if (ui->lx9Reset == QObject::sender()) {
        bool ok;
        UpdateCounter();
        QByteArray datagramAll;
        QDataStream out(&datagramAll, QIODevice::WriteOnly);
        QString header = "FEAD";
        out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 0;
        out << (quint32) 0 << (quint32) 4;
        Sender(datagramAll);
        out.device()->seek(12);
        out << (quint32) 5;
        Sender(datagramAll);
    } else if (ui->sampleSetPB == QObject::sender()) {
        bool ok;
        UpdateCounter();
        QByteArray datagramAll;
        QDataStream out(&datagramAll, QIODevice::WriteOnly);
        QString header = "FEAD";
        if (ui->writeRB->isChecked())
            out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 2;
        else if (ui->readRB->isChecked())
            out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 3;
        out << (quint32) 11 << (quint32) (ui->sampleValue->currentIndex());
        Sender(datagramAll);
    } else if (ui->applyDetectionMode == QObject::sender()) {
        qDebug() << "Function Without Response in Use ! This will reset everything in register 0x00 and the trigger!!";
        bool ok;
        UpdateCounter();
        QByteArray datagramAll;
        QDataStream out(&datagramAll, QIODevice::WriteOnly);
        QString header = "FEAD";
        out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 2;
        out << (quint32) 0 << (quint32) 7 << (quint32) 4 << (quint32) ((ui->detectionTime->value() - 50) / 25);
        Sender(datagramAll);
    }
}
//_________________________________________________________________________________________

quint32 MainWindow::ValueToReplace(QString datagramHex, int bitToChange, bool bitValue) {
    bool ok;
    QBitArray commandToSend(32, false);
    QString datagramBin, temp;
    datagramBin = temp.number(datagramHex.toUInt(&ok, 16), 2);
    for (int i = 0; i < datagramBin.size(); i++) {
        QString bit = datagramBin.at(i);
        commandToSend.setBit(32 - datagramBin.size() + i, bit.toUInt(&ok, 10));
    }
    commandToSend.setBit(31 - bitToChange, bitValue); //set 13th bit
    QByteArray byteArray = bitsToBytes(commandToSend);
    quint32 temp32 = byteArray.toHex().toUInt(&ok, 16);
    return temp32;
}
//_________________________________________________________________________________________

quint32 MainWindow::reverse32(QString datagramHex) {
    bool ok;
    QBitArray commandToSend(32, false);
    QString datagramBin, temp;
    datagramBin = temp.number(datagramHex.toUInt(&ok, 16), 2);
    for (int i = 0; i < datagramBin.size(); i++) {
        QString bit = datagramBin.at(i);
        commandToSend.setBit(32 - datagramBin.size() + i, bit.toUInt(&ok, 10));
    }
    QBitArray commandToSendR(32, false);
    for (int i = 0; i < 32; i++) {
        commandToSendR.setBit(31 - i, commandToSend[i]);
    }
    QByteArray byteArray = bitsToBytes(commandToSendR);
    quint32 temp32 = byteArray.toHex().toUInt(&ok, 16);
    return temp32;
}
//_________________________________________________________________________________________

void MainWindow::MergerFPGA() {
    QByteArray datagramAll;
    QDataStream out(&datagramAll, QIODevice::WriteOnly);
    if (ui->onAcq_fpga == QObject::sender())
        out << (quint32) 3 << (quint32) 0 << (quint32) 1 << (quint32) 1;
    else if (ui->offAcq_fpga == QObject::sender())
        out << (quint32) 3 << (quint32) 0 << (quint32) 1 << (quint32) 0;

    else if (ui->triggerCnt_fpga_enable == QObject::sender())
        out << (quint32) 2 << (quint32) 3 << (quint32) 1 << (quint32) 0;

    else if (ui->triggerCnt_fpga_clear == QObject::sender()) {
        out << (quint32) 2 << (quint32) 3 << (quint32) 1 << (quint32) 1;
        SenderFPGA(datagramAll);
        out.device()->seek(0);
        out << (quint32) 2 << (quint32) 3 << (quint32) 1 << (quint32) 0;
    } else if (ui->triggerEnable_fpga == QObject::sender())
        out << (quint32) 2 << (quint32) 4 << (quint32) 1 << (quint32) 1;
    else if (ui->triggerDisable_fpga == QObject::sender())
        out << (quint32) 2 << (quint32) 4 << (quint32) 1 << (quint32) 0;

    else if (ui->realData_fpga == QObject::sender())
        out << (quint32) 2 << (quint32) 5 << (quint32) 1 << (quint32) 0;
    else if (ui->testData_fpga == QObject::sender())
        out << (quint32) 2 << (quint32) 5 << (quint32) 1 << (quint32) 1;

    else if (ui->triggerCnt_fpga_read == QObject::sender())
        out << (quint32) 1 << (quint32) 48 << (quint32) 1;


    else if (ui->timeWindow_fpgaPB == QObject::sender())
        out << (quint32) 2 << (quint32) 6 << (quint32) 1 << (quint32) (ui->fa_maxCnt->value());

    SenderFPGA(datagramAll);

    if (ui->trigger_fpga_init == QObject::sender()) {
        qDebug() << "Initialization of FPGA";

        qDebug() << "Turning DAQ OFF";
        out.device()->seek(0);
        out << (quint32) 3 << (quint32) 0 << (quint32) 1 << (quint32) 0;
        Sleeper::msleep(500);
        SenderFPGA(datagramAll);

        qDebug() << "Clear Trigger Counter";
        out.device()->seek(0);
        out << (quint32) 2 << (quint32) 3 << (quint32) 1 << (quint32) 1;
        Sleeper::msleep(500);
        SenderFPGA(datagramAll);

        qDebug() << "Enable Trigger Counter";
        out.device()->seek(0);
        out << (quint32) 2 << (quint32) 3 << (quint32) 1 << (quint32) 0;
        Sleeper::msleep(500);
        SenderFPGA(datagramAll);

        qDebug() << "Enable Triggers";
        out.device()->seek(0);
        out << (quint32) 2 << (quint32) 4 << (quint32) 1 << (quint32) 1;
        Sleeper::msleep(500);
        SenderFPGA(datagramAll);

        qDebug() << "Set Datatype to Real";
        out.device()->seek(0);
        out << (quint32) 2 << (quint32) 5 << (quint32) 1 << (quint32) 0;
        Sleeper::msleep(500);
        SenderFPGA(datagramAll);

        qDebug() << "Setting Time Window";
        out.device()->seek(0);
        out << (quint32) 2 << (quint32) 6 << (quint32) 1 << (quint32) 255;
        Sleeper::msleep(500);
        SenderFPGA(datagramAll);

        qDebug() << "Turning DAQ ON";
        out.device()->seek(0);
        out << (quint32) 3 << (quint32) 0 << (quint32) 1 << (quint32) 1;
        Sleeper::msleep(500);
        SenderFPGA(datagramAll);

        qDebug() << "Initialization of FPGA - DONE!";
    }
    // Read Back Directly

    //    QByteArray datagramAllRead;
    //    QDataStream outRead (&datagramAllRead, QIODevice::WriteOnly);
    //    if(ui->onAcq_fpga == QObject::sender())
    //        outRead<<(quint32)1<<(quint32)0<<(quint32)1;
    //    else if(ui->offAcq_fpga == QObject::sender())
    //        outRead<<(quint32)1<<(quint32)0<<(quint32)1;

    ////    else if(ui->triggerCnt_fpga_clear == QObject::sender())
    ////        outRead<<(quint32)1<<(quint32)3<<(quint32)1;

    //    else if(ui->triggerEnable_fpga == QObject::sender())
    //        outRead<<(quint32)1<<(quint32)4<<(quint32)1;
    //    else if(ui->triggerDisable_fpga == QObject::sender())
    //        outRead<<(quint32)1<<(quint32)4<<(quint32)1;

    //    else if(ui->realData_fpga == QObject::sender())
    //        outRead<<(quint32)1<<(quint32)5<<(quint32)1;
    //    else if(ui->testData_fpga == QObject::sender())
    //        outRead<<(quint32)1<<(quint32)5<<(quint32)1;

    //    else if(ui->timeWindow_fpgaPB == QObject::sender())
    //        outRead<<(quint32)1<<(quint32)6<<(quint32)1;

    //    SenderFPGA(datagramAllRead);


}
//_________________________________________________________________________________________

QByteArray MainWindow::bitsToBytes(QBitArray bits) {
    QByteArray bytes;
    bytes.resize(bits.count() / 8); //add more §for a header of 8 bits????
    bytes.fill(0);
    // Convert from QBitArray to QByteArray
    for (int b = 0; b < bits.count(); ++b)
        bytes[b / 8] = (bytes.at(b / 8) | ((bits[b] ? 1 : 0) << (7 - (b % 8))));
    return bytes;
}
//_________________________________________________________________________________________

void MainWindow::Sender(QByteArray blockOfData) {
    if (bnd && ui->connectionLabel->text() == " All Alive") {
        if (ui->setVMMs->currentText() != "") {
            if (ui->setVMMs->currentText() == "All" && headerSet == 0 && multicastingFlag == 0) {
                if (!spiSent) {
                    for (int i = 0; i < ui->numbersOfFecs->value(); i++) {
                        QString address = ips[i];
                        Sleeper::msleep(5);
                        socket->writeDatagram(blockOfData, QHostAddress(address), FECPort);
                        if (!threadDi->isRunning())
                            qDebug() << "IP:" << address << ", data:" << blockOfData.toHex() << ", size:" << blockOfData.size();
                    }
                } else {
                    socket->writeDatagram(blockOfData, QHostAddress(currentAddressForRecipe), FECPort);
                    if (!threadDi->isRunning())
                        qDebug() << "IP:" << currentAddressForRecipe << ", data:" << blockOfData.toHex() << ", size:" << blockOfData.size();
                    spiSent = 0;
                }
            } else if (multicastingFlag == 0) {
                QString address = ips[ui->setVMMs->currentIndex()];
                socket->writeDatagram(blockOfData, QHostAddress(address), FECPort);
                qDebug() << "IP:" << address << ", data:" << blockOfData.toHex() << ", size:" << blockOfData.size();
            } else if (multicastingFlag == 1) {
                Sleeper::msleep(20);
                socket->writeDatagram(blockOfData, QHostAddress("10.0.0.255"), FECPort);
                qDebug() << "Broadcasting IP:" << QHostAddress::Broadcast << ", data:" << blockOfData.toHex() << ", size:" << blockOfData.size();
                multicastingFlag = 0;
            }
        } else {
            qDebug() << "NO IPs";
        }
    } else {
        qDebug() << "Error from socket: " << socket->errorString() << ", Local Port = " << socket->localPort() << ", Bind Reply: " << bnd;
        socket->close();
        socket->disconnectFromHost();
    }
}
//_________________________________________________________________________________________

void MainWindow::SenderFPGA(QByteArray blockOfData) {
    //    if(bndFPGA && communicationAliveFPGA){
    //QString address = ips_tr;
    //socketFPGA->writeDatagram(blockOfData,QHostAddress(address), FPGAPort);
    socketTCP->write(blockOfData);
    qDebug() << blockOfData.toHex();
    //    }else{
    //        qDebug()<<"NO IPs";
    //    }
}
//_________________________________________________________________________________________

void MainWindow::hideChannels(int state) {
    if (!ui->hideChannels->isChecked()) {
        this->setFixedSize(620, 725);
        ui->enableDebugPB->setChecked(0);
    } else {
        this->setFixedSize(1154, 725);
    }
}
//_________________________________________________________________________________________

void MainWindow::showDebugScreen(int state) {
    if (ui->hideChannels->isChecked() && ui->enableDebugPB->isChecked()) {
        this->setFixedSize(1154, 874);
    } else if (!ui->hideChannels->isChecked() && ui->enableDebugPB->isChecked()) {
        this->setFixedSize(620, 874);
    } else if (!ui->hideChannels->isChecked() && !ui->enableDebugPB->isChecked()) {
        this->setFixedSize(620, 725);
    } else if (ui->hideChannels->isChecked() && !ui->enableDebugPB->isChecked()) {
        this->setFixedSize(1154, 725);
    }
}
//_________________________________________________________________________________________

void MainWindow::clearDebugScreen() {
    if (ui->clearDebugScreenPB == QObject::sender())
        ui->debugScreen->setText("*************** Waiting for Data *****************");
    if (ui->clearDebugScreenPB_fpga == QObject::sender())
        ui->debugScreen_fpga->setText("*************** Waiting for Data *****************");
}
//_________________________________________________________________________________________

void MainWindow::UpdateCounter() {
    commandCounter++;
    QString tmp;
    ui->cmdlabel->setText(tmp.number(commandCounter));
}
//_________________________________________________________________________________________

void MainWindow::constructHeader(int) {
    bool ok;
    QString tempString;
    if (ui->setVMMs->currentText() != "All") {
        ui->header4LE->setText(tempString.number(ui->setVMMs->currentIndex() + ui->ip4->text().toUInt(&ok, 10), 10));
    }
    if (ui->setVMMs->currentText() == "All")ui->header4LE->setText(ui->ip4->text());
}
//_________________________________________________________________________________________

void MainWindow::threadHandler() {
    if (ui->startDi == QObject::sender()) {
        threadDi->start();
    } else if (ui->stopDi == QObject::sender()) {
        threadDi->exit(0);
        qDebug() << "Di Thread Stopped";
    }
}
//_________________________________________________________________________________________

void MainWindow::sendDis(int) {
    bool ok;
    UpdateCounter();
    QByteArray datagramAll;
    QDataStream out(&datagramAll, QIODevice::WriteOnly);
    QString header = "FEAD";
    out << (quint32) commandCounter << (quint16) header.toUInt(&ok, 16) << (quint16) 2;
    out << (quint32) 1 << (quint32) 32;
    if (ui->setVMMs->currentText() == "All")
        multicastingFlag = 1;
    void delayMs();

    //    Sleeper::msleep(10);
    Sender(datagramAll);
    out.device()->seek(12);
    out << (quint32) 0;
    if (ui->setVMMs->currentText() == "All")
        multicastingFlag = 1;
    Sleeper::msleep(10);
    //    delayMs();
    Sender(datagramAll);
}
//_________________________________________________________________________________________________

void MainWindow::triggerHandler() {//hugh: this is where root file is made
    if (ui->checkTriggers == QObject::sender()) {
        bool ok;
        QString runNumber;
        QTextStream daqInput(&fileDaq);
        QString rootFile = ui->runDirectoryField->text() + "/run_%4d.root";
        const char* rootFileChar = rootFile.toStdString().c_str();
        fileDaq.setFileName(ui->runDirectoryField->text() + "/dataBNL_Tracking_Run_" + runNumber.number(ui->runNumber->value()) + ".txt");
        fileDaqRoot = new TFile(Form(rootFileChar, ui->runNumber->text().toInt(&ok, 10)), "UPDATE");

        // added by hugh skottowe 20140206
        QString textFile = ui->runDirectoryField->text() + "/run_%4d.txt";
        const char *const textFileChar = textFile.toStdString().c_str();
        fileDaqText.open(Form(textFileChar, ui->runNumber->text().toInt(&ok, 10)));
        fileDaqText << "# Start of text file data for run " << ui->runNumber->text().toInt(&ok, 10) << "\n";

        TTree *run_properties = new TTree("run_properties", "run_properties");
        vmm1 = new TTree("vmm1", "vmm1");
        vmm1Calibration = new TTree("vmm1Calibration", "vmm1Calibration");

        int runVariable, tacSlopVariable, peakTimeVariable, dacCountsVariable, pulserCountsVariable, calibrationRunVariable, angleVariable;
        double gainVariable;
        QString tempString;
        TBranch *run = run_properties->Branch("runNumber", &runVariable);
        TBranch *gain = run_properties->Branch("gain", &gainVariable);
        TBranch *tacSlope = run_properties->Branch("tacSlope", &tacSlopVariable);
        TBranch *peakTime = run_properties->Branch("peakTime", &peakTimeVariable);
        TBranch *dacCounts = run_properties->Branch("dacCounts", &dacCountsVariable);
        TBranch *pulserCounts = run_properties->Branch("pulserCounts", &pulserCountsVariable);
        TBranch *angle = run_properties->Branch("angle", &angleVariable);

        TBranch *calibrationRun = run_properties->Branch("calibrationRun", &calibrationRunVariable);
        if (ui->calibration->isChecked()) calibrationRunVariable = 1;
        else calibrationRunVariable = 0;

        runVariable = ui->runNumber->value();
        tempString = ui->sg->currentText().left(3);
        gainVariable = tempString.toDouble();
        tempString = ui->stc->currentText().left(4);
        tacSlopVariable = tempString.toInt();
        tempString = ui->st->currentText().left(3);
        peakTimeVariable = tempString.toInt();
        dacCountsVariable = ui->sdt->value();
        pulserCountsVariable = ui->sdp_2->value();
        angleVariable = ui->angle->value();

        run->Fill();
        gain->Fill();
        tacSlope->Fill();
        peakTime->Fill();
        dacCounts->Fill();
        pulserCounts->Fill();
        calibrationRun->Fill();
        angle->Fill();

        run_properties->Fill();
        run_properties->Write("", TObject::kOverwrite);
        delete run_properties;

        tdoVariable.clear();
        pdoVariable.clear();
        chIdVariable.clear();
        boardVariable.clear();
        currentEvent = 0;
        eventNumberBranch = vmm1->Branch("event", &eventNumberVariable);
        eventNumberCounterBranch = vmm1->Branch("eventCnt", &eventNumberCounterVariable);
        boardBranch = vmm1->Branch("board", &boardVariable);
        chIdBranch = vmm1->Branch("channel", &chIdVariable);
        tdoBranch = vmm1->Branch("tdo", &tdoVariable);
        pdoBranch = vmm1->Branch("pdo", &pdoVariable);



        if (ui->calibration->isChecked()) {
            pulserBranchForCalibration = vmm1Calibration->Branch("pulser", &pulserVariableForCalibration);
            gainBranchForCalibration = vmm1Calibration->Branch("gain", &gainVariableForCalibration);
            boardBranchForCalibration = vmm1Calibration->Branch("board", &boardVariableForCalibration);
            channelBranchForCalibration = vmm1Calibration->Branch("channel", &chIdVariableForCalibration);
            neighborBranchForCalibration = vmm1Calibration->Branch("neighbor", &neighborVariableForCalibration);
            pdoBranchForCalibration = vmm1Calibration->Branch("pdo", &pdoVariableForCalibration);
            tdoBranchForCalibration = vmm1Calibration->Branch("tdo", &tdoVariableForCalibration);
            timeModeBranchForCalibration = vmm1Calibration->Branch("timeMode", &timeModeValueForCalibration);
        }

        if (fileDaq.exists()) {
            QMessageBox::information(this, "ERROR",
                    "Run File exists in " + runDirectory.path() +
                    "Please increase the run Number");
        } else {
            daqCnt = 0;
            socketDAQ = new QUdpSocket(this);
            bool bounding = socketDAQ->bind(DAQPort);
            if (bounding) {
                fileDaq.open(QIODevice::ReadWrite);
                daqInput << "##################################################################" << "\n";
                daqInput << "#                          run: " + runNumber.number(ui->runNumber->value(), 10) + "                             #" << "\n";
                daqInput << "#    Gain=" + ui->sg->currentText() + ", Peak Time:" + ui->st->currentText() + ", Neighbor Trigger: " + ui->sng->currentText() + "       #" << "\n";
                daqInput << "#    TAC Slope=" + ui->stc->currentText() + ", DAC Counts:" + ui->sdt->text() + ", in mV:" + ui->dacmvLabel->text() + ", Time Window:" + ui->triggerTimeout->text() + "ns           #" << "\n";
                daqInput << "#    User Comments=" + ui->userComments->text() + "           #" << "\n";
                if (ui->calibration->isChecked())
                    daqInput << "###################   CALIBRATION RUN   ##########################" << "\n";
                daqInput << "##################################################################" << "\n";
                connect(socketDAQ, SIGNAL(readyRead()), this, SLOT(dataDAQPending()));
                qDebug() << "DAQ Port Is OK!";

            } else {
                qDebug() << "DAQ Port Problem!";
                socketDAQ->disconnectFromHost();
                socketDAQ->close();
            }
        }
        ui->runStatusField->setText("Run:" + ui->runNumber->text() + " ongoing");
        ui->runStatusField->setStyleSheet("background-color:green");
        ui->checkTriggers->setEnabled(0);
        ui->stopTriggerCnt->setEnabled(1);
        calibrationStop = 0;
        if (ui->calibration->isChecked()) {
            //startCalibration();//hugh: should disable this line
        }
        if (ui->doCalibRun->isChecked()) {
            // added by hugh skottowe 20140212
            startCalibration();
        }
    }
    if (ui->clearTriggerCnt == QObject::sender()) {
        daqCnt = 0;
        QString tempString;
        ui->triggerCntLabel->setText(tempString.number(daqCnt, 10));
    }
    if (ui->stopTriggerCnt == QObject::sender()) {
        calibrationStop = 1;
        socketDAQ->close();
        fileDaq.close();
        ui->runStatusField->setText("Run:" + ui->runNumber->text() + " finished");
        ui->runStatusField->setStyleSheet("background-color:gray");
        vmm1->Write("", TObject::kOverwrite);
        fileDaqRoot->Write();
        fileDaqRoot->Close();
        fileDaqText.close();
        ui->runNumber->setValue(ui->runNumber->value() + 1);
        ui->checkTriggers->setEnabled(1);
        ui->stopTriggerCnt->setEnabled(0);
        if (ui->calibration->isChecked()) {
            threadDi->exit(0);
        }
        //ui->calibration->setChecked(0);//commented out by hugh skottowe 20140212
    }
}
//_________________________________________________________________________________________________

void MainWindow::writeFPGAFile(QString inputPacket) {
    QTextStream daqInputfpga(&fileDaq_fpga);
    if (daqFile_fpga == true) {
        daqInputfpga << inputPacket << "\n";
    }
}

//_________________________________________________________________________________________________

void MainWindow::triggerHandler_fpga() {
    if (!ui->calibration->isChecked()) {
        if (ui->checkTriggers == QObject::sender()) {
            QString runNumber;

            vmm1Trigger = new TTree("vmm1Trigger", "vmm1Trigger");
            triggerEventBranch = vmm1Trigger->Branch("event", &triggerEventVariable);
            triggerTimeBranch = vmm1Trigger->Branch("time", &triggerTimeVariable);
            triggerChannelBranch = vmm1Trigger->Branch("channel", &triggerChannelVariable);
            triggerBoardBranch = vmm1Trigger->Branch("board", &triggerBoardVariable);

            fileDaq_fpga.setFileName(ui->runDirectoryField->text() + "/dataBNL_Trigger_Run_" + runNumber.number(ui->runNumber->value()) + ".txt");
            daqCnt_fpga = 0;
            QString tempString;
            ui->triggerCntLabel_fpga->setText(tempString.number(daqCnt_fpga, 10));
            daqFile_fpga = 1;
            if (fileDaq_fpga.exists()) {
                QMessageBox::information(this, "ERROR",
                        "Run File exists in " + runDirectory.path() +
                        "Please increase the run Number");
            } else {
                fileDaq_fpga.open(QIODevice::ReadWrite);
                QTextStream daqInput_fpga(&fileDaq_fpga);
                daqInput_fpga << "##################################################################" << "\n";
                daqInput_fpga << "#                  Trigger run: " + runNumber.number(ui->runNumber->value(), 10) + "                             #" << "\n";
                daqInput_fpga << "#    Gain=" + ui->sg->currentText() + ", Peak Time:" + ui->st->currentText() + ", Neighbor Trigger: " + ui->sng->currentText() + "       #" << "\n";
                daqInput_fpga << "#    TAC Slope=" + ui->stc->currentText() + ", DAC Counts:" + ui->sdt->text() + ", in mV:" + ui->dacmvLabel->text() + ", Time window:" + ui->fa_maxCnt->text() + "(counts in 5ns/count)           #" << "\n";
                daqInput_fpga << "#    User Comments=" + ui->userComments->text() + "           #" << "\n";
                daqInput_fpga << "##################################################################" << "\n";
            }
        }
        if (ui->clearTriggerCnt == QObject::sender()) {
            QString tempString;
            daqCnt_fpga = 0;
            ui->triggerCntLabel_fpga->setText(tempString.number(daqCnt_fpga, 10));
        }
        if (ui->stopTriggerCnt == QObject::sender()) {
            daqFile_fpga = 0;
            Sleeper::msleep(10);
            fileDaq_fpga.close();
        }
    }
}
//_________________________________________________________________________________________________

void MainWindow::dataDAQPending() {
    bool ok;
    QString lineChange = "\n";
    QTextStream daqInput(&fileDaq);
    QString tempString;
    while (socketDAQ->hasPendingDatagrams()) {
        bufferDAQ.resize(socketDAQ->pendingDatagramSize());
        socketDAQ->readDatagram(bufferDAQ.data(), bufferDAQ.size());
        //        daqInput<<bufferDAQ.toHex()<<lineChange;

        if (bufferDAQ.toHex() != "fafafafa") {
            //            qDebug()<< "1)***************Nea grammi pou den einai fafafafa ****************** ";
            daqCnt++;
            ui->triggerCntLabel->setText(tempString.number(daqCnt, 10));

            QString hexCHID = bufferDAQ.mid(8, 1).toHex();
            qint32 chID = hexCHID.toInt(&ok, 16);
            BoardsHits->Fill(chID);
            QString evIDhex = bufferDAQ.mid(0, 4).toHex();
            qint32 evID = evIDhex.toInt(&ok, 16);
            //            qDebug()<<"2) Irthe i board:"<<chID<<", me event :"<<evID<<"kai to current event einai:"<<currentEvent;
            if (evID > currentEvent && !ui->calibration->isChecked()) {//hugh: leave this as it is
                //                qDebug()<<"3) Mpike na grapsei to event";
                EventNumber->Fill(evID - 1);
                eventNumberVariable = evID - 1;
                //                qDebug()<<"4) Tha grapsw to event:"<<evID-1;
                vmm1->Fill();

                // added by hugh skottowe 20140206
                fileDaqText << "EventNum " << eventNumberVariable;
                {
                    timespec ts;
                    clock_gettime(CLOCK_REALTIME, &ts);
                    fileDaqText << " Sec " << ts.tv_sec << " NS " << ts.tv_nsec;
                }
                fileDaqText << " : txt of vmm1 tree\n";
                for (unsigned i = 0; i < boardVariable.size(); i++) {
                    for (unsigned j = 0; j < chIdVariable.at(i).size(); j++) {
                        fileDaqText << boardVariable.at(i) << " "
                                << chIdVariable.at(i).at(j) << " "
                                << pdoVariable.at(i).at(j) << " "
                                << tdoVariable.at(i).at(j) << "\n";
                    }
                }

                boardVariable.clear();
                pdoVariable.clear();
                tdoVariable.clear();
                chIdVariable.clear();
                currentEvent = evID;
            }

            boardVariable.push_back(chID);
            boardEvents[chID - 15]++;
            boardVariableForCalibration = chID;
            QString tempgainString = ui->sg->currentText().left(3);
            gainVariableForCalibration = tempgainString.toDouble();
            pulserVariableForCalibration = ui->sdp_2->value();
            timeModeValueForCalibration = ui->detectionTime->value();

            vector<double> tempPdo, tempTdo, tempCh;
            tempPdo.clear();
            tempTdo.clear();
            tempCh.clear();
            pdoVariableForCalibration.clear();
            tdoVariableForCalibration.clear();
            chIdVariableForCalibration.clear();
            neighborVariableForCalibration.clear();
            for (int i = 12; i <= bufferDAQ.size() - 4;) {
                vector<double> chInfo = bytesTobits(bufferDAQ.mid(i, 4));
                tempPdo.push_back(chInfo.at(2));
                tempTdo.push_back(chInfo.at(1));
                tempCh.push_back(chInfo.at(0));

                pdoVariableForCalibration.push_back(chInfo.at(2));
                tdoVariableForCalibration.push_back(chInfo.at(1));
                chIdVariableForCalibration.push_back(chInfo.at(0));
                int tempChannel = chInfo.at(0);
                if (VMM1STBool[tempChannel])
                    neighborVariableForCalibration.push_back(0);
                else
                    neighborVariableForCalibration.push_back(1);

                if (ui->monitoring->isChecked()) {
                    if (chID == T1Chips[1] || chID == T1Chips[2]) {
                        T1Charges->Fill(chInfo.at(2));
                        T1Times->Fill(chInfo.at(1));
                        if (chID == T1Chips[1]) T1Profile->Fill(128 + chInfo.at(0));
                        else if (chID == T1Chips[2]) T1Profile->Fill(64 + chInfo.at(0));
                    } else if (chID == T2Chips[1] || chID == T2Chips[2]) {
                        T2Charges->Fill(chInfo.at(2));
                        T2Times->Fill(chInfo.at(1));
                        if (chID == T2Chips[1]) T2Profile->Fill(64 + chInfo.at(0));
                        else if (chID == T2Chips[2]) T2Profile->Fill(128 + chInfo.at(0));
                    } else if (chID == T3Chips[1] || chID == T3Chips[2]) {
                        T3Charges->Fill(chInfo.at(2));
                        T3Times->Fill(chInfo.at(1));
                        if (chID == T3Chips[1]) T3Profile->Fill(128 + chInfo.at(0));
                        else if (chID == T3Chips[2]) T3Profile->Fill(64 + chInfo.at(0));
                    } else if (chID == T4Chips[1] || chID == T4Chips[2]) {
                        T4Charges->Fill(chInfo.at(2));
                        T4Times->Fill(chInfo.at(1));
                        if (chID == T4Chips[1]) T4Profile->Fill(64 + chInfo.at(0));
                        else if (chID == T4Chips[2]) T4Profile->Fill(128 + chInfo.at(0));
                    } else if (chID == T5Chips[1] || chID == T5Chips[2]) {
                        T5Charges->Fill(chInfo.at(2));
                        T5Times->Fill(chInfo.at(1));
                        if (chID == T5Chips[1]) T5Profile->Fill(128 + chInfo.at(0));
                        else if (chID == T5Chips[2]) T5Profile->Fill(64 + chInfo.at(0));
                    } else if (chID == T6Chips[1] || chID == T6Chips[2]) {
                        T6Charges->Fill(chInfo.at(2));
                        T6Times->Fill(chInfo.at(1));
                        if (chID == T6Chips[1]) T6Profile->Fill(64 + chInfo.at(0));
                        else if (chID == T6Chips[2]) T6Profile->Fill(128 + chInfo.at(0));
                    } else if (chID == T7Chips[1] || chID == T7Chips[2]) {
                        T7Charges->Fill(chInfo.at(2));
                        T7Times->Fill(chInfo.at(1));
                        if (chID == T7Chips[1]) T7Profile->Fill(128 + chInfo.at(0));
                        else if (chID == T7Chips[2]) T7Profile->Fill(64 + chInfo.at(0));
                    } else if (chID == T8Chips[1] || chID == T8Chips[2]) {
                        T8Charges->Fill(chInfo.at(2));
                        T8Times->Fill(chInfo.at(1));
                        if (chID == T8Chips[1]) T8Profile->Fill(64 + chInfo.at(0));
                        else if (chID == T8Chips[2]) T8Profile->Fill(128 + chInfo.at(0));
                    }
                }
                i = i + 4;
            }
            pdoVariable.push_back(tempPdo);
            tdoVariable.push_back(tempTdo);
            chIdVariable.push_back(tempCh);
            vmm1Calibration->Fill();

            // added by hugh skottowe 20140206
            fileDaqText << "EventNum " << eventNumberVariable;
            {
                timespec ts;
                clock_gettime(CLOCK_REALTIME, &ts);
                fileDaqText << " Sec " << ts.tv_sec << " NS " << ts.tv_nsec;
            }
            fileDaqText << " : txt of vmm1Calibration tree\n";
            for (unsigned i = 0; i < boardVariable.size(); i++) {
                for (unsigned j = 0; j < chIdVariable.at(i).size(); j++) {
                    fileDaqText << boardVariable.at(i) << " "
                            << chIdVariable.at(i).at(j) << " "
                            << pdoVariable.at(i).at(j) << " "
                            << tdoVariable.at(i).at(j) << "\n";
                }
            }
        }
    }
}
//_________________________________________________________________________________________________

void MainWindow::changeDACtoMVs(int value) {
    QString tempstring;
    ui->dacmvLabel->setText(tempstring.number((0.6862 * ui->sdt->value() + 63.478), 'f', 2) + " mV");
}

//_________________________________________________________________________________________________

vector<double> MainWindow::bytesTobits(QByteArray bytes) {
    bool ok;
    quint32 bytesInt = bytes.toHex().toUInt(&ok, 16);
    uint time = (bytesInt & 0x1fff);
    uint amplitude = (bytesInt & 0x3ffe000) >> 13;
    uint channel = (bytesInt & 0xfc000000) >> 26;
    vector<double> chInfo;
    chInfo.clear();
    chInfo.push_back(channel);
    chInfo.push_back(time); //*(3.3/16384.));
    chInfo.push_back(amplitude); //*(3.3/16384.));
    return chInfo;
}
//_________________________________________________________________________________________________

vector<double> MainWindow::bytesTobitsTrigger(QByteArray bytes) {
    bool ok;
    quint32 bytesInt = bytes.toHex().toUInt(&ok, 16);
    uint time2 = (bytesInt & 0xff00) >> 8;
    uint channel2 = (bytesInt & 0x0000003f);
    uint time1 = (bytesInt & 0xff000000) >> 24;
    uint channel1 = (bytesInt & 0x3f0000) >> 16;
    //qDebug()<<"Trigger Data Came : "<<bytes.toHex()<<", ch1:"<<channel1<<", time1:"<<time1<<", ch2:"<<channel2<<", time2:"<<time2;
    vector<double> chInfo;
    chInfo.clear();
    chInfo.push_back(channel1);
    chInfo.push_back(time1);
    chInfo.push_back(channel2);
    chInfo.push_back(time2);
    return chInfo;
}
//_________________________________________________________________________________________________

void MainWindow::initializePlots() {
    T1Profile = new TH1D("T1Profile", "T1 Beam Profile", 256, 0, 256);
    T2Profile = new TH1D("T2Profile", "T2 Beam Profile", 256, 0, 256);
    T3Profile = new TH1D("T3Profile", "T3 Beam Profile", 256, 0, 256);
    T4Profile = new TH1D("T4Profile", "T4 Beam Profile", 256, 0, 256);
    T5Profile = new TH1D("T5Profile", "T5 Beam Profile", 256, 0, 256);
    T6Profile = new TH1D("T6Profile", "T6 Beam Profile", 256, 0, 256);
    T7Profile = new TH1D("T7Profile", "T7 Beam Profile", 256, 0, 256);
    T8Profile = new TH1D("T8Profile", "T8 Beam Profile", 256, 0, 256);

    T1Times = new TH1D("T1Times", "T1 Times", 1000, 0, 5000);
    T2Times = new TH1D("T2Times", "T2 Times", 1000, 0, 5000);
    T3Times = new TH1D("T3Times", "T3 Times", 1000, 0, 5000);
    T4Times = new TH1D("T4Times", "T4 Times", 1000, 0, 5000);
    T5Times = new TH1D("T5Times", "T5 Times", 1000, 0, 5000);
    T6Times = new TH1D("T6Times", "T6 Times", 1000, 0, 5000);
    T7Times = new TH1D("T7Times", "T7 Times", 1000, 0, 5000);
    T8Times = new TH1D("T8Times", "T8 Times", 1000, 0, 5000);

    T1Charges = new TH1D("T1Charges", "T1 Charges", 1000, 0, 5000);
    T2Charges = new TH1D("T2Charges", "T2 Charges", 1000, 0, 5000);
    T3Charges = new TH1D("T3Charges", "T3 Charges", 1000, 0, 5000);
    T4Charges = new TH1D("T4Charges", "T4 Charges", 1000, 0, 5000);
    T5Charges = new TH1D("T5Charges", "T5 Charges", 1000, 0, 5000);
    T6Charges = new TH1D("T6Charges", "T6 Charges", 1000, 0, 5000);
    T7Charges = new TH1D("T7Charges", "T7 Charges", 1000, 0, 5000);
    T8Charges = new TH1D("T8Charges", "T8 Charges", 1000, 0, 5000);

    BoardsHits = new TH1D("BoardsHits", "Boards Hits", 35, 0, 35);
    EventNumber = new TH1D("EventNumber", "Tracking Event Number", 500000, 0, 500000);
    EventNumberTrigger = new TH1D("EventNumberTrigger", "Trigger Event Number", 500000, 0, 500000);
}
//_________________________________________________________________________________________________

void MainWindow::updateCanvas(int) {

    //    Quality->GetCanvas()->Update();
    //    Quality->Refresh();
    //    EventNumber->GetXaxis()->SetRangeUser(EventNumber->FindFirstBinAbove(0),EventNumber->FindLastBinAbove(0));
    //    EventNumberTrigger->GetXaxis()->SetRangeUser(EventNumberTrigger->FindFirstBinAbove(0),EventNumberTrigger->FindLastBinAbove(0));

    //    times->GetCanvas()->Update();
    //    times->Refresh();

    //    charges->GetCanvas()->Update();
    //    charges->Refresh();

    //    profiles->GetCanvas()->Update();
    //    profiles->Refresh();
}

//_________________________________________________________________________________________________

void MainWindow::openMonitoring(int) {
    //    if(ui->monitoring->isChecked()){
    //        threadFill->start();
    //        monitoringTabWidget = new QTabWidget();
    //        profiles = new TQtWidget();
    //        times = new TQtWidget();
    //        charges = new TQtWidget();
    //        Quality = new TQtWidget();
    //        monitoringTabWidget->addTab(profiles,"Beam Profiles");
    //        monitoringTabWidget->addTab(times,"Timing Distributions");
    //        monitoringTabWidget->addTab(charges,"Charge Distributions");
    //        monitoringTabWidget->addTab(Quality,"Quality Plots");

    //        T1Profile->Reset(); T1Times->Reset(); T1Charges->Reset();
    //        T2Profile->Reset(); T2Times->Reset(); T2Charges->Reset();
    //        T3Profile->Reset(); T3Times->Reset(); T3Charges->Reset();
    //        T4Profile->Reset(); T4Times->Reset(); T4Charges->Reset();
    //        T5Profile->Reset(); T5Times->Reset(); T5Charges->Reset();
    //        T6Profile->Reset(); T6Times->Reset(); T6Charges->Reset();
    //        T7Profile->Reset(); T7Times->Reset(); T7Charges->Reset();
    //        T8Profile->Reset(); T8Times->Reset(); T8Charges->Reset();
    //        BoardsHits->Reset(); EventNumber->Reset();EventNumberTrigger->Reset();

    //        profiles->GetCanvas()->Divide(2,4);
    //        profiles->GetCanvas()->cd(1);
    //        T1Profile->Draw();
    //        profiles->GetCanvas()->cd(2);
    //        T2Profile->Draw();
    //        profiles->GetCanvas()->cd(3);
    //        T3Profile->Draw();
    //        profiles->GetCanvas()->cd(4);
    //        T4Profile->Draw();
    //        profiles->GetCanvas()->cd(5);
    //        T5Profile->Draw();
    //        profiles->GetCanvas()->cd(6);
    //        T6Profile->Draw();
    //        profiles->GetCanvas()->cd(7);
    //        T7Profile->Draw();
    //        profiles->GetCanvas()->cd(8);
    //        T8Profile->Draw();

    //        times->GetCanvas()->Divide(2,4);
    //        times->GetCanvas()->cd(1);
    //        T1Times->Draw();
    //        times->GetCanvas()->cd(2);
    //        T2Times->Draw();
    //        times->GetCanvas()->cd(3);
    //        T3Times->Draw();
    //        times->GetCanvas()->cd(4);
    //        T4Times->Draw();
    //        times->GetCanvas()->cd(5);
    //        T5Times->Draw();
    //        times->GetCanvas()->cd(6);
    //        T6Times->Draw();
    //        times->GetCanvas()->cd(7);
    //        T7Times->Draw();
    //        times->GetCanvas()->cd(8);
    //        T8Times->Draw();

    //        charges->GetCanvas()->Divide(2,4);
    //        charges->GetCanvas()->cd(1);
    //        T1Charges->Draw();
    //        charges->GetCanvas()->cd(2);
    //        T2Charges->Draw();
    //        charges->GetCanvas()->cd(3);
    //        T3Charges->Draw();
    //        charges->GetCanvas()->cd(4);
    //        T4Charges->Draw();
    //        charges->GetCanvas()->cd(5);
    //        T5Charges->Draw();
    //        charges->GetCanvas()->cd(6);
    //        T6Charges->Draw();
    //        charges->GetCanvas()->cd(7);
    //        T7Charges->Draw();
    //        charges->GetCanvas()->cd(8);
    //        T8Charges->Draw();

    //        Quality->GetCanvas()->Divide(2,2);
    //        Quality->GetCanvas()->cd(1);
    //        BoardsHits->Draw();
    //        Quality->GetCanvas()->cd(2);
    //        EventNumber->Draw();
    //        Quality->GetCanvas()->cd(4);
    //        EventNumberTrigger->Draw();
    //        monitoringTabWidget->show();
    //    }else{
    //        threadFill->exit(0);
    //        monitoringTabWidget->close();
    //        if(threadFill->isRunning()){
    //            qDebug()<<"Den To Ekleise o aisthimatias";
    //            threadFill->quit();
    //            threadFill->exit(1);
    //        }
    //    }
}

void MainWindow::selectWorkingDirectory() {
    QFileDialog dirDialog;
    dirDialog.setFileMode(QFileDialog::DirectoryOnly);
    dirDialog.exec();
    runDirectory = dirDialog.directory();
    QString temp(runDirectory.path());
    ui->runDirectoryField->setText(temp);
    QStringList filters;
    filters << "run_*.root";
    runDirectory.setNameFilters(filters);
    QFileInfoList listOfFiles = runDirectory.entryInfoList();
    if (listOfFiles.size() != 0) {
        for (int i = 0; i < listOfFiles.size(); i++) {
            QFileInfo fileInfo = listOfFiles.at(i);
            QString temp;
            if ("run_" + temp.number(ui->runNumber->value()) + ".root" == fileInfo.fileName()) {
                ui->runNumber->setValue(ui->runNumber->value() + 1);
            }
        }
    }
}
//------------------------- Load Thresholds -------------------------------------------

void MainWindow::LoadThresholds(int state) {
    if (ui->loadThrCB->isChecked()) {
        if (ui->abovePed->value() == 5) {
            // 5mV
            boardThreshold[1] = 204;
            boardThreshold[2] = 179;
            boardThreshold[3] = 183;
            boardThreshold[4] = 192;
            boardThreshold[5] = 189;
            boardThreshold[6] = 176;
            boardThreshold[7] = 174;
            boardThreshold[8] = 187;
            boardThreshold[9] = 155;
            boardThreshold[10] = 166;
            boardThreshold[11] = 167;
            boardThreshold[12] = 173;
            boardThreshold[13] = 187;
            boardThreshold[14] = 171;
            boardThreshold[15] = 176;
            boardThreshold[16] = 147;
        } else if (ui->abovePed->value() == 10) {
            // 10 mV
            boardThreshold[1] = 212;
            boardThreshold[2] = 187;
            boardThreshold[3] = 190;
            boardThreshold[4] = 200;
            boardThreshold[5] = 196;
            boardThreshold[6] = 183;
            boardThreshold[7] = 181;
            boardThreshold[8] = 194;
            boardThreshold[9] = 162;
            boardThreshold[10] = 174;
            boardThreshold[11] = 174;
            boardThreshold[12] = 180;
            boardThreshold[13] = 196;
            boardThreshold[14] = 178;
            boardThreshold[15] = 183;
            boardThreshold[16] = 155;
        } else if (ui->abovePed->value() == 15) {
            // 15mV
            boardThreshold[1] = 221;
            boardThreshold[2] = 194;
            boardThreshold[3] = 198;
            boardThreshold[4] = 207;
            boardThreshold[5] = 203;
            boardThreshold[6] = 191;
            boardThreshold[7] = 189;
            boardThreshold[8] = 201;
            boardThreshold[9] = 170;
            boardThreshold[10] = 181;
            boardThreshold[11] = 181;
            boardThreshold[12] = 187;
            boardThreshold[13] = 204;
            boardThreshold[14] = 185;
            boardThreshold[15] = 191;
            boardThreshold[16] = 162;
        } else if (ui->abovePed->value() == 20) {
            // 20mV
            boardThreshold[1] = 230;
            boardThreshold[2] = 202;
            boardThreshold[3] = 205;
            boardThreshold[4] = 215;
            boardThreshold[5] = 210;
            boardThreshold[6] = 198;
            boardThreshold[7] = 196;
            boardThreshold[8] = 208;
            boardThreshold[9] = 177;
            boardThreshold[10] = 188;
            boardThreshold[11] = 189;
            boardThreshold[12] = 195;
            boardThreshold[13] = 212;
            boardThreshold[14] = 192;
            boardThreshold[15] = 198;
            boardThreshold[16] = 170;
        } else if (ui->abovePed->value() == 25) {
            // 25mV
            boardThreshold[1] = 237;
            boardThreshold[2] = 209;
            boardThreshold[3] = 213;
            boardThreshold[4] = 223;
            boardThreshold[5] = 217;
            boardThreshold[6] = 206;
            boardThreshold[7] = 204;
            boardThreshold[8] = 216;
            boardThreshold[9] = 184;
            boardThreshold[10] = 195;
            boardThreshold[11] = 196;
            boardThreshold[12] = 202;
            boardThreshold[13] = 220;
            boardThreshold[14] = 199;
            boardThreshold[15] = 205;
            boardThreshold[16] = 177;
        }
    } else {
        for (int i = 0; i <= 19; i++) {
            boardThreshold[i] = 220;
        }
        ui->sdt->setValue(220);
    }
}

// method that runs a calibration run for given parameters of time (ns), gain (mV/fC)
void MainWindow::doCalibrationRun(int t, int g) {
    // set the value of gain using implicit values in combo box (0 -> 0.5, 1 -> 1.0, 2 -> 3.0, 3 -> 9.0 (mV/fC))
    ui->sg->setCurrentIndex(g);
    // must check if this is the only thing we must do to set gain

    // reset boardEvents (?)
    for (int j = 1; j <= 16; j++) {
        boardEvents[j] = 0;
    }

    // calibrate on various pulser DAC values (controls total pulse charge)
    for (int p = 250; p <= 400; p += 50) {
        // set pulse total charge
        ui->sdp_2->setValue(p);

        // calibrate all channels
        for (int ch = 0; ch < 64; ch++) {
            // reset checkbox values
            for (int box = 0; box < 64; box++) {
                VMM1ST[chT]->setStyleSheet("background-color: gray");
                VMM1STBool[chT] = 0;
                VMM1STBoolAll = 0;
                VMM1STBoolAll2 = 0;
            }
        }

        // reset electronics
        emit ui->cdaq_reset->click();
        delay();

        // set header (on packets???)
        emit ui->setHeaderPB->click();
        delay();
        emit ui->setHeaderPB->click();
        delay();

        // switch off neighbors to reduce electrical interference
        ui->sng->setCurrentIndex(0);

        // set electronics configuration
        emit ui->SendConfiguration->click();
        delay();
        emit ui->SendConfiguration->click();
        delay();

        // ???
        qDebug() << "Applying Sampling";
        ui->sampleValue->setCurrentIndex(2);
        emit ui->sampleSetPB->click();
        delay();

        // ???
        qDebug() << "Enabling DAC";
        ui->daqModeOutput->setCurrentIndex(1);
        emit ui->setDaqMode->click(); // DAC or DAQ? dac is digital-to-analog converter; DAQ is data acquisition.
        delay();
        emit ui->onACQ->click();

        // set timing (length of timer sawtooth)
        ui->detectionTime->setValue(t * 25 + 50); // t is hardcoded
        ui->detectionMode->setCurrentIndex(1);
        ui->edgeSelection->setCurrentIndex(0);
        delay();

        // ???
        qDebug() << "Apply detection Mode, trigger & ACQ";
        emit ui->applyDetectionMode->click();

        // select number of events to gather for calibration
        int eventsForCalibration = 100;
        delay();

        // ???
        QString commandsSentStartPointStr = ui->cmdlabel->text();

        // get data
        ui->startDi->click();

        // stop calibration condition what is??
        if (ui->stopTriggerCnt == QObject::sender())
            break;
        // reset boardEvents again (?))
        for (int b = 1; b <= 16; b++) boardEvents[b] = 0;

        // not sure what this piece of code does but included just in case
        while (ui->calibration->isChecked()) { // evidently you can kill the calibration routine at any time by unchecking
            bool stop = 10;
            for (int b = 1; b <= ui->numbersOfFecs->value(); b++) { // what's a fec
                if (boardEvents[b] < eventsForCalibration) {
                    QString currStr = ui->cmdlabel->text();
                    // condition: "stop entering"? correlate with the inappropriate greek below
                    if (currStr.toInt(&ok, 10) - commandsSentStartPointStr.toInt(&ok, 10) > eventsForCalibration) {//(ui->setVMMs->currentIndex()-1)*eventsForCalibration){
                        qDebug() << "Mpike na to Stamatisei"; // GREEK IS NOT OKAY
                        // for the record this is "μπηκε να το σταματησει" -> "BIKE to stop" but apparently mpike is enter so stop entering
                        emit ui->stopDi->click(); // stop pulsing
                        delay();
                        emit ui->cdaq_reset->click();
                        delay();
                        stop = 1; // I guess we're stopping then (this results in an outer loop break)
                        break;
                    } else {
                        delay();
                        stop = 0;
                    }
                } else if (boardEvents[b] >= eventsForCalibration) {
                    qDebug() << "Ta mazepse"; // GREEK IS NOT OKAY
                    emit ui->stopDi->click();
                    delay();
                    emit ui->cdaq_reset->click();
                    delay();
                    stop = 1;
                    break;
                }
            }

            if (stop) break;
            qDebug() << "Waiting for Event Collecting";
            if (ui->stopTriggerCnt == QObject::sender())
                break;
        }
    }
}

//------------------------- Calibration Procedure -------------------------------------------

void MainWindow::startCalibration() {
    void delay(); // wait 200 milliseconds
    bool ok;
    if (ui->calibration->isChecked()) {
        if (ui->gain->isChecked()) { // assuming we have gain and time checkboxes
            for (int g = 0; g < 3; g++) {
                doCalibrationRun(2, g); // 2 for now, pick better value later??
            }
        } else if (ui->time->isChecked()) {
            for (int t = 2; t < 13; t += 2) {
                doCalibrationRun(t, 0); // 0 for now, pick better value later??
            }
        }
    }

    // calibration complete!
    emit ui->stopTriggerCnt->click();
}

//--------------------------------------------------------------------

void delay() {
    QTime dieTime = QTime::currentTime().addMSecs(200); //.addSecs(1);

    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
//--------------------------------------------------------------------

void delayMs() {
    QTime dieTime = QTime::currentTime().addMSecs(10);

    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
//--------------------------------------------------------------------

void MainWindow::loadCalibrationConstants(int) {
    bool ok;
    if (ui->loadCalibDataCB->isChecked()) {
        QFile file(":/boardCalibConstants_qt.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString line = in.readLine();
            QVector<int> temp;
            QStringList list = line.split(",");
            for (int i = 1; i < 18; i++) {
                temp.clear();
                for (int j = 0; j < 64; j++) {
                    temp.push_back(list.at((j * 17) + i).toInt(&ok, 10));
                }
                calibConstants.push_back(temp);
            }
        }
        //        for(int i=0;i<calibConstants.size();i++){
        //            for(int j=0;j<calibConstants[i].size();j++){
        //                qDebug()<<"board:"<<i<<", channel:"<<j<<", trim:"<<calibConstants[i][j];
        //            }
        //        }
        qDebug() << "Calibration File Loaded";
    } else {
        qDebug() << "Reset Trims Done";
        calibConstants.clear();
        emit SDLabel->setCurrentIndex(0);
        emit SDLabel2->setCurrentIndex(0);
        for (int i = 0; i < 64; i++) emit VMM1SDVoltage[i]->setCurrentIndex(0);
    }
}
