#ifndef GRIDMODBUS_H
#define GRIDMODBUS_H

#include "gridmodel.h"

class GridModBus : public GridModel
{
    Q_OBJECT
public:
    GridModBus(int rows, int columns, QObject *parent = 0);

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

};

#endif // GRIDMODBUS_H
