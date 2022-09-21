#include <stdio.h>
#define MAX 100
typedef struct stacktype { // 스택 구조체 정의
	char stack[MAX];
	int top;
}stacktype;
void init(stacktype* s) { // 스택 초기화 함수
	s->top = -1;
}
int is_full(stacktype* s) { // 스택 포화 검사 함수
	return (s->top == MAX - 1);
}
int is_empty(stacktype* s) { // 스택 공백 검사 함수
	return (s->top == -1);
}
char pop(stacktype* s) { // 스택 팝 함수
	char out; // 입력 받을 변수
	out = s->stack[(s->top)--]; // 스택에 상단에 있는 문자를 out변수에 넣어준다.
	return out; // 값 리턴
}
void push(stacktype* s, char item) { // 스택 푸쉬 함수
	s->stack[++(s->top)] = item; // 넘겨 받은 문자들을 스택에 쌓아준다.
}
int check_matching(char input_string[]){ // 회문 검사 함수
	stacktype s; // 구조체 생성
	int i = 0; // 문자길이 변수
	init(&s); // 스택 초기화
	while (input_string[i] != NULL) { // 문자열의 끝가지 반복
		if ('a' <= input_string[i] && input_string[i] <= 'z') { // 입력 받은 문자가 a~z 사이면 실행
			if (is_full(&s)) { // 스택 포화 검사
				printf("스택이 가득 찼습니다.");
				return 0; 
			}
			push(&s, input_string[i]);  // 참이면 스택에 추가
		}
		else if ('A' <= input_string[i] && input_string[i] <= 'Z') { // 입력 받은 문자가 A~Z 사이면 실행
			if (is_full(&s)) { // 스택 포화 검사
				printf("스택이 가득 찼습니다.");
				return 0;
			}
			char c = input_string[i] + ('a' - 'A'); // 대문자를 소문자로 변경
			push(&s, c); // 스택에 추가
		}
		i++; // 문자길이 변수 증가
	}
	i = 0; // 문자길이 변수 초기화
	int j = 0; // 알파벳이 아닌 문자를 카운트해주는 변수
	while (input_string[i+j] != NULL) { // 문자열의 끝까지 반복
		if (isalpha(input_string[i+j])!=0) { // 입력받은 문자가 알파벳이면 실행
			if ('a' <= input_string[i+j] && input_string[i+j] <= 'z') { // a~z 사이 이면
				if (pop(&s) != input_string[i+j]) return 0; // 스택에서 꺼낸값과 입력받은 문자가 다르면 종료
			}
			else if ('A' <= input_string[i+j] && input_string[i+j] <= 'Z') { // A~Z 사이 이면
				char a = input_string[i] + ('a' - 'A'); // 대문자를 소문자로 변경
				if (pop(&s) != a) return 0;  // 스택에서 꺼낸값과 입력받은 문자가 다르면 종료
			}
			i++; // 문자 길이 변수 증가
		}
		else j++; // 알파벳이 아닌것을 카운트
	}
	if (!is_empty) printf("검사가 제대로 이루어지지 않았습니다"); // 공백 상태가 아니면  실행
	return 1; // 검사가 정상적으로 끝나면 참 리턴
}
int main() {
	char input_string[MAX] = {NULL}; // 입력받을 문자들의 배열
	
	printf("문자열을 입력하시오>>");
	gets_s(input_string, sizeof(input_string)); // get_s 사용해 공백까지 입력받는다.
	if (check_matching(input_string) == 1) printf("회문입니다."); // 참이 리턴되면 실행
	else printf("회문이 아닙니다.");
}
