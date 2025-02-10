#include <stdio.h>
int main ()
{

    float celsius;
    float fah;
    for(celsius=50; celsius<=150; celsius++)
    {
        fah=((9*celsius)/5)+32;

        printf("%.0f C--------%.1f F\n\n", celsius,fah);

    }

    return 0;

}
