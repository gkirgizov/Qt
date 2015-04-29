#pragma once

#include <QGraphicsScene>
#include <QPoint>

#include "gungraphicsitem.h"
#include "targetgraphicsitem.h"

class GunCore : public QObject
{
	Q_OBJECT

public:
	GunCore(QObject *parent = 0);

	GunCore(const QRectF &sizeRect, QObject *parent = 0);

	~GunCore();

	int doFire();

	void changeAngle(int value);

	void changeStartSpeed(int value);

	void outputResult(const QString &info);

	void redraw(const QRectF &sizeRect, qreal gunWidth = 70, qreal gunHeight = 30);

	QGraphicsScene scene;

private:
	GunGraphicsItem *gun = nullptr;
	TargetGraphicsItem *target = nullptr;

	int angle;
	int speed;

	qreal f(qreal x, qreal g = 9.81);
	qreal f_(qreal x, qreal g, qreal sinA, qreal cosA);

	//QPainterPath clearPath;
};
