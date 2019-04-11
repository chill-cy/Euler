/*************************************************************************
	> File Name: EP42_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月30日 星期六 23时08分20秒
 ************************************************************************/
 

 

#include <stdio.h>

#include <inttypes.h>

#include <math.h>

#include "042.h"

 

bool isTriangleNumber(int32_t n) {

    int32_t m = (int32_t)floor(sqrt(n * 2));

    return m * (m + 1) / 2 == n;

}

 

int32_t main() {

    int32_t i = 0, sum = 0, total = 0;

    while (wordList[i].length() != 0) {

        sum = 0;

        for (int32_t j = 0; j < wordList[i].length(); j++) {

            sum += wordList[i][j] - 'A' + 1;

        }

        if (isTriangleNumber(sum)) ++total;

        ++i;

    }

    printf("%d\n", total);

    return 0;

}

 
 
