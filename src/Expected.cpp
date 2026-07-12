#include "Expected.h"

#include <iostream>

Expected::Expected()
{

}

Expected::Expected(const std::uniform_int_distribution<>& die)
    : m_die{die}
{

}
