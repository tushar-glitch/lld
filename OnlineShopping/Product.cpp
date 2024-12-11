// Product.cpp
#include <iostream>
#include <string>
#include "Product.h"

using namespace std;

Product::Product() : id(-1), name("Test"), category("Test"), price(0) {}

Product::Product(int id, string name, string category, int price)
    : id(id), name(name), category(category), price(price) {}

Product::Product(const Product &other) {
    cout << "Copy constructor called" << endl;
    id = other.id;
    name = other.name;
    category = other.category;
    price = other.price;
}

Product::Product(Product &&other) noexcept {
    cout << "Move constructor called" << endl;
    id = other.id;
    name = std::move(other.name);
    category = std::move(other.category);
    price = other.price;
}

Product &Product::operator=(const Product &other) {
    cout << "Copy assignment operator called" << endl;
    if (this == &other) return *this;  // Handle self-assignment
    id = other.id;
    name = other.name;
    category = other.category;
    price = other.price;
    return *this;
}

Product &Product::operator=(Product &&other) noexcept {
    cout << "Move assignment operator called" << endl;
    if (this == &other) return *this;  // Handle self-assignment
    id = other.id;
    name = std::move(other.name);
    category = std::move(other.category);
    price = other.price;
    return *this;
}
