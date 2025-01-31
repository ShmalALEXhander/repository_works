#include <iostream>
using namespace std;

typedef unsigned char byt;

struct _dat {
	bool busy;
	char procces;
	int address;
	int size;

	_dat* next;
	_dat* prev;
};
class ArrayIterator {
private:
	inline static int index = 0;
	const char* arr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static const int N = 26;
public:
	char next() {
		if (index < N) return arr[index++];
		else return ' ';
	}
};
class Memory {
	_dat* head;
	byt* mass;
	int MEMORY_SIZE;
	ArrayIterator names;
	int len = 0;
public: Memory(int MEMORY_SIZE_) {
	MEMORY_SIZE = MEMORY_SIZE_;
	mass = new byt[MEMORY_SIZE];
	head = new _dat;
	head->busy = false;
	head->procces = ' ';
	head->address = 0;
	head->size = MEMORY_SIZE;
	head->next = head->prev = NULL;
	len++;
}
	  int get_mem(int size) {
		  if (size > MEMORY_SIZE) return -1;
		  _dat* curr = head;
		  while (curr) {
			  if (!curr->busy && curr->size >= size) { 
				  if (curr->size > size) {
					  _dat* block = new _dat;
					  if (curr->next) {
						  curr->next->prev = block;
						  block->next = curr->next;
						  block->prev = curr;
						  curr->next = block;
					  }
					  else {
						  curr->next = block;
						  block->prev = curr;
						  block->next = NULL;
					  }
					  block->busy = false;
					  block->procces = ' '; 
					  block->address = curr->address + size;
					  block->size = curr->size - size;
					  curr->procces = names.next();
					  curr->size = size;
					  curr->busy = true;
					  len++;
				  }
				  else {
					  curr->busy = true;
					  curr->procces = 'A';
					  len++;
				  }
				  break;
			  }
			  curr = curr->next;
		  }
	  }
	  void print() {
		  _dat* curr = head;
		  while (curr) {
			  cout << " ";
			  cout << " Busy: " << ((curr->busy) ? "Y" : "N");
			  cout << " Procces: " << curr->procces;
			  cout << " Address: " << curr->address;
			  cout << " Size: " << curr->size;
			  curr = curr->next;
			  cout << "\n";
		  }
		  cout << "\n";
	  }
	  void free_mem(char process_) {
		  int flag = false;
		  _dat* curr = head;
		  while (curr) {
			  if (curr->procces == process_ && curr->busy == true) {
				  curr->procces = ' ';
				  curr->busy = false;
				  flag = true;				  
				  if (curr->next && curr->next->busy == false) {
					  curr->size += curr->next->size;

					  _dat* tmp = curr->next;
					  if (curr->next->next) {
						  curr->next->next->prev = curr;
						  curr->next = curr->next->next;
						  delete tmp;

						  len--;
					  }
					  else {
						  delete tmp;
						  curr->next = NULL;

						  len--;
					  }
				  }
				  if (curr->prev && curr->prev->busy == false) {
					  curr->prev->size += curr->size;
					  curr = curr->prev;
					  _dat* tmp = curr->next;
					  if (curr->next->next) {
						  curr->next->next->prev = curr;
						  curr->next = curr->next->next;
						  delete tmp;
					  }
					  else {
						  delete tmp;
						  curr->next = NULL;
					  }
				  }
			  }
			  if (flag == false)
				  curr = curr->next;
			  else return;
		  }
	  }
};




int main() {
	Memory mem = Memory(512); // это без указателей
	mem.print();
	mem.get_mem(64);
	mem.print();
	mem.print();
	mem.get_mem(128);
	mem.print();
	mem.get_mem(32);
	mem.print();
	mem.get_mem(64);
	mem.print();
	mem.free_mem('B');
	mem.print();
	mem.free_mem('C');
	mem.print();
	mem.free_mem('D');
	mem.print();
	mem.free_mem('A');
	mem.print();
}