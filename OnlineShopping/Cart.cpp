#include<iostream>
#include<unordered_map>
#include<string>
#include "Product.cpp"
#include "Catalog.cpp"

using namespace std;

class Cart{
    unordered_map<int, int> cartProducts;

    public:
    void addProductToCart(int id, int amountOfProduct, Catalog& catalog){
        if(!catalog.isProductInInventory(id)){
            cout << "No product found." << endl;
        }
        else{
            cartProducts[id] = amountOfProduct;
            cout << "Product(s) added to cart." << endl;
        }
    }

    void deleteProduct(int id, Catalog& catalog){
        if(!catalog.isProductInInventory(id)){
            cout << "No product found." << endl;
        }
        else{
            cartProducts.erase(id);
            cout << "Product(s) deleted from cart." << endl;
        }
    }
};