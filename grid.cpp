#include "grid.h"
/**
 * @brief Grid::Grid
 * @param rows
 * @param columns
 */
Grid::Grid(int rows, int columns):
    numRows_(rows),
    numCols_(columns)
{
    if (numRows_ <= 0)
        throw;
    if (numCols_ <= 0)
        throw;

    matrix_ = new quint16 * [numRows_];
    for (int c = 0; c < numRows_; ++c)
        matrix_[c] = new quint16[numCols_];

    for (int r = 0; r < numRows_; ++r)
        for (int c = 0; c < numCols_; ++c)
            matrix_[r][c] = 0;
}
/**
 * @brief Grid::~Grid
 */
Grid::~Grid()
{
    for (int c = 0; c < numRows_; ++c)
        delete[] matrix_[c];
    delete[] matrix_;
}
/**
 * @brief Grid::data
 * @param row
 * @param col
 * @return
 */
quint16 Grid::data(int row, int col) const
{
    if (row < 0 || row > numRows_)
        throw;
    if (col < 0 || col > numCols_)
        throw;

    return matrix_[row][col];
}
/**
 * @brief Grid::setData
 * @param row
 * @param col
 * @param value
 * @return
 */
bool Grid::setData(int row, int col, quint16 value)
{
    if (row < 0 || row > numRows_)
        throw;
    if (col < 0 || col > numCols_)
        throw;

    matrix_[row][col] = value;
    return true;
}
