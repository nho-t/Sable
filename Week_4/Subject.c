#include <stdio.h>

int hash(char s[]) {
    int h = 0;

    for (int i = 0; s[i]; i++) h = (h * 31 + s[i]) % 10000;

    return h;
}

int main() {
    char text[100], enc[100], dec[100], pw[100];
    int i, saved = hash("sable123");

    printf("영문 문자열 입력: ");
    scanf(" %99[^\n]", text);

    printf("\n[인코딩 예시 - HEX]\n");
    for (i = 0; text[i]; i++) printf("%02X ", (unsigned char)text[i]);
    printf("\n");

    printf("\n[암호화 예시 - 간단한 시프트]\n");
    for (i = 0; text[i]; i++) enc[i] = text[i] + 3;
    enc[i] = '\0';
    for (i = 0; enc[i]; i++) dec[i] = enc[i] - 3;
    dec[i] = '\0';
    printf("원문: %s\n", text);
    printf("암호문: %s\n", enc);
    printf("복호화: %s\n", dec);

    printf("\n[해시 예시]\n");
    printf("해시값: %d\n", hash(text));

    printf("\n[비밀번호 비교]\n");
    printf("비밀번호 입력: ");
    scanf("%99s", pw);
    printf("저장된 해시값: %d\n", saved);
    printf("입력한 해시값: %d\n", hash(pw));

    if (hash(pw) == saved) printf("비밀번호 일치\n");
    else printf("비밀번호 불일치\n");

    printf("-> 비밀번호는 복호화하지 않고 해시값으로 비교한다.\n");

    return 0;
}
