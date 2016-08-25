#include "mainwindow.h"
#include "gridmodbus.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableView>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    vBoxLayout_(new QHBoxLayout),
    tableView_(new QTableView(this)),
    grid_(new GridModBus(this))
{
    tableView_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tableView_->setModel(grid_);
    vBoxLayout_->addWidget(tableView_);
    setLayout(vBoxLayout_);
}
