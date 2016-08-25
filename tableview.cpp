#include "tableview.h"
#include "gridmodbus.h"

TableView::TableView(QWidget *parent):
    QTableView(parent),
    grdModBus_(new GridModBus(this))
{
    setModel(grdModBus_);
}
