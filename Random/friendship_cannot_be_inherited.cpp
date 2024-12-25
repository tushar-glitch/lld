#include <iostream>

class Foo{
  int a;
  public:
  friend class Bar;
  void A(){
      std::cout<<a<<"\n";
  }
};

class Bar{
  int b;
  public:
  Bar() = default;
  Bar(int _b):b{_b}{};
  void test(int _a, Foo &obj){
      obj.a = _a;
  }
  void B(){
      std::cout<<b<<"\n";
  }
};

class FooBar:public Bar{
    int c;
      public:
      FooBar(int _c):c{_c}{};
      void test(int _a, Foo &obj){
          obj.a = _a;
      }
      void C(){
          std::cout<<c<<"\n";
      }
};

int main()
{
    Foo _foo;
    Bar _bar{5};
    _bar.test(9, _foo);
    _foo.A();
    _bar.B();
    return 0;
}