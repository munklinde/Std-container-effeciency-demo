#ifndef __MEMWASTE_H__
#define __MEMWASTE_H__

#include <memory>

#if defined(MEMWASTE_ENABLE_MOVE)
#define MEMWASTE_HAS_MOVE 1
#else
#define MEMWASTE_HAS_MOVE 0
#endif

class memwaste
{
private:
    unsigned int id;
    std::unique_ptr<char[]> pwaste;

public:
    static int counter;
    enum { ss = 100000000 };

    memwaste();
    ~memwaste();

    memwaste(const memwaste& other);
    memwaste& operator=(const memwaste& other);

#if MEMWASTE_HAS_MOVE
    memwaste(memwaste&& other) noexcept;
    memwaste& operator=(memwaste&& other) noexcept;
#endif
};

#endif
