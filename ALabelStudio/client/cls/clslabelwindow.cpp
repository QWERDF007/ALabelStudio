#include <QStringLiteral>
#include <QStatusBar>
#include <QAction>
#include <QFileDialog>
#include <QFileInfo>
#include "spdlog/spdlog.h"
#include "clslabelwindow.h"
#include "ui_clslabelwindow.h"

namespace ALabelStudio {
namespace cls {

ClsLabelWindow::ClsLabelWindow(QWidget *parent) :
    LabelWindow(parent),
    ui(new Ui::ClsLabelWindow), scene_(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene_);
    initMeanBar();
    setWindowTitle(QStringLiteral("图像分类标注"));
    statusBar()->showMessage(QStringLiteral("欢迎使用图像分类标注工具"), 500);
//    QListWidget
    connect(ui->files_list, &QListWidget::currentItemChanged, this, &ClsLabelWindow::onFileListCurrentItemChanged);
    connect(ui->files_list, &QListWidget::itemSelectionChanged, this, &ClsLabelWindow::onFileListItemSelectionChanged);
}

ClsLabelWindow::~ClsLabelWindow()
{
    delete ui;
    SPDLOG_DEBUG("~ClsLabelWindow");
}

LabelType ClsLabelWindow::labelType()
{
    return LabelType::cls;
}


void ClsLabelWindow::initMeanBar()
{
    menuBar()->insertMenu(ui->menu_file->menuAction(), taskMenu());
    menuBar()->addMenu(helpMenu());
    connect(ui->action_open_file, &QAction::triggered, this, &ClsLabelWindow::onOpenFileTrigged);
}

void ClsLabelWindow::onOpenFileTrigged(bool)
{
    auto selected_file =  QFileDialog::getOpenFileName(
                this, QStringLiteral("选择文件"), QString(), QStringLiteral("Images (*.png *.jpg)"));
    if (!selected_file.isEmpty()) {
        QFileInfo file_info(selected_file);
        auto base_name = file_info.baseName();
        if (!fpaths_.contains(base_name)) {
            ui->files_list->addItem(base_name);
            fpaths_[base_name] = file_info.filePath();
        }
    }
    SPDLOG_DEBUG(selected_file.toStdString());
//    ui->graphicsView->scene()->addPixmap(QPixmap(selected_file));
}

void ClsLabelWindow::onOpenFolderTrigged(bool)
{

}

void ClsLabelWindow::onFileListCurrentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    SPDLOG_DEBUG("{} cur: {} prev: {}", current->text().toStdString(), (void*)current, (void*)previous);
    if (current && current != previous) {
        auto base_name = current->text();
        ui->graphicsView->scene()->addPixmap(QPixmap(fpaths_[base_name]));
        ui->graphicsView->update();
    }
}

void ClsLabelWindow::onFileListItemSelectionChanged()
{
//    auto selected_item = ui->files_list->selected
    SPDLOG_DEBUG("onFileListItemSelectionChanged");
}


} // namespace cls
} // namespace ALabelStudio
