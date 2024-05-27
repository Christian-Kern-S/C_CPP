#ifndef MOCKOBSERVER_HPP
#define MOCKOBSERVER_HPP

#include "../INCLUDE/Observer.hpp"
#include <gmock/gmock.h>

class MockObserver : public Observer
{
public:
    MOCK_METHOD(void, update, (int i_), (override));
};
#endif