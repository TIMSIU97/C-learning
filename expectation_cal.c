#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    float pw, exp, rate, capital;

    while (1) {
        printf("*****just for fun*****\n\r");
        printf("pls enter the win rate, eg: 0.55\n\r");
        scanf("%f",&pw);
        getchar();
        printf("***********************************\n\r");
        printf("pls enter the profit rate, eg: 0.86\n\r");
        scanf("%f",&rate);
        getchar();
        printf("***********************************\n\r");
        printf("pls enter the principle, eg: 100\n\r");
        scanf("%f",&capital);
        getchar();

        if (capital > 0 && rate > 0) {
            if (pw < 1 && pw > 0) {
                exp = (capital * rate * pw) - (capital * (1 - pw));
            } else {
                printf("***********************************\n\r");
                printf("pw must be smaller than 1\n\r");
                getchar();
                continue;
            }
        }

        if (exp > 0) {
            printf("***********************************\n\r");
            printf("worth to bet, exp = %f\n\r",exp);
            getchar();
        } else if (exp < 0) {
            printf("***********************************\n\r");
            printf("not worth to bet, exp = %f\n\r",exp);
            getchar();
        } else {
            printf("***********************************\n\r");
            printf("exp = 0\n\r");
            getchar();
        }
    }

    return 0;
}