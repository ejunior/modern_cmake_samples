// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "version.h"

int main (int argc, char *argv[])
{
  if (argc < 2)
    {
    fprintf(stdout,"%s Version %d.%d.%d\n",
            argv[0],
            _VERSION_MAJOR,
            _VERSION_MINOR,
            _VERSION_PATCH);
    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
    }

    //cout <<

  double inputValue = atof(argv[1]);
  double outputValue = sqrt(inputValue);
  fprintf(stdout,"The square root of %g is %g\n",
          inputValue, outputValue);
  return 0;
}