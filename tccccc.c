/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月07日 星期四 21时24分40秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int matrix[100][100];
    int m;
    int n;
    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int dir[4][2] = {
        {0, 1}, {1, 0},
        {0, -1}, {-1, 0}
    };
    int x, y, k, l;
    x = y = k = l = 0;
    while(1) {
        if(x != 0 || y != 0) printf(" ");
        printf("%d", matrix[x][y]);
        if(dir[k][0] != 0) {
            if(x + dir[k][0] >= m - l || x + dir[k][0] <= l) {
                k++;
                if(k == 4) {
                    k = 0;
                    l++;
                }
            }
        } else {
            if(y + dir[k][1] >= n - l || y + dir[k][1] < l) {
                k++;
            }
        }
        x += dir[k][0];
        y += dir[k][1];
        if(dir[k][0] != 0 && (x >= m - l || x <= l)) break;
        if(dir[k][1] != 0 && (y >= n - l || y < l)) break;
    }
return 0;
}
