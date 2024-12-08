#include<iostream>
#include<string>
#include "Product.cpp"
using namespace std;
class Admin{
    int id;
    string name, email;
    public:
        Admin(int id, string name, string email) : id(id), name(name), email(email) {}
};