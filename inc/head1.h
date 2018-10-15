#ifndef HEAD1_H
#define HEAD1_H

class Head1
{
public:
	Head1(){}
	~Head1(){}

	inline const char* getText(){
		#ifndef TEST_DEF
			return "TEST_DEF defined";
		#else
			return "TEST_DEF _NOT_ defined";
		#endif
	}
};

#endif
