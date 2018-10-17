
#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

#include <dll1/dll1.h>

int main()
{
    typedef std::istream_iterator<int> in;

	Dll1 dll1;

    std::cout << "Type in any number: ";
	std::cout << "teste: " << dll1.getText() << std::endl;

    std::for_each(
        in(std::cin), in(), std::cout 
				<< (boost::lambda::_1 * 10) 
				<< "\nType in another number: " );
    return 0;
}
