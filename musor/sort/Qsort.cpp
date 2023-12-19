#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> arr){
	for (int i = 0; i<arr.size(); i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

vector<int> QuickSort(vector<int>& nums) {
	for(int x = nums.size()-1, i=-1, j=0, tmp; x>0; x--){
		if(j==x){
			tmp = nums[i+1];
			nums[i+1] = nums[x];
			nums[x] = tmp;
		}
		else if(nums[j]<nums[x]){
			j++;
		}
		else{
			i++;
			tmp = nums[j];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
		show(nums);
	}
    return nums;
}	

int main(){
	int b[] = {1,2,5,4,3};
	vector<int> a(b, b + sizeof(b) / sizeof(b[0]) );
	a=QuickSort(a);
	show(a);
	return 0;
}
