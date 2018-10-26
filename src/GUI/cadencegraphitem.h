#ifndef CADENCEGRAPHITEM_H
#define CADENCEGRAPHITEM_H

#include "graphitem.h"

class CadenceGraphItem : public GraphItem
{
	Q_OBJECT

public:
	CadenceGraphItem(const Graph &graph, GraphType type,
	  QGraphicsItem *parent = 0);

	qreal max() const {return _max;}
	qreal avg() const {return _avg;}

private:
	QString toolTip() const;

	qreal _avg, _max;
};

#endif // CADENCEGRAPHITEM_H
