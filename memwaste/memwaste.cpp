#include <memory>
#include <algorithm>
#include <iostream>
#include "memwaste.h"

int memwaste::counter = 0;

memwaste::memwaste()
    : id(++counter)
    , pwaste(std::make_unique<char[]>(ss))
{
    std::cout << "Making waste id:" << id << std::endl;
}

memwaste::memwaste(const memwaste& other)
    : id(++counter)
    , pwaste(std::make_unique<char[]>(ss))
{
    std::copy_n(other.pwaste.get(), ss, pwaste.get());
    std::cout << "Making waste id:" << id << " by copy constructing from id:" << other.id << std::endl;
}

memwaste& memwaste::operator=(const memwaste& other)
{
    std::cout << "Changing waste id:" << id << " by assignment from id:" << other.id << std::endl;
    if (this == &other) return *this;
    pwaste = std::make_unique<char[]>(ss);
    std::copy_n(other.pwaste.get(), ss, pwaste.get());
    id = other.id;
    return *this;
}

memwaste::~memwaste()
{
    std::cout << "Destroying waste id:" << id << std::endl;
}

#ifdef __CPP_20__

memwaste& memwaste::operator=(memwaste&& other) noexcept
{
    std::cout << "Making waste id:" << id << " by move assignment from id:" << other.id << std::endl;
    if (this == &other) return *this;
    pwaste = std::move(other.pwaste);
    id = other.id;
    other.id = 0;
    return *this;
}

memwaste::memwaste(memwaste&& other) noexcept
    : id(std::exchange(other.id, 0))
    , pwaste(std::move(other.pwaste))
{
    std::cout << "Making waste id:" << id << " by move constructing from id:" << other.id << std::endl;
}
#endif
