#if 1==0
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct ComplexNode {
	int data;
	struct ComplexNode* _pNext;
	struct ComplexNode* _pRandom;
}*PComplexNode, ComplexNode;

//������ӡ������
void showSList(PComplexNode list) {
	PComplexNode pCur = list;
	while (pCur) {
		printf("%d ", pCur->data);
		pCur = pCur->_pNext;
	}
	printf("\n");
}

//��������ĸ���
PComplexNode copyComplexNode(PComplexNode list) {
	assert(list);
	
	PComplexNode newList = list;

	//�������ÿ��Ԫ�غ����һ���ڵ�
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

	//��randomָ����ֵ
	while (pNew->_pNext) {
		pNew->_pRandom = pOld->_pRandom == NULL ? NULL : pOld->_pRandom->_pNext;

		pOld = pOld->_pNext->_pNext;
		pNew = pOld->_pNext;
	}

	//������������
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

//β�巨
void insertIntoTail(PComplexNode* list, int data) {
	assert(list);
	PComplexNode insertNode =(PComplexNode)malloc(sizeof(ComplexNode));
	insertNode->data = data;
	insertNode->_pNext = NULL;
	//�����ָ����ָ���Լ�
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