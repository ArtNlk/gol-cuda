#include "grid.h"

Grid::Grid(size_t width, size_t height) :
    m_data(width*height),
    m_width(width),
    m_height(height)
{

}

uint8_t& Grid::at(size_t row, size_t column)
{
    size_t idx = linearIndex(row,column);
    return m_data.at(idx);
}

size_t Grid::linearIndex(size_t row, size_t column)
{
    return row * m_width + column;
}

std::array<size_t, 8> Grid::getNeighbors(size_t row, size_t column)
{
    std::array<size_t ,8> output;
    size_t currentIdx = linearIndex(row, column);
    output[0] = linearIndex(row==m_height-1? 0 : row + 1, column == 0? m_width - 1: column - 1);//top left
    output[1] = linearIndex(row==m_height-1? 0 : row + 1, column);//top center
    output[2] = linearIndex(row==m_height-1? 0 : row + 1, column == m_width - 1? 0: column + 1);//top right

    output[3] = linearIndex(row, column == 0? m_width - 1: column - 1);//center left
    output[4] = linearIndex(row, column == m_width - 1? 0: column + 1);//center right

    output[5] = linearIndex(row==0? m_height-1 : row - 1, column == 0? m_width - 1: column - 1);//bottom left
    output[6] = linearIndex(row==0? m_height-1 : row - 1, column);//bottom center
    output[7] = linearIndex(row==0? m_height-1 : row - 1, column == m_width - 1? 0: column + 1);//bottom right

    return output;
}
