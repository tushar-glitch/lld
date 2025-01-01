#include <iostream>
using namespace std;

template <typename T>
class smartpointer{
  T* _ptr;
  public:
  smartpointer(T* ptr): _ptr{ptr}{};
  ~smartpointer(){
      delete _ptr;
  }
  T& operator*() const{
      return *_ptr;
  }
  T& operator->() const{
      return _ptr;
  }
};

class Resource{
  public:
  Resource(){
      cout<<"Resource acquired!"<<endl;
  }
  
  ~Resource(){
      cout<<"Resource deallocation!"<<endl;
  }
};


int main()
{
    smartpointer<Resource> res(new Resource());
    return 0;
}