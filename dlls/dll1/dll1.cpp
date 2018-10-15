#include "dll1.h"
#include "../../libsrc/lib1/lib1.h"

Dll1::Dll1(){}
Dll1::~Dll1(){}
const char* Dll1::getText(){
	Lib1 lib1;

	return lib1.getText();
}
