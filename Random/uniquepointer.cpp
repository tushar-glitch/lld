#include <iostream>

template <typename T>
class uniquePointer{
    public:
    explicit uniquePointer(T* ptr = nullptr):m_ptr(ptr){};
    
    uniquePointer(const uniquePointer& other) = delete;
    uniquePointer& operator=(const uniquePointer& other) = delete;
    
    uniquePointer(uniquePointer& other){
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }
    
    void operator=(uniquePointer& other){
        if(this != &other){
            delete m_ptr;
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
    }
    
    ~uniquePointer(){
        delete m_ptr;
    }
    T& operator*(){
        return *m_ptr;
    }
    
    T* operator->(){
        return m_ptr;
    }
    private:
    T* m_ptr;
};

int _global = 1;

int main(){
    uniquePointer<int> obj (new int(2));
    std::cout<<*obj;
    uniquePointer<int> obj2(obj);
    std::cout<<*obj2;
    uniquePointer<int> obj3 (new int(5));
    obj3 = obj2;
    std::cout<<*obj3;
    
    return 0;
}