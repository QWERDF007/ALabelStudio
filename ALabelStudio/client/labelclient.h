#ifndef LABELCLIENT_H
#define LABELCLIENT_H

#include <QMainWindow>
#include "labelwindow.h"


namespace Ui {
    class LabelClient;
}


namespace ALabelStudio {

/**
 * @brief 用于承载具体标注窗口的主窗口，隐藏菜单栏和状态栏，
 * 使用标注窗口的，标注窗口才是实现操作的实体。
 */
class LabelClient : public QMainWindow
{
    Q_OBJECT

public:
    LabelClient(QWidget *parent = nullptr);
    ~LabelClient();

private:
    Ui::LabelClient *ui;
    QLayout *main_layout_ = nullptr;
    LabelType cur_label_type;

    void setLabelWindow(LabelWindow *label_window);

private slots:
    /**
     * @brief 任务切换，清空当前主窗口的所有部件，然后创建新的标注窗口。
     * 若切换前后 label_type 一致则不做处理。
     * @param label_type 标注类型
     */
    void onTaskChanged(ALabelStudio::LabelType label_type);
};

} // namespace ALabelStudio

#endif // LABELCLIENT_H
