#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void show(vector<int>::iterator iBegin, vector<int>::iterator iEnd){
	for(; iBegin<iEnd; iBegin++)
		cout<<*iBegin<<" ";
	cout<<"\n";
}

void iterTest(vector<int>::iterator i){
	*(i+1)=7;
}

void MergeSort2(vector<int>::iterator iBegin, vector<int>::iterator iEnd) {
	
	int halfSize=(iEnd-iBegin)/2, odd=0;
	
	if ((iEnd-iBegin)%2!=0){
		//firstHalf.push_back(nums[0]);
		odd=1;
	}
	/*	
	for (int i = 0; i<halfSize; i++){
		firstHalf.push_back(nums[i+odd]);
		secondHalf.push_back(nums[halfSize+i+odd]);
	}
	
	if(firstHalf.size()>1){
		firstHalf=MergeSort(firstHalf);
	}
	
	if(secondHalf.size()>1){
		secondHalf=MergeSort(secondHalf);
	}
	*/
	for (int i = 0, x = 0, y = 0; i < iEnd-iBegin; i++){
		if((x < halfSize+odd && *(iBegin+x) < *(iBegin+halfSize+y)) || y==halfSize){
			*(iBegin+i) = *(iBegin+x);
			x++;
		}
		else{
			*(iBegin+i) = *(iBegin+halfSize+y);
			y++;
		}
		show(iBegin, iEnd);
	}
}

vector<int> MergeSort(vector<int> nums) {
	
	vector<int> tmp;
	
	int halfSize=(iEnd-iBegin)/2, odd=0;
	
	if ((iEnd-iBegin)%2!=0){
		//firstHalf.push_back(nums[0]);
		odd=1;
	}
	/*	
	for (int i = 0; i<halfSize; i++){
		firstHalf.push_back(nums[i+odd]);
		secondHalf.push_back(nums[halfSize+i+odd]);
	}
	
	if(firstHalf.size()>1){
		firstHalf=MergeSort(firstHalf);
	}
	
	if(secondHalf.size()>1){
		secondHalf=MergeSort(secondHalf);
	}
	*/
	for (int i = 0, x = 0, y = 0; i < iEnd-iBegin; i++){
		if((x < halfSize+odd && *(iBegin+x) < *(iBegin+halfSize+y)) || y==halfSize){
			*(iBegin+i) = *(iBegin+x);
			x++;
		}
		else{
			*(iBegin+i) = *(iBegin+halfSize+y);
			y++;
		}
		show(iBegin, iEnd);
	}
}

int main(){
	int b[] = {2, 3, 1, 4};
	vector<int> a(b, b + sizeof(b) / sizeof(b[0]));
	
	show(a.begin(), a.end());
	MergeSort(a.begin(), a.end());
	show(a.begin(), a.end());
	return 0;
}
