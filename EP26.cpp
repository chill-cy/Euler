/*************************************************************************
	> File Name: EP26.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月29日 星期五 15时54分26秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_N 1000
//int rest[MAX_N] = {0}只是将数组int类型初始化为０，
//memset(rest, 0, sizeof(rest));memset是将二进制各位置为二进制的０或１,因为置为二进制全１时首位１表示符号位
int rest[MAX_N];//余数出现在第几次循环 

int GetLoopLength(int n) {
    memset(rest, 0, sizeof(rest));
    int ret = 1 % n, ind = 0;//ret是余数，ind是循环次数,ind的初值无所谓
    while (rest[ret] == 0 && ret) {
       // printf("%d", y * 10 / d);
        rest[ret] = ++ind;
        ret *= 10;
        ret %= n;
    }
    // printf("(%d)\n", y ? n - dnum);
    return ret ? ind - rest[ret] : 0;
}

int main() {
    int maxLen = 0;
    int curLen, num;
    for (int i = 1; i < MAX_N; i++) {
        int curLen = GetLoopLength(i);
        if (curLen > maxLen) {
            maxLen = curLen;
            num = i;
        }
    }
    printf("%d\n", num);
    return 0;
}
