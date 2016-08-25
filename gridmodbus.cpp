#include "gridmodbus.h"

const int ROWS = 5000;
const int COLUMNS = 3;

QHash<int, QPair<int, int> > GridModBus::dataMap_;

/**
 * @brief GridModBus::GridModBus
 * @param rows
 * @param columns
 * @param parent
 */
GridModBus::GridModBus(QObject *parent):
    GridModel(ROWS, COLUMNS, parent)
{
    if (dataMap_.isEmpty()) {
        dataMap_.insert(Utils::SEASON, QPair<int, int>(0, 0));
        dataMap_.insert(Utils::GENERAL_OFF_ON, QPair<int, int>(1, 0));
        dataMap_.insert(Utils::TEMP_EXT, QPair<int, int>(0, 1));
        dataMap_.insert(Utils::TYPE, QPair<int, int>(0, 2));
        dataMap_.insert(Utils::DATE_YEAR, QPair<int, int>(1, 2));
        dataMap_.insert(Utils::DATE_MONTH, QPair<int, int>(2, 2));
        dataMap_.insert(Utils::DATE_DAY, QPair<int, int>(3, 2));
        dataMap_.insert(Utils::DATE_HOUR, QPair<int, int>(4, 2));
        dataMap_.insert(Utils::DATE_MIN, QPair<int, int>(5, 2));
    }

    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLUMNS; ++c){
            QModelIndex mi = index(r, c, QModelIndex());

            setData(mi, 0x00);
        }
    }
}
/**
 * @brief GridModBus::set
 * @param gridData
 * @param value
 * @param pos
 * @return
 */
bool GridModBus::set(Utils::GRID_DATA gridData, const QVariant &value, int pos)
{
    bool ret = false;
    QHash<int, QPair<int, int> >::const_iterator it = dataMap_.find(gridData);

    ret = (it != dataMap_.constEnd());
    if (ret) {
        int row = (*it).first;
        int col = (*it).second;

        QModelIndex mi = index(row + pos, col, QModelIndex());
        ret = setData(mi, value);
    }
    return ret;
}
/**
 * @brief GridModBus::get
 * @param gridData
 * @param data
 * @param pos
 * @return
 */
bool GridModBus::get(Utils::GRID_DATA gridData, QVariant &value, int pos)
{
    bool ret = false;
    QHash<int, QPair<int, int> >::const_iterator it = dataMap_.find(gridData);

    ret = (it != dataMap_.constEnd());
    if (ret) {
        int row = (*it).first;
        int col = (*it).second;

        QModelIndex mi = index(row + pos, col, QModelIndex());
        value = data(mi);
        ret = (value != QVariant());
    }
    return ret;
}
/**
 * @brief GridModBus::headerData
 * @param section
 * @param orientation
 * @param role
 * @return
 */
QVariant GridModBus::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return "B";
        case 1:
            return "A";
        case 2:
            return "I";
        default:
            return QVariant();
        }
    }
    return QVariant();
}
