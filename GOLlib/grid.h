#ifndef GRID_H
#define GRID_H

#include <vector>
#include <array>

class Grid
{
public:
    Grid(size_t width, size_t height);

    uint8_t& at(size_t row, size_t column);

    size_t linearIndex(size_t row, size_t column);

    std::vector<uint8_t>& data()
    {
        return m_data;
    }

    size_t width(){return m_width;}
    size_t height(){return m_height;}

    std::array<size_t,8> getNeighbors(size_t row, size_t column);

protected:
    std::vector<uint8_t> m_data;
    size_t m_width;
    size_t m_height;
};

#endif // GRID_H
