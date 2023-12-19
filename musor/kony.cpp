#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(int x) {
        if(x>=0)
        {
            int len = 0;
            for (int i = x; i>0 ; len++)
                i/=10;
            //cout<<len<<"\n";
            for (int i = 1; i<=len; i++)
            {
                //cout << x/(int)pow(10,len-i)%10 << " " << x%(int)pow(10,i)/(int)pow(10,i-1) << "\n";
                if (x/(int)pow(10,len-i)%10 != x%(int)pow(10,i)/(int)pow(10,i-1))
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
        return true;
    }

int main()
{
	cout<<"0 "<<isPalindrome(0) << "\n";
	cout<<"100 "<<isPalindrome(100) << "\n";
	cout<<"1488 "<<isPalindrome(1488) << "\n";
	cout<<"148841 "<<isPalindrome(148841) << "\n";
	cout<<"11 "<<isPalindrome(11) << "\n";
	cout<<"-1 "<<isPalindrome(-1) << "\n";
	cout<<"5 "<<isPalindrome(5) << "\n";
	cout<<"999 "<<isPalindrome(999) << "\n";
	cout<<"1000000001 "<<isPalindrome(1000000001) << "\n";
	return 0;
}
