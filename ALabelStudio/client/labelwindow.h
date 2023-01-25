#ifndef LABELWINDOW_H
#define LABELWINDOW_H

#include <QMainWindow>
#include <QString>

namespace ALabelStudio {

enum class LabelType {
    cls = 0,
    det,
    seg,
};

class LabelWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit LabelWindow(QWidget *parent = nullptr);

    virtual ~LabelWindow();

    virtual LabelType labelType() = 0;

    virtual void about();

    void setTaskChecked(LabelType label_type);

signals:
    void taskChanged(ALabelStudio::LabelType label_type);

protected:
    QMenu* taskMenu();

    QMenu* helpMenu();

private:
    QAction *cls_task_{nullptr};

    QAction *det_task_{nullptr};

    QAction *seg_task_{nullptr};

    void setTaskChecked(QAction *task);
};

} // namespace ALabelStudio

#endif // LABELWINDOW_H
