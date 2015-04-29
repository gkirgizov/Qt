#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QVector>

class TargetGraphicsItem : public QGraphicsItem
{
public:
	explicit TargetGraphicsItem(QGraphicsItem *parent = 0);

	TargetGraphicsItem(qreal left, qreal top, qreal width, qreal height, QGraphicsItem *parent = 0);

	QRectF boundingRect() const;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	bool isInternal(qreal y);

	//TODO
	int getScore(qreal y);

	qreal left();
	qreal top();

	qreal width();
	qreal height();

private:
	qreal left_;
	qreal top_;

	qreal width_;
	qreal height_;

	QVector<QRectF> rects;
};
