
/* Please be aware that the code in its current state is in the initial phase and has undergone minimal testing. It is strongly recommended to thoroughly test and make any necessary modifications before utilizing it. */
/* I cannot be held responsible for any issues or difficulties arising from using the code without making appropriate modifications. */
/* basic stack implementation in C */
/*
basic stack implementation in C
File: Main.c
Author: Malkoot Khan
Date: 14/07/2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;

struct Stack {
	int item;
	struct Stack* next;
};

struct Stack* createStackNode(int data) {
	struct Stack* stk = (struct Stack*)malloc(sizeof(struct Stack));
	stk->item = data;
	stk->next = NULL;
	return stk;
}
bool isEmpty(struct Stack** top) {
	if (*top == NULL)
		return true;
	return false;
}

void push(struct Stack** top, int data) {
	struct Stack* newNode = createStackNode(data);
	newNode->next = *top;
	*top = newNode;
}
void pop(struct Stack** top) {
	if (*top == NULL) {
		printf("Stack is empty!\n");
		return;
	}
	struct Stack* s = *top;
	*top = s->next;
	free(s);
}
int peek(struct Stack** top) {
	if (isEmpty(top)) {
		printf("stack is empty!\n");
		return;
	}
	return (*top)->item;
}
void releaseMem(struct Stack** top) {
	if (*top)
		pop(top);
}
void display(struct Stack* top) {
	if (top == NULL) {
		printf("Stack is empty!\n");
		return;
	}
	struct Stack* s = top;
	while (s != NULL) {
		printf("%d ", s->item);
		s = s->next;
	}
	printf("\n");
}

int main() {
	struct Stack *top = NULL;
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);
	push(&top, 40);
	display(top);
	pop(&top);
	display(top);
	pop(&top);
	display(top);
	pop(&top);
	releaseMem(&top);
	display(top);
	pop(&top);
	display(top);
	return 0;
}

