#include <iostream>
#include "MathFunctions.h"

// a hack square root calculation using simple operations
double mysqrt(double input_num)
{
	if(input_num<=0)
	{
		return 0;
	}
	double result,delta;
	result = input_num;
	delta = 0.0;
	int sqrt_iter = 0;
	// do ten iterations
	for(sqrt_iter=0; sqrt_iter<10; ++sqrt_iter)
	{
		if(result <=0)
		{
			result = 0.1;
		}
		delta = input_num-(result*result);
		result = result + 0.5*delta/result;
		//fprintf(stdout,"Computing sqrt of %g to be %g\n",x,result);
	}
	return result;
}
