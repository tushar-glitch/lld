// Product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
    int id;
    string name, category;
    int price;

public:
    Product();
    Product(int id, string name, string category, int price);
    Product(const Product &other);
    Product(Product &&other) noexcept;

    // Copy assignment operator
    Product &operator=(const Product &other);

    // Move assignment operator
    Product &operator=(Product &&other) noexcept;
};

#endif
