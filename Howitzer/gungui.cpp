#include "gungui.h"
#include "ui_gungui.h"

GunGui::GunGui(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GunGui),
	core(this)
{
	ui->setupUi(this);
	this->redraw(ui->graphicsView->width(), ui->graphicsView->height());
}

GunGui::~GunGui()
{
	delete ui;
}

void GunGui::redraw(qreal width, qreal height, qreal margin)
{
	QRectF sceneRect(0, 0, width - margin, height - margin);
	ui->graphicsView->setSceneRect(sceneRect);
	this->core.redraw(sceneRect);
	ui->graphicsView->setScene(&core.scene);
}

void GunGui::on_angleHSlider_valueChanged(int value)
{
	core.changeAngle(value);
}

void GunGui::on_forceHSlider_valueChanged(int value)
{
	core.changeStartSpeed(value);
}

void GunGui::on_fireButton_clicked()
{
	ui->scoresLineEdit->setText("0");
	ui->scoresLineEdit->setText(QString::number(core.doFire()));
}
