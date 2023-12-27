#include "ChatWindows.h"
#include "ui_Chatwindows.h"
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include <QColorDialog>
#include <QFileDialog>

ChatWindows::ChatWindows(QWidget *parent,QString userName) :
    QWidget(parent),
    ui(new Ui::ChatWindows)
{
    ui->setupUi(this);
    mChatUserName = userName;
    mPort = 9999;
    mpUdpSocket = new QUdpSocket(this);

    mpUdpSocket->bind(mPort,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    sendMsg(UserEnter);
    initConnect();
}

void ChatWindows::initUi(void){
}

void ChatWindows::initConnect(void){
    connect(ui->btnSend,&QPushButton::clicked,this,&ChatWindows::slotSendMsg);
    connect(mpUdpSocket,&QUdpSocket::readyRead,this,&ChatWindows::slotReceiveMsg);
    connect(ui->btnExit,&QPushButton::clicked,this,&ChatWindows::slotExitWnd);

    connect(ui->fontTypeBox,&QFontComboBox::currentFontChanged,this,&ChatWindows::slotSetFontType);
    connect(ui->fontSizeBox,QOverload<const QString &>::of(&QFontComboBox::currentTextChanged),
            this,&ChatWindows::slotSetFontSize);
    connect(ui->btnBold,&QToolButton::clicked,this,&ChatWindows::slotSetFontBold);
    connect(ui->btnItalic,&QToolButton::clicked,this,&ChatWindows::slotSetFontItalic);
    connect(ui->btnUnderline,&QToolButton::clicked,this,&ChatWindows::slotSetFontUnderLine);
    connect(ui->btnColor,&QToolButton::clicked,this,&ChatWindows::slotSetFontColor);
    connect(ui->btnSave,&QToolButton::clicked,this,&ChatWindows::slotSetTextSave);
    connect(ui->btnClear,&QToolButton::clicked,this,&ChatWindows::slotSetFontClear);
}

void ChatWindows::slotSetFontType(const QFont &font){
    ui->textEdit->setFontFamily(font.toString());
    ui->textEdit->setFocus();
}

void ChatWindows::slotSetFontSize(const QString &text){
    ui->textEdit->setFontPointSize(text.toDouble());
    ui->textEdit->setFocus();
}

void ChatWindows::slotSetFontBold(bool checked){
    if(checked) {
        ui->textEdit->setFontWeight(QFont::Bold);
    } else {
        ui->textEdit->setFontWeight(QFont::Normal);
    }
}

void ChatWindows::slotSetFontItalic(bool checked){
    ui->textEdit->setFontItalic(checked);
    ui->textEdit->setFocus();
}

void ChatWindows::slotSetFontUnderLine(bool checked){
    ui->textEdit->setFontUnderline(checked);
    ui->textEdit->setFocus();
}

void ChatWindows::slotSetFontColor(void){
    QColor color = QColorDialog::getColor(color,this);
    ui->textEdit->setTextColor(color);
}

void ChatWindows::slotSetTextSave(void){
    if(ui->textBrowser->toPlainText().isEmpty()) {
        QMessageBox::warning(this,"警告","警告！保存内容不能为空!");
        return;
    }
    QString filename= QFileDialog::getSaveFileName(this,"保存聊天记录","聊天记录","(*.txt)");
    if(!filename.isEmpty())
    {
        QFile file(filename);
        file.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream stream(&file);
        stream<< ui->textBrowser->toPlainText();
        file.close();
    }
}

void ChatWindows::slotSetFontClear(void){
    ui->textEdit->clear();
}

void ChatWindows::sendMsg(ChatWindows::MsgType type){
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    stream << type << mChatUserName;
    QString nowMsg;
    switch(type){
    case Msg:
        if(ui->textEdit->toPlainText() == ""){
            QMessageBox::warning(this,"警告","发送的聊天内容不能为空!");
            return;
        }
        nowMsg = this->getMsg();
        qDebug() << nowMsg;
        stream << nowMsg;
        break;
    case UserEnter:
        break;
    case UserLeft:
        break;
    }
    mpUdpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,mPort);
}

QString ChatWindows::getMsg(void){
    QString msgHtml = ui->textEdit->toHtml();
    QString msgText = ui->textEdit->toPlainText();
    ui->textEdit->clear();
    ui->textEdit->setFocus();
    return msgHtml;
}

void ChatWindows::userEnterAction(QString username){
    bool isEmpty = ui->tableWidget->findItems(username,Qt::MatchExactly).isEmpty();

    if(isEmpty){
        QTableWidgetItem *table = new QTableWidgetItem(username);
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,table);

        ui->textBrowser->setTextColor(QColor(Qt::gray));
        ui->textBrowser->append(QString("%1已上线").arg(username));
        ui->labelUserNum->setText(QString("在线人数:%1").arg(ui->tableWidget->rowCount()));
        sendMsg(UserEnter);
    }
}

void ChatWindows::userLeftAction(QString username,QString time){
    bool IsEmpty=ui->tableWidget->findItems(username,Qt::MatchExactly).isEmpty();
    if(!IsEmpty){
        int row = ui->tableWidget->findItems(username,Qt::MatchExactly).first()->row();
        ui->tableWidget->removeRow(row);

        ui->textBrowser->append(QString("%1用户于%2离开").arg(username).arg(time));

        ui->labelUserNum->setText(QString("在线人数:%1").arg(ui->tableWidget->rowCount()));
    }
}

void ChatWindows::slotReceiveMsg(void){
    qint64 qSize = mpUdpSocket->pendingDatagramSize();
    int size = static_cast<int>(qSize);
    QByteArray *array = new QByteArray(size,0);
    mpUdpSocket->readDatagram((*array).data(), qSize);
    QDataStream stream(array, QIODevice::ReadOnly);
    int type;
    QString name, msg;
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh::mm::ss");
    stream >> type;
    switch (type) {
    case Msg:
        stream >> name >> msg;
        ui->textBrowser->setTextColor(QColor(Qt::blue));
        ui->textBrowser->append(QString("[%1]%2").arg(name).arg(time));
        ui->textBrowser->append(msg);
        break;
    case UserLeft:
        stream >> name;
        userLeftAction(name, time);
        break;
    case UserEnter:
        stream >> name;
        userEnterAction(name);
        break;
    }
}

void ChatWindows::slotSendMsg(void){
    sendMsg(MsgType::Msg);
}

void ChatWindows::closeWnd(void){
    sendMsg(UserLeft);
    if(mpUdpSocket != nullptr){
        mpUdpSocket->close();
        mpUdpSocket->destroyed();
    }
}

void ChatWindows::slotExitWnd(void){
    this->close();
    closeWnd();
}

void ChatWindows::closeEvent(QCloseEvent *event){
    emit this->sigCloseChatWnd();
    closeWnd();
    QWidget::closeEvent(event);
}

ChatWindows::~ChatWindows()
{
    delete ui;
}
