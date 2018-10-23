//
// Created by ejunior on 22-Oct-18.
//

#include <boost/format.hpp>
#include <utility>
#include <iostream>
using namespace std;
using namespace boost;

auto sum_product(double a, double b){
    return make_tuple(a, b, a+b, a*b);
}

int main(){
    auto x = sum_product(1.2,2);
    auto y = make_pair(get<2>(x), get<3>(x));

    std::cout << get<0>(x) << ", "<< get<1>(x);

    std::cout << format(" sum is %1% and multiply is %2%") % y.first % y.second << "\n";
}