#include "gridmodel.h"
#include "grid.h"
/**
 * @brief GridModel::GridModel
 * @param rows
 * @param columns
 * @param parent
 */
GridModel::GridModel(int rows, int columns, QObject *parent) :
    QAbstractTableModel(parent),
    internalGrid_(new Grid(rows, columns))
{

}
/**
 * @brief GridModel::~GridModel
 */
GridModel::~GridModel()
{
    delete internalGrid_;
}
/**
 * @brief GridModel::rowCount
 * @param parent
 * @return
 */
int GridModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return internalGrid_->rowCount();
}
/**
 * @brief GridModel::columnCount
 * @param parent
 * @return
 */
int GridModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return internalGrid_->columnCount();
}
/**
 * @brief GridModel::data
 * @param index
 * @param role
 * @return
 */
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
/**
 * @brief GridModel::setData
 * @param index
 * @param value
 * @param role
 * @return
 */
bool GridModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool ret = false;

    if (!index.isValid())
         return ret;

     if (index.row() >= internalGrid_->rowCount() || index.row() < 0)
         return ret;

     if (index.column() >= internalGrid_->columnCount() || index.column() < 0)
         return ret;

     if (role == Qt::EditRole) {
        int v = value.toInt(&ret);
        if (ret) {
            if (v < 0 || v > 0xFFFF)
                ret = false;
            else
                ret = internalGrid_->setData(index.row(), index.column(), static_cast<quint16>(v));
        }
     }

    return ret;
}
/**
 * @brief GridModel::headerData
 * @param section
 * @param orientation
 * @param role
 * @return
 */
QVariant GridModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(section)
    Q_UNUSED(orientation)
    Q_UNUSED(role)
    // must be implemented by the subclasses
    return QVariant();
}

