#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 차후에 스택이 필요하면 여기만 복사하여 붙인다. 
// ===== 스택 코드의 시작 ===== 
#define MAX_STACK_SIZE 10

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "Stack Full\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		printf("pop -1\n");
		fprintf(stderr, "Stack Empty!\n");
		return;
	}
	else {
		printf("pop : %d\n", s->data[(s->top)]);
		return s->data[(s->top)--];

	}
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 


int main(void)
{
	StackType s;

	init_stack(&s);

	srand(time(NULL));
	printf("-------using Struct-------\n");
	int rand_num;
	for (int i = 0; i < 30; i++)
	{
		printf("[%d]\t", i);
		rand_num = rand() % 100 + 1;
		if (rand_num % 2 == 0)
		{
			printf("push :  %d\n", rand_num);
			push(&s, rand_num);
		}
		else {
			pop(&s);
		}
	}


	
}
