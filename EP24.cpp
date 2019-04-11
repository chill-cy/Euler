/*************************************************************************
	> File Name: EP24.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月29日 星期五 10时26分58秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 10

int jnum[MAX_N] = {0};//表示该位增长到下一个数字时变化的状态数
int dnum[MAX_N] = {0};//表示数字i是否被使用过

void init () {
    jnum[0] = dnum[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        dnum[i] = 1;
        jnum[i] = i * jnum[i - 1];//该位向上增大到未使用数字中下一个只比它大的数字时变化的状态数
        //即若共十位数字，则第１位的数字增由０增为２则需经过2 * (9!)，第１位之后还有９位，所以有９！种排列； 
    }
    return ;
}

int judge_num(int n, int k) {
    //返回值表示使用该位哪个数字，参数n表示该位之后还有几个数字未被使用,参数k表示还剩多少种状态数
    int ind = (k / jnum[n]) + 1, i = -1;
    //ind 统计未用过的数字中使用第几个数字，＋１是因为本身是最小数字时没有状态数的变化
　　//如当前位数字由０增到２则它＝因为增加的状态数而发生的增量２＋本身为０时０未被使用过
    //即在未被使用的数字中２排在0,1之后所以２是未用过的数字中的第３个数字
    while (ind > 0) {
        i++;
        ind -= dnum[i];
    }
    dnum[i] = 0;
    return i;
}

int main() {
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    k -= 1;
    for (int i = n - 1; i >= 0; i--) {
        int num = judge_num(i, k);
        printf("%d", num);
        k %= jnum[i];//更新剩余状态数
    }
    printf("\n");
    return 0;
}
