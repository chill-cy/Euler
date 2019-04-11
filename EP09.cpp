/*************************************************************************
	> File Name: EP09.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月24日 星期日 16时42分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    bool flag = true;
    int32_t a, b, c, e;
    for (int32_t i = 1; i < 32 && flag; ++i) {
        for (int32_t j = i + 1; j <= 32 && flag; ++j) {
            a = j * j - i * i;
            b = 2 * i * j;
            c = i * i + j * j;
            if (1000 % (a + b + c) == 0) {//x * a + x * b + x * c = x * (a + b + c) = 1000
//（使a, b, c将其和的倍数＝＝1000的情况也枚举了，只要找到和的倍数能被1000整除则无需遍历下去了，只需找到其倍数x即可
                e = (int32_t)pow(1000 / (a + b + c), 3);//1000 / (a + b + c) == x, 
                printf("%d\n", e * a * b * c);//即(x * a) * (x * b) * (x * c)为所求三元组乘积
                flag = false;
            }
        }
    }
    return 0;
}
