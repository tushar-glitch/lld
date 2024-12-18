#include <iostream>
using namespace std;

const int maxSize = 4;

class set{
    int arr[maxSize], len;
    public:
        set(){
            len = 0;
        }
        
        void push(int ele){
            if(ele<0 || ele>=maxSize){
                cout<<"Sorry element is out of range!"<<endl;
                return;
            }
            if(len == maxSize-1){
                cout<<"Sorry set is full!"<<endl;
                return;
            }
            if(!arr[ele]) len++;
            arr[ele] = 1;
        }
        
        void pop(int ele){
            if(arr[ele]) len--;
            arr[ele] = 0;
        }
        
        int size(){
            return len;
        }
};

int main()
{
    set s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    cout<<s.size()<<endl;
    return 0;
}