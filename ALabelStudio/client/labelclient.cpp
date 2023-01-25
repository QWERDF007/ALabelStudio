#include <QGridLayout>
#include "labelclient.h"
#include "ui_labelclient.h"
#include "cls/clslabelwindow.h"
#include "det/detlabelwindow.h"
#include "spdlog/spdlog.h"

namespace ALabelStudio {

LabelClient::LabelClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LabelClient)
{
    ui->setupUi(this);
    // TODO 用户登录，鉴权
    LabelWindow *label_window = new cls::ClsLabelWindow(this);
    main_layout_ = new QGridLayout(nullptr);
    main_layout_->setContentsMargins(0,0,0,0);
    centralWidget()->setLayout(main_layout_);
    setLabelWindow(label_window);
    menuBar()->hide();
    statusBar()->hide();
}

LabelClient::~LabelClient()
{
    delete ui;
}

void LabelClient::setLabelWindow(LabelWindow *label_window)
{
    if (label_window) {
        cur_label_type = label_window->labelType();
        label_window->setTaskChecked(cur_label_type);
        main_layout_->addWidget(label_window);
        setWindowTitle(label_window->windowTitle());
        resize(label_window->size());
        connect(label_window, &LabelWindow::taskChanged, this, &LabelClient::onTaskChanged);
    }
}

void LabelClient::onTaskChanged(LabelType label_type)
{
    SPDLOG_DEBUG("sender: {}, {}", sender()->metaObject()->className(), (void*)sender());
    if (label_type == cur_label_type) {
        return;
    }

    LabelWindow *label_window = nullptr;
    switch (label_type) {
    case LabelType::cls:
        label_window = new cls::ClsLabelWindow(this);
        break;
    case LabelType::det:
        label_window = new det::DetLabelWindow(this);
        break;
    default:
        break;
    }

    if (label_window) {
        int widgets_count = main_layout_->count();
        for (int i = 0; i < widgets_count; ++i) {
            QWidget *widget = main_layout_->itemAt(i)->widget();
            main_layout_->removeWidget(widget);
            widget->setParent(nullptr);
            widget->deleteLater();
        }

    }

    setLabelWindow(label_window);
}

} // namespace ALabelStudio
