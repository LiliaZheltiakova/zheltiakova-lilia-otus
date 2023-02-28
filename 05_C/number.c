#include <stdio.h>
#include <stdbool.h>

void main()
{
        int a = 0;
        int b = 999;
        int count = 0;
        int n = 0;
        int answ = 0;
        for(count; count < 10; count++)
        {
                n = ((b - a) / 2) + a;

                printf("Step %d. Does your desired number is greater than %d? (1/0) \n", count, n);
                scanf("%d", &answ);

                if(answ == 1) // increase floor
                {
                        a = n + 1;
                }

                else if(answ == 0) // decrease cieling
                {
                        b = n;
                }

                else
                {
                        printf("Answer isn't correct (%d) \n", answ);
                        return;
                }
        }

        printf("Your number is(%d) \n", a);
}
