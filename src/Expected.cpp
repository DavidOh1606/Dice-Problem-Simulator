#include "Expected.h"

#include <iostream>

Expected::Expected(const std::string& valueName)
    : m_valueName{valueName}
{

}

Expected::Expected(const std::string& valueName, const std::uniform_int_distribution<>& die)
    : m_valueName{valueName}, m_die{die}
{

}

std::string& Expected::valueName()
{
    return m_valueName;
}