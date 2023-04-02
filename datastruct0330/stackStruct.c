#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�. 
// ===== ���� �ڵ��� ���� ===== 
#define MAX_STACK_SIZE 10

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "Stack Full\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
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
// ��ũ�Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== ���� �ڵ��� �� ===== 


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
