#include <iostream>
#include <numeric>
using namespace std;

class Fraction{
  int num, den;
  public:
  Fraction() = default;
  Fraction(int x, int y):num{x}, den{y}{
      reduce();
  };
  void print(){
      cout<<num<<"/"<<den<<endl;
  }
  
  void reduce(){
      int hcf = gcd(num, den);
      if(hcf){
          num /= hcf;
          den /= hcf;
      }
  }
  
  friend Fraction operator*(const Fraction&, const Fraction&);
  friend Fraction operator*(int, const Fraction&);
  friend Fraction operator*(const Fraction&, int);
};

Fraction operator*(const Fraction &obj1, const Fraction &obj2){
    return {obj1.num * obj2.num, obj1.den * obj2.den};
}

Fraction operator*(int n, const Fraction &obj){
    return {obj.num * n, obj.den};
}

Fraction operator*(const Fraction &obj, int n){
    return {obj.num * n, obj.den};
}

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();
    
    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();
    return 0;
}