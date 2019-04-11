/*************************************************************************
	> File Name: EP18.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月26日 星期二 22时28分03秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 15

int keep[MAX_N + 5][MAX_N + 5] = {0};
int map[MAX_N + 5][MAX_N + 5] = {0};

int solve(int i, int j) {
    if (keep[i][j]) return keep[i][j];
    if (i == MAX_N) return 0;
    int lnum = solve(i + 1, j), rnum = solve(i + 1, j + 1);
    keep[i][j] = (lnum > rnum ? lnum : rnum) + map[i][j];
    return keep[i][j];
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", map[i] + j);
        }
    }
    printf("%d\n", solve(0, 0));
    return 0;
}





















