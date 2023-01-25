#include "spdlog/spdlog.h"
#include "detlabelwindow.h"
#include "ui_detlabelwindow.h"

namespace ALabelStudio {
namespace det {

DetLabelWindow::DetLabelWindow(QWidget *parent) :
    LabelWindow(parent),
    ui(new Ui::DetLabelWindow)
{
    ui->setupUi(this);
    setWindowTitle(QStringLiteral("检测标注"));
    menuBar()->insertMenu(ui->menu_file->menuAction(), taskMenu());
    menuBar()->addMenu(helpMenu());
    setWindowTitle(QStringLiteral("目标检测标注"));
    statusBar()->showMessage(QStringLiteral("欢迎使用目标检测标注工具"), 500);
}

DetLabelWindow::~DetLabelWindow()
{
    delete ui;
    SPDLOG_DEBUG("~DetLabelWindow");
}

LabelType DetLabelWindow::labelType()
{
    return LabelType::det;
}

} // namespace det
} // namespace ALabelStudio
