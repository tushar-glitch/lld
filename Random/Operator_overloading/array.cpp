#include <iostream>
using namespace std;

class IntArray{
  int* startingAddress;
  int sizeOfArray;
  public:
  IntArray(int size){
      startingAddress = new int[size];
      int *ptr = startingAddress;
      sizeOfArray = size;
      for(int i=0;i<size;++i){
          *ptr = 1;
          ptr++;
      }
  }
  ~IntArray(){
      delete startingAddress;
  }
  friend ostream& operator<<(ostream&, IntArray&);
  
  int& operator[](int index){
      int* ptr = startingAddress;
      ptr += index;
      return *ptr;
  }
  
  void operator=(const IntArray& obj2){
      int newSize = obj2.sizeOfArray;
      this->sizeOfArray = newSize;
      int *ptr1 = this->startingAddress,*ptr2 = obj2.startingAddress;
      for(int i=0;i<newSize;++i){
          *ptr1 = *ptr2;
          ptr1++;
          ptr2++;
      }
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

	auto& ref{ a };
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';
    // IntArray arr(100);
    // for(int i=0;i<1000;++i) arr[i] = i;
    // cout<<arr<<endl;
    return 0;
}