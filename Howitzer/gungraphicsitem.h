#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QPoint>

class GunGraphicsItem : public QGraphicsItem
{
public:
	explicit GunGraphicsItem(QGraphicsItem *parent = 0);

	GunGraphicsItem(qreal left, qreal top, qreal width, qreal height, qreal angle = 0, QGraphicsItem *parent = 0);

	QRectF boundingRect() const;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	QPointF fireFrom();

	qreal left();
	qreal top();

	qreal width();
	qreal height();

private:
	qreal left_;
	qreal top_;

	qreal width_;
	qreal height_;
};
