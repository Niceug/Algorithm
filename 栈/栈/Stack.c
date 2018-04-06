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
	//�Ƿ���ͨ��
	int isAWay;
	//�Ƿ��߹�
	int went;
	//�Ƿ���˹�
	int back;
}State;

typedef char DataType;

typedef struct Stack {
	//�������ַΪջ��ָ��
	DataType* _array;
	//ջ��ָ��
	int _top;
	//ջ�Ĵ�С
	unsigned int _capacity;
}*PStack;


//��ʼ��ջ
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

//ѹջ
void StackPush(PStack stack, DataType data) {
	assert(stack);
	//�ж�ջ�Ƿ�����
	if (stack->_top >= stack->_capacity) {
		//����10���ռ�
		stack->_array = (DataType*)realloc(stack->_array, 
			sizeof(DataType)*(stack->_capacity + 10));
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
DataType StackTop(PStack stack) {
	assert(stack);
	if (stack->_top != 0)
		return *(stack->_array + (stack->_top - 1));
	return 0;
}

//��ջ
int StackPop(PStack stack, DataType* data) {
	assert(stack);
	//�ж�ջ�Ƿ�Ϊ��
	if (stack->_top == 0) {
		return 0;
	}
	//�ȼ�һ��ȡֵ
	--stack->_top;
	*data =  *(stack->_array + stack->_top);
	
	return 1;
}

//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(PStack stack) {
	assert(stack);
	//Ϊ�շ���1
	return stack->_top == 0 ? 1 : 0;
}

//��ЧԪ�ظ���
int StackSize(PStack stack) {
	assert(stack);
	return stack->_top;
}

//���ջ������������ɾ��
void ClearStack(PStack stack) {
	assert(stack);
	stack->_top = 0;
}

//����ջ
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

//��ӡջ������Ԫ��
void showAll(PStack stack) {
	assert(stack);
	if (0 == stack->_top)
		return;
	DataType* arr = stack->_array;
	int i = 0;
	while (i<stack->_top) {
		printf("ջ�е�Ԫ��%s\n", arr[i]);
		i++;
		if (i == stack->_top)
			break;
	}
	printf("-----------------------\n");
}

//������ת10����
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

//����ƥ��
void MatchBranckets(char* str) {
	if (str == NULL)
		return;
	
	//��ʼ��ջ
	PStack stack = (PStack)malloc(sizeof(struct Stack));
	StackInit(stack);

	char* p_str = str;

	//�������浯�����ַ�
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
				printf("ƥ��ʧ��\n");
				return;
			}

		}

		p_str++;
	}

	//������֮��,ջ�л������ţ�����ƥ��ʧ��
	if (StackPop(stack, &c))
	{
		printf("ƥ��ʧ��\n");
		return;
	}
	printf("ƥ��ɹ�\n");
}
//
////�Թ�����
//void mazeProblem(State** arr, int arrLen, int start_x, int start_y) {
//	PStack stack = (PStack)malloc(sizeof(struct Stack));
//	StackInit(stack);
//	Direction go = WEST;
//	int x = start_x;
//	int y = start_y;
//	//WEST, NORTH, EAST, SOUTH;��->��->��->��
//	PStack tempStack;
//	while (1) {
//		switch (go)
//		{
//		case WEST:
//		{
//			--x;
//			if (arr[y][x].isAWay == 0) {
//				go = NORTH;
//				//���߹���·���ϼǺ�
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
//������ת8���ƣ�ÿ��3�����֣���������������һ��ջ
void TestBinaryToTen() {
	PStack stack = (PStack)malloc(sizeof(struct Stack));
	StackInit(stack);
	char* str = "1101";
	int sum = BinaryToTen(stack, str);
	printf("%sת��Ϊ10����Ϊ%d\n",str, sum);

	char* str1 = "1101001";
	int sum1 = BinaryToTen(stack, str1);
	printf("%sת��Ϊ10����Ϊ%d\n",str1, sum1);
}
//
//void TestMazeProblem() {
//	//��һ�����������Ƿ��ܹ�ͨ�У��ڶ������������Ƿ��߹�, ���������������Ƿ���˹�
//	State arr[6][6] = {
//		{ { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } },
//		{ { 0, 0, 0 },{ 0, 0, 0 },{ 1, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } },
//		{ { 0, 0, 0 },{ 0, 0, 0 },{ 1, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } },
//		{ { 0, 0, 0 },{ 0, 0, 0 },{ 1, 0, 0 },{ 1, 0, 0 },{ 1, 0, 0 },{ 0, 0, 0 } },
//		{ { 0, 0, 0 },{ 0, 0, 0 },{ 1, 0, 0 },{ 0, 0, 0 },{ 1, 0, 0 },{ 1, 0, 0 } },
//		{ { 0, 0, 0 },{ 0, 0, 0 },{ 1, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } }
//	};
//	//2,5λ��ʼλ��
//	mazeProblem(arr, sizeof(arr[0]) / sizeof(arr[0][0]), 2, 5);
//}


