#include "targetgraphicsitem.h"

TargetGraphicsItem::TargetGraphicsItem(QGraphicsItem *parent) :
	QGraphicsItem(parent) {}

TargetGraphicsItem::TargetGraphicsItem(qreal left, qreal top, qreal width, qreal height, QGraphicsItem *parent) :
	QGraphicsItem(parent),
	left_(left),
	top_(top),
	width_(width),
	height_(height) {}

QRectF TargetGraphicsItem::boundingRect() const
{
	qreal penWidth = 1;
	return QRectF(left_ - penWidth / 2, top_ - penWidth / 2,
				  width_ + penWidth, height_ + penWidth);
}

void TargetGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	rects.push_back(QRectF(left_, top_ + height_ / 3, width_, height_ / 3));
	rects.push_back(QRectF(left_, top_ + height_ / 6, width_, height_ * 2 / 3));
	rects.push_back(QRectF(left_, top_, width_, height_));
	painter->drawRects(rects);
}

bool TargetGraphicsItem::isInternal(qreal y)
{
	return (y < height_ && y > top_);
}

int TargetGraphicsItem::getScore(qreal y)
{
	const int step = 20;
	int scores = rects.size() * step;
	for(QRectF rect : rects)
	{
		if (y > rect.top() && y < rect.bottom())
		{
			return scores;
		}
		scores -= step;
	}
	return 0;
}

qreal TargetGraphicsItem::left() { return left_; }
qreal TargetGraphicsItem::top() { return top_; }
qreal TargetGraphicsItem::width() { return width_; }
qreal TargetGraphicsItem::height() { return height_; }
