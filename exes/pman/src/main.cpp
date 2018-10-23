
#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <dll1/dll1.h>

int main()
{
    typedef std::istream_iterator<int> in;

	Dll1 dll1;

	auto text = dll1.getText();
    std::cout << "teste: " << text << "\n\n";

//    std::cout << "Type in any number: ";

//    std::for_each(
//        in(std::cin), in(), std::cout
//				<< (boost::lambda::_1 * 10)
//				<< "\nType in another number: " );
    return 0;
}
