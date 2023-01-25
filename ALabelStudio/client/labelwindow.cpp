#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QMessageBox>
#include "spdlog/spdlog.h"
#include "labelwindow.h"
#include "aboutdialog.h"


namespace ALabelStudio {

LabelWindow::LabelWindow(QWidget *parent)
    : QMainWindow{parent}
{

}

LabelWindow::~LabelWindow()
{
    SPDLOG_DEBUG("~LabelWindow");
}

void LabelWindow::about()
{
    // TODO 实现 about 对话框
    AboutDialog *dialog = new AboutDialog(this);
    // 阻塞模式
    dialog->exec();
    dialog->deleteLater();
}

void LabelWindow::setTaskChecked(LabelType label_type)
{
    switch (label_type) {
    case LabelType::cls:
        setTaskChecked(cls_task_);
        break;
    case LabelType::det:
        setTaskChecked(det_task_);
        break;
    case LabelType::seg:
        setTaskChecked(seg_task_);
        break;
    default:
        break;
    }
}

QMenu *LabelWindow::taskMenu()
{
    QMenu *tasks = new QMenu(QStringLiteral("任务"), this);

    cls_task_ = new QAction(QStringLiteral("图像分类"), tasks);
    det_task_ = new QAction(QStringLiteral("目标检测"), tasks);
    seg_task_ = new QAction(QStringLiteral("语义分割"), tasks);
    cls_task_->setCheckable(true);
    det_task_->setCheckable(true);
    seg_task_->setCheckable(true);

    tasks->addAction(cls_task_);
    tasks->addAction(det_task_);
    tasks->addAction(seg_task_);

    connect(cls_task_, &QAction::toggled, this, [&](bool) {
        emit taskChanged(LabelType::cls);
    });
    connect(det_task_, &QAction::toggled, this, [&](bool) {
        emit taskChanged(LabelType::det);
    });
    connect(seg_task_, &QAction::toggled, this, [&](bool) {
        emit taskChanged(LabelType::seg);
    });

    return tasks;
}

QMenu *LabelWindow::helpMenu()
{
    QMenu *help_menu = new QMenu(QStringLiteral("帮助"), this);
    QAction *about_action = new QAction(QStringLiteral("关于"), help_menu);
    help_menu->addAction(about_action);

    connect(about_action, &QAction::triggered, this, [&](bool){
        about();
    });

    return help_menu;
}

void LabelWindow::setTaskChecked(QAction *task)
{
    if (task) {
        task->setChecked(true);
        task->setEnabled(false);
    }
}

} // namespace ALabelStudio
