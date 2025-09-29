#ifndef __MEMWASTE_H__
#define __MEMWASTE_H__

//#define __CPP_20__

#include <memory>
class memwaste
{
private:
	unsigned int id;
	std::unique_ptr<char[]> pwaste;
public:
	static int counter;
	enum {ss=100000000};
public:
	memwaste();
	~memwaste();
	memwaste(const memwaste& other);
	memwaste& operator=(const memwaste& other);
#ifdef __CPP_20__
	memwaste& operator=(memwaste&& other) noexcept;
	memwaste(memwaste&& other) noexcept;
#endif

};

#endif
