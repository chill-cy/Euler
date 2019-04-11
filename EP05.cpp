/*************************************************************************
	> File Name: EP05.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月19日 星期二 23时08分00秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 10000

int prime[MAX_N + 5] = {0};//存储i个素数的值
int is_prime[MAX_N + 5] = {0};//判断第i个数是否为素数
int main() {
    for (int M = 2; M <= MAX_N; M++) {
        if (!is_prime[M]) {
            prime[++prime[0]] = M;//将M放入素数表中
        }
        for (int j = 1, p = prime[1]; j <= prime[0]; j += 1, p = prime[j]) {
            //p一定小于等于Ｍ的最小素因子
            //用Ｍ整数标记素数倍数，如M = 15时标记其素数倍数15 * 2, 15 * 3;
            if (p * M > MAX_N) break;
            is_prime[p * M] = 1;
            if (M % p == 0) break;//p已经枚举到了M中的最小素因子
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        //prime[i]存第i个素数，is_prime[i]表示i这个数字是不是素数
        printf("%d ", prime[i]);   //打印素数表
    }
    printf("\n");
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d is prime = %d\n", n, is_prime[n]);//n是不是素数
    }
    return 0;
}
