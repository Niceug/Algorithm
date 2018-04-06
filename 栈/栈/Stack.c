#if 1
#pragma warning(disable:4996)

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#define Init_StackSize 100
typedef enum Direction{
	EAST, WEST, NORTH, SOUTH
}Direction;
typedef struct State {
	//是否能通行
	int isAWay;
	//是否被走过
	int went;
	//是否回退过
	int back;
}State;

typedef char DataType;

typedef struct Stack {
	//以数组地址为栈底指针
	DataType* _array;
	//栈顶指针
	int _top;
	//栈的大小
	unsigned int _capacity;
}*PStack;


//初始化栈
void StackInit(PStack stack) {
	stack->_array = (DataType*)malloc(sizeof(DataType)*Init_StackSize);
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
void StackPush(PStack stack, DataType data) {
	assert(stack);
	//判断栈是否已满
	if (stack->_top >= stack->_capacity) {
		//申请10个空间
		stack->_array = (DataType*)realloc(stack->_array, 
			sizeof(DataType)*(stack->_capacity + 10));
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
DataType StackTop(PStack stack) {
	assert(stack);
	if (stack->_top != 0)
		return *(stack->_array + (stack->_top - 1));
	return 0;
}

//出栈
int StackPop(PStack stack, DataType* data) {
	assert(stack);
	//判断栈是否为空
	if (stack->_top == 0) {
		return 0;
	}
	//先减一再取值
	--stack->_top;
	*data =  *(stack->_array + stack->_top);
	
	return 1;
}

//判断栈是否为空
int StackEmpty(PStack stack) {
	assert(stack);
	//为空返回1
	return stack->_top == 0 ? 1 : 0;
}

//有效元素个数
int StackSize(PStack stack) {
	assert(stack);
	return stack->_top;
}

//清空栈，不进行物理删除
void ClearStack(PStack stack) {
	assert(stack);
	stack->_top = 0;
}

//销毁栈
void dropStack(PStack stack) {
	assert(stack);
	int len = stack->_capacity;
	for (int i = 0; i < len; i++) {
		free(stack->_array);
		stack->_array++;
	}
	stack->_array = NULL;
	stack->_top = 0;
	stack->_capacity = 0;
}

//打印栈中所有元素
void showAll(PStack stack) {
	assert(stack);
	if (0 == stack->_top)
		return;
	DataType* arr = stack->_array;
	int i = 0;
	while (i<stack->_top) {
		printf("栈中的元素%s\n", arr[i]);
		i++;
		if (i == stack->_top)
			break;
	}
	printf("-----------------------\n");
}

//二进制转10进制
int BinaryToTen(PStack stack, DataType* str) {
	assert(stack);
	unsigned int len = stack->_capacity;
	char* p_str = str;
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (*p_str == '\0')
			break;
		StackPush(stack, *p_str);
		p_str++;
	}
	char binary = ' ';
	for (int i = 0; i < len; i++) {
		if (0 == StackPop(stack, &binary))
			break;
			sum += (binary - 48)*pow(2, i);
	}
	return sum;
}

//括号匹配
void MatchBranckets(char* str) {
	if (str == NULL)
		return;
	
	//初始化栈
	PStack stack = (PStack)malloc(sizeof(struct Stack));
	StackInit(stack);

	char* p_str = str;

	//用来保存弹出的字符
	char c;

	while (*p_str) {

		if (*p_str == '{' || *p_str == '(' || *p_str == '[') {
			StackPush(stack, *p_str);
		}

		if (*p_str == '}' || *p_str == ')' || *p_str == ']') {

			StackPop(stack, &c);

			if (c == '{' && *p_str == '}');
			else if (c == '(' && *p_str == ')');
			else if (c == '[' && *p_str == ']');
			else {
				printf("匹配失败\n");
				return;
			}

		}

		p_str++;
	}

	//遍历完之后,栈中还有括号，代表匹配失败
	if (StackPop(stack, &c))
	{
		printf("匹配失败\n");
		return;
	}
	printf("匹配成功\n");
}
//
////迷宫问题
//void mazeProblem(State** arr, int arrLen, int start_x, int start_y) {
//	PStack stack = (PStack)malloc(sizeof(struct Stack));
//	StackInit(stack);
//	Direction go = WEST;
//	int x = start_x;
//	int y = start_y;
//	//WEST, NORTH, EAST, SOUTH;左->上->右->下
//	PStack tempStack;
//	while (1) {
//		switch (go)
//		{
//		case WEST:
//		{
//			--x;
//			if (arr[y][x].isAWay == 0) {
//				go = NORTH;
//				//给走过的路打上记号
//				arr[y][x].went = 1;
//				StackPop(stack, &tempStack);
//				++x;
//			}
//			else {
//				StackPush(stack, arr[y][x + 1]);
//			}
//
//		}break;
//
//		default:
//			break;
//		}
//	}
//}
//
//二进制转8进制，每弹3个数字，计算结果，进入另一个栈
void TestBinaryToTen() {
	PStack stack = (PStack)malloc(sizeof(struct Stack));
	StackInit(stack);
	char* str = "1101";
	int sum = BinaryToTen(stack, str);
	printf("%s转换为10进制为%d\n",str, sum);

	char* str1 = "1101001";
	int sum1 = BinaryToTen(stack, str1);
	printf("%s转换为10进制为%d\n",str1, sum1);
}
//
//void TestMazeProblem() {
//	//第一个参数代表是否能够通行，第二个参数代表是否被走过, 第三个参数代表是否回退过
//	State arr[6][6] = {
//		{ { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } },
//		{ { 0, 0, 0 },{ 0, 0, 0 },{ 1, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } },
//		{ { 0, 0, 0 },{ 0, 0, 0 },{ 1, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } },
//		{ { 0, 0, 0 },{ 0, 0, 0 },{ 1, 0, 0 },{ 1, 0, 0 },{ 1, 0, 0 },{ 0, 0, 0 } },
//		{ { 0, 0, 0 },{ 0, 0, 0 },{ 1, 0, 0 },{ 0, 0, 0 },{ 1, 0, 0 },{ 1, 0, 0 } },
//		{ { 0, 0, 0 },{ 0, 0, 0 },{ 1, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } }
//	};
//	//2,5位起始位置
//	mazeProblem(arr, sizeof(arr[0]) / sizeof(arr[0][0]), 2, 5);
//}


//根据操作符的不同进行不同的计算
int caculate(int first, int second, char operator) {
	if (operator == '+') {
		return first + second;
	}
	else if (operator == '-') {
		return first - second;
	}
	else if (operator == '*') {
		return first * second;
	}
	else if (operator == '/') {
		return first / second;
	}
}

//后缀表达式求值
int caculateNifixExpression(char* str) {

	//用来放整形操作数
	PStack operator = (PStack)malloc(sizeof(struct Stack));
	StackInit(operator);

	if (str == NULL)
		return;

	char* p_str = str;
	char* p_preStr = str;

	int* StackPopData = 0;
	//弹出的第一个操作数，右操作数
	int first = 0;
	//弹出的第二个操作数, 左操作数
	int second = 0;
	while (*p_str) {
		if (*p_str == ' ') {
			//空格前是数字，压栈
			if (*p_preStr >= '0' && *p_preStr <= '9')
				StackPush(operator, atoi(p_preStr));
			p_preStr = p_str + 1;
		}
		if (*p_str == '+' || *p_str == '-' || *p_str == '*' || *p_str == '/') {

			//弹出两个操作数
			StackPop(operator, &StackPopData);
			second = StackPopData;
			StackPop(operator, &StackPopData);
			first = StackPopData;

			//计算结果
			StackPopData = caculate(first, second, *p_str);

			//结果入栈
			StackPush(operator, StackPopData);
		}
		p_str++;
	}
	StackPop(operator, &StackPopData);
	printf("%d\n", StackPopData);
	return StackPopData;
}


//用于优先级比较的函数
int cmpPriority(char first, char second) {

	//按优先级递减, 0最大
	char arr[] = {'*', '/', '+', '-'};

	int prioFirst = 0;
	int prioSecond = 0;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] == first)
			prioFirst = i;
		if (arr[i] == second)
			prioSecond = i;
	}

	//前面优先级大于等于后面返回1
	return prioFirst <= prioSecond ? 1 : 0;
}


