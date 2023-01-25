QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = ALabelStudio

# 库版本号，大版本升级 MAJ，小版本升级 MIN，补丁 PAT
VERSION_MAJ = 0
VERSION_MIN = 0
VERSION_PAT = 1

S = .
VERSION = $$VERSION_MAJ$$S$$VERSION_MIN$$S$$VERSION_PAT$$

DEFINES += ALABELSTUDIO_VERSION=\\\"$$VERSION\\\"


#message('ALabelStudio Version: $${VERSION}')


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutdialog.cpp \
    labelclient.cpp \
    labelwindow.cpp \
    labeluser.cpp \
    logindialog.cpp \
    main.cpp \
    cls\clslabelwindow.cpp \
    det\detlabelwindow.cpp

HEADERS += \
    aboutdialog.h \
    labelclient.h \
    labelwindow.h \
    labeluser.h \
    logindialog.h \
    cls\clslabelwindow.h \
    det\detlabelwindow.h

FORMS += \
    aboutdialog.ui \
    labelclient.ui \
    logindialog.ui \
    cls\clslabelwindow.ui \
    det\detlabelwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += \
    $$PWD/../utils \
    $$PWD/../widgets

win32 {

QMAKE_CXXFLAGS += /utf-8
QMAKE_CFLAGS   += /utf-8

## 屏蔽宏 MIN/MAX，避免和 std::max/min 编译冲突
#DEFINES += NOMINMAX

win32-msvc {

    CONFIG(release, debug|release) {
        LIBS += \
            -L$$PWD/../build/windows/ \
            -lwidgets
    }

    CONFIG(debug, debug|release) {
        LIBS += \
            -L$$PWD/../build/windows/ \
            -lwidgetsd
    }


} # msvc
} # win32


RC_ICONS = ../icons/logo.ico

RESOURCES += \
    ../icons/icons.qrc

include($$PWD/../third_party/third_party.pri)
