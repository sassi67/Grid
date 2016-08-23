#ifndef GRIDMODBUS_H
#define GRIDMODBUS_H

#include "gridmodel.h"
#include "utils.h"

class GridModBus : public GridModel
{
    Q_OBJECT
public:
    GridModBus(QObject *parent = 0);
    bool set(Utils::GRID_DATA gridData, const QVariant& value, int pos = 0);
    bool get(Utils::GRID_DATA gridData, QVariant& value, int pos = 0);

protected:
private:
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    static QHash<int, QPair<int, int> > dataMap_;
};

#endif // GRIDMODBUS_H
