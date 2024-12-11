// Catalog.h
#ifndef CATALOG_H
#define CATALOG_H

#include <unordered_map>
#include <string>
#include "Product.h"  // Include the Product class header

class Catalog {
    std::unordered_map<int, Product> products;

public:
    void addProduct(int id, std::string name, std::string category, int price);
    bool isProductInInventory(int id);
};

#endif
