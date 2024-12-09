#include<iostream>
#include<string>
#include "Catalog.cpp"

using namespace std;
class Admin{
    int id;
    string name, email;
    Catalog *catalog;

    public:
        Admin(int id, string name, string email, Catalog *catalog) : id(id), name(name), email(email), catalog(catalog)
        {
        cout << "Admin created" << endl;
        }

        void addProduct(int id, string name, string category, int price){
            catalog->addProduct(id, name, category, price);
        }

        // void updateProduct(int id, string name, string category, int price){
        //     catalog->updateProduct(id, name, category, price);
        // }

        // void deleteProduct(int id){
        //     catalog->deleteProduct(id);
        // }
};