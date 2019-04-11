/*************************************************************************
	> File Name: EP18_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月27日 星期三 10时41分18秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 15

#define max(a,b) ((a) > (b) ? (a) : (b))

int keep[MAX_N + 5][MAX_N + 5] = {0};//定义从起始点到i, j点的距离

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", keep[i] + j);
        }
    }

    for (int i = 1; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {keep[i][j] += keep[i - 1][j]; continue;}
            if (j == i) {keep[i][j] += keep[i - 1][j - 1];  continue;}
            keep[i][j] += max(keep[i - 1][j], keep[i - 1][j - 1]);
        } 
    }
    int ans = 0;
    for (int j = 0; j < MAX_N; j++) {
        ans = max(keep[MAX_N - 1][j], ans);
    }
    printf("%d\n", ans);
    return 0;
}
