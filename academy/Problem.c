/*
 * Problem.c
 *
 *  Created on: 2018. 7. 3.
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>

int Hall[201];
int main()
{

    int i, j, k, T, N, A, B;
    scanf("%d", &T);
    for (k = 1; k <= T; k++)
    {
        scanf("%d", &N);
        for (i = 1; i <= N; i++)
        {
            scanf("%d %d", &A, &B);
            if (A <= B)
            {
                for (j = (A + 1) / 2; j <= (B + 1) / 2; j++)
                {
                    Hall[j]++;
                }
            }
            else
            {
                for (j = (B + 1) / 2; j <= (A + 1) / 2; j++)
                {
                    Hall[j]++;
                }
            }
        }
        int ans = 0;
        for (i = 1; i <= 200; i++)
        {
            if (ans < Hall[i])
            {
                ans = Hall[i];
            }
            Hall[i] = 0;
        }
        printf("#%d %d\n", k, ans);
    }
}
