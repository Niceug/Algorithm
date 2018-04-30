#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "stack.h"
#define Init_StackSize 100


//初始化栈
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

//压栈
void StackPush(PStack stack, StackElement data) {
	assert(stack);
	//判断栈是否已满
	if (stack->_top >= stack->_capacity) {
		//申请10个空间
		stack->_array = (StackElement*)realloc(stack->_array,
			sizeof(StackElement)*(stack->_capacity + 10));
		//判断是否申请成功
		if (!stack->_array) {
			exit(0);
		}
		stack->_top = stack->_capacity;
		stack->_capacity = stack->_capacity + 10;
	}

	*(stack->_array + stack->_top) = data;
	stack->_top++;
}

//获取栈顶元素
StackElement StackTop(PStack stack) {
	assert(stack);
	if (stack->_top != 0)
		return *(stack->_array + (stack->_top - 1));
	return 0;
}

//出栈
int StackPop(PStack stack, StackElement* data) {
	assert(stack);
	//判断栈是否为空
	if (stack->_top == 0) {
		return 0;
	}
	//先减一再取值
	--stack->_top;
	*data = *(stack->_array + stack->_top);

	return 1;
}