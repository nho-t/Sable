#include <stdio.h>
#include <string.h>

/*
   Subject_2.c
   주제 3. 평문, 암호화, 키
   매우 단순한 교육용 예제이다.
   실제 보안 구현에는 사용하면 안 된다.
*/

void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] + key;
    }
}

void decrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] - key;
    }
}

int main() {
    char plaintext[100] = "HELLO";
    int key = 3;
    char encrypted[100];

    strcpy(encrypted, plaintext);

    printf("주제 3. 평문, 암호화, 키\n\n");
    printf("평문: %s\n", plaintext);
    printf("키: %d\n", key);

    encrypt(encrypted, key);
    printf("암호화 결과: %s\n", encrypted);

    decrypt(encrypted, key);
    printf("복호화 결과: %s\n", encrypted);

    return 0;
}
