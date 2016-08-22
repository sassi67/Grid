#ifndef GRIDMODELITEM_H
#define GRIDMODELITEM_H

#include <QObject>

class GridModelItem
{
public:
    GridModelItem(int rows = 0, int columns = 0);
    ~GridModelItem();
private:
    int numRows_;
    int numCols_;
    quint16 **matrix_;

};

#endif // GRIDMODELITEM_H
