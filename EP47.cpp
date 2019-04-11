/*************************************************************************
	> File Name: EP47.cpp
	> Author: 
    > Mail: 
	> Created Time: 2019年03月31日 星期日 11时35分52秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX_N 1000000


int32_t prime[MAX_N + 5] = {0};
int32_t a[MAX_N + 5] = {0};//a[i]标记数字i有多少不同素因子

int32_t main() {
    for (int32_t i = 2; i <= MAX_N; i++) {//线筛
        if (!prime[i]) {prime[++prime[0]] = i; a[i] = 1;}//素数i本身充当素因子，初始化为１
        for (int32_t j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {//如果prime[j]是i中的因子,那么i * prime[j]中的因子种类等于i中的因子种类
                a[i * prime[j]] = a[i];
                break;
            } else {//如果prime[j]不是i中的因子，那么i * prime[j]中的因子种类多一个
                a[i * prime[j]] = a[i] + 1;
            }
        }
    }
    for (int32_t i = 1; i <= MAX_N - 3; i++) {
        if (a[i] ^ 4) continue;
        if (a[i + 1] ^ 4) continue;
        if (a[i + 2] ^ 4) continue;
        if (a[i + 3] ^ 4) continue;
        printf("%d\n", i);
        break;
    }
    return 0;
}
