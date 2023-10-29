#include "golcpu.h"
#include <functional>
#include <random>
#include <ctime>

GOLCpu::GOLCpu(size_t rows, size_t columns) :
    m_fieldOne(columns, rows),
    m_fieldTwo(columns, rows)
{
    m_currentField = &m_fieldOne;
    m_backField = &m_fieldTwo;
    init();
}

void GOLCpu::init()
{
    static auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::mt19937_64(time(0)));
    for(int i = 0; i < m_currentField->data().size(); i++)
    {
        uint8_t temp = gen() ? 255 : 0;
        m_currentField->data()[i] = temp;
        m_backField->data()[i] = temp;
    }
}

void GOLCpu::update()
{
    for(int row = 0; row<m_currentField->height(); row++)
    {
        for(int col = 0; col<m_currentField->width(); col++)
        {
            int count = 0;
            for(size_t idx : m_currentField->getNeighbors(row,col))
            {
                if(m_currentField->data().at(idx) > 0)
                {
                    count++;
                }
            }
            if(m_currentField->at(row,col) > 0 && (count == 2 || count == 3))
            {
                m_backField->at(row,col) = 255;
                continue;
            }
            else if(m_currentField->at(row,col) == 0 && count == 3)
            {
                m_backField->at(row,col) = 255;
                continue;
            }
            else
            {
                m_backField->at(row,col) = 0;
                continue;
            }
        }
    }
    std::swap(m_currentField,m_backField);
}
