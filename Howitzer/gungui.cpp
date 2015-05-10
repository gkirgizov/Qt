#include "gungui.h"
#include "ui_gungui.h"

#include <QResizeEvent>

GunGui::GunGui(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GunGui),
	core(this),
	viewSceneWidthDifference(18),
	viewSceneHeightDifference(76),
	sceneRectMargin(7)
{
	ui->setupUi(this);
	ui->graphicsView->setScene(&core.scene);
	const qreal viewWidth(this->size().width() - viewSceneWidthDifference);
	const qreal viewHeight(this->size().height() - viewSceneHeightDifference);
	this->redraw(viewWidth, viewHeight, sceneRectMargin);
}

GunGui::~GunGui()
{
	delete ui;
}

void GunGui::resizeEvent(QResizeEvent *resize)
{
	const qreal viewWidth = resize->size().width() - viewSceneWidthDifference;
	const qreal viewHeight = resize->size().height() - viewSceneHeightDifference;
	this->redraw(viewWidth, viewHeight, sceneRectMargin);
}

void GunGui::redraw(qreal width, qreal height, qreal margin)
{
	//this->ui->graphicsView->viewport()->update();
	QRectF sceneRect(0, 0, width - margin, height - margin);
	this->core.redraw(sceneRect);
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
