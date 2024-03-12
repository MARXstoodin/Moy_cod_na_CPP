#include <iostream>
#include <thread>
#include <mutex>

std::mutex mfoo;
std::mutex mbar;

void foo()
{
	while(1)
	{
		mbar.lock();
		std::cout<<"foo"<<std::endl;
		mfoo.unlock();
	}
}

void bar()
{
	while(1)
	{
		mfoo.lock();
		std::cout<<"bar"<<std::endl;
		mbar.unlock();
	}
}

int main()
{
	mfoo.lock();
	mbar.unlock();
	std::thread t1(foo);
	std::thread t2(bar);
	t1.join();
	t2.join();
	return 0;
}
