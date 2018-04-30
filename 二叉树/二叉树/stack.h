extern struct BTree;
typedef struct BTree* StackElement;



typedef struct Stack {
	//以数组地址为栈底指针
	StackElement* _array;
	//栈顶指针
	int _top;
	//栈的大小
	unsigned int _capacity;
}*PStack, Stack;


//初始化栈
void StackInit(PStack stack);

//压栈
void StackPush(PStack stack, StackElement data);

//获取栈顶元素
StackElement StackTop(PStack stack);

//出栈
int StackPop(PStack stack, StackElement* data);