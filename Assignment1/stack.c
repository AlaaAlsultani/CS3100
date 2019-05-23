// CS 3100 Assignment1
// Author: Brayden Houston
// Talked With: Joesph Hwang
// Date: 20190520
// FileName: stack.c

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

stackT *NewStack(void){
	stackT *sStack =  malloc (sizeof(sStack));
	sStack->head = NULL;
	return sStack;
}

//push
//	allocate space for new node
//	save the value passed in
//	set the next pointer to head
//	set head to point to this new node
void Push(stackT *stack, valueT value){
	nodeT *node = (nodeT*) malloc(sizeof(nodeT));
	node->value = value;
	node->next = stack->head;
	stack->head = node;
}

//pop
//	check if stack is empty
//	save the value of node pointed to by head
//	save a pointer tto the node head points to in temp
//	set head to temp->value in next
//	free temp 
//	return value
valueT Pop(stackT *stack){
	if(IsEmpty(stack)){
		printf("Cannot work with an empty stack");
		return 0;
	}
	else{
		nodeT *node = stack->head;
		valueT value = stack->head->value;
		stack->head = stack->head->next;
		free(node);
		return value;
	}
}

//Empty Stack
//	 while stack->head != NULL
// 	pop stack
void EmptyStack(stackT *stack){
	while(stack->head != NULL){
		Pop(stack);
	}
}

//Free stack
// 	if stack isempty
//	 	free(stack)
// 	else
//	 	error
void FreeStack(stackT *stack){
	if(IsEmpty(stack)){
		free(stack);
	}
	else{
	 	printf("Nothing to free up.");
	}
}

//Is empty
//	return stack->head == NULL
bool IsEmpty(stackT *stack){
	if(stack->head == NULL){
		return true;
	}	
	return false;
}
