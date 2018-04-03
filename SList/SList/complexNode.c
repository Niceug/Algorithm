#if 1==0
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct ComplexNode {
	int data;
	struct ComplexNode* _pNext;
	struct ComplexNode* _pRandom;
}*PComplexNode, ComplexNode;

//正常打印单链表
void showSList(PComplexNode list) {
	PComplexNode pCur = list;
	while (pCur) {
		printf("%d ", pCur->data);
		pCur = pCur->_pNext;
	}
	printf("\n");
}

//复杂链表的复制
PComplexNode copyComplexNode(PComplexNode list) {
	assert(list);
	
	PComplexNode newList = list;

	//在链表的每个元素后面插一个节点
	PComplexNode pNewNode = NULL;
	while (newList) {
		pNewNode = (PComplexNode)malloc(sizeof(ComplexNode));
		pNewNode->data = newList->data;
		pNewNode->_pNext = newList->_pNext;
		newList->_pNext = pNewNode;
		newList = newList->_pNext->_pNext;
	}
	
	PComplexNode pNew = list->_pNext;
	PComplexNode pOld = list;

	//给random指针域赋值
	while (pNew->_pNext) {
		pNew->_pRandom = pOld->_pRandom == NULL ? NULL : pOld->_pRandom->_pNext;

		pOld = pOld->_pNext->_pNext;
		pNew = pOld->_pNext;
	}

	//分离两个链表
	pNew = list->_pNext;
	newList = list->_pNext;
	pOld = list;
	while (pNew->_pNext) {
		pOld->_pNext = pNew->_pNext;
		pOld = pOld->_pNext;
		pNew->_pNext = pOld->_pNext;
		pNew = pNew->_pNext;
	}

	return newList;
}

//尾插法
void insertIntoTail(PComplexNode* list, int data) {
	assert(list);
	PComplexNode insertNode =(PComplexNode)malloc(sizeof(ComplexNode));
	insertNode->data = data;
	insertNode->_pNext = NULL;
	//让随机指针域都指向自己
	insertNode->_pRandom = insertNode;
	if (*list == NULL) {
		*list = insertNode;
		return;
	}
	PComplexNode pCur = *list;
	while (pCur->_pNext) {
		pCur = pCur->_pNext;
	}
	pCur->_pNext = insertNode;
}


int main() {
	
	PComplexNode list = NULL;
	insertIntoTail(&list, 1);
	insertIntoTail(&list, 2);
	insertIntoTail(&list, 3);
	insertIntoTail(&list, 4);
	insertIntoTail(&list, 5);
	insertIntoTail(&list, 6);

	PComplexNode newList = copyComplexNode(list);
	showSList(newList);

	return 0;
}

#endif