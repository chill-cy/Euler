/*************************************************************************
	> File Name: EP12_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月24日 星期日 19时24分41秒
 ************************************************************************/
//线筛法
#include <stdio.h>
#define MAX_N 100000

int dnum[MAX_N + 5] = {0};//dnum[i]表示第i个数字的约数个数
int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i * 2 <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                int bj = 0, temp_i = i;
                while (temp_i % prime[j] == 0) bj += 1, temp_i /= prime[j];
                //循环求出Ｎ(即i = N * prime[j]^bj) 最后temp_i也就是不包含prime[j]这个因子的　i的因数
                dnum[i * prime[j]] = dnum[i] / (bj + 1) * (bj + 2);//dum[N] = dnum[i] / (bj + 1);
                //i * prime[j] == (N * prime[j]) * prime[j] = N * prime[j] ^ 2;
                //而dnum[prime[j]] = bj + 1,dnum[prime[j]^2] = bj + 2;
                //根据约数公式　dnum[i * prime[j]] == dnum[N] * dum[prime[j]^2] == (dum[i]/(bj + 1)) * (bj + 2);
                break;
            } else {
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];//i % prime[j] != 0则i,prime[j]互素，F(c) = F(a) *F(b)
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