////中缀表达式求值，从左到右操作数和操作符都入栈，优先级比较，
////遇到优先级低的或者一样的操作符就开始求值
//int caculateSuffixExpression(char* str) {
//	
//	//操作数栈
//	PStack operand = (PStack)malloc(sizeof(struct Stack));
//	StackInit(operand);
//
//	//操作符栈
//	PStack operator = (PStack)malloc(sizeof(struct Stack));
//	StackInit(operator);
//
//	//弹出的两个操作数。
//	char StackPopOperandFirst = NULL;
//	char** StackPopOperandSecond = NULL;
//
//	//弹出的操作符
//	char** StackPopOperator = NULL;
//
//	//计算结果
//	int result = 0;
//	
//	char* p_str = str;
//
//	//指向p_str的前面，用来取操作数
//	char* p_preStr = str;
//
//	//用来转换操作数
//	char castOperand[3] = {0};
//
//	//用来转换操作符
//	char castOperator[2] = { 0 };
//	char* casted;
//
//	while (*p_str) {
//
//		//只有遇到操作符，才进行入栈出栈操作
//		if (*p_str < '0' || *p_str > '9') {
//			while (1) {
//				DataType topData= StackTop(operator);
//				//操作符栈为空，直接压入操作数和操作符
//				if (0 == topData) {
//					
//					//操作符入栈
//					castOperator[0] = *p_str;
//					StackPush(operator, castOperator);
//					casted = itoa(atoi(p_preStr), castOperand, 10);
//					printf("%s压栈\n", casted);
//					StackPush(operand, casted);
//					break;
//				}
//				else if (cmpPriority(*p_str, topData[0]) > 0) {
//					//遇到的操作符优先级大于栈顶元素，将该操作符压栈;
//					casted = itoa(atoi(p_preStr), castOperand, 10);
//					printf("%s压栈\n", casted);
//					StackPush(operand, casted);
//
//					//将遇到的操作符压栈
//					castOperator[0] = *p_str;
//					StackPush(operator, castOperator);
//					break;
//				}
//				else {
//					//遇到的操作符优先级小于自己，就弹出操作符和操作数计算;
//					StackPop(operator, &StackPopOperator);
//
//					StackPop(operand, &StackPopOperandSecond);
//					printf("操作数2出栈%s\n", StackPopOperandSecond);
//					printf("栈中元素有%d个\n", StackSize(operand));
//					//计算
//					result = caculate(atoi(StackPopOperandSecond), atoi(p_preStr), StackPopOperator[0]);
//					printf("计算结果=%d\n", result);
//					char* casted = itoa(result, castOperand, 10);
//
//					//结果入栈
//					printf("结果入栈%s\n", casted);
//					StackPush(operand, casted);
//					printf("栈中元素有%d个\n", StackSize(operand));
//					//遇到的操作符入栈
//					castOperator[0] = *p_str;
//					StackPush(operator, castOperator);
//					if (StackSize(operand) < 2)
//						break;
//				}
//			}
//			
//			p_preStr = p_str + 1;
//		}
//		p_str++;
//	}
//
//	//剩余元素出栈求值
//	StackPop(operand, &StackPopOperandSecond);
//	result = caculate(atoi(StackPopOperandSecond), atoi(p_preStr), StackPopOperator[0]);
//	printf("结果为%d\n", result);
//	return 0;
//}

