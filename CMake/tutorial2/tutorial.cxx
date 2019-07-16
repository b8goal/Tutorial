// A simple program that computes the square root of a number
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif
int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    // fprintf(stdout, "%s Version %d.%d\n",
    // 		argv[0],
    // 		Tutorial_VERSION_MAJOR,
    // 		Tutorial_VERSION_MINOR);
    //   fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
  }
  double inputValue = atof(argv[1]);
#ifdef USE_MYMATH
  double outputValue = mysqrt(inputValue);
#else
  double outputValue = sqrt(inputValue);
#endif
  std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;
  return 0;
}
