#include <cstring>
#include <string>
#include <lib1/lib1.h>

#include "dll1/dll1.h"

#include "ClasseA.h"

Dll1::Dll1(){}
Dll1::~Dll1(){}

const std::string Dll1::getText(){

	Lib1 lib1;


	std::string a(ClasseA::value());
	std::string b(lib1.getText());
	
	std::string valor = a+" "+b;

	for( const auto &x: {1,2,3,5}){
		valor = valor + "\n" + std::to_string(x);
	}


	return valor;
}
