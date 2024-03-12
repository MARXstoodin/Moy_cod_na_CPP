#include <iostream>

using namespace std;

class spider
{
	public:
		spider()
		{
			static int tmp_count = 0;
			tmp_count++;
			spider_count = &tmp_count;
			
			static int tmp = 8;
			deafault_leg_count = &tmp;
		}
		void mutate(int new_leg_cout)
		{
			*deafault_leg_count = new_leg_cout;
		}
		int show_legs()
		{
			return *deafault_leg_count;
		}
		int operator()()
		{
			return *spider_count;
		}
	private:
		int* spider_count;
		int* deafault_leg_count;
};



int main()
{
	spider man;
	cout<<man()<<"\n";
	spider man2;
	man2.mutate(12);
	cout<<man()<<" "<<man.show_legs()<<"\n";
	cout<<man2()<<" "<<man2.show_legs()<<"\n";
	spider man3;
	man2.mutate(man.show_legs()*2);
	cout<<man()<<" "<<man.show_legs()<<"\n";
	cout<<man2()<<" "<<man2.show_legs()<<"\n";
	cout<<man3()<<" "<<man.show_legs()<<"\n";
	return 0;
}