//中缀转后缀
char* SuffixToNifix(char* str) {

	//操作数栈
	PStack operand = (PStack)malloc(sizeof(struct Stack));
	StackInit(operand);

	//操作符栈
	PStack operator = (PStack)malloc(sizeof(struct Stack));
	StackInit(operator);

	char buffer;
	while (*str) {
		//判断是操作数还是操作符
		if (*str >= '0' && *str <= '9') {
			//操作数入栈		
			StackPush(operand, *str);
			if(*(str + 1) < '0' || *(str + 1) > '9')
				if (StackTop(operand) != 0)
					StackPush(operand, 0);
		}
		else {
			/*if (StackTop(operand) != 0)
				StackPush(operand, 0);*/
			//扫描到操作符
			//判断操作符栈是否为空，为空直接入栈
			if (1 == StackEmpty(operator)) {
				StackPush(operator, *str);
			}
			else if ('(' == *str) {
				//遇到左括号，直接入栈，左括号的优先级最高
				StackPush(operator, *str);
			}
			else if (')' == *str) {
				//遇到右括号，一直出栈，并压栈到操作数栈，直到把括号弹出
				while (1) {
					StackPop(operator, &buffer);
					if (buffer == '(')
						break;
					StackPush(operand, buffer);
					/*if (StackTop(operand) != 0)
						StackPush(operand, 0);*/
				}		
			}
			else {
				
				//非空，则比较当前栈顶运算符和遇到的运算符的优先级
				char operatorTop = StackTop(operator);
				if (cmpPriority(operatorTop, *str) > 0 && operatorTop != '(') {
					//栈顶运算符优先级较高，弹出栈顶运算符，并压到操作数栈
					StackPop(operator, &buffer);
					StackPush(operand, buffer);
					StackPush(operator, *str);
				}
				else {
					//栈顶运算符优先级较低，当前运算符直接入栈
					StackPush(operator, *str);
				}
			
			}
			
		}
		
		str++;
	}
	char buf;
	while (StackPop(operator, &buf)) {
		StackPush(operand, buf);
	}
	while (StackPop(operand, &buf)) {
		StackPush(operator, buf);

	}
	while (StackPop(operator, &buf)) {
		printf("%c", buf);
	}
	printf("\n");
	return NULL;
}