//���ݲ������Ĳ�ͬ���в�ͬ�ļ���
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

//��׺���ʽ��ֵ
int caculateNifixExpression(char* str) {

	//���������β�����
	PStack operator = (PStack)malloc(sizeof(struct Stack));
	StackInit(operator);

	if (str == NULL)
		return;

	char* p_str = str;
	char* p_preStr = str;

	int* StackPopData = 0;
	//�����ĵ�һ�����������Ҳ�����
	int first = 0;
	//�����ĵڶ���������, �������
	int second = 0;
	while (*p_str) {
		if (*p_str == ' ') {
			//�ո�ǰ�����֣�ѹջ
			if (*p_preStr >= '0' && *p_preStr <= '9')
				StackPush(operator, atoi(p_preStr));
			p_preStr = p_str + 1;
		}
		if (*p_str == '+' || *p_str == '-' || *p_str == '*' || *p_str == '/') {

			//��������������
			StackPop(operator, &StackPopData);
			second = StackPopData;
			StackPop(operator, &StackPopData);
			first = StackPopData;

			//������
			StackPopData = caculate(first, second, *p_str);

			//�����ջ
			StackPush(operator, StackPopData);
		}
		p_str++;
	}
	StackPop(operator, &StackPopData);
	printf("%d\n", StackPopData);
	return StackPopData;
}


//�������ȼ��Ƚϵĺ���
int cmpPriority(char first, char second) {

	//�����ȼ��ݼ�, 0���
	char arr[] = {'*', '/', '+', '-'};

	int prioFirst = 0;
	int prioSecond = 0;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] == first)
			prioFirst = i;
		if (arr[i] == second)
			prioSecond = i;
	}

	//ǰ�����ȼ����ڵ��ں��淵��1
	return prioFirst <= prioSecond ? 1 : 0;
}


////��׺���ʽ��ֵ�������Ҳ������Ͳ���������ջ�����ȼ��Ƚϣ�
////�������ȼ��͵Ļ���һ���Ĳ������Ϳ�ʼ��ֵ
//int caculateSuffixExpression(char* str) {
//	
//	//������ջ
//	PStack operand = (PStack)malloc(sizeof(struct Stack));
//	StackInit(operand);
//
//	//������ջ
//	PStack operator = (PStack)malloc(sizeof(struct Stack));
//	StackInit(operator);
//
//	//������������������
//	char StackPopOperandFirst = NULL;
//	char** StackPopOperandSecond = NULL;
//
//	//�����Ĳ�����
//	char** StackPopOperator = NULL;
//
//	//������
//	int result = 0;
//	
//	char* p_str = str;
//
//	//ָ��p_str��ǰ�棬����ȡ������
//	char* p_preStr = str;
//
//	//����ת��������
//	char castOperand[3] = {0};
//
//	//����ת��������
//	char castOperator[2] = { 0 };
//	char* casted;
//
//	while (*p_str) {
//
//		//ֻ���������������Ž�����ջ��ջ����
//		if (*p_str < '0' || *p_str > '9') {
//			while (1) {
//				DataType topData= StackTop(operator);
//				//������ջΪ�գ�ֱ��ѹ��������Ͳ�����
//				if (0 == topData) {
//					
//					//��������ջ
//					castOperator[0] = *p_str;
//					StackPush(operator, castOperator);
//					casted = itoa(atoi(p_preStr), castOperand, 10);
//					printf("%sѹջ\n", casted);
//					StackPush(operand, casted);
//					break;
//				}
//				else if (cmpPriority(*p_str, topData[0]) > 0) {
//					//�����Ĳ��������ȼ�����ջ��Ԫ�أ����ò�����ѹջ;
//					casted = itoa(atoi(p_preStr), castOperand, 10);
//					printf("%sѹջ\n", casted);
//					StackPush(operand, casted);
//
//					//�������Ĳ�����ѹջ
//					castOperator[0] = *p_str;
//					StackPush(operator, castOperator);
//					break;
//				}
//				else {
//					//�����Ĳ��������ȼ�С���Լ����͵����������Ͳ���������;
//					StackPop(operator, &StackPopOperator);
//
//					StackPop(operand, &StackPopOperandSecond);
//					printf("������2��ջ%s\n", StackPopOperandSecond);
//					printf("ջ��Ԫ����%d��\n", StackSize(operand));
//					//����
//					result = caculate(atoi(StackPopOperandSecond), atoi(p_preStr), StackPopOperator[0]);
//					printf("������=%d\n", result);
//					char* casted = itoa(result, castOperand, 10);
//
//					//�����ջ
//					printf("�����ջ%s\n", casted);
//					StackPush(operand, casted);
//					printf("ջ��Ԫ����%d��\n", StackSize(operand));
//					//�����Ĳ�������ջ
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
//	//ʣ��Ԫ�س�ջ��ֵ
//	StackPop(operand, &StackPopOperandSecond);
//	result = caculate(atoi(StackPopOperandSecond), atoi(p_preStr), StackPopOperator[0]);
//	printf("���Ϊ%d\n", result);
//	return 0;
//}

