#include <stdio.h>
#include <stdlib.h>


typedef int DataType;

/**
*队列中的节点
*/
typedef struct Node {
	DataType _data;
	struct Node* _pNext;
}*PNode, Node;


/**
*队列
pHead 队头指针
pTail 队尾指针
size 队列大小
*/
typedef struct Queue {
	struct Node* pHead;
	struct Node* pTail;
}Queue;

/**
初始化队列
*/
void QueueInit(Queue* queue);
/**
入队
*/
void QueuePush(Queue* queue, DataType data);
/**
出队列
*/
int QueuePop(Queue* queue, DataType* data);

/**
判空
*/
int QueueEmpty(Queue* queue);

/** 
取队头元素 
*/
DataType QueueFront(Queue* q);

/**
取队尾元素
*/ 
DataType QueueBack(Queue* q);

/**
获取队列中元素的个数
*/ 
int QueueSize(Queue* q);


void TestQueue();

int main() {
	TestQueue();
	return 0;
}


void TestQueue() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	QueueInit(queue);
	QueuePush(queue, 4);
	QueuePush(queue, 5);
	QueuePush(queue, 6);
	printf("队列中元素个数为%d\n\n", QueueSize(queue));

	printf("队列是否为空：%s\n", QueueEmpty(queue) == 1 ? "为空" : "不为空");

	printf("队头为%d\n", QueueFront(queue));
	printf("队尾为%d\n", QueueBack(queue));
	int a;
	QueuePop(queue, &a);
	printf("\n出队列%d\n", a);

	QueuePop(queue, &a);
	printf("出队列%d\n", a);

	QueuePop(queue, &a);
	printf("出队列%d\n", a);

	printf("队列中元素个数为%d\n\n", QueueSize(queue));

	printf("队列是否为空：%s\n\n", QueueEmpty(queue) == 1 ? "为空" : "不为空");
}

void QueueInit(Queue* queue) 
{
	if (queue == NULL)
		return;

	queue->pHead = NULL;
	queue->pTail = NULL;
}

void QueuePush(Queue* queue, DataType data) {
	if (queue == NULL)
		return;

	PNode node = (PNode)malloc(sizeof(Node));
	if (node == NULL)
		return;

	node->_pNext = NULL;
	node->_data = data;

	if (queue->pHead == NULL) {
		queue->pHead = node;
		queue->pTail = node;
	}
	else {
		queue->pTail->_pNext = node;
		queue->pTail = node;
	}
}

int QueuePop(Queue* queue, DataType* data) {
	if (queue == NULL)
		return 0;
	if (queue->pHead == NULL)
		return 0;

	*data = queue->pHead->_data;

	PNode pre = queue->pHead;
	queue->pHead = queue->pHead->_pNext;
	pre->_pNext = NULL;

	free(pre);

	return 1;
}

int QueueEmpty(Queue* queue) {
	if (queue->pHead == NULL)
		return 1;
	return 0;
}

// 取队头元素 
DataType QueueFront(Queue* q) {
	if (q == NULL || q->pHead == NULL)
		return -1;
	return q->pHead->_data;
}

// 取队尾元素 
DataType QueueBack(Queue* q) {
	if (q == NULL || q->pTail == NULL)
		return -1;
	return q->pTail->_data;
}

// 获取队列中元素的个数 
int QueueSize(Queue* q) {

	if (q == NULL || q->pHead == NULL)
		return 0;

	PNode cur = q->pHead;

	int count = 1;

	while (cur != q->pTail) {
		cur = cur->_pNext;
		count++;
	}

	return count;
}
