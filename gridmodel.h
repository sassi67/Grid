#ifndef GRIDMODEL_H
#define GRIDMODEL_H

#include <QAbstractTableModel>

class GridModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit GridModel(QObject *parent = 0);

    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:

signals:

public slots:
};

#endif // GRIDMODEL_H
