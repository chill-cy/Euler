/*************************************************************************
	> File Name: 33.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月19日 星期二 02时19分14秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h> 


int32_t gcd(int32_t a, int32_t b) {
    if (!b) return a;
    return gcd(b, a % b);
} 
int32_t IsNonTrivial (int32_t x, int32_t y) {
    if (x > 100 || x < 10) return false;
    if (y > 100 || y < 10) return false;
    int32_t x1, x2, y1, y2;
    x1 = x / 10; x2 = x % 10;
    y1 = y / 10; y2 = y % 10;
    if (!x1 || !x2 || !y1 || !y2) return false;
    if (x1 == y1 && x2 * y == y2 * x && x2 != 0) return true;
    if (x1 == y2 && x2 * y == y1 * x && x2 != 0) return true;
    if (x2 == y2 && x1 * y == y1 * x && x1 != 0) return true;
    if (x2 == y1 && x1 * y == y2 * x && x1 != 0) return true;
    return false;
}

int main () {
    int32_t x = 1, y = 1, c;
    for (int32_t i = 1; i < 100; i++) {
        for (int32_t j =i + 1; j < 100; j++) {
            if (IsNonTrivial(i, j) == false) continue;
                x *= i; y *= j;
                c = gcd(x, y);
                x /= c; y /= c;
        }
    }
         printf("%d\n", y);
     return 0;
}
