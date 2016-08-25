#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>

class GridModBus;

class TableView : public QTableView
{
public:
    explicit TableView(QWidget *parent = 0);
private:
    GridModBus* grdModBus_;

};

#endif // TABLEVIEW_H
