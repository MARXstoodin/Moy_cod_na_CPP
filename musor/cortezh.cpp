#include <iostream>
#include <string>

/*
functions:
 set:
  push_front()
  push_back()
  insert()
  
 delete:
  pop_front()
  pop_back()
  erase()
 
 get:
  lenght()
  []
  
 need:
  =
*/

template < typename T >
  class List {
    public:

	//set
    void push_front(T value) {
    	listNode * newNode = new listNode;

    	if (first != nullptr)
    		newNode -> next = first;
    		
    	newNode -> storage = value;
    	first = newNode;
    }

    void push_back(T value) {
      listNode * newNode = new listNode;

      if (first == nullptr)
        first = newNode;
      else {
        listNode * thisNode = first;
        while (thisNode -> next != nullptr)
          thisNode = thisNode -> next;
        thisNode -> next = newNode;
      }
      newNode -> storage = value;
    }
	
	void insert(int index, int value) {
      try {
        if (first == nullptr)
          throw std::string("List is 0 lenght!");

        if (index < 0)
          throw std::string("Value in () cannot be less than zero!");

		listNode * newNode = new listNode;
		newNode->storage = value;

        /*if (index == 0) {
        	newNode->next = first;
          	first = newNode;
        }
		else{*/
			listNode * thisNode = first;
	        listNode * nextNode = nullptr;
	
	        for (int i = index; i > 0; i--) {
	          if (thisNode -> next == nullptr && i != 0)
	            throw std::string("Value in () cannot be higer than list lenght!");
	
	          thisNode = thisNode -> next;
	        }
	        
	        if(thisNode->next != nullptr)
	        	nextNode = thisNode->next;
			
			thisNode->next = newNode;
			newNode->next = nextNode;
		//}
      } catch (std::string error) {
        std::cout << error;
      }
    }
	
    //delete
    void pop_front() {
      try {
        if (first == nullptr)
          throw std::string("List is 0 lenght!");

        listNode * thisNode = first;

        if (first -> next != nullptr)
          first = first -> next;
        else
          first = nullptr;

        delete thisNode;
      } catch (std::string error) {
        std::cout << error;
      }
    }

    void pop_back() {
      try {
        if (first == nullptr)
          throw std::string("List is 0 lenght!");

        listNode * thisNode = first;
        listNode * previousNode = nullptr;
		
		if (first -> next == nullptr)
          first = first -> next;
        else {
        	while (thisNode -> next != nullptr) {
          		previousNode = thisNode;
          		thisNode = thisNode -> next;
        	}
        	previousNode -> next = nullptr;
		}
		
        delete thisNode;
      } catch (std::string error) {
        std::cout << error;
      }
    }

    void erase(int index) {
      try {
        if (first == nullptr)
          throw std::string("List is 0 lenght!");

        if (index < 0)
          throw std::string("Value in () cannot be less than zero!");

        if (index == 0) {
          listNode * thisNode = first -> next;
          delete first;
          first = thisNode;
        }
		else{
		
        	listNode * thisNode = first;
        	listNode * previousNode = nullptr;

        	for (int i = index; i > 0; i--) {
          		if (thisNode -> next == nullptr && i != 0)
            		throw std::string("Value in () cannot be higer than list lenght!");

          		if (i == 1)
   	        		previousNode = thisNode;
	
    	    	thisNode = thisNode -> next;
	        }

        	if (thisNode -> next != nullptr)
          		previousNode -> next = thisNode -> next;
        	else
    	      previousNode -> next = nullptr;
	
        	delete thisNode;
    	}
      } catch (std::string error) {
        std::cout << error;
      }
    }

    //get
    int lenght() {
      int len = 0;
      if (first != nullptr) {
        len++;
        listNode * thisNode = first;
        while (thisNode -> next != nullptr) {
          len++;
          thisNode = thisNode -> next;
        }
      }
      return len;
    }

    T operator[](int index) {
      try {
        if (first == nullptr)
          throw std::string("List is 0 lenght!");

        if (index < 0)
          throw std::string("Value in [] cannot be less than zero!");

        listNode * thisNode = first;

        for (int i = index; i > 0; i--) {
          if (thisNode -> next == nullptr && i != 0)
            throw std::string("Value in [] cannot be higer than list lenght!");
          thisNode = thisNode -> next;
        }

        return thisNode -> storage;
      } catch (std::string error) {
        std::cout << error;
        return NULL;
      }
    }
    private: struct listNode {
      T storage;
      listNode * next = nullptr;
    };
    listNode * first = nullptr;
  };

int main(int argc, char * argv[]) {
  List < int > a;
  std::cout << a[0] << "\n";
  std::cout << "len = " << a.lenght() << "\n";
  a.push_back(1);
  std::cout << a[0] << "\n";
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);
  std::cout << "len = " << a.lenght() << "\n";
  std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
  a.pop_back();
  std::cout << "len = " << a.lenght() << "\n";
  a.erase(0);
  std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
  std::cout << "len = " << a.lenght() << "\n";
  std::cout << a[-3] << "\n";
  std::cout << a['e'] << "\n";
  std::cout << a[4] << "\n";
  a.push_front(2345);
  std::cout << "len = " << a.lenght() << "\n";
  std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
  a.pop_front();
  std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
  a.pop_front();
  a.pop_front();
  a.pop_front();
  a.pop_front();
  std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
  a.push_back(3);
  a.push_front(1);
  std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
  a.pop_back();
  a.pop_back();
  a.push_front(2345);
  a.pop_back();
  a.pop_back();
  a.push_front(2345);
  a.pop_front();
  std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
  a.push_back(3);
  a.push_front(1);
  std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
  a.pop_front();
  a.pop_back();
  a.pop_back();
  a.push_front(2345);
  std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
  a.erase(0);
  std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
  std::cout << "end\n";
  a.push_front(1);
  a.push_front(2);
  a.push_front(4);
  std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
  a.insert(2,3);
  std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
  a.insert(4,8);
  a.insert(2,9);
  std::cout << a[0] << a[1] << a[2] << a[3] << a[4] << a[5] << "\n";
  
  /*List<std::string> b;
 b.push_back("aboba");
 
b.push_back("amoma");
 std::cout<<b[0]<<" "<<b[1]<<"\n";
 //b.erase(1);
 std::cout<<b[0]<<b[1]<<"\n"; //b[1] ?? ???????? ????????!
 b.push_back("aboba");
 std::cout<<b[0]<<" "<<b[1]<<"\n";
 //std::cout<<b[5];*/

  return 0;
}
