#include<stdio.h>
#include<stdlib.h>

struct stack {
	int size;
	int top;
	int *S;
};

void create (struct stack *st){
	printf("Enter the stack size ");
	scanf("%d", &st->size);
	st->top = -1;
	st->S = (int *)malloc(st->size*sizeof(int));
}

void display(struct stack st){
	int i;
	for(i=st.top;i>=0;i--){
		printf("%d ", st.S[i]);
	}
	printf("\n");
}

void push(struct stack *st, int x){
	if(st->top >= st->size-1) {
		printf("Stack Overflow");		
	}else{
		st->top++;
		st->S[st->top] = x;
	}

}

int pop(struct stack *st){
	int x = -1;
	if(st->top == -1){
		printf("Stack Underflow");
	}else{
		x = st->S[st->top];
		st->top--;
	}
	return x;
}

int peek(struct stack *st, int pos){
	int x = -1;
	if((st->top)-pos+1 < 0 ){
		printf("invalid Position");
	}else {
		x = st->S[st->top-pos+1];
	}
}

void main () {
	struct stack st;
	create(&st);
	
	push(&st,3);
	push(&st,2);
	
	pop(&st);
	
	display(st);
}
