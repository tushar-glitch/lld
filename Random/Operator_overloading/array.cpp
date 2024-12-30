#include <iostream>
using namespace std;

class IntArray{
  int* startingAddress;
  int sizeOfArray;
  public:
  IntArray(int size){
      startingAddress = new int();
      int *ptr = startingAddress;
      sizeOfArray = size;
      for(int i=0;i<size;++i){
          *ptr = 1;
          ptr++;
      }
  }
  friend ostream& operator<<(ostream&, IntArray&);
  
  int& operator[](int index){
      int* ptr = startingAddress;
      ptr += index;
      return *ptr;
  }
  
};

ostream& operator<<(ostream& out, IntArray& obj){
    int size = obj.sizeOfArray;
    int *ptr = obj.startingAddress;
    for(int i=0;i<size;++i){
        out<<*ptr<<" ";
        ptr++;
    }
    return out;
}


IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
    IntArray a{ fillArray() };

	std::cout << a << '\n';
    return 0;
}