/*************************************************************************
	> File Name: EP37.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月20日 星期三 20时19分51秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <math.h>

#define MAX_N 100000
#define MAX_RANGE 5000000

int32_t isPrime[MAX_RANGE + 5] = {0};
int32_t prime[MAX_RANGE + 5] = {0};

void initPrime() {
    isPrime[0] = isPrime[1] = 1;
    for (int32_t i = 2; i <= MAX_RANGE; i++) {
        if (!isPrime[i]) {prime[++prime[0]] = i;}
        for (int32_t j = 1; j <= prime[0]; j++) {
            if (prime[j] * i >= MAX_RANGE) break;
            isPrime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

bool isCircularPrime(int32_t n) {
    if(isPrime[n] != 0) return false;
    int32_t x = n, h;
    while (x) {
        if (isPrime[x] != 0) return false;
        x /= 10;
    }
    h = (int32_t)pow(10,floor(log10(n)));//求最高位位权
    x = n;
    while (x) {
        if (isPrime[x] != 0) return false;
        x -= (x / h) * h;
        h /= 10;
    }
    return true;
}

int32_t solve() {
    int32_t many = 0, flag = 11;
    for (int32_t i = 1; i <= prime[0]; i++) {
        if (prime[i] < 10) continue;
        if (!isCircularPrime(prime[i])) continue;
        many += prime[i];
        if (!(--flag)) break;
    }
    return many;
}


int main() {
    initPrime();
    int32_t many = solve();
    printf("%d\n", many);
    return 0;
}
