#include <QApplication>
#include <QDebug>
#include "spdlog/spdlog.h"
#include "labelclient.h"

void initLogger()
{

    /*
     * 格式：日期 时间 [等级] 消息
     * 示例:
     * 2023-01-24 21:03:26 [I] Welcome to ALabelStudio!
     */
    spdlog::set_pattern("%Y-%m-%d %T %@ [%^%L%$] %v");
    spdlog::set_level(spdlog::level::debug);
}

int main(int argc, char *argv[])
{
    initLogger();

    QApplication a(argc, argv);
    spdlog::info("Welcome to {} {}!", a.applicationName().toStdString(), a.applicationVersion().toStdString());
    ALabelStudio::LabelClient client;
    client.show();

    return a.exec();
}
