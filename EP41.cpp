/*************************************************************************
	> File Name: EP41.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月03日 星期三 10时14分29秒
 ************************************************************************/
 
 

#include <iostream>

#include <cstdio>

#include <algorithm>

using namespace std;

#define R_M_TEST_ROUND 30

int32_t R_M_TEST(int32_t *num, int32_t n) {
    int64_t x = 0, a, m, ans;
    while (n--) {
        x = x * 10 + num[n];
    }
    for (int32_t i = 0; i < R_M_TEST_ROUND; i++) {
        a = (rand() % (x - 1)) + 1;
        ans = 1;
        m = x - 1;
        while (m) {
            if (m % 2) ans = (ans * a) % x;
            a = (a * a) % x;
            m /= 2;
        }
        if (ans != 1) return 0;
    }
    return x;
}

 

int32_t main() {
    srand(time(0));
    int32_t num[9] = {0}, ans = 0, temp_ans;
    for (int32_t i = 3; i <= 9; ++i) {
        for (int32_t j = 0; j < i; ++j) {
            num[j] = j + 1;
        }
        do {
            temp_ans = R_M_TEST(num, i);
            if (temp_ans > ans) ans = temp_ans;
        } while (next_permutation(num, num + i));//按字典序升序的方式生成的所以算法大多数时候会返回true,当生成最大排列时会返回false;
    }
    cout << ans << endl;
    return 0;
}
/*
  3     > Author:
  4     > Mail:
  5     > Created Time: 2019年04月03日 星期三 
  
  
 
 
  int32_t main() {
      srand(time(0));
      int32_t num[9] = {0}, ans = 0;
      for (int32_t i = 7; i > 3 && !ans; --i) {
          if ((1 + i) * i % 6 == 0) continue;
          for (int32_t j = 0; j < i; ++j) {
              num[j] = i - j;
          }
          do {
              ans = R_M_TEST(num, i);
          } while (!ans && prev_permutation(num + i));
      }
      cout << ans << endl;
  }
*/
