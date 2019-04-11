/*************************************************************************
	> File Name: EP22.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月27日 星期三 18时22分59秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <inttypes.h>
#include <algorithm>
#include "022.h"

int32_t main() {
    int64_t i = 0, len, sum, total = 0;
    while (name[i++].length() != 0);
    std::sort(nameList, nameList + i - 1);
    i = 0;
    while (nameList[i].length() != 0) {
        sum = 0;
        for (int32_t j = 0; j < nameList[i].length(); j++) {
            sum = 0;
            for (int32_t j = 0; j < nameList[i].length(); j++) {
                sum += nameList[i][j] - 'A' + 1;
            }
            total += sum * (++i);
        }
    }
    printf("%" PRId64 "\n",total);
    return 0;
}
