/*************************************************************************
	> File Name: EP41_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月03日 星期三 11时26分55秒
 ************************************************************************/




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
