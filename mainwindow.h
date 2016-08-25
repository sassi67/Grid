#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QVBoxLayout;
class QHBoxLayout;
class QTableView;
class GridModBus;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private:
    QHBoxLayout*   vBoxLayout_;
    QTableView*     tableView_;
    GridModBus*     grid_;

signals:

public slots:
};

#endif // MAINWINDOW_H
