#include "gridmodbus.h"
/**
 * @brief GridModBus::GridModBus
 * @param rows
 * @param columns
 * @param parent
 */
GridModBus::GridModBus(int rows, int columns, QObject *parent):
    GridModel(rows, columns, parent)
{

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
                 return " ";
             case 1:
                 return "B";
             case 2:
                 return "A";
             case 3:
                 return "I";
             default:
                 return QVariant();
         }
     }
     return QVariant();
}
