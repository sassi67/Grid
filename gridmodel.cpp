#include "gridmodel.h"
#include "gridmodelitem.h"

GridModel::GridModel(int rows, int columns, QObject *parent) :
    QAbstractTableModel(parent),
    internalGrid_(new GridModelItem(rows, columns))
{

}

GridModel::~GridModel()
{
    delete internalGrid_;
}

int GridModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return internalGrid_->rowCount();
}

int GridModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return internalGrid_->columnCount();
}

QVariant GridModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
         return QVariant();

     if (index.row() >= internalGrid_->rowCount() || index.row() < 0)
         return QVariant();

     if (index.column() >= internalGrid_->columnCount() || index.column() < 0)
         return QVariant();

     if (role == Qt::DisplayRole) {
        return internalGrid_->data(index.row(), index.column());
     }

     return QVariant();
}
