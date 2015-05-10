#include "guncore.h"

#include <qmath.h>
#include <QPainter>

GunCore::GunCore(QObject *parent) :
	QObject(parent),
	angle(0),
	speed(0) {}

GunCore::GunCore(const QRectF &sizeRect, QObject *parent) :
	GunCore(parent)
{
	this->redraw(sizeRect);
}

GunCore::~GunCore()
{
	delete this->gun;
	delete this->target;
}

qreal GunCore::f(qreal x, qreal g)
{
	const qreal pi = 3.14159265358979323846;
	const qreal rAngle = angle * pi / 180;
	const qreal sinA = qSin(rAngle);
	const qreal cosA = qCos(rAngle);

	const qreal yt = f_(x, g, sinA, cosA);
	return -yt;
}
qreal GunCore::f_(qreal x, qreal g, qreal sinA, qreal cosA)
{
	const qreal t = x / (speed * cosA);
	return (speed * t * sinA - g * t * t / 2);
}

int GunCore::doFire()
{
	QPointF fireFrom = gun->mapToScene(gun->fireFrom());
	QPointF prev(fireFrom);

	const qreal dx = 1;
	for (qreal xt = dx; ; xt += dx)
	{
		const qreal y = fireFrom.y() + f(xt);
		const qreal x = fireFrom.x() + xt;

		if (x >= target->left())
		{
			return target->getScore(y);
		}

		QPointF current = QPointF(x, y);
		QLineF dy(prev, current);
		scene.addLine(dy);
		prev = current;
//		qreal lineY = dy.y1() > dy.y2() ? dy.y1() : dy.y2();
//		clearPath.addRect(QRectF(dy.x1(), lineY, dy.dx(), dy.dy()));
	}
	return 0;
}

void GunCore::changeAngle(int value)
{
	this->angle = value;
	redraw(scene.sceneRect());
}

void GunCore::changeStartSpeed(int value)
{
	this->speed = value;
}

//TODO
void GunCore::outputResult(const QString &info)
{

}

void GunCore::redraw(const QRectF &sizeRect, qreal gunWidth, qreal gunHeight)
{	
	QPainterPath clearPath;
	clearPath.addRect(scene.sceneRect());
	scene.setSelectionArea(clearPath);
	scene.clearSelection();
	scene.setSceneRect(sizeRect);

	//gun
	const qreal gunTop = sizeRect.bottom() - gunHeight;
	const qreal gunLeft = sizeRect.left();
	delete this->gun;
	this->gun = new GunGraphicsItem(gunLeft, gunTop, gunWidth, gunHeight, -angle);
	scene.addItem(gun);

	//target	
	const qreal targetWidth = 10;	
	const qreal targetHeight = sizeRect.height() / 2;
	const qreal targetTop = sizeRect.height() / 4;
	const qreal targetLeft = sizeRect.width() - targetWidth;
	scene.addRect(QRectF(targetLeft, 0, targetWidth, sizeRect.height()));
	delete this->target;
	this->target = new TargetGraphicsItem(targetLeft, targetTop, targetWidth, targetHeight);
	scene.addItem(target);

	scene.update();
}
