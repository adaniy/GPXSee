#ifndef POI_H
#define POI_H

#include <QList>
#include <QPointF>
#include <QString>
#include <QStringList>
#include "common/rtree.h"
#include "waypoint.h"

class Path;
class Area;
class RectC;

class POI : public QObject
{
	Q_OBJECT

public:
	POI(QObject *parent = 0);

	bool loadFile(const QString &path);
	void loadDir(const QString &path);
	const QString &errorString() const {return _errorString;}
	int errorLine() const {return _errorLine;}

	unsigned radius() const {return _radius;}
	void setRadius(unsigned radius);
	void useDEM(bool use);

	QList<Waypoint> points(const Path &path) const;
	QList<Waypoint> points(const Waypoint &point) const;
	QList<Waypoint> points(const Area &area) const;

	const QStringList &files() const {return _files;}
	void enableFile(const QString &fileName, bool enable);
	void clear();

signals:
	void pointsChanged();

private:
	typedef RTree<size_t, qreal, 2> POITree;
	struct FileIndex {
		int start;
		int end;
		bool enabled;
	};

	bool loadFile(const QString &path, bool dir);
	void search(const RectC &rect, QSet<int> &set) const;
	void appendElevation(QList<Waypoint> &points) const;

	POITree _tree;
	QVector<Waypoint> _data;
	QStringList _files;
	QList<FileIndex> _indexes;

	unsigned _radius;
	bool _useDEM;

	QString _errorString;
	int _errorLine;
};

#endif // POI_H
