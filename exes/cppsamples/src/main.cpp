//
// Created by ejunior on 22-Oct-18.
//

#include <boost/format.hpp>
#include <utility>
#include <iostream>

#include "samples.h"

using namespace std;
using namespace boost;

auto sum_product(double a, double b) -> decltype(make_tuple(a, b, a + b, a * b)) { // -> not needed c++ 14
    return make_tuple(a, b, a + b, a * b);
}

void printName(const string &s) {
    cout << "normal reference " << s << "\n";
}

void printName(string &&s) {
    cout << "rvalue reference " << s << "\n";
}

template<typename T>
void newPrintName(T t) {
    cout << "now with template function " << t << "\n";
}


int main() {
    auto x = sum_product(1.2, 2);
    auto y = make_pair(get<2>(x), get<3>(x));

    cout << get<0>(x) << ", " << get<1>(x) <<", " << get<3>(x);  // ugly as hell

    cout << format(" sum is %1% and multiply is %2%") % y.first % y.second << "\n";

    string &&nome = getName();

    nome = "Edmilson";

    cout << nome << " " << getName() << "\n";
    cout << getName() << "\n\n";

    printName(nome);
    printName(getName());

    newPrintName(nome);
    newPrintName(getName());


}