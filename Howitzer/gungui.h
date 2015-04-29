#pragma once

#include <QWidget>

#include "guncore.h"

namespace Ui {
	class GunGui;
}

class GunGui : public QWidget
{
	Q_OBJECT

public:
	explicit GunGui(QWidget *parent = 0);
	~GunGui();

private slots:
	void on_angleHSlider_valueChanged(int value);

	void on_forceHSlider_valueChanged(int value);

	void on_fireButton_clicked();

	void redraw(qreal width, qreal height, qreal margin = 7);

private:
	Ui::GunGui *ui;

	GunCore core;

};
