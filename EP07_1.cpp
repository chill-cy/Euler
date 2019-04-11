/*************************************************************************
	> File Name: EP07_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月19日 星期二 16时42分04秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 200000
int prime[MAX_N] = {0};

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = 2 * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
    }
    return ;
}

int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
