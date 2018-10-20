#ifndef HEAD1_H
#define HEAD1_H

#include <string>

using namespace std;

class Head1
{
public:
	Head1() = default;
	~Head1() = default;

	const string getText(){
		#ifdef TEST_DEF
	        return string("TEST_DEF defined");
		#else
			return string("TEST_DEF _NOT_ defined");
		#endif
	}
};

#endif
