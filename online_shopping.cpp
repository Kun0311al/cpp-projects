#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    int price;

    Product(string n, int p) {
        name = n;
        price = p;
    }

    void display() {
        cout << "Product Name: " << name << "\tPrice: " << price << endl;
    }
};

class Customer {
public:
    string name;
    string email;
    vector<Product> cart;

    Customer(string n, string e) {
        name = n;
        email = e;
    }

    void displayCart() {
        if (cart.empty()) {
            cout << "Your cart is empty." << endl;
        } else {
            cout << "Your cart: " << endl;
            for (Product p : cart) {
                p.display();
            }
        }
    }

    void checkout() {
        if (cart.empty()) {
            cout << "Your cart is empty. Please add products to your cart." << endl;
        } else {
            int total = 0;
            for (Product p : cart) {
                total += p.price;
            }
            cout << "Total amount to be paid: " << total << endl;
            cout << "Thank you for shopping with us!" << endl;
            cart.clear();
        }
    }
};

class OnlineShop {
public:
    vector<Product> products;

    OnlineShop() {
        products.push_back(Product("Product 1", 100));
        products.push_back(Product("Product 2", 200));
        products.push_back(Product("Product 3", 300));
        products.push_back(Product("Product 4", 400));
    }

    void displayProducts() {
        cout << "Available products: " << endl;
        for (Product p : products) {
            p.display();
        }
    }

    void addToCart(Customer &c, int index) {
        if (index < 0 || index >= products.size()) {
            cout << "Invalid product index. Please try again." << endl;
        } else {
            Product p = products[index];
            c.cart.push_back(p);
            cout << "Product added to cart: " << p.name << endl;
        }
    }
};

int main() {
    OnlineShop shop;
    Customer c("John Doe", "johndoe@gmail.com");

    cout << "Welcome to the Online Shopping System!" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. View Products" << endl;
    cout << "2. Add Product to Cart" << endl;
    cout << "3. View Cart" << endl;
    cout << "4. Checkout" << endl;
    cout << "5. Exit" << endl;

    int option = 0;
    while (option != 5) {
        cout << "Enter option number: ";
        cin >> option;
        switch (option) {
            case 1:
                shop.displayProducts();
                break;
            case 2:
                int index;
                cout << "Enter product index: ";
                cin >> index;
                shop.addToCart(c, index);
                break;
            case 3:
                c.displayCart();
                break;
            case 4:
                c.checkout();
                break;
            case 5:
                cout << "Thank you for using the Online Shopping System." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }

    return 0;
}
