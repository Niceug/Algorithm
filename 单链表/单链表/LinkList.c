#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node, *PNode;


//////////////////����ͷ���ĵ�����////////////////////////////////////// 
// .h 
// �����ʼ�� 
void SListInit(PNode* pHead);

// β�� 
void SListPushBack(PNode* pHead, DataType _data);

// βɾ 
void SListPopBack(PNode* pHead);

// ͷ�� 
void SListPushFront(PNode* pHead, DataType _data);

// ͷɾ 
void SListPopFront(PNode* pHead);

// ����ֵΪ_data�Ľ�㣬���ظý���������е�λ�� 
PNode SListFind(PNode pHead, DataType _data);

// ������posλ�ú������_data 
void SListInsert(PNode* pHead, PNode pos, DataType _data);

// ɾ������posλ���ϵĽ�� 
void SListErase(PNode* pHead, PNode pos);

// ���ٵ����� 
void SListDestroy(PNode* pHead);

// �������н��ĸ��� 
int SListSize(PNode pHead);

// �������еĽ����� 
void SListClear(PNode* pHead);

// ��ȡ��� 
PNode BuySListNode(DataType _data);

// ��ȡ�����е����һ����㣬���ظý��ĵ�ַ 
PNode SListBack(PNode pHead);

void showSList(PNode head);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
// ��������������⣬�����´���ҵ�н����ڵ�����ʵ�� 
// ɾ������ķ�β��㣬Ҫ���ܱ������� 
void DeleteNotTailNode(PNode pos);

// ������posλ��ǰ����ֵΪ_data�Ľ�� 
void InsertPosFront(PNode pos, DataType _data);

// Լɪ�� 
void JosephCircle(PNode* pHead, const int M);

// ʹ��ð�ݷ�ʽ�Ե������������ 
void BubbleSort(PNode pHead);

// �����������---����ָ�� 
void ReverseSList(PNode* pHead);

// �����������---ʹ��ͷ�巨 
PNode ReverseSListOP(PNode pHead);

// �ϲ��������������ϲ�������ȻҪ���� 
PNode MergeSList(PNode pHead1, PNode pHead2);

// ����������м��㣬Ҫ��ֻ�ܱ���һ������ 
PNode FindMiddleNode(PNode pHead);

// ��������ĵ�����K����� 
PNode FindLastKNode(PNode pHead, int K);

// �ж������������Ƿ��ཻ---�������� 
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);

// ����ཻ ��ȡ���� 
PNode GetCrossNode(PNode pHead1, PNode pHead2);


void testMerge() {

	PNode head = NULL;
	head = (PNode)malloc(sizeof(Node));
	//����Ԫ�ظ���
	head->_data = 1;
	head->_pNext = NULL;
	SListPushBack(head, 2);
	SListPushBack(head, 3);
	SListPushBack(head, 5);
	SListPushBack(head, 7);
	SListPushBack(head, 9);


	PNode head1 = NULL;
	head1 = (PNode)malloc(sizeof(Node));
	//����Ԫ�ظ���
	head1->_data = 0;
	head1->_pNext = NULL;
	SListPushBack(head1, 2);
	SListPushBack(head1, 4);
	SListPushBack(head1, 6);
	SListPushBack(head1, 8);
	SListPushBack(head1, 10);

	PNode merge = MergeSList(head1, head);
	showSList(merge);
}


