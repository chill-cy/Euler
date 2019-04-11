/*************************************************************************
	> File Name: EP44_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月22日 星期五 17时29分35秒
 ************************************************************************/
//求一个数字n的立方结果
#include <stdio.h>
#include <inttypes.h>

#define MAX_N 3000

int32_t Cube(int32_t n) {
    return n * n * n;
}

int32_t IsCube(int32_t a) {
    int32_t range = a;
    if (a < 0) range = -a;
    int32_t maxn = range, minn = -range;
    int32_t midn = (maxn + minn) >> 1;
    while (minn < maxn) {
        if (Cube(midn) == a) break;
        if (Cube(midn) < a) {
            minn = midn + 1;
        } else {
            maxn = midn - 1;
        } 
        midn = (maxn + minn) >> 1;
    }
    return Cube(midn) == a;
}

int32_t main() {
    printf("%d\n", IsCube(55));
    printf("%d\n", IsCube(27));
    printf("%d\n", IsCube(-27));
    return 0;
}
