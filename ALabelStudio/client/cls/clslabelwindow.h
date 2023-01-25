#ifndef CLSLABELWINDOW_H
#define CLSLABELWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QListWidgetItem>
#include <QMap>

#include "../labelwindow.h"

namespace Ui {
class ClsLabelWindow;
}

namespace ALabelStudio {
namespace cls {

class ClsLabelWindow : public LabelWindow
{
    Q_OBJECT

public:
    explicit ClsLabelWindow(QWidget *parent = nullptr);

    ~ClsLabelWindow();

    virtual LabelType labelType() override;

private:
    Ui::ClsLabelWindow *ui;

    QGraphicsScene *scene_{nullptr};

    QMap<QString, QString> fpaths_;

    void initMeanBar();

private slots:
    void onOpenFileTrigged(bool);

    void onOpenFolderTrigged(bool);

    void onFileListCurrentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void onFileListItemSelectionChanged();
};

} // namespace cls
} // namespace ALabelStudio

#endif // CLSLABELWINDOW_H
