#include <stdio.h>
#include <string.h>

/*
   Subject_1.c
   주제 2. 기밀성, 무결성, 인증, 부인방지
   매우 단순한 교육용 예제이다.
   실제 보안 구현에는 사용하면 안 된다.
*/

void confidentiality_demo() {
    char message[] = "HELLO";
    char hidden[100];
    int key = 1;
    int len = strlen(message);

    for (int i = 0; i < len; i++) {
        hidden[i] = message[i] + key;
    }
    hidden[len] = '\0';

    printf("[기밀성]\n");
    printf("원본 메시지: %s\n", message);
    printf("숨긴 메시지: %s\n", hidden);
    printf("설명: 키를 알아야 다시 원래 문자로 되돌릴 수 있다.\n\n");
}

int make_checksum(const char *text) {
    int sum = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        sum += text[i];
    }
    return sum;
}

void integrity_demo() {
    char original[] = "DATA";
    char changed[] = "DUTA";

    int sum1 = make_checksum(original);
    int sum2 = make_checksum(changed);

    printf("[무결성]\n");
    printf("원본 데이터: %s, 체크값: %d\n", original, sum1);
    printf("변경 데이터: %s, 체크값: %d\n", changed, sum2);

    if (sum1 == sum2) {
        printf("결과: 데이터가 같다고 판단한다.\n\n");
    } else {
        printf("결과: 데이터가 바뀌었다고 판단한다.\n\n");
    }
}

int authenticate(const char *input, const char *saved) {
    return strcmp(input, saved) == 0;
}

void authentication_demo() {
    char saved_password[] = "1234";
    char input1[] = "1234";
    char input2[] = "1111";

    printf("[인증]\n");
    printf("입력값 %s -> %s\n", input1,
           authenticate(input1, saved_password) ? "인증 성공" : "인증 실패");
    printf("입력값 %s -> %s\n\n", input2,
           authenticate(input2, saved_password) ? "인증 성공" : "인증 실패");
}

int sign_message(const char *message, int private_mark) {
    return make_checksum(message) + private_mark;
}

int verify_signature(const char *message, int signature, int private_mark) {
    return signature == make_checksum(message) + private_mark;
}

void non_repudiation_demo() {
    char message[] = "APPROVE";
    int private_mark = 100;
    int signature = sign_message(message, private_mark);

    printf("[부인방지]\n");
    printf("메시지: %s\n", message);
    printf("서명값: %d\n", signature);

    if (verify_signature(message, signature, private_mark)) {
        printf("검증 결과: 서명이 맞다. 보낸 사람이 남긴 값으로 확인된다.\n");
    } else {
        printf("검증 결과: 서명이 틀리다.\n");
    }

    if (verify_signature("CHANGE", signature, private_mark)) {
        printf("변조 메시지 검증 결과: 서명이 맞다.\n\n");
    } else {
        printf("변조 메시지 검증 결과: 서명이 틀리다.\n\n");
    }
}

int main() {
    printf("주제 2. 기밀성, 무결성, 인증, 부인방지\n\n");

    confidentiality_demo();
    integrity_demo();
    authentication_demo();
    non_repudiation_demo();

    return 0;
}
