/*************************************************************************
	> File Name: EP07_4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月19日 星期二 21时28分17秒
 ************************************************************************/
#include <stdio.h>
#define MAX_N 100xssxsxxsxsxsxccx

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};

int main() {
    for (int M = 2; M <= MAX_N; M++) {
        if (!is_prime[M]) {
            prime[++prime[0]] = M;
        }
        for (int j = 1, p = prime[1]; j <= prime[0]; j+= 1, p = prime[j]) {
            if (p * M > MAX_N) break;
            is_prime[p * M] = p;
            prime[p * M] = p;
            if (M % p == 0) break;
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        printf("%d ", prime[i]);
    }
    return 0;
}
