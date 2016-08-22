#ifndef GRIDMODELITEM_H
#define GRIDMODELITEM_H

#include <QObject>

class GridModelItem
{
public:
    GridModelItem(int rows = 0, int columns = 0);
    ~GridModelItem();

    int rowCount() const { return numRows_; }
    int columnCount() const { return numCols_; }
    quint16 data(int row, int col) const;

private:
    int numRows_;
    int numCols_;
    quint16 **matrix_;

};

#endif // GRIDMODELITEM_H
