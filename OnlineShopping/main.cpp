#include<iostream>
#include "Admin.cpp"
#include "Catalog.cpp"
using namespace std;

int main(){
    Catalog catalog;
    Admin admin(1, "Tushar", "tushar@gmail.com", &catalog);
    admin.addProduct(1, "Mouse", "Electronics", 500);
    return 0;
}