int main()
{	
	PNode pHead;
	SListInit(&pHead);
	printf("β��\n");
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 5);
	showSList(pHead);

	printf("ͷ��\n");
	SListPushFront(&pHead, 3);
	showSList(pHead);

	printf("βɾ\n");
	SListPopBack(&pHead);
	showSList(pHead);

	printf("ͷɾ\n");
	SListPopFront(&pHead);
	showSList(pHead);

	// ����ֵΪ_data�Ľ�㣬���ظý���������е�λ�� 
	PNode searchNode = SListFind(pHead,  5);
	printf("�ҵ�ֵΪ5�Ľڵ�ڵ�����ΪsearchNode\n", searchNode->_data);


	// ������posλ�ú������_data 
	printf("��searchNode����ڵ��������� \n");
	SListInsert(&pHead, searchNode, 8);
	showSList(pHead);


	// ɾ������posλ���ϵĽ�� 
	printf("ɾ��searchNode����ڵ� \n");
	SListErase(&pHead, searchNode);
	showSList(pHead);

	

	// �������н��ĸ��� 
	int count = SListSize(pHead);
	printf("�����нڵ����Ϊ%d\n", count);

	
	// ��ȡ��� 
	//PNode BuySListNode(DataType _data);

	// ��ȡ�����е����һ����㣬���ظý��ĵ�ַ 
	PNode pTail = SListBack(pHead);
	printf("���һ���ڵ�Ϊ%d��ַΪ%p\n", pTail->_data, pTail);

	// �������еĽ����� 
	printf("����ڵ����");
	SListClear(&pHead);
	showSList(pHead);

	// ���ٵ�����
	/*
	
	

	printf("��������\n");
	SListDestroy(&pHead);*/


	//showSList(pHead);
	//testMerge();

	//PNode head = NULL;
	//head = (PNode)malloc(sizeof(Node));
	////����Ԫ�ظ���
	//head->_data = 1;
	//head->_pNext = NULL;
	//
	////β��
	//SListPushBack(head, 2);
	//SListPushBack(head, 3);
	//SListPushBack(head, 4);
	//SListPushBack(head, 5);
	//SListPushBack(head, 6);
	//SListClear(&head);
	////ͷ��
	////SListPushBack(head, 100);
	//showSList(head);

	//JosephCircle(&head, 3);
	//showSList(head);

	////�ҵ�������k���ڵ�
	//FindLastKNode(head, 3);

	////ɾ��������k���ڵ�
	//DeleteLastKNode(head, 3);

	////�ҵ��м�ڵ�
	//PNode middleNode = FindMiddleNode(head);

	////ɾ����β�ڵ��ָ���ڵ�
	//DeleteNotTailNode(head->_pNext->_pNext);
	//showSList(head);

	//

	//PNode p = (PNode)malloc(sizeof(Node));
	//p->_pNext = NULL;
	//p->_data = 1000;

	////��ָ���ڵ�֮ǰ����һ���ڵ�
	//InsertPosFront(head->_pNext->_pNext, p);
	//showSList(head);

	////int k = 2;
	////PNode node = searchDaoshuNode(head, k);
	////printf("������%d���ڵ�����Ϊ%d\n", k, node->_data);

	//BubbleSort(head);
	//showSList(head);

	//reverseShowSList(head);

	//ReverseSList(&head);

	return 0;
}

//β�巨����Ԫ��
//void SListPushBack(PNode head, int num) {
//	assert(head);
//
//	PNode pPreCur = NULL;
//
//	PNode addNode = (PNode)malloc(sizeof(Node));
//	addNode->_data = num;
//
//	if (head->_pNext == NULL) {
//		head->_pNext = addNode;
//		addNode->_pNext = NULL;
//	}
//
//	else {
//		PNode pCur = head->_pNext;
//		while (pCur != NULL) {
//			pPreCur = pCur;
//			pCur = pCur->_pNext;
//		}
//		pPreCur->_pNext = addNode;
//		addNode->_pNext = NULL;
//	}
//}


//��ʼ��
void SListInit(PNode* pHead){
	*pHead = (PNode)malloc(sizeof(Node));
	(*pHead)->_data = 0;
	(*pHead)->_pNext = NULL;

}

// β�� 
void SListPushBack(PNode* pHead, DataType _data){
	assert(*pHead);
	
	PNode insertNode = BuySListNode(_data);

	PNode pTail = *pHead;
	while (pTail->_pNext) {
		pTail = pTail->_pNext;
	}
	pTail->_pNext = insertNode;
}

