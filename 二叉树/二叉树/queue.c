#include <stdio.h>
#include <stdlib.h>


typedef int DataType;

/**
*�����еĽڵ�
*/
typedef struct Node {
	DataType _data;
	struct Node* _pNext;
}*PNode, Node;


/**
*����
pHead ��ͷָ��
pTail ��βָ��
size ���д�С
*/
typedef struct Queue {
	struct Node* pHead;
	struct Node* pTail;
}Queue;

/**
��ʼ������
*/
void QueueInit(Queue* queue);
/**
���
*/
void QueuePush(Queue* queue, DataType data);
/**
������
*/
int QueuePop(Queue* queue, DataType* data);

/**
�п�
*/
int QueueEmpty(Queue* queue);

/** 
ȡ��ͷԪ�� 
*/
DataType QueueFront(Queue* q);

/**
ȡ��βԪ��
*/ 
DataType QueueBack(Queue* q);

/**
��ȡ������Ԫ�صĸ���
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
	printf("������Ԫ�ظ���Ϊ%d\n\n", QueueSize(queue));

	printf("�����Ƿ�Ϊ�գ�%s\n", QueueEmpty(queue) == 1 ? "Ϊ��" : "��Ϊ��");

	printf("��ͷΪ%d\n", QueueFront(queue));
	printf("��βΪ%d\n", QueueBack(queue));
	int a;
	QueuePop(queue, &a);
	printf("\n������%d\n", a);

	QueuePop(queue, &a);
	printf("������%d\n", a);

	QueuePop(queue, &a);
	printf("������%d\n", a);

	printf("������Ԫ�ظ���Ϊ%d\n\n", QueueSize(queue));

	printf("�����Ƿ�Ϊ�գ�%s\n\n", QueueEmpty(queue) == 1 ? "Ϊ��" : "��Ϊ��");
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

// ȡ��ͷԪ�� 
DataType QueueFront(Queue* q) {
	if (q == NULL || q->pHead == NULL)
		return -1;
	return q->pHead->_data;
}

// ȡ��βԪ�� 
DataType QueueBack(Queue* q) {
	if (q == NULL || q->pTail == NULL)
		return -1;
	return q->pTail->_data;
}

// ��ȡ������Ԫ�صĸ��� 
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
