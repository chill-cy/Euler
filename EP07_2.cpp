/*************************************************************************
	> File Name: EP07_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月19日 星期二 18时12分41秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 200000

int prime[MAX_N + 5] = {0};
void init() {
    for (int i = 2; i * i <= MAX_N; i++) {//根号n 是所求值的最大值
        if (prime[0]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {//j要比i大，比如3(i) * 5(j), 5(i) * 3(j)　j < i 的情况已经被计算过了，　所以无需重复计算
            prime[j] = 1;
        }
    }
    for (int j = 2; j <= MAX_N; j++) {
        if (prime[j]) continue;
        prime[++prime[0]] = j;
    }
    return ;
}


int main () {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
//1毫秒可以做几百万次运算
//欧几里得算法
