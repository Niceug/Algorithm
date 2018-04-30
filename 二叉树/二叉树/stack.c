#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "stack.h"
#define Init_StackSize 100


//��ʼ��ջ
void StackInit(PStack stack) {
	stack->_array = (StackElement*)malloc(sizeof(StackElement)*Init_StackSize);
	for (int i = 0; i < sizeof(stack->_array) / sizeof(stack->_array[0]); i++) {
		stack->_array[i] = 0;
	}
	if (!stack->_array) {
		exit(0);
	}
	stack->_top = 0;
	stack->_capacity = Init_StackSize;
}

//ѹջ
void StackPush(PStack stack, StackElement data) {
	assert(stack);
	//�ж�ջ�Ƿ�����
	if (stack->_top >= stack->_capacity) {
		//����10���ռ�
		stack->_array = (StackElement*)realloc(stack->_array,
			sizeof(StackElement)*(stack->_capacity + 10));
		//�ж��Ƿ�����ɹ�
		if (!stack->_array) {
			exit(0);
		}
		stack->_top = stack->_capacity;
		stack->_capacity = stack->_capacity + 10;
	}

	*(stack->_array + stack->_top) = data;
	stack->_top++;
}

//��ȡջ��Ԫ��
StackElement StackTop(PStack stack) {
	assert(stack);
	if (stack->_top != 0)
		return *(stack->_array + (stack->_top - 1));
	return 0;
}

//��ջ
int StackPop(PStack stack, StackElement* data) {
	assert(stack);
	//�ж�ջ�Ƿ�Ϊ��
	if (stack->_top == 0) {
		return 0;
	}
	//�ȼ�һ��ȡֵ
	--stack->_top;
	*data = *(stack->_array + stack->_top);

	return 1;
}