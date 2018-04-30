typedef int ElementType;

/**
*�����еĽڵ�
*/
typedef struct Node {
	ElementType _data;
	struct Node* _pNext;
}*PNode, Node;


/**
*����
 pHead ��ͷָ��
 pTail ��βָ��
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
void QueuePush(Queue* queue, ElementType data);
/**
������
*/
int QueuePop(Queue* queue, ElementType* data);

/**
�п�
*/
int QueueEmpty(Queue* queue);

/** 
ȡ��ͷԪ�� 
*/
ElementType QueueFront(Queue* q);

/** 
ȡ��βԪ��
*/
ElementType QueueBack(Queue* q);

/** 
��ȡ������Ԫ�صĸ��� 
*/
int QueueSize(Queue* q);
