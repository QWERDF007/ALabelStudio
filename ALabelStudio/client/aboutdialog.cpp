#include <QCoreApplication>
#include <QPushButton>
#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "spdlog/spdlog.h"

namespace ALabelStudio {

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    setWindowTitle(QString("关于%1").arg(QCoreApplication::applicationName()));
    ui->app_name_version->setText(QString("%1  %2").arg(
                                      QCoreApplication::applicationName(),
                                      QCoreApplication::applicationVersion()));
    ui->app_brief->setText(brief());
    connect(ui->close_button, &QPushButton::clicked, this, [&](){
       this->close();
    });
}

AboutDialog::~AboutDialog()
{
    delete ui;
    SPDLOG_DEBUG("");
}

QString AboutDialog::brief() const
{
    return QStringLiteral("一个标注工具");
}

} // namespace ALabelStudio
