#include <iostream>
using namespace std;

class Complex{
    int x, y;
    
    public:
        Complex(){
            x = 0, y = 0;
        }
        Complex(int i, int j){
            x = i, y = j;
        }
        Complex operator+(Complex op){
            Complex temp;
            temp.x = x + op.x;
            temp.y = y + op.y;
            return temp;
        }
        void show(){
            cout<<x<<" "<<y<<endl;
        }
};

int main()
{
    Complex a(1,3), b(2, 4);
    Complex c = a+b;
    c.show();
    return 0;
}



// 2nd method - 
// #include <iostream>
// using namespace std;

// class Complex{
//     int x, y;
    
//     public:
//         Complex(){
//             x = 0, y = 0;
//         }
//         Complex(int i, int j){
//             x = i, y = j;
//         }
//         Complex operator+(Complex op);
//         void show(){
//             cout<<x<<" "<<y<<endl;
//         }
// };

// Complex Complex::operator+(Complex op){
//     Complex temp;
//     temp.x = x + op.x, temp.y = y + op.y;
//     return temp;
// }

// int main()
// {
//     Complex a(1,3), b(2, 4);
//     Complex c = a+b;
//     c.show();
//     return 0;
// }