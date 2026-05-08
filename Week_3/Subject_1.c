#include <stdio.h>

void decrypt(char in[], char out[], int key) {
    int i;

    for (i = 0; in[i]; i++) {
        if (in[i] >= 'A' && in[i] <= 'Z') out[i] = (in[i] - 'A' - key + 26) % 26 + 'A';
        else if (in[i] >= 'a' && in[i] <= 'z') out[i] = (in[i] - 'a' - key + 26) % 26 + 'a';
        else out[i] = in[i];
    }

    out[i] = '\0';
}

int main() {
    char cipher[100], plain[100];

    printf("----- 브루트포스 -----\n");
    printf("카이사르 암호문 입력: ");
    scanf(" %99[^\n]", cipher);

    for (int key = 0; key < 26; key++) {
        decrypt(cipher, plain, key);
        printf("key %2d -> %s\n", key, plain);
    }

    printf("\n가능한 키가 26개뿐이라 전부 시도할 수 있다.\n");
    printf("-> 이것이 키 공간이 작다는 의미이다.\n");

    return 0;
}
