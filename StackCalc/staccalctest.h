#pragma once

#include <QObject>
#include <QtTest>
#include <QtTest/QtTest>

#include "calcstack.h"

class StacCalcTest : public QObject
{
	Q_OBJECT

private slots:
	void separateTest();
};
