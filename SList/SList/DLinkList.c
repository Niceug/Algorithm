#if 0==1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/**
��ͷ����˫������
pNext��ָ����һ���ڵ��ָ��
pPre��ָ��ǰһ���ڵ��ָ��
*/
typedef int DataType;
typedef struct DNode {
	struct DNode* pNext;
	struct DNode* pPre;
	DataType data;
}*PDNode, DNode;

//��ʼ������
void initDList(PDNode* pHead);

//ͷ�巨����ڵ�
void insertIntoFront(PDNode pHead, DataType data);

//β�巨����ڵ�
void insertIntoTail(PDNode pHead, DataType data);

//ͷɾ��ɾ���ڵ�
void deleteFromFront(PDNode pHead);

//βɾ��ɾ���ڵ�
void deleteFromTail(PDNode pHead);

//����λ��ǰ����ڵ�
void insertIntoAnyWhere(PDNode posNode, DataType data);

//ɾ������λ�ýڵ�
void deleteFromAnyWhere(PDNode posNode);

//�����ڵ�
PDNode BuyNode(DataType data);

//��ȡ����λ�ýڵ㣬��˳����
PDNode getAnyWhereNode(PDNode pHead, unsigned int pos);

//��ӡ����
void showDList(PDNode pHead);


int main() {

	PDNode pHead = NULL;
	initDList(&pHead);

	//ͷ��
	insertIntoFront(pHead, 1);
	insertIntoFront(pHead, 2);
	insertIntoFront(pHead, 3);
	insertIntoFront(pHead, 4);

	//β��
	insertIntoTail(pHead, 9);
	insertIntoTail(pHead, 10);
	insertIntoTail(pHead, 11);
	insertIntoTail(pHead, 12);

	printf("ԭ����Ϊ\n");
	showDList(pHead);
	//posNode��ȡ������9
	printf("����λ�ò�\n");
	PDNode posNode = getAnyWhereNode(pHead, 5);
	insertIntoAnyWhere(posNode, 5);
	showDList(pHead);

	//ɾ��1
	printf("ͷɾ\n");
	deleteFromFront(pHead);
	showDList(pHead);

	//ɾ��12
	printf("βɾ\n");
	deleteFromTail(pHead);
	showDList(pHead);

	//ɾ��9
	printf("����λ��ɾ\n");
	deleteFromAnyWhere(posNode);

	showDList(pHead);

	return 0;
}


//��ʼ������
void initDList(PDNode* pHead) {
	*pHead = (PDNode)malloc(sizeof(DNode));
	(*pHead)->pNext = NULL;
	(*pHead)->pPre = NULL;
}

//��ȡ�½ڵ�
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

//ͷ�巨����ڵ�
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

//β�巨����ڵ�
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
	//����
	pCur->pNext = insertNode;
	insertNode->pPre = pCur;
}

//ͷɾ��ɾ���ڵ�
void deleteFromFront(PDNode pHead) {
	assert(&pHead);

	//�ж������Ƿ�Ϊ��
	if (pHead->pNext == NULL)
		return;

	//�ж������Ƿ�ֻ��һ��Ԫ��
	if (pHead->pNext->pNext == NULL) {
		free(pHead->pNext);
		pHead->pNext = NULL;
		return;
	}

	//ͷɾ
	PDNode deleteNode = pHead->pNext;
	pHead->pNext = pHead->pNext->pNext;
	pHead->pNext->pPre = pHead;
	free(deleteNode);
	deleteNode = NULL;
}

//βɾ��ɾ���ڵ�
void deleteFromTail(PDNode pHead) {
	assert(&pHead);
	PDNode pCur = pHead->pNext;
	while (pCur->pNext) {
		pCur = pCur->pNext;
	}

	//βɾ
	pCur->pPre->pNext = NULL;
	free(pCur);
	pCur = NULL;

}

//����λ��ǰ����ڵ�
void insertIntoAnyWhere(PDNode posNode, DataType data) {
	PDNode insertNode = BuyNode(data);
	if (posNode) {
		insertNode->pPre = posNode->pPre;
		posNode->pPre = insertNode;
		insertNode->pPre->pNext = insertNode;
		insertNode->pNext = posNode;
	}
}

//ɾ������λ�ýڵ�
void deleteFromAnyWhere(PDNode posNode){
	if (posNode->pNext) {
		posNode->pNext->pPre = posNode->pPre;
	}
	posNode->pPre->pNext = posNode->pNext;
	free(posNode);
	posNode = NULL;
}

//��ӡ����
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