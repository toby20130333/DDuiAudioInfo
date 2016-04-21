## DDuiAudioTags Powered Qt Module

TagLib Audio Meta-Data Library
TagLib is a library for reading and editing the meta-data of several popular audio formats. Currently it supports both ID3v1 and ID3v2 for MP3 files, Ogg Vorbis comments and ID3 tags and Vorbis comments in FLAC, MPC, Speex, WavPack TrueAudio, WAV, AIFF, MP4 and ASF files.

TagLib is distributed under the GNU Lesser General Public License (LGPL) and Mozilla Public License (MPL). Essentially that means that it may be used in proprietary applications, but if changes are made to TagLib they must be contributed back to the project. Please review the licenses if you are considering using TagLib in your project.

There is some general information about the motivation and workings of TagLib that can be found in the API documentation.

```
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
```

This project aims at bringing the power of audio inforamtion to Qt application.


# Summary
* [How to build](#how-to-build)
* [How to use with DDuiTaglib](#how-to-use-with-qml-plugins)
* [How to extend](#how-to-extend)
* [Todo](#todo)

## How to Build
#### Add the [Taglib](https://taglib.github.io/) source code  to your local machine on Mac Windows Linux.
#### Make Sure Setting your env for make and cmake
#### Use Command

```
open qtcreator
open cmakelist.txt with qtcreator
run  cmake
make clean(mingw32-make clean)
make （mingw32-make mingw) | nmake(vc)
sudo make install (*unix)
```
## Use QtCreator
You may use qtcreator to build it.


## How to use with DDuiTaglib
Note that for the following, you need to have `Qt SDK` for Qt5.x or later installed.

#### DDuiTaglib
You can use DDuiTaglibto show your audio info on UI.

```
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibtag
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibtag

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
```

## FeedBack

Contact information

- Email(373955953#qq.com, Change#to@)
- QQ: 39559539234
- QQ Group:312125701
- github: [寒山-居士](https://github.com/toby20130333)


## Thanks

[Qt for taglib](http://stackoverflow.com/questions/22393287/qt-multimedia-how-to-force-read-tags-from-media-file)

## About Author

```
  var duoduozhijiao = {
    nickName  : "寒山-居士",
    site : "http://www.heilqt.com",
    blog : "http://blog.heilqt.com"
  }
  ```
