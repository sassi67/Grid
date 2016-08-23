#ifndef GRIDMODELITEM_H
#define GRIDMODELITEM_H

#include <QObject>

class Grid
{
public:
    Grid(int rows, int columns);
    ~Grid();

    int rowCount() const { return numRows_; }
    int columnCount() const { return numCols_; }
    quint16 data(int row, int col) const;
    bool setData(int row, int col, quint16 value);

private:
    int numRows_;
    int numCols_;
    quint16 **matrix_;

};

#endif // GRIDMODELITEM_H
