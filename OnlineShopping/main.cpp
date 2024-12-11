#include<iostream>
#include "Admin.h"
#include "Catalog.h"
using namespace std;

int main(){
    cout << "1" << endl;
    Catalog catalog;
    Admin admin(1, "Tushar", "tushar@gmail.com", &catalog);
    // admin.addProduct(1, "Mouse", "Electronics", 500);
    return 0;
}