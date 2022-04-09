#include "customer.h"
#include "product.h"

using namespace std;

Customer::Customer(const string &fname)
{
    ifstream f;
    f.open(fname);
    f >> name;
    string s;
    while(f >> s) {
        list.push_back(s);
    }
    f.close();
}

std::string Customer::purchase(const Store &store)
{
	std::stringstream output;
    for (string productName : list) {
        Product* product;
        if (linsearch(productName, store.foods, product)) {
            cart.push_back(product);
            output << product->getName() << " " << product->getPrice() << endl;
            store.foods->takeOutFromStock(product); // instead of store.foods->_stocks->remove()
        }
    }
    for (string productName : list) {
        Product *product;
        if (condminsearch(productName, store.technical, product)) {
            cart.push_back(product);
            output <<  product->getName() << " " << product->getPrice() << endl;
            store.technical->takeOutFromStock(product); // instead of store.foods->_stocks->remove()
        }
    }
	return output.str();
}

bool Customer::linsearch(std::string name, Department* d, Product* &product) const
{
    bool l = false;
    for(Product* p : d->_stock ) {
        if ( ( l = (name == p->getName()) ) ) {
            product = p; break;
        }
    }
    return l;
}

bool Customer::condminsearch(std::string name, Department* d, Product* &product) const
{
    bool l = false;
    int min;
    for(Product* p : d->_stock )  {
        if (p->getName() != name) continue;
        if (l) {
            if (min > p->getPrice()) {
                min = p->getPrice();
                product = p;
            }
        }
        else  {
            l = true;
            min = p->getPrice();
            product = p;
        }
    }
    return l;
}
