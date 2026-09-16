#include <iostream>
#include <vector>
using namespace std;

/*
OCP + SRP:
- Extend behavior without modifying existing code
- Separate responsibilities
*/

//  1. Product (Data only)
class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

// 2. ShoppingCart (Manages products)
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

    // Destructor to free memory
    ~ShoppingCart() {
        for (auto p : products) {
            delete p;
        }
    }
};

// 3. Pricing Strategy (Abstraction)
class PricingStrategy {
public:
    virtual double calculate(double total) = 0; // Pure virtual  function
    virtual ~PricingStrategy() {}
};

//  4. Concrete Strategies (Extension without modification)

// No extra charges
class NoTax : public PricingStrategy {
public:
    double calculate(double total) override {
        return total;
    }
};

// GST Strategy
class GSTStrategy : public PricingStrategy {
private:
    double percent;

public:
    GSTStrategy(double percent) {
        if (percent < 0 || percent > 100) {
            throw invalid_argument("GST must be between 0 and 100");
        }
        this->percent = percent;
    }

    double calculate(double total) override {
        return total + (total * percent / 100.0);
    }
};

// Discount Strategy
class DiscountStrategy : public PricingStrategy {
private:
    double discount_perc;

public:
    DiscountStrategy(double discount) {
        if (discount < 0 || discount > 100) {
            throw invalid_argument("Discount must be between 0 and 100");
        }
        this->discount_perc = discount;
    }

    double calculate(double total) override {
        return total-(total * discount_perc/100);
    }
};

//  5. Invoice Printer (Only printing)
class InvoicePrinter {
public:
    void print(const ShoppingCart* cart, PricingStrategy* strategy) {
        cout << "\n--- Shopping Cart Invoice ---\n";

        for (auto p : cart->getProducts()) {
            cout << p->name << " INR - " << p->price << endl;
        }

        double total = cart->calculateTotal();
        double finalTotal = strategy->calculate(total);

        cout << "Final Total: INR " << finalTotal << endl;
    }
};

//  6. Storage (Persistence only)
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

    //  Choose strategy dynamically
    PricingStrategy* strategy;

    int choice;
    cout << "\nChoose Pricing Strategy:\n";
    cout << "1. No Tax\n2. GST\n3. Discount\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        strategy = new NoTax();
    } else if (choice == 2) {
        double gst;
        cout << "Enter GST %: ";
        cin >> gst;
        strategy = new GSTStrategy(gst);
    } else {
        double discount;
        cout << "Enter Discount percent: ";
        cin >> discount;
        strategy = new DiscountStrategy(discount);
    }

    printer->print(cart, strategy);

    ShoppingCartStorage* storage = new ShoppingCartStorage();
    storage->saveToDB(cart);

    //  Cleanup
    delete strategy;
    delete printer;
    delete storage;
    delete cart;

    return 0;
}