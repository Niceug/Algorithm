#if 0==1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/**
带头结点的双向链表
pNext：指向下一个节点的指针
pPre：指向前一个节点的指针
*/
typedef int DataType;
typedef struct DNode {
	struct DNode* pNext;
	struct DNode* pPre;
	DataType data;
}*PDNode, DNode;

//初始化链表
void initDList(PDNode* pHead);

//头插法插入节点
void insertIntoFront(PDNode pHead, DataType data);

//尾插法插入节点
void insertIntoTail(PDNode pHead, DataType data);

//头删法删除节点
void deleteFromFront(PDNode pHead);

//尾删法删除节点
void deleteFromTail(PDNode pHead);

//任意位置前插入节点
void insertIntoAnyWhere(PDNode posNode, DataType data);

//删除任意位置节点
void deleteFromAnyWhere(PDNode posNode);

//产生节点
PDNode BuyNode(DataType data);

//获取任意位置节点，按顺序找
PDNode getAnyWhereNode(PDNode pHead, unsigned int pos);

//打印链表
void showDList(PDNode pHead);


int main() {

	PDNode pHead = NULL;
	initDList(&pHead);

	//头插
	insertIntoFront(pHead, 1);
	insertIntoFront(pHead, 2);
	insertIntoFront(pHead, 3);
	insertIntoFront(pHead, 4);

	//尾插
	insertIntoTail(pHead, 9);
	insertIntoTail(pHead, 10);
	insertIntoTail(pHead, 11);
	insertIntoTail(pHead, 12);

	printf("原链表为\n");
	showDList(pHead);
	//posNode获取到的是9
	printf("任意位置插\n");
	PDNode posNode = getAnyWhereNode(pHead, 5);
	insertIntoAnyWhere(posNode, 5);
	showDList(pHead);

	//删除1
	printf("头删\n");
	deleteFromFront(pHead);
	showDList(pHead);

	//删除12
	printf("尾删\n");
	deleteFromTail(pHead);
	showDList(pHead);

	//删除9
	printf("任意位置删\n");
	deleteFromAnyWhere(posNode);

	showDList(pHead);

	return 0;
}


//初始化链表
void initDList(PDNode* pHead) {
	*pHead = (PDNode)malloc(sizeof(DNode));
	(*pHead)->pNext = NULL;
	(*pHead)->pPre = NULL;
}

//获取新节点
PDNode BuyNode(DataType data) {
	PDNode newNode = (PDNode)malloc(sizeof(DNode));
	
	if (newNode == NULL) {
		assert(newNode);
		return NULL;
	}

	newNode->data = data;
	newNode->pNext = NULL;
	newNode->pPre = NULL;

	return newNode;
}

//头插法插入节点
void insertIntoFront(PDNode pHead, DataType data) {
	assert(&pHead);
	PDNode insertNode = BuyNode(data);
	if (pHead->pNext == NULL)
	{
		pHead->pNext = insertNode;
		insertNode->pPre = pHead;
	}
	else {
		insertNode->pNext = pHead->pNext;
		insertNode->pPre = pHead;
		pHead->pNext = insertNode;
		insertNode->pNext->pPre = insertNode;
	}
}

//尾插法插入节点
void insertIntoTail(PDNode pHead, DataType data) {
	assert(&pHead);
	PDNode insertNode = BuyNode(data);

	if (pHead->pNext == NULL) {
		pHead->pNext = insertNode;
		insertNode->pPre = pHead;
	}

	PDNode pCur = pHead;
	while (pCur->pNext) {
		pCur = pCur->pNext;
	}
	//插入
	pCur->pNext = insertNode;
	insertNode->pPre = pCur;
}

//头删法删除节点
void deleteFromFront(PDNode pHead) {
	assert(&pHead);

	//判断链表是否为空
	if (pHead->pNext == NULL)
		return;

	//判断链表是否只有一个元素
	if (pHead->pNext->pNext == NULL) {
		free(pHead->pNext);
		pHead->pNext = NULL;
		return;
	}

	//头删
	PDNode deleteNode = pHead->pNext;
	pHead->pNext = pHead->pNext->pNext;
	pHead->pNext->pPre = pHead;
	free(deleteNode);
	deleteNode = NULL;
}

//尾删法删除节点
void deleteFromTail(PDNode pHead) {
	assert(&pHead);
	PDNode pCur = pHead->pNext;
	while (pCur->pNext) {
		pCur = pCur->pNext;
	}

	//尾删
	pCur->pPre->pNext = NULL;
	free(pCur);
	pCur = NULL;

}

//任意位置前插入节点
void insertIntoAnyWhere(PDNode posNode, DataType data) {
	PDNode insertNode = BuyNode(data);
	if (posNode) {
		insertNode->pPre = posNode->pPre;
		posNode->pPre = insertNode;
		insertNode->pPre->pNext = insertNode;
		insertNode->pNext = posNode;
	}
}

//删除任意位置节点
void deleteFromAnyWhere(PDNode posNode){
	if (posNode->pNext) {
		posNode->pNext->pPre = posNode->pPre;
	}
	posNode->pPre->pNext = posNode->pNext;
	free(posNode);
	posNode = NULL;
}

//打印链表
void showDList(PDNode pHead) {
	assert(&pHead);
	
	PDNode pCur = pHead->pNext;
	while (pCur) {
		printf("-->%d", pCur->data);
		pCur = pCur->pNext;
	}

	printf("\n");
}


PDNode getAnyWhereNode(PDNode pHead, unsigned int pos) {
	assert(&pHead);
	PDNode pCur = pHead;
	while (pos--) {
		pCur = pCur->pNext;
		if (pCur == NULL)
			return NULL;
	}
	return pCur;
}
#endif