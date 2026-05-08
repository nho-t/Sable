#include <stdio.h>

int main() {
    char cipher[100], guess[100];
    int count[26] = { 0 }, max = 0, key, i;

    printf("----- 빈도 분석 -----\n");
    printf("암호문 입력: ");
    scanf(" %99[^\n]", cipher);

    for (i = 0; cipher[i]; i++) {
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') count[cipher[i] - 'A']++;
        else if (cipher[i] >= 'a' && cipher[i] <= 'z') count[cipher[i] - 'a']++;
    }

    for (i = 1; i < 26; i++) {
        if (count[i] > count[max]) max = i;
    }

    key = (max - ('E' - 'A') + 26) % 26;

    for (i = 0; cipher[i]; i++) {
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') guess[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A';
        else if (cipher[i] >= 'a' && cipher[i] <= 'z') guess[i] = (cipher[i] - 'a' - key + 26) % 26 + 'a';
        else guess[i] = cipher[i];
    }
    guess[i] = '\0';

    printf("가장 많이 나온 문자: %c\n", 'A' + max);
    printf("E를 기준으로 추정한 키: %d\n", key);
    printf("추정 복호화 결과: %s\n", guess);
    printf("-> 가장 많이 나온 글자를 기준으로 복호화를 추측하는 예시이다.\n");

    return 0;
}
