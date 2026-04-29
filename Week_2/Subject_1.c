#include <stdio.h>
#include <string.h>

/* --------------------------------------------------
   1. 카이사르 암호 (Caesar Cipher)
   - 알파벳을 key만큼 밀어서 암호화한다.
   - 대문자와 소문자는 각각 알파벳 범위 안에서 순환한다.
-------------------------------------------------- */
void caesar_encrypt(const char* plain, char* cipher, int key) {
    int normalized_key = key % 26;

    if (normalized_key < 0) {
        normalized_key += 26;
    }

    for (int i = 0; plain[i] != '\0'; i++) {
        if (plain[i] >= 'A' && plain[i] <= 'Z') {
            cipher[i] = (plain[i] - 'A' + normalized_key) % 26 + 'A';
        }
        else if (plain[i] >= 'a' && plain[i] <= 'z') {
            cipher[i] = (plain[i] - 'a' + normalized_key) % 26 + 'a';
        }
        else {
            cipher[i] = plain[i];
        }
    }

    cipher[strlen(plain)] = '\0';
}

/* --------------------------------------------------
   2. 복호화
   - 암호화 때 사용한 key만큼 반대로 이동시켜 평문을 복원한다.
-------------------------------------------------- */
void caesar_decrypt(const char* cipher, char* plain, int key) {
    caesar_encrypt(cipher, plain, 26 - (key % 26));
}

/* --------------------------------------------------
   3. 키의 활용
   - 같은 평문이라도 key가 다르면 결과가 달라진다.
-------------------------------------------------- */
void compare_keys(const char* plain) {
    char result1[100];
    char result2[100];
    char result3[100];

    caesar_encrypt(plain, result1, 1);
    caesar_encrypt(plain, result2, 3);
    caesar_encrypt(plain, result3, 10);

    printf("같은 평문: %s\n", plain);
    printf("키 1 사용 결과 : %s\n", result1);
    printf("키 3 사용 결과 : %s\n", result2);
    printf("키 10 사용 결과: %s\n", result3);
    printf("-> 키가 달라지면 암호문도 달라진다.\n\n");
}

/* --------------------------------------------------
   4. 브루트포스 예시
   - 카이사르 암호는 가능한 key 수가 적어서 전부 시도해 볼 수 있다.
-------------------------------------------------- */
void brute_force_demo(const char* cipher) {
    char guessed[100];

    printf("브루트포스 결과:\n");

    for (int key = 0; key < 26; key++) {
        caesar_decrypt(cipher, guessed, key);
        printf("key %2d -> %s\n", key, guessed);
    }

    printf("-> 가능한 key를 모두 시도할 수 있다는 점이 카이사르 암호의 약점이다.\n");
}

int main() {
    char plain[100];
    char cipher[100];
    char decrypted[100];
    int key;

    printf("----- 1. 카이사르 암호 (Caesar Cipher) -----\n");
    printf("평문 입력: ");
    scanf(" %99[^\n]", plain);

    printf("이동할 키 입력(0~25): ");
    scanf("%d", &key);

    caesar_encrypt(plain, cipher, key);
    printf("암호화 결과: %s\n", cipher);

    printf("----- 2. 복호화 확인 -----\n");
    caesar_decrypt(cipher, decrypted, key);
    printf("복호화 결과: %s\n\n", decrypted);

    printf("----- 3. 키의 활용 -----\n");
    compare_keys(plain);

    printf("----- 4. 카이사르 암호의 한계 -----\n");
    brute_force_demo(cipher);

    return 0;
}
