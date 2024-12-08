#include<iostream>
#include<unordered_map>
#include<string>
#include "Product.cpp"
using namespace std;

class Catalog{
    unordered_map<int, Product> items;

    public:
    void addProduct(string name, string category, int price){
        int id = 10;
        Product product(id, name, category, price);
    }
};