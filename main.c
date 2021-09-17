#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double function(double x)
{
    return pow(x ,3)-x-3;
}

double derivative(double x)
{
    return 3*(x*x)-1;
}

double NR(double b)
{
    return b - ( function(b)/derivative(b) );
}

double RF(double a ,double b)
{
    return (a * function(b) - b * function(a) ) / ( function(b) - function(a) );
}

double getAbs(double regula ,double newton)
{
    if( regula-newton < 0)
        return -(regula-newton);
    else
        return (regula-newton);
}

int main()
{
    double epsilon = 0.000001;
    double a=1.3 ,b=2;
    double newton = NR(b);
    double regula = RF(a ,b);
    while ( getAbs(regula,newton) > epsilon )
    {
        printf("Newton :%-8f\nRegula :%-8f\n%f<%f\n\n",newton ,regula ,getAbs(regula,newton) ,epsilon);
        newton = NR(newton);
        regula = RF(regula ,newton);
    }
    printf("Newton :%-8f\nRegula :%-8f\n%f<%f\n",newton ,regula ,getAbs(regula,newton) ,epsilon);
}
