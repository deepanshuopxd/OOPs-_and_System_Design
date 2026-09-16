#include <iostream>
#include <vector>
using namespace std;
/*
SRP(Single Responsibility Principle): Each class has ONLY ONE responsibility
*/
// 1. Product → Data
class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

// 2. ShoppingCart → Manages products
class ShoppingCart {
private:
    vector<Product*> products;

public:
    void addProduct(Product* p) {
        products.push_back(p);
    }

    const vector<Product*>& getProducts() const {
        return products;
    }

    double calculateTotal() const {
        double total = 0;
        for (auto p : products) {
            total += p->price;
        }
        return total;
    }

    //  Destructor to avoid memory leak
    ~ShoppingCart() {
        for (auto p : products) {
            delete p;
        }
    }
};

// 3. PricingService → Pricing logic
class PricingService {
public:
    static double applyGST(double total, double gstPercent) {
        return total + (total * gstPercent / 100.0);
    }
};

// 4. InvoicePrinter → Printing
class InvoicePrinter {
public:
    void print(const ShoppingCart* cart) {
        cout << "Shopping Cart Invoice\n";
        for (auto p : cart->getProducts()) {
            cout << p->name << " : INR -> " << p->price << endl;
        }
        cout << "Total: INR " << cart->calculateTotal() << endl;
    }

    void printWithGST(const ShoppingCart* cart, double gstPercent) {
        double total = cart->calculateTotal();
        double finalTotal = PricingService::applyGST(total, gstPercent);

        cout << "\nInvoice with GST (" << gstPercent << "%)\n";
        cout << "Final Total: INR " << finalTotal << endl;
    }
};

// 5. Storage → Persistence
class ShoppingCartStorage {
public:
    void saveToDB(const ShoppingCart* cart) {
        cout << "Saving to Database...\n";
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("MacBook", 100000));
    cart->addProduct(new Product("Keyboard", 1000));
    cart->addProduct(new Product("Mouse", 550));
    cart->addProduct(new Product("iPad", 67000));
    cart->addProduct(new Product("iPhone", 133000));

    InvoicePrinter* printer = new InvoicePrinter();
    printer->print(cart);

    double gst;
    cout << "\nEnter GST %: ";
    cin >> gst;

    printer->printWithGST(cart, gst);

    ShoppingCartStorage* storage = new ShoppingCartStorage();
    storage->saveToDB(cart);

    delete printer;
    delete storage;
    delete cart;

    return 0;
}