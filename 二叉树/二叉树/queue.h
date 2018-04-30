typedef int ElementType;

/**
*队列中的节点
*/
typedef struct Node {
	ElementType _data;
	struct Node* _pNext;
}*PNode, Node;


/**
*队列
 pHead 队头指针
 pTail 队尾指针
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
void QueuePush(Queue* queue, ElementType data);
/**
出队列
*/
int QueuePop(Queue* queue, ElementType* data);

/**
判空
*/
int QueueEmpty(Queue* queue);

/** 
取队头元素 
*/
ElementType QueueFront(Queue* q);

/** 
取队尾元素
*/
ElementType QueueBack(Queue* q);

/** 
获取队列中元素的个数 
*/
int QueueSize(Queue* q);
