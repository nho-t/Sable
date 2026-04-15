#include <stdio.h>
#include <string.h>

/* --------------------------------------------------
   1. 기밀성 (Confidentiality)
   - 영어 알파벳을 한 칸씩 밀어서 원문을 바로 읽지 못하게 한다.
-------------------------------------------------- */
void confidentiality_demo() {
    char text[100];

    printf("----- 기밀성 (Confidentiality) -----\n");
    printf("문자열 입력: ");
    scanf(" %99[^\n]", text);

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + 1) % 26 + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + 1) % 26 + 'a';
        }
    }

    printf("기밀성 적용 결과: %s\n\n", text);
}

/* --------------------------------------------------
   2. 무결성 (Integrity)
   - 문자열의 아스키 코드 총합을 이용해 데이터가 바뀌었는지 단순 확인한다.
-------------------------------------------------- */
int calculate_value(const char* text) {
    int sum = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        sum += (unsigned char)text[i];
    }

    return sum;
}

void integrity_demo() {
    char original[100];
    char changed[100];
    int value1, value2;

    printf("----- 무결성 (Integrity) -----\n");
    printf("원본 문자열 입력: ");
    scanf(" %99[^\n]", original);

    printf("비교 문자열 입력: ");
    scanf(" %99[^\n]", changed);

    value1 = calculate_value(original);
    value2 = calculate_value(changed);

    printf("원본 체크값: %d\n", value1);
    printf("비교 체크값: %d\n", value2);

    if (value1 == value2) {
        printf("-> 데이터가 그대로라고 판단한다.\n\n");
    } else {
        printf("-> 데이터가 바뀌었다고 판단한다.\n\n");
    }
}

/* --------------------------------------------------
   3. 인증 (Authentication)
   - 아이디와 비밀번호가 맞는지 확인한다.
-------------------------------------------------- */
int authenticate(const char* id, const char* pw) {
    const char* real_id = "admin";
    const char* real_pw = "1234";

    if (strcmp(id, real_id) == 0 && strcmp(pw, real_pw) == 0) {
        return 1;
    }

    return 0;
}

void authentication_demo() {
    char id[50];
    char pw[50];

    printf("----- 인증 (Authentication) -----\n");
    printf("아이디 입력: ");
    scanf("%49s", id);

    printf("비밀번호 입력: ");
    scanf("%49s", pw);

    if (authenticate(id, pw)) {
        printf("-> 인증 성공.\n\n");
    } else {
        printf("-> 인증 실패.\n\n");
    }
}

/* --------------------------------------------------
   4. 부인방지 (Non-repudiation)
   - 발신자, 메시지, 서명값을 남겨 쉽게 부인하기 어렵게 한다.
-------------------------------------------------- */
void non_repudiation_demo() {
    char sender[50];
    char message[100];
    char signed_document[300];
    int signature_value;

    printf("----- 부인방지 (Non-repudiation) -----\n");
    printf("발신자 입력: ");
    scanf("%49s", sender);

    printf("메시지 입력: ");
    scanf(" %99[^\n]", message);

    signature_value = calculate_value(sender) + calculate_value(message) + 500;

    sprintf(signed_document,
            "[Sender: %s] [Message: %s] [Signature: %d]",
            sender, message, signature_value);

    printf("생성된 서명 문서:\n%s\n", signed_document);
    printf("-> 발신자 정보와 서명값이 남으므로 쉽게 부인하기 어렵다.\n\n");
}

int main() {
    confidentiality_demo();
    integrity_demo();
    authentication_demo();
    non_repudiation_demo();

    return 0;
}