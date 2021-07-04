#ifndef FEEEDITORWIDGET_H
#define FEEEDITORWIDGET_H

#include <QWidget>

namespace Ui {
class FeeEditorWidget;
}

class FeeEditorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FeeEditorWidget(QWidget *parent = nullptr);
    ~FeeEditorWidget();

private:
    Ui::FeeEditorWidget *ui;
};

#endif // FEEEDITORWIDGET_H
