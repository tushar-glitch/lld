#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "Catalog.h"

using namespace std;

class Admin {
    int id;
    string name, email;
    Catalog *catalog;

public:
    Admin(int id, string name, string email, Catalog *catalog);

    void addProduct(int id, string name, string category, int price);
    // void updateProduct(int id, string name, string category, int price);
    // void deleteProduct(int id);
};

#endif
