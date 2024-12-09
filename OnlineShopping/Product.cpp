#include <iostream>
#include <string>
using namespace std;

class Product {
    int id;
    string name, category;
    int price;

public:
    Product() : id(-1), name("Test"), category("Test"), price(0) {}

    Product(int id, string name, string category, int price)
        : id(id), name(name), category(category), price(price) {}

    // Copy constructor
    Product(const Product &other) {
        cout << "Copy constructor called" << endl;
        id = other.id;
        name = other.name;
        category = other.category;
        price = other.price;
    }

    // Move constructor
    Product(Product &&other) noexcept {
        cout << "Move constructor called" << endl;
        id = other.id;
        name = std::move(other.name);
        category = std::move(other.category);
        price = other.price;
    }

    // Copy assignment operator
    Product &operator=(const Product &other) {
        cout << "Copy assignment operator called" << endl;
        if (this != &other) {
            id = other.id;
            name = other.name;
            category = other.category;
            price = other.price;
        }
        return *this;
    }

    // Move assignment operator
    Product &operator=(Product &&other) noexcept {
        cout << "Move assignment operator called" << endl;
        if (this != &other) {
            id = other.id;
            name = std::move(other.name);
            category = std::move(other.category);
            price = other.price;
        }
        return *this;
    }
};
