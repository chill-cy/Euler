/*************************************************************************
	> File Name: EP12_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月24日 星期日 22时58分28秒
 ************************************************************************/
//素数筛法２
#include <stdio.h>
#define MAX_N 100000
//任何数都可分解为素数的乘积
int dnum[MAX_N + 5] = {0};
int mnum[MAX_N + 5] = {0};//相当于bj;
int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i * 2 <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;//若i为素数则其最小素因子就是本身，
        }
        for (int j = 1; j <= prime[j]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            } else {
                mnum[i * prime[j]] = 1;
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
    return ;
}

int factor_nums(int n) {
    if (n & 1) {
        return dnum[n] * dnum[(n + 1) / 2];
    }
    return dnum[n / 2] * dnum[n + 1];
}

int main() {
    init();
    int n = 1;
    while (factor_nums(n) < 500) ++n;
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
