#include<iostream>
#include<unordered_map>
#include<string>
#include "Product.cpp"
using namespace std;

bool isProductInInventory(int id, unordered_map<int, Product>& products){
    return (products.find(id) != products.end());
}

class Catalog{
    unordered_map<int, Product> products;

    public:
    void addProduct(string name, string category, int price){
        int id = 10;
        Product product(id, name, category, price);
        products[id]=product;
    }

    void updateProduct(int id, string name, string category, int price){
        if(isProductInInventory(id, products)){
            cout<<"No product with this id found."<<endl;
        }
        else{
            Product product(id, name, category, price);
            products[id] = product;
            cout<<"Product updated successfully."<<endl;
        }
    }
    
    void deleteProduct(int id){
        if(isProductInInventory(id, products)){
            cout<<"No product with this id found."<<endl;
        }
        else{
            products.erase(id);
            cout<<"Product deleted successfully."<<endl;
        }
    }
    
    // void addCategory(string name){
        
    // }
};