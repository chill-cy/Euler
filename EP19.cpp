/*************************************************************************
	> File Name: EP19.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月31日 星期日 16时00分54秒
 ************************************************************************/
//蔡勒公式推导http://www.cnblogs.com/mq0036/p/3534314.html
#include <stdio.h>
#include <inttypes.h>
    
int32_t is_sunday(int32_t y, int32_t m) {
    int32_t w;
    int32_t day = 1;
    if (m < 3) {
        y--; 
        m += 12;
    }
    w = (day + 2 * m + 3 * (m + 1) / 5 + y + (y / 4) - (y / 100) + (y / 400)) % 7;//蔡勒公式
    return w;
}

int32_t main() {
    int32_t sunday = 0;
    for (int32_t y = 1901; y <= 2000; y++) {
        for (int32_t m = 1; m  <= 12; m++) {
            if (is_sunday(y, m) == 6)
            sunday++;
        }
    }
    printf("%d\n", sunday);
    return 0;
}
