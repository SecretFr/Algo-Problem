/*
 * problem.c
 *
 *  Created on: 2018. 7. 4.
 *      Author: Administrator
 */

#include <stdio.h>
#include <stdlib.h>

int find_max_index(int *A, int s, int e)
{
    int v;
    int i;
    int k;
    v = 0;
    i = 0;
    for(k = s; k < e; k++){
        if(A[k] > v){
            v = A[k];
            i = k;
        }
    }
    return i;
}

/*int main()
{
    int T, N, i, j;
    scanf("%d",&T);

    for(i = 0; i< T; i++){
        scanf("%d", &N);
        int *S, *P;
        S= (int*)malloc(sizeof(int)*N);
        P= (int*)malloc(sizeof(int)*N);

        for(j = 0; j < N; j++){
            scanf("%d ", &S[j]);
        }
        for(j = 0; j < N; j++){
            P[j] = -1;
        }
        int local_max_ind;
        int sp = 0;
        int ep = N;
        do{
            local_max_ind = find_max_index(S, sp, ep);
            P[local_max_ind] = 0;
            sp = local_max_ind +1;
            ep = N;
        }while( local_max_ind != N-1);

        int num = 0;
        long long cost = 0;
        for(j = 0; j < N; j++){
            if(P[j] == -1){ //buy
                num++;
                cost += P[j] *S[j];
            }
            else{//Sell
                cost += num*S[j];
                num = 0;
            }
        }
        printf("#%d %lld\n", i+1, cost);

        free(S);
        free(P);
    }
    return 0;
}*/

int main(void){
	int T, i, N, j;

	scanf("%d", &T);
	for(i=0; i<T; i++){
		scanf("%d", &N);
		int *P;
		P = (int*)malloc(sizeof(int)*N);
		for(j=0; j<N; j++){
			scanf("%d", &P[j]);
		}
		long long max = P[N-1];
		long long sum = 0;
		for(j=N-2; j>=0; j--){
			if(max>P[j]){
				sum += max-P[j];
			}
			else{
				max = P[j];
			}
		}
		printf("#%d %lld\n", i+1, sum);
		free(P);
	}

	return 0;
}
