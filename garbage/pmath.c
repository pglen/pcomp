/*--------------------------------------------------------------------------
**  Math functions
*/

#include <stdio.h>
#include <math.h>

double  Log2( double x)

{
   return errcheck( log(x), "log") ;
}


double Log10( double x)
{
   return errcheck( log10(x), "log10") ;
}

double Exp( double x)
{
   return errcheck( exp(x), "exp") ;
}

double Pow( double x, double y)
{
   return errcheck( pow(x, y), "exponentiation") ;
}

double integer( double x)
{
   return (double)(long) x ;
}

double Sqrt( double x)
{
   return errcheck( sqrt(x), "sqrt") ;
}


#if 0

int main()

{
    int x = 10;
    double aa = sqrt(10000);
    printf("nn %lf\n", aa);
    double bb = exp(2);
    printf("ee %lf\n", bb);
}

#endif
