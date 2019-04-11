/*************************************************************************
	> File Name: EP07_3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月19日 星期二 18时57分26秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 200000

int prime[MAX_N] = {0};
int main() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {//标记i的倍数
            if (prime[j]) continue;//添加此句判断使j的素因子不会被更新，始终保存的是最小的素因子
            //如果i不是素数继续下次循环，直到找到素数将其倍数置为i，即i是j的最小素因子
            prime[j] = i;
        }
    }
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d = 1", n);
        while (n != 1) {
            printf(" * %d", prime[n]);
            n /= prime[n];
        }
    }
    printf("\n");
    return 0;
}
