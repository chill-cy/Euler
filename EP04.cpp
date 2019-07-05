/*************************************************************************
	> File Name: EP04.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月27日 星期四 22时05分55秒
 ************************************************************************/
#include <stdio.h>
#include<iostream>
using namespace std;
//#define base 10
int is_valid(int x, int base) {
    int temp = 0, raw = x; 
    while (x) {
        temp = temp * base + x % base;
        x /= base;
    }
    return temp == raw;
}

int main() {
    int ans = 0;
    
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (is_valid(i * j, 10) && ans < i * j) ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