//��׺ת��׺
char* SuffixToNifix(char* str) {

	//������ջ
	PStack operand = (PStack)malloc(sizeof(struct Stack));
	StackInit(operand);

	//������ջ
	PStack operator = (PStack)malloc(sizeof(struct Stack));
	StackInit(operator);

	char buffer;
	while (*str) {
		//�ж��ǲ��������ǲ�����
		if (*str >= '0' && *str <= '9') {
			//��������ջ		
			StackPush(operand, *str);
			if(*(str + 1) < '0' || *(str + 1) > '9')
				if (StackTop(operand) != 0)
					StackPush(operand, 0);
		}
		else {
			/*if (StackTop(operand) != 0)
				StackPush(operand, 0);*/
			//ɨ�赽������
			//�жϲ�����ջ�Ƿ�Ϊ�գ�Ϊ��ֱ����ջ
			if (1 == StackEmpty(operator)) {
				StackPush(operator, *str);
			}
			else if ('(' == *str) {
				//���������ţ�ֱ����ջ�������ŵ����ȼ����
				StackPush(operator, *str);
			}
			else if (')' == *str) {
				//���������ţ�һֱ��ջ����ѹջ��������ջ��ֱ�������ŵ���
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
				
				//�ǿգ���Ƚϵ�ǰջ�������������������������ȼ�
				char operatorTop = StackTop(operator);
				if (cmpPriority(operatorTop, *str) > 0 && operatorTop != '(') {
					//ջ����������ȼ��ϸߣ�����ջ�����������ѹ��������ջ
					StackPop(operator, &buffer);
					StackPush(operand, buffer);
					StackPush(operator, *str);
				}
				else {
					//ջ����������ȼ��ϵͣ���ǰ�����ֱ����ջ
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
	printf("��׺���ʽ%s��������Ϊ:", str1);
	caculateNifixExpression(str1);
	printf("��׺���ʽ%s��������Ϊ:", str2);
	caculateNifixExpression(str2);*/
	// + 7*(4+5)
	/*char* str3 = "9*8/6+20+2+1";
	caculateSuffixExpression(str3);*/
	//�Թ�����
	//TestMazeProblem();
	//����ƥ��
	/*char *str5 = "(){({}){";
	char *str6 = "(){({){";
	char *str7 = "(){({)}{";
	char *str8 = "(){({})}";
	printf("%s��", str5);
	MatchBranckets(str5);
	printf("%s��", str6);
	MatchBranckets(str6);
	printf("%s��", str7);
	MatchBranckets(str7);
	printf("%s��", str8);
	MatchBranckets(str8);*/
	//������ת10����
	TestBinaryToTen();
	/*char* str4 = "999*8/(6+20)+2+1";
	printf("��ǰ��׺���ʽΪ��%s\n", str4);
	printf("ת��Ϊ��׺���ʽΪ��");*/
	//SuffixToNifix(str4);
	//char* buffer = "123456";
	//char** pBuf = &buffer;
	//*(&pBuf + 1) = '\0';
	//printf("%s\n", buffer);
	////��ջ��ջ����
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
	////Ԫ�ظ���
	//printf("%d\n", StackSize(stack));
	////ջ�п�
	//printf("%d\n", StackEmpty(stack));
	//printf("%s\n", StackTop(stack));
	//char ** str;
	//StackPop(stack, &str);
	//printf("%s\n", str);
	//printf("��%s\n", StackTop(stack));
	//StackPush(stack, str);
	//char buf[2] = { 0 };
	//buf[0] = '*';
	//StackPush(stack, buf);
	////StackPop(stack, &str);
	//printf("��%s\n", StackTop(stack));
	return 0;
}	
#endif