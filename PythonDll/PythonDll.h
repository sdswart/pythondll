// PythonDll.h - Contains declaration of Function class  
#pragma once  

#ifdef PYTHONDLL_EXPORTS  
#define PYTHONDLL_API __declspec(dllexport)   
#else  
#define PYTHONDLL_API __declspec(dllimport)   
#endif  

namespace PYTHONDLL
{
	// This class is exported from the PythonDll.dll  
	class Functions
	{
	public:
		// Returns a + b  
		static PYTHONDLL_API double Test(double a);
	};
}
