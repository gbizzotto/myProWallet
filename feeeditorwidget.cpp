#include "feeeditorwidget.h"
#include "ui_feeeditorwidget.h"

FeeEditorWidget::FeeEditorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FeeEditorWidget)
{
    ui->setupUi(this);
}

FeeEditorWidget::~FeeEditorWidget()
{
    delete ui;
}
