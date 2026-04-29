#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* --------------------------------------------------
   1. 단순 치환 키 검사
   - 26개의 영문자가 한 번씩만 등장해야 한다.
-------------------------------------------------- */
int is_valid_key(const char* key) {
    int seen[26] = { 0 };

    if (strlen(key) != 26) {
        return 0;
    }

    for (int i = 0; key[i] != '\0'; i++) {
        char upper = (char)toupper((unsigned char)key[i]);

        if (upper < 'A' || upper > 'Z') {
            return 0;
        }

        if (seen[upper - 'A']) {
            return 0;
        }

        seen[upper - 'A'] = 1;
    }

    return 1;
}

/* --------------------------------------------------
   2. 역치환표 생성
   - 복호화를 위해 암호문 알파벳을 다시 평문 알파벳으로 돌리는 표를 만든다.
-------------------------------------------------- */
void build_reverse_key(const char* key, char* reverse_key) {
    for (int i = 0; i < 26; i++) {
        char upper = (char)toupper((unsigned char)key[i]);
        reverse_key[upper - 'A'] = (char)('A' + i);
    }

    reverse_key[26] = '\0';
}

/* --------------------------------------------------
   3. 단순 치환 암호화
   - 평문 알파벳을 key에 적힌 대응 문자로 바꾼다.
-------------------------------------------------- */
void substitution_encrypt(const char* plain, char* cipher, const char* key) {
    for (int i = 0; plain[i] != '\0'; i++) {
        if (plain[i] >= 'A' && plain[i] <= 'Z') {
            cipher[i] = (char)toupper((unsigned char)key[plain[i] - 'A']);
        }
        else if (plain[i] >= 'a' && plain[i] <= 'z') {
            cipher[i] = (char)tolower((unsigned char)key[plain[i] - 'a']);
        }
        else {
            cipher[i] = plain[i];
        }
    }

    cipher[strlen(plain)] = '\0';
}

/* --------------------------------------------------
   4. 단순 치환 복호화
   - 역치환표를 사용해 원래 평문으로 복원한다.
-------------------------------------------------- */
void substitution_decrypt(const char* cipher, char* plain, const char* reverse_key) {
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            plain[i] = reverse_key[cipher[i] - 'A'];
        }
        else if (cipher[i] >= 'a' && cipher[i] <= 'z') {
            plain[i] = (char)tolower((unsigned char)reverse_key[cipher[i] - 'a']);
        }
        else {
            plain[i] = cipher[i];
        }
    }

    plain[strlen(cipher)] = '\0';
}

/* --------------------------------------------------
   5. 키의 활용
   - 같은 평문이어도 치환 키가 다르면 결과가 달라진다.
-------------------------------------------------- */
void compare_substitution_keys(const char* plain, const char* key1, const char* key2) {
    char result1[100];
    char result2[100];

    substitution_encrypt(plain, result1, key1);
    substitution_encrypt(plain, result2, key2);

    printf("같은 평문: %s\n", plain);
    printf("키 1 결과: %s\n", result1);
    printf("키 2 결과: %s\n", result2);
    printf("-> 치환 키가 바뀌면 암호문도 달라진다.\n");
}

int main() {
    char plain[100];
    char key[100];
    char reverse_key[27];
    char cipher[100];
    char decrypted[100];
    const char* sample_key = "MNBVCXZLKJHGFDSAPOIUYTREWQ";

    printf("----- 1. 단순 치환 암호 (Simple Substitution Cipher) -----\n");
    printf("평문 입력: ");
    scanf(" %99[^\n]", plain);

    printf("치환 키 입력(26글자 영문): ");
    scanf("%99s", key);

    if (!is_valid_key(key)) {
        printf("올바르지 않은 키입니다.\n");
        printf("예시 키: QWERTYUIOPASDFGHJKLZXCVBNM\n");
        return 1;
    }

    build_reverse_key(key, reverse_key);
    substitution_encrypt(plain, cipher, key);

    printf("암호화 결과: %s\n", cipher);

    printf("----- 2. 복호화 확인 -----\n");
    substitution_decrypt(cipher, decrypted, reverse_key);
    printf("복호화 결과: %s\n\n", decrypted);

    printf("----- 3. 키의 활용 -----\n");
    compare_substitution_keys(plain, key, sample_key);

    return 0;
}
