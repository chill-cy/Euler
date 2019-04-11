/*************************************************************************
	> File Name: EP15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月25日 星期一 10时32分15秒
 ************************************************************************/

//组合问题
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main() {
    int64_t ans = 1, m = 20;
    for (int i = 40; i > 20; i--) {
        ans *= i;
        while (ans % m == 0 && m != 1) {
            ans /= m;
            m--;
        }
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
