#include <stdio.h>
#include <string.h>

/* --------------------------------------------------
   1. 평문 (Plaintext)
-------------------------------------------------- */
void show_plaintext(const char* text) {
    printf("입력한 평문: %s\n", text);
}

/* --------------------------------------------------
   2. 암호화 (Encryption)
   - 평문을 바로 읽지 못하도록 다른 형태로 바꾸는 과정으로, 여기서는 각 문자에 key만큼 더하는 아주 단순한 방식.
-------------------------------------------------- */
void encrypt_text(const char* plain, char* encrypted, int key) {
    int i;

    for (i = 0; plain[i] != '\0'; i++) {
        encrypted[i] = plain[i] + key;
    }

    encrypted[i] = '\0';
}

/* --------------------------------------------------
   복호화 함수
   - 암호화된 데이터를 다시 원래 형태로 되돌린다.
-------------------------------------------------- */
void decrypt_text(const char* encrypted, char* decrypted, int key) {
    int i;

    for (i = 0; encrypted[i] != '\0'; i++) {
        decrypted[i] = encrypted[i] - key;
    }

    decrypted[i] = '\0';
}

/* --------------------------------------------------
   3. 키 (Key)
   - 암호화할 때 사용하는 값이다. 또한 같은 평문이라도 키가 다르면 결과가 달라진다.
-------------------------------------------------- */
void key_demo(const char* plain) {
    char result1[100];
    char result2[100];

    encrypt_text(plain, result1, 1);
    encrypt_text(plain, result2, 3);

    printf("같은 평문: %s\n", plain);
    printf("키 1 사용 결과: %s\n", result1);
    printf("키 3 사용 결과: %s\n", result2);
    printf("-> 키가 다르면 암호화 결과도 달라지는 것을 확인 가능.\n");
}

int main() {
    char plain[100];
    char encrypted[100];
    char decrypted[100];
    int key;

    /* ---------------- 1. 평문 ---------------- */
    printf("----- 1. 평문 (Plaintext) -----\n");
    printf("평문 입력: ");
    scanf(" %99[^\n]", plain);

    show_plaintext(plain);
    printf("-> 평문은 암호화 전의 원래 데이터.\n\n");

    /* ---------------- 2. 암호화 ---------------- */
    printf("----- 2. 암호화 (Encryption) -----\n");
    printf("암호화에 사용할 키 입력(정수): ");
    scanf("%d", &key);

    encrypt_text(plain, encrypted, key);

    printf("원본 평문: %s\n", plain);
    printf("암호화 결과: %s\n", encrypted);

    /* ---------------- 복호화 확인 ---------------- */
    decrypt_text(encrypted, decrypted, key);
    printf("복호화 결과: %s\n", decrypted);
  
    /* ---------------- 3. 키 ---------------- */
    printf("----- 3. 키 (Key) -----\n");
    key_demo(plain);

    return 0;
}