int main() {
	
	/*char* str1 = "9 8 * 1 / 7 4 5 + * +";
	char* str2 = "12 3 4 + * 6 - 8 2 / +";
	printf("后缀表达式%s的运算结果为:", str1);
	caculateNifixExpression(str1);
	printf("后缀表达式%s的运算结果为:", str2);
	caculateNifixExpression(str2);*/
	// + 7*(4+5)
	/*char* str3 = "9*8/6+20+2+1";
	caculateSuffixExpression(str3);*/
	//迷宫问题
	//TestMazeProblem();
	//括号匹配
	/*char *str5 = "(){({}){";
	char *str6 = "(){({){";
	char *str7 = "(){({)}{";
	char *str8 = "(){({})}";
	printf("%s：", str5);
	MatchBranckets(str5);
	printf("%s：", str6);
	MatchBranckets(str6);
	printf("%s：", str7);
	MatchBranckets(str7);
	printf("%s：", str8);
	MatchBranckets(str8);*/
	//二进制转10进制
	TestBinaryToTen();
	/*char* str4 = "999*8/(6+20)+2+1";
	printf("当前中缀表达式为：%s\n", str4);
	printf("转换为后缀表达式为：");*/
	//SuffixToNifix(str4);
	//char* buffer = "123456";
	//char** pBuf = &buffer;
	//*(&pBuf + 1) = '\0';
	//printf("%s\n", buffer);
	////出栈入栈操作
	//PStack stack = (PStack)malloc(sizeof(struct Stack));
	//StackInit(stack);
	//char* strc = {0};
	//strc = "43";
	//StackPush(stack, strc);
	//strc = "56";
	//StackPush(stack, "6");
	//StackPush(stack, "7");
	//StackPush(stack, "8");
	//showAll(stack);
	////元素个数
	//printf("%d\n", StackSize(stack));
	////栈判空
	//printf("%d\n", StackEmpty(stack));
	//printf("%s\n", StackTop(stack));
	//char ** str;
	//StackPop(stack, &str);
	//printf("%s\n", str);
	//printf("顶%s\n", StackTop(stack));
	//StackPush(stack, str);
	//char buf[2] = { 0 };
	//buf[0] = '*';
	//StackPush(stack, buf);
	////StackPop(stack, &str);
	//printf("顶%s\n", StackTop(stack));
	return 0;
}	
#endif