// βɾ 
void SListPopBack(PNode* pHead){
	assert(*pHead);
	PNode pTail = *pHead;
	PNode pPreTail = *pHead;
	while (pTail->_pNext) {
		pPreTail = pTail;
		pTail = pTail->_pNext;
	}
	pPreTail->_pNext = NULL;
	free(pTail);
	pTail = NULL;
}

// ͷ�� 
void SListPushFront(PNode* pHead, DataType _data){
	assert(*pHead);

	PNode insertNode = BuySListNode(_data);

	PNode head = *pHead;
	insertNode->_pNext = head->_pNext;
	head->_pNext = insertNode;
}

// ͷɾ 
void SListPopFront(PNode* pHead){
	assert(*pHead);
	PNode pCur = *pHead;
	PNode pNext = NULL;
	pNext = pCur->_pNext;
	pCur->_pNext = pCur->_pNext->_pNext;
	free(pNext);
	if (pCur->_pNext->_pNext == NULL) {
		free(pCur->_pNext);
	}
}

// ����ֵΪ_data�Ľ�㣬���ظý���������е�λ�� 
PNode SListFind(PNode pHead, DataType _data){
	assert(pHead);
	PNode pCur = pHead;
	while (pCur) {
		if (pCur->_data == _data) {
			return pCur;
		}
		pCur = pCur->_pNext;
	}

}

// ������posλ�ú������_data 
void SListInsert(PNode* pHead, PNode pos, DataType _data){
	assert(*pHead);
	PNode pCur = *pHead;
	PNode newNode = BuySListNode(_data);
	while (pCur->_pNext) {
		if (pCur == pos)
		{
			newNode->_pNext = pCur->_pNext;
			pCur->_pNext = newNode;
			break;
		}
		pCur = pCur->_pNext;
	}

	pCur->_pNext = newNode;
}

// ɾ������posλ���ϵĽ�� 
void SListErase(PNode* pHead, PNode pos){
	assert(*pHead);
	PNode pCur = *pHead;
	PNode pPreCur = NULL;
	while (pCur) {

		if (pCur == pos) {
			pPreCur->_pNext = pCur->_pNext;
			free(pos);
			break;
		}
		pPreCur = pCur;
		pCur = pCur->_pNext;

	}

}

// ���ٵ����� 
void SListDestroy(PNode* pHead){
	assert(*pHead);
	PNode pPreCur = *pHead;
	while (*pHead) {
		pPreCur = *pHead;
		(*pHead) = (*pHead)->_pNext;
		free(pPreCur);
	}
	free(*pHead);
	pHead = NULL;
}

// �������н��ĸ��� 
int SListSize(PNode pHead){
	assert(pHead);
	PNode pCur = pHead;
	int count = 0;
	while (pCur) {
		++count;
		pCur = pCur->_pNext;
	}
	return count;

}


//�޸�ͷָ����봫ͷָ��ĵ�ַ��
// �������еĽ����� 
void SListClear(PNode* pHead){
	assert(*pHead);
	PNode preNode = *pHead;
	while (*pHead) {
		preNode = *pHead;
		(*pHead) = (*pHead)->_pNext;
		free(preNode);
		preNode = NULL;
	}
}

// ��ȡ��� 
PNode BuySListNode(DataType _data){
	PNode node = (PNode)malloc(sizeof(Node));
	node->_pNext = NULL;
	node->_data = _data;
	return node;
}

// ��ȡ�����е����һ����㣬���ظý��ĵ�ַ 
PNode SListBack(PNode pHead) {
	assert(pHead);
	PNode pTail = pHead;
	while (pTail->_pNext) {
		pTail = pTail->_pNext;
	}
	return pTail;
}

////ͷ�巨����Ԫ��
//void SListPushFront(PNode head, int num) {
//	assert(head);
//	PNode addNode = (PNode)malloc(sizeof(Node));
//	addNode->_data = num;
//	addNode->_pNext = NULL;
//	if (head->_pNext == NULL) {
//		head->_pNext = addNode;
//	}
//	else {
//		addNode->_pNext = head->_pNext;
//		head->_pNext = addNode;
//	}
//}

