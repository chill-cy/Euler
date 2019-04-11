/*************************************************************************
	> File Name: 31_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月18日 星期一 16时46分36秒
 ************************************************************************/

#include <stdio.h>
#define MAX_W 8

int dp[8][201] = {0};
int w[MAX_W] = {1, 2, 5, 10, 20, 50, 100, 200};

int main() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 201; j++) {
            if(j == 0) {
                dp[i][j] = 1;
                continue;
            }  
            dp[i][j] = 0;
            if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
            if (j - w[i] >= 0) dp[i][j] += dp[i][j - w[i]];
        }
    }
    printf("%d\n", dp[MAX_W - 1][200]);
    return 0;
}
