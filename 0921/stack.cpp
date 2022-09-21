#include <stdio.h>
#define MAX 100
typedef struct stacktype { // ���� ����ü ����
	char stack[MAX];
	int top;
}stacktype;
void init(stacktype* s) { // ���� �ʱ�ȭ �Լ�
	s->top = -1;
}
int is_full(stacktype* s) { // ���� ��ȭ �˻� �Լ�
	return (s->top == MAX - 1);
}
int is_empty(stacktype* s) { // ���� ���� �˻� �Լ�
	return (s->top == -1);
}
char pop(stacktype* s) { // ���� �� �Լ�
	char out; // �Է� ���� ����
	out = s->stack[(s->top)--]; // ���ÿ� ��ܿ� �ִ� ���ڸ� out������ �־��ش�.
	return out; // �� ����
}
void push(stacktype* s, char item) { // ���� Ǫ�� �Լ�
	s->stack[++(s->top)] = item; // �Ѱ� ���� ���ڵ��� ���ÿ� �׾��ش�.
}
int check_matching(char input_string[]){ // ȸ�� �˻� �Լ�
	stacktype s; // ����ü ����
	int i = 0; // ���ڱ��� ����
	init(&s); // ���� �ʱ�ȭ
	while (input_string[i] != NULL) { // ���ڿ��� ������ �ݺ�
		if ('a' <= input_string[i] && input_string[i] <= 'z') { // �Է� ���� ���ڰ� a~z ���̸� ����
			if (is_full(&s)) { // ���� ��ȭ �˻�
				printf("������ ���� á���ϴ�.");
				return 0; 
			}
			push(&s, input_string[i]);  // ���̸� ���ÿ� �߰�
		}
		else if ('A' <= input_string[i] && input_string[i] <= 'Z') { // �Է� ���� ���ڰ� A~Z ���̸� ����
			if (is_full(&s)) { // ���� ��ȭ �˻�
				printf("������ ���� á���ϴ�.");
				return 0;
			}
			char c = input_string[i] + ('a' - 'A'); // �빮�ڸ� �ҹ��ڷ� ����
			push(&s, c); // ���ÿ� �߰�
		}
		i++; // ���ڱ��� ���� ����
	}
	i = 0; // ���ڱ��� ���� �ʱ�ȭ
	int j = 0; // ���ĺ��� �ƴ� ���ڸ� ī��Ʈ���ִ� ����
	while (input_string[i+j] != NULL) { // ���ڿ��� ������ �ݺ�
		if (isalpha(input_string[i+j])!=0) { // �Է¹��� ���ڰ� ���ĺ��̸� ����
			if ('a' <= input_string[i+j] && input_string[i+j] <= 'z') { // a~z ���� �̸�
				if (pop(&s) != input_string[i+j]) return 0; // ���ÿ��� �������� �Է¹��� ���ڰ� �ٸ��� ����
			}
			else if ('A' <= input_string[i+j] && input_string[i+j] <= 'Z') { // A~Z ���� �̸�
				char a = input_string[i] + ('a' - 'A'); // �빮�ڸ� �ҹ��ڷ� ����
				if (pop(&s) != a) return 0;  // ���ÿ��� �������� �Է¹��� ���ڰ� �ٸ��� ����
			}
			i++; // ���� ���� ���� ����
		}
		else j++; // ���ĺ��� �ƴѰ��� ī��Ʈ
	}
	if (!is_empty) printf("�˻簡 ����� �̷������ �ʾҽ��ϴ�"); // ���� ���°� �ƴϸ�  ����
	return 1; // �˻簡 ���������� ������ �� ����
}
int main() {
	char input_string[MAX] = {NULL}; // �Է¹��� ���ڵ��� �迭
	
	printf("���ڿ��� �Է��Ͻÿ�>>");
	gets_s(input_string, sizeof(input_string)); // get_s ����� ������� �Է¹޴´�.
	if (check_matching(input_string) == 1) printf("ȸ���Դϴ�."); // ���� ���ϵǸ� ����
	else printf("ȸ���� �ƴմϴ�.");
}
