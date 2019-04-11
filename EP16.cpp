/*************************************************************************
	> File Name: EP16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月25日 星期一 11时16分36秒
 ************************************************************************/

#include <stdio.h>
#define BASE 1000
//内联函数在编译时不是一个真正的函数，inline 将代码段拷贝到相关调用的位置，
//inline不是一个定义式，而是一个建议式，内联操作对某些函数是不能成功的如递归函数；
//所以并不是将一个函数声明成inline形式就一定会加速
inline int get_ditist_sum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    } 
    return sum;
}
int main() {
    int ans[400] = {0};
    ans[0] = ans[1] = 1;
    for (int j = 1; j <= 100; j++) {
        for (int i = 1; i <= ans[0]; i++) ans[i] <<= 10; 
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / BASE;
            ans[i] %= BASE;
            ans[0] += (i == ans[0]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= ans[0]; i++) {
        sum += get_ditist_sum(ans[i]);
    }
    printf("%d\n", sum);
    return 0;
}
