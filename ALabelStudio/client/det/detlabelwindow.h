#ifndef DETLABELWINDOW_H
#define DETLABELWINDOW_H

#include <QMainWindow>
#include "../labelwindow.h"

namespace Ui {
class DetLabelWindow;
}

namespace ALabelStudio {
namespace det {

class DetLabelWindow : public LabelWindow
{
    Q_OBJECT

public:
    explicit DetLabelWindow(QWidget *parent = nullptr);

    ~DetLabelWindow();

    virtual LabelType labelType() override;

private:
    Ui::DetLabelWindow *ui;
};

} // namespace det
} // namespace ALabelStudio

#endif // DETLABELWINDOW_H
