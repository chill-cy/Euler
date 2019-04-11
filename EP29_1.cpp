/*************************************************************************
	> File Name: EP29_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月29日 星期五 21时55分10秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 10000
#define MAX_M 210


int *result[MAX_N] = {0};
int result_length = 0;

int find_result(int *num) {
    for (int i = 0; i < result_length; i++) {
        if (memcmp(result[i], num, sizeof(int) * MAX_M)) continue;
        return i + 1;
    }
    return 0;
}

void calc_num(int *num, int a) {
    for (int j = 1; j <= num[0]; j++) num[j] *= a;
    for (int j = 1; j <= num[0]; j++) {
        if (num[j] < 10) continue;
        num[j + 1] += num[j] / 10;
        num[j] %= 10;
        num[0] += (j == num[0]);
    }
    return ;
}


int main() {
    for (int a = 2; a <= 100; a++) {
        int *temp = (int *)calloc(sizeof(int), MAX_M);
        temp[0] = temp[1] = 1;
        calc_num(temp, a);
        for (int b = 2; b <= 100; b++) {
            calc_num(temp, a);
            if (find_result(temp) == 0) {
                result[result_length++] = (int *)malloc(sizeof(int) * MAX_M);
                memcpy(result[result_length], temp, sizeof(int) * MAX_M);    
            }
        }
    } 
    printf("%d\n", result_length);
    return 0;
}
