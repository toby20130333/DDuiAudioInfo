#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <taglib/fileref.h>
#include <taglib/tag.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
///
/// \brief Widget::gettags
/// \param mediafile
/// \return
/// 获取mp3的信息
///  以下只是获取了部分信息
/// 你可以参考FileRef这个类把想要拿到的数据都可以取出来
/// mediafile为mp3文件的路径
QString Widget::gettags(QString mediafile){
    QString string;
    TagLib::FileRef file(mediafile.toUtf8().data());
    TagLib::String title_string = file.tag()->title();
    TagLib::String album_string = file.tag()->album();
    QString title = QString::fromStdWString(title_string.toWString());
    QString  album = QString::fromStdWString(album_string.toWString());
    QString artist = QString::fromStdWString(file.tag()->artist().toWString());
    QString comment = QString::fromStdWString(file.tag()->comment().toWString());
    QString genre = QString::fromStdWString(file.tag()->artist().toWString());
    QString year = QString::number(file.tag()->year());
    string = "标题: " + title+"\n唱片集:"+album + " \n艺术家:" + artist+"\n注释:"+comment+ " \n流派: " + genre+"\n年份: "+year;
    QString lengths = QString::number(file.audioProperties()->bitrate());
    string.append("\n比特率: ");
    string.append(lengths);
    string.append("kbps");
    return string;
}

void Widget::on_pushButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,
               tr("Open MP3/WAV file"), ".", "Mp3 (*.mp3);;WAV (*.wav)");
    if(file.isEmpty())return;
    ui->textBrowser->append(gettags(file));
}
