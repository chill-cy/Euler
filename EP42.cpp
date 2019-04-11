/*************************************************************************
> File Name: EP42.cpp
> Author: 
> Mail: 
> Created Time: 2019年03月30日 星期六 21时39分19秒
************************************************************************/
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

#define MAX_M 2000

int32_t t[MAX_M + 5] = {0};

void seq() {
    for (int32_t i = 1; i <= MAX_M; i++) {
        t[i] = 1 / 2 * i * (i + 1);
    }
    return ;
}

int32_t find(int32_t a) {
    for (int32_t i = 1; i <= MAX_M; i++) {
        if (a == t[i]) return 1;
    }
    return 0;
}

int32_t is_triangle (char *b) {
    int32_t len = strlen(b);
    int32_t sum = 0;
    for (int32_t i = 0; i < len; i++) {
        sum += (b[i] - 'A' + 1);
    }
    return find(sum);
}

int32_t main() {
    char a[1000000] = {0};
    char *b[MAX_M + 5] = {0};
    int32_t ans = 0;
    scanf("%[A-Z""]s", a);
    printf("%s\n", a);
    fflush(stdout);
    int i = 0;
    b[i] = strtok(a, ",");
    while (a != NULL) {
        i++;
        b[i] = strtok(NULL, ",");
        }
    for (int j = 0; j < i; j++) {
        if (is_triangle(b[j]) == 1) {
            ans++;
        } 
    }
    printf("%d\n", ans);
    return 0;
}
