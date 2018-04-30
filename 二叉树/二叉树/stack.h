extern struct BTree;
typedef struct BTree* StackElement;



typedef struct Stack {
	//�������ַΪջ��ָ��
	StackElement* _array;
	//ջ��ָ��
	int _top;
	//ջ�Ĵ�С
	unsigned int _capacity;
}*PStack, Stack;


//��ʼ��ջ
void StackInit(PStack stack);

//ѹջ
void StackPush(PStack stack, StackElement data);

//��ȡջ��Ԫ��
StackElement StackTop(PStack stack);

//��ջ
int StackPop(PStack stack, StackElement* data);