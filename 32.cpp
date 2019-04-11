/*************************************************************************
	> File Name: 32.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月18日 星期一 22时56分14秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX_N 10000

int digit (int a) {
    return log10(a) + 1;
}

int get_digit (int a, int *num) {
    while (a) {
        if(a % 10 == 0) return 0;
        if(num[a % 10]) return 0;
        num[a % 10] = 1;
        a /= 10;
    }
    return 1;
}
int is_digit(int a, int b, int c) {
    int num[10] = {0};
    while (!get_digit(a, num)) return 0;
    while (!get_digit(b, num)) return 0;
    while (!get_digit(c, num)) return 0;
    return 1;
}

int arr[MAX_N] = {0};

int main() {
    int ans = 0;
    for (int a = 2; digit(a) + digit(a) + digit(a * a) <= 9; a++) {
        for (int b = a + 1; digit(a) + digit(b) + digit(a * b) <= 9; b++) {
            if (is_digit(a, b, a * b)) {
                if (digit(a) + digit(b) + digit(a * b) < 9) continue; 
                ans += a * b * (1 - arr[a * b]);
                arr[a * b] = 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
