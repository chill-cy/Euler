/*************************************************************************
	> File Name: EP07.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月19日 星期二 14时31分09秒
 ************************************************************************/

#include <stdio.h>

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n = 0, num = 1;
    do {//n * 根号n----- 时间复杂度为n ^1.5
        num += 1;
        while (!is_prime(num)) num++;
        n += 1;
    } while (n < 10001);
    printf("%d\n", num);
    return 0;
}
