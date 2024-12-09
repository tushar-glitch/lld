#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include "Product.cpp"
using namespace std;


class Catalog{
    unordered_map<int, int> products;

public:
    void addProduct(int id, string name, string category, int price){
        cout << "1";
        Product product(id, name, category, price);
        cout << "2";
        products[id]=0;
        cout << "3";
        cout << "Product added successfully." << endl;
        cout<<"Details:" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Price: " << price << endl;
    }

    // void updateProduct(int id, string name, string category, int price){
    //     if(isProductInInventory(id)){
    //         cout<<"No product with this id found."<<endl;
    //     }
    //     else{
    //         Product product(id, name, category, price);
    //         products[id] = product;
    //         cout<<"Product updated successfully."<<endl;
    //     }
    // }
    
    // void deleteProduct(int id){
    //     if(isProductInInventory(id)){
    //         cout<<"No product with this id found."<<endl;
    //     }
    //     else{
    //         products.erase(id);
    //         cout<<"Product deleted successfully."<<endl;
    //     }
    // }

    bool isProductInInventory(int id){
        return (products.find(id) != products.end());
    }
    
    // void addCategory(string name){
        
    // }
};