/*************************************************************************mZ	> File Name: EP18_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月27日 星期三 10时22分15秒
 ************************************************************************/
 
#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

#define MAX_N 15 

int keep[MAX_N + 5][MAX_N + 5] = {0};

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &keep[i][j]);
        }
    }
    for (int i = MAX_N - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            keep[i][j] += max(keep[i + 1][j], keep[i + 1][j + 1]);
        }
    }
    printf("%d\n", keep[0][0]);
    return 0;
}
