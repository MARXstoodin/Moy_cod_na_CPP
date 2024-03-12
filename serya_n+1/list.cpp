#include <iostream>

using namespace std;

template <typename T>
struct node{
	T value;
	node* next;
};

template <typename T>
class intList{
	
	private:
		node<T>* first;
		
	public:
		intList(){
			/*cout<<"a";
			first->next = NULL;
			cout<<"b";*/
		}
		
		T back(){
			node<T>* last = first;
			while(last->next != NULL){
				last = last->next;
			}
			return last->value;
		}
		
		void pushBack(T value){
			if(first==NULL){
				pushFront(value);
			}
			else{
				node<T>* last = first;
				node<T>* newLast = new node<T>;
				cout<<"a";
				cout<<last->next;
				while(last->next != NULL){
					last = last->next;
				}
				last->next = newLast;
				newLast->next=NULL;
				newLast->value = value;
			}
		}
		
		T popBack(){
			node<T>* last = first;
			node<T>* preLast = first;
			
			while(last->next != NULL){
				last = last->next;
			}
			
			while(preLast->next->next != NULL){
				preLast = preLast->next;
			}
			
			preLast->next = NULL;
			int ret = last->value;
			delete last;
			return ret;
		}
		
		T front(){
			return first->value;
		}
		
		T pushFront(T value){
			node<T>* tmp = new node<T>;
			tmp->value = value;
			tmp->next = first;
			first = tmp;
		}
		
		T popFront(){
			node<T>* tmp = first;
			first = tmp->next;
			int ret = tmp->value;
			delete tmp;
			return ret;
		}
		
		T size(){
			node<T>* last = first;
			T i = 1;
			while(last->next != NULL){
				last = last->next;
				i++;
			}
			return i;
		}
		/*
		void view(int index){
			node* selected = first;
			for(int i = 0; i<index; i++){
				if(last->next == NULL){
					throw "Fuk u.";
				}
				selected = selected->next;
			}
		}*/
};

int main(){
	intList<int> ints;
	
	ints.pushFront(1);
	cout<<ints.back()<<" ";
	
	ints.pushFront(5+3);
	cout<<ints.front()<<"\n";
	
	
	intList<float> floats;
	
	floats.pushFront(0.1);
	cout<<floats.back()<<" ";
	//cout<<0.5*0.0002<<" ";
	floats.pushFront(0.5*0.0002);
	cout<<floats.front();
	
	
	/*
	list.pushBack(3);
	cout<<list.back();
	
	list.pushBack(4);	
	cout<<list.back();
	*/
}