//ɾ��һ����ͷ������ķ�β�ڵ�(�滻��)
void DeleteNotTailNode(PNode deleteNode) {
	assert(deleteNode);
	deleteNode->_data = deleteNode->_pNext->_data;
	PNode p = deleteNode->_pNext;
	deleteNode->_pNext = deleteNode->_pNext->_pNext;
	free(p);
}

//��һ����֪��ڵ�ǰ����һ���ڵ�
void InsertPosFront(PNode descNode, DataType _data) {
	assert(descNode);
	PNode insertNode = malloc(sizeof(Node));
	insertNode->_pNext = NULL;
	insertNode->_data = _data;
	insertNode->_pNext = descNode->_pNext->_pNext;
	descNode->_pNext = insertNode;
	int temp = descNode->_data;
	descNode->_data = insertNode->_data;
	insertNode->_data = temp;
}

//������ӡ������
void showSList(PNode head) {
	PNode pCur = head;
	while (pCur) {
		printf("%d ", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("\n");
}


//�����ӡ������
void reverseShowSList(PNode head) {
	PNode pCur = head;
	if (pCur != NULL) {
		reverseShowSList(pCur->_pNext);
		printf("%d ", pCur->_data);
	}
}


//ð������
void BubbleSort(PNode head) {
	assert(head);
	PNode pOut = head;
	PNode pIn = head;
	PNode pTail = NULL;
	while (pOut != pTail) {
		pIn = pOut;
		while (1) {
			if (pIn->_pNext == pTail) {
				break;
			}
			if (pIn->_data > pIn->_pNext->_data) {
				int temp = pIn->_data;
				pIn->_data = pIn->_pNext->_data;
				pIn->_pNext->_data = temp;
			}
			pIn = pIn->_pNext;
		}
		pTail = pIn;
	}
}

//�ҵ��м�ڵ�
PNode FindMiddleNode(PNode head) {
	assert(head);
	PNode pCurFast = head;
	PNode pCurSlow = head;
	PNode pPreCurSlow = NULL;
	while (pCurFast) {

		pCurFast = pCurFast->_pNext;
		if (pCurFast == NULL) {
			printf("�м�ڵ�Ϊ%d\n", pCurSlow->_data);
			return pCurSlow;
		}

		pCurFast = pCurFast->_pNext;
		//���ܻ���Ҫ��һ������ֵ
		pPreCurSlow = pCurSlow;
		pCurSlow = pCurSlow->_pNext;
		if (pCurFast == NULL) {
			printf("�м�ڵ�Ϊ%d\n", pCurSlow->_data);
			return pCurSlow;
		}
	}
}

//�ҵ�������k���ڵ�,һ��ָ������k��
PNode FindLastKNode(PNode head, int k) {
	assert(head);
	PNode pCurFast = head;
	PNode pCurSlow = head;
	int count = k;
	while (count--) {
		pCurFast = pCurFast->_pNext;
		if (pCurFast == NULL)
			return NULL;
	}
	while (pCurFast) {
		pCurFast = pCurFast->_pNext;
		pCurSlow = pCurSlow->_pNext;
	}
	printf("������%d��Ԫ��Ϊ%d\n", k, pCurSlow->_data);
	return pCurSlow;
}

void DeleteLastKNode(PNode head, int k) {
	assert(head);
	PNode pCurFast = head;
	PNode pCurSlow = head;
	PNode pPreCurSlow = NULL;
	int count = k;
	while (count--) {
		pCurFast = pCurFast->_pNext;
		if (pCurFast == NULL)
			return NULL;
	}
	while (pCurFast) {
		pCurFast = pCurFast->_pNext;
		pPreCurSlow = pCurSlow;
		pCurSlow = pCurSlow->_pNext;
	}
	PNode temp = pPreCurSlow->_pNext;
	pPreCurSlow->_pNext = pPreCurSlow->_pNext->_pNext;
	free(temp);
}

//��β��ͷ��ӡ���ݹ�
//ɾ����ͷ������ķ�Ϊ�ڵ㣺�滻��(ֻ��ɾ����β�ڵ�)��
//����ͷ�������һ���ڵ�Ǯ����һ���ڵ㣺�Ȳ嵽�����ٽ���
//�ҵ�����k���ڵ㣺����1,����k��
//���м�Ľڵ㣺����ָ�룬��һ��һ��������
//�ж����������Ƿ��ཻ����һ����������һ���ڵ�ָ��ڶ�����������Ľڵ㣬��Ҫ��������֪������


//�ݹ鷨�ҵ����ڼ����ڵ�
PNode searchDaoshuNode(PNode head) {
	PNode pCur = head;
	int k = 5;
	int all = -5;
	if (pCur != NULL) {
		all++;
		searchDaoshuNode(pCur->_pNext);
		return pCur;
	}
}

//����Լɪ��
void setJosephCirecle(PNode head) {
	assert(head);
	PNode pTail = head;
	while (1) {
		pTail = pTail->_pNext;
		if (pTail->_pNext == NULL)
		{
			pTail->_pNext = head;
			return;
		}
	}
}
/**������ʵ��Լɪ��
num��ʾ�����ĵڼ����ڵ㱻ɾ��
*/
void JosephCircle(PNode* head, int num) {
	assert(head);

	PNode *pPre = head;
	PNode *pTemp = NULL;
	//����Լɪ��
	setJosephCirecle(head);

	while (1) {
		int count = num;
		while (--count) {
			*pPre = *head;
			*head = (*head)->_pNext;
		}
		*pTemp = (*pPre)->_pNext;
		*head = (*pPre)->_pNext->_pNext;
		(*pPre)->_pNext = (*pPre)->_pNext->_pNext;
		printf("ɾ���ڵ�%d\n", (*pTemp)->_data);
		free(*pTemp);
		if ((*head)->_pNext == *head)
			break;
	}
	(*head)->_pNext = NULL;
}

//���õ�����
void ReverseSList(PNode* head) {
	assert(head);
	PNode preNode = NULL;
	PNode pCur = head;
	PNode p__pNextNode = NULL;

	while (pCur != NULL) {
		p__pNextNode = pCur->_pNext;
		pCur->_pNext = preNode;
		preNode = pCur;
		pCur = p__pNextNode;
	}
}

//�ϲ�������������
PNode MergeSList(PNode head1, PNode head2) {
	assert(head1);
	assert(head2);

	PNode phead = NULL;
	PNode pPreHead1 = head1;
	PNode pPreHead2 = head2;

	int gap = 0;

	//�ж��Ƿ�������Ϊ��
	if (head1->_pNext == NULL || head2->_pNext == NULL) {
		return head1->_pNext == NULL ? head2 : head1;
	}

	phead = head1->_data < head2->_data ? head1 : head2;

	if (phead == head1) {
		head1 = head1->_pNext;
	}
	else {
		head2 = head2->_pNext;
	}

	PNode head = phead;



	while (1) {


		if (head1->_data < head2->_data) {

			pPreHead2 = head2;
			//1�е�Ԫ��С��2�еģ���ָ��1��
			head1 = pPreHead1;
			phead->_pNext = head1;
			//�ж���һ��Ԫ���Ƿ�С��2�е�,�������С�ڣ��ҾͰ�head1����ƶ�
			head1 = head1->_pNext;
		}


		if (head1->_data >= head2->_data) {

			pPreHead1 = head1;
			head2 = pPreHead2;
			phead->_pNext = head2;

			head2 = head2->_pNext;


		}


		if (head1 == NULL) {
			gap = 1;
			break;
		}


		if (head2 = NULL) {
			gap = 2;
			break;
		}

		phead = phead->_pNext;

	}
	phead = gap == 1 ? head2 : head1;
	return phead;
}
