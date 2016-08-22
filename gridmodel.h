#ifndef GRIDMODEL_H
#define GRIDMODEL_H

#include <QAbstractTableModel>

class GridModelItem;

class GridModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    GridModel(int rows, int columns, QObject *parent = 0);
    ~GridModel();

    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    GridModelItem* internalGrid_;

signals:

public slots:
};

#endif // GRIDMODEL_H
