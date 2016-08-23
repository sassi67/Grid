#ifndef GRIDMODEL_H
#define GRIDMODEL_H

#include <QAbstractTableModel>

class Grid;

class GridModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    GridModel(int rows, int columns, QObject *parent = 0);
    virtual ~GridModel();

protected:
    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    Grid* internalGrid_;

signals:

public slots:
};

#endif // GRIDMODEL_H
