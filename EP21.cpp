/*************************************************************************
	> File Name: EP21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月31日 星期日 18时53分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdint.h>

#define MAX_N 10000

int32_t isPrime[MAX_N + 5] = {0};//存储数字i中最小素因子项的幂次值，即isisPrime[24] = 8
int32_t prime[MAX_N] = {0};//打印素数表，isisPrime数组和isPrime数组可以合并为一个数组
//因为i向后走不会覆盖掉前面已经找到的素数，即使prime[]的值被素数刷新，也没关系因为没有覆盖掉后面需要用到的最小素因子项的幂次值，
//所以要求的目的数组d[i]的值也不会被刷新
int32_t d[MAX_N + 5] = {0};//数字i的约数和

int32_t main() {
    d[1] = 0;
    for (int32_t i = 2; i <= MAX_N; i++) {
        if (!isPrime[i]) {//i未被标记为和数则i为素数
            isPrime[i] = i;
            d[i] = i + 1;//素数的约数和初始化为１＋本身
            prime[++prime[0]] = i;
        }
        for (int32_t j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            if (i % prime[j] == 0) {//i和isPrime[j]不互素，f(b) = f(a) * (1-p1^(a1 + 2)) / (1-p1^(a1+1));
                is_Prime[i * prime[j]] = is_Prime[i] * prime[j]; //数字i * prime[j]的幂次加１，即再乘一次素因子prime[j];
                d[i * prime[j]] = d[i] * (isPrime[i] * prime[j] * prime[j] - 1) / (isPrime[i] * prime[j] - 1);
                break;
            } else {//i和isPrime[j]互素f(c)=f(a) * f(b);
                isPrime[i * prime[j]] = prime[j];
                //prime[j]不能被i整除时即prime[j]小于i中最小素因子,所以i*prime[j]的最小素因子的幂次值应该是prime[j]
                d[i * prime[j]] = d[prime[j]] * d[i];
            }
        }
    }
    for (int32_t i = 0; i <= MAX_N; i++) {
        d[i] -= i;
    }
    int32_t sum = 0;
    for (int32_t i = 0; i <= MAX_N; i++) {
        if (d[i] <= MAX_N && d[i] != i && d[d[i]] == i) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
