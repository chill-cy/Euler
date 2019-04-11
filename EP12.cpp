/*************************************************************************
	> File Name: EP12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月24日 星期日 18时46分53秒
 ************************************************************************/
//自己写的
#include <stdio.h>
#define MAX_N 100000


int f(int n) {
    return n * (n + 1) / 2;
}

int first_triangle(int k) {
    int ans = 0;
    for (int i = 1; i * i <= k; i++) {
        if (i * i == k) {
            ans += 1;
            break;
        }
        if (k % i == 0) ans += 2;
    }
    return ans;
}

int main() {
    for (int i = 1; i <= MAX_N; i++) {
        if (first_triangle(f(i)) > 500) {
            printf("%d\n", f(i));
            break;
        }
    } 
    return 0;
}
