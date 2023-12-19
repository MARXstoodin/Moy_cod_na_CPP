#include <iostream>

using namespace std;

struct node{
	int value;
	node* next;
};

class intList{
	
	private:
		node* first;
		
	public:
		intList(){
			/*cout<<"a";
			first->next = NULL;
			cout<<"b";*/
		}
		
		int back(){
			node* last = first;
			while(last->next != NULL){
				last = last->next;
			}
			return last->value;
		}
		
		void pushBack(int value){
			if(first==NULL){
				pushFront(value);
			}
			else{
				node* last = first;
				node* newLast = new node;
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
		
		int popBack(){
			node* last = first;
			node* preLast = first;
			
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
		
		int front(){
			return first->value;
		}
		
		int pushFront(int value){
			node* tmp = new node;
			tmp->value = value;
			tmp->next = first;
			first = tmp;
		}
		
		int popFront(){
			node* tmp = first;
			first = tmp->next;
			int ret = tmp->value;
			delete tmp;
			return ret;
		}
		
		int size(){
			node* last = first;
			int i = 1;
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
	intList list;
	
	list.pushBack(7);
	
	cout<<list.front();
	
	list.popFront();
	
	cout<<list.back();
	
}
