#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin(int id, string name, string email, Catalog *catalog)
    : id(id), name(name), email(email), catalog(catalog) {
    cout << "Admin created" << endl;
}

void Admin::addProduct(int id, string name, string category, int price) {
    cout << "!111111111111111111111111111111111111111111111111111111111";
    // catalog->addProduct(id, name, category, price);
}

// void Admin::updateProduct(int id, string name, string category, int price) {
//     catalog->updateProduct(id, name, category, price);
// }

// void Admin::deleteProduct(int id) {
//     catalog->deleteProduct(id);
// }
