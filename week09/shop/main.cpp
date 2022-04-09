#include <iostream>
#include "customer.h"

/*
customers have a shopping list, which contains the name of the products they would like to buy.
,but they buy differently at the two departments. At the food department,they just put the first
product they find into their cart.
At the technical department, they always buy the cheapest product from
among products with the same name. Simulate the purchasing proces

 */

using namespace std;

int main()
{
    Customer c("customer1.txt");
    Store s("foods.txt", "technical.txt");
    cout << c.getName() << " has bought the following products:\n"
         << c.purchase(s);
    return 0;
}
