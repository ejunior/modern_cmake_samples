//
// Created by ejunior on 22-Oct-18.
//

#include <boost/format.hpp>
#include <utility>
#include <iostream>
using namespace std;
using namespace boost;

auto sum_product(double a, double b){
    return std::make_tuple(a, b, a+b, a*b);
}

int main(){
    auto x = sum_product(1.2,2);
    std::cout << get<0>(x) << ", "<< get<1>(x) << "\n";
    std::cout << format("writing %1%, %2%") % x.second % x.first % x.third << "\n";
}