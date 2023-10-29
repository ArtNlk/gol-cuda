#ifndef GOLCPU_H
#define GOLCPU_H

#include "grid.h"

class GOLCpu
{
public:
    GOLCpu(size_t rows, size_t columns);

    void init();

    void update();

    bool getAt(size_t row, size_t column);
    void setAt(size_t row, size_t column, bool val);

    std::vector<uint8_t>& data()
    {
        return m_currentField->data();
    }

protected:
    Grid* m_currentField;
    Grid* m_backField;
    Grid m_fieldOne;
    Grid m_fieldTwo;
};

#endif // GOLCPU_H
