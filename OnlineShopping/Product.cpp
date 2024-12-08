#include<iostream>
#include<string>
using namespace std;

class Product{
    int id;
    string name, category;
    int price;

    public:
    Product(int id, string name, string category, int price) : id(id), name(name), category(category), price(price) {}
};