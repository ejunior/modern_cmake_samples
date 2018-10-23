#ifndef DLL1_H
#define DLL1_H

#ifdef WIN32
	#define FNDT_DLL_EXPORT __declspec(dllexport)
#else
 	#define FNDT_DLL_EXPORT
#endif

class Dll1
{
public:
    FNDT_DLL_EXPORT Dll1();
    FNDT_DLL_EXPORT ~Dll1();

    FNDT_DLL_EXPORT const std::string getText();

};

#endif
