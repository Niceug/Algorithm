#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node, *PNode;


//////////////////不带头结点的单链表////////////////////////////////////// 
// .h 
// 链表初始化 
void SListInit(PNode* pHead);

// 尾插 
void SListPushBack(PNode* pHead, DataType _data);

// 尾删 
void SListPopBack(PNode* pHead);

// 头插 
void SListPushFront(PNode* pHead, DataType _data);

// 头删 
void SListPopFront(PNode* pHead);

// 查找值为_data的结点，返回该结点在链表中的位置 
PNode SListFind(PNode pHead, DataType _data);

// 在链表pos位置后插入结点_data 
void SListInsert(PNode* pHead, PNode pos, DataType _data);

// 删除链表pos位置上的结点 
void SListErase(PNode* pHead, PNode pos);

// 销毁单链表 
void SListDestroy(PNode* pHead);

// 求链表中结点的个数 
int SListSize(PNode pHead);

// 将链表中的结点清空 
void SListClear(PNode* pHead);

// 获取结点 
PNode BuySListNode(DataType _data);

// 获取链表中的最后一个结点，返回该结点的地址 
PNode SListBack(PNode pHead);

void showSList(PNode head);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
// 以下链表的面试题，放在下次作业中交，在底下先实现 
// 删除链表的非尾结点，要求不能遍历链表 
void DeleteNotTailNode(PNode pos);

// 在链表pos位置前插入值为_data的结点 
void InsertPosFront(PNode pos, DataType _data);

// 约瑟夫环 
void JosephCircle(PNode* pHead, const int M);

// 使用冒泡方式对单链表进行排序 
void BubbleSort(PNode pHead);

// 单链表的逆序---三个指针 
void ReverseSList(PNode* pHead);

// 单链表的逆序---使用头插法 
PNode ReverseSListOP(PNode pHead);

// 合并两个有序链表，合并起来依然要有序 
PNode MergeSList(PNode pHead1, PNode pHead2);

// 查找链表的中间结点，要求只能遍历一次链表 
PNode FindMiddleNode(PNode pHead);

// 查找链表的倒数第K个结点 
PNode FindLastKNode(PNode pHead, int K);

// 判断两个单链表是否相交---链表不带环 
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);

// 如果相交 获取交点 
PNode GetCrossNode(PNode pHead1, PNode pHead2);


void testMerge() {

	PNode head = NULL;
	head = (PNode)malloc(sizeof(Node));
	//插入元素个数
	head->_data = 1;
	head->_pNext = NULL;
	SListPushBack(head, 2);
	SListPushBack(head, 3);
	SListPushBack(head, 5);
	SListPushBack(head, 7);
	SListPushBack(head, 9);


	PNode head1 = NULL;
	head1 = (PNode)malloc(sizeof(Node));
	//插入元素个数
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
	printf("尾插\n");
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 5);
	showSList(pHead);

	printf("头插\n");
	SListPushFront(&pHead, 3);
	showSList(pHead);

	printf("尾删\n");
	SListPopBack(&pHead);
	showSList(pHead);

	printf("头删\n");
	SListPopFront(&pHead);
	showSList(pHead);

	// 查找值为_data的结点，返回该结点在链表中的位置 
	PNode searchNode = SListFind(pHead,  5);
	printf("找到值为5的节点节点名称为searchNode\n", searchNode->_data);


	// 在链表pos位置后插入结点_data 
	printf("在searchNode这个节点后面插入结点 \n");
	SListInsert(&pHead, searchNode, 8);
	showSList(pHead);


	// 删除链表pos位置上的结点 
	printf("删除searchNode这个节点 \n");
	SListErase(&pHead, searchNode);
	showSList(pHead);

	

	// 求链表中结点的个数 
	int count = SListSize(pHead);
	printf("链表中节点个数为%d\n", count);

	
	// 获取结点 
	//PNode BuySListNode(DataType _data);

	// 获取链表中的最后一个结点，返回该结点的地址 
	PNode pTail = SListBack(pHead);
	printf("最后一个节点为%d地址为%p\n", pTail->_data, pTail);

	// 将链表中的结点清空 
	printf("链表节点清空");
	SListClear(&pHead);
	showSList(pHead);

	// 销毁单链表
	/*
	
	

	printf("销毁链表\n");
	SListDestroy(&pHead);*/


	//showSList(pHead);
	//testMerge();

	//PNode head = NULL;
	//head = (PNode)malloc(sizeof(Node));
	////插入元素个数
	//head->_data = 1;
	//head->_pNext = NULL;
	//
	////尾插
	//SListPushBack(head, 2);
	//SListPushBack(head, 3);
	//SListPushBack(head, 4);
	//SListPushBack(head, 5);
	//SListPushBack(head, 6);
	//SListClear(&head);
	////头插
	////SListPushBack(head, 100);
	//showSList(head);

	//JosephCircle(&head, 3);
	//showSList(head);

	////找到倒数第k个节点
	//FindLastKNode(head, 3);

	////删除倒数第k个节点
	//DeleteLastKNode(head, 3);

	////找到中间节点
	//PNode middleNode = FindMiddleNode(head);

	////删除非尾节点的指定节点
	//DeleteNotTailNode(head->_pNext->_pNext);
	//showSList(head);

	//

	//PNode p = (PNode)malloc(sizeof(Node));
	//p->_pNext = NULL;
	//p->_data = 1000;

	////在指定节点之前插入一个节点
	//InsertPosFront(head->_pNext->_pNext, p);
	//showSList(head);

	////int k = 2;
	////PNode node = searchDaoshuNode(head, k);
	////printf("倒数第%d个节点数据为%d\n", k, node->_data);

	//BubbleSort(head);
	//showSList(head);

	//reverseShowSList(head);

	//ReverseSList(&head);

	return 0;
}

//尾插法插入元素
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


//初始化
void SListInit(PNode* pHead){
	*pHead = (PNode)malloc(sizeof(Node));
	(*pHead)->_data = 0;
	(*pHead)->_pNext = NULL;

}

// 尾插 
void SListPushBack(PNode* pHead, DataType _data){
	assert(*pHead);
	
	PNode insertNode = BuySListNode(_data);

	PNode pTail = *pHead;
	while (pTail->_pNext) {
		pTail = pTail->_pNext;
	}
	pTail->_pNext = insertNode;
}

// 尾删 
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

// 头插 
void SListPushFront(PNode* pHead, DataType _data){
	assert(*pHead);

	PNode insertNode = BuySListNode(_data);

	PNode head = *pHead;
	insertNode->_pNext = head->_pNext;
	head->_pNext = insertNode;
}

// 头删 
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

// 查找值为_data的结点，返回该结点在链表中的位置 
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

// 在链表pos位置后插入结点_data 
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

// 删除链表pos位置上的结点 
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

// 销毁单链表 
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

// 求链表中结点的个数 
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


//修改头指针必须传头指针的地址。
// 将链表中的结点清空 
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

// 获取结点 
PNode BuySListNode(DataType _data){
	PNode node = (PNode)malloc(sizeof(Node));
	node->_pNext = NULL;
	node->_data = _data;
	return node;
}

// 获取链表中的最后一个结点，返回该结点的地址 
PNode SListBack(PNode pHead) {
	assert(pHead);
	PNode pTail = pHead;
	while (pTail->_pNext) {
		pTail = pTail->_pNext;
	}
	return pTail;
}

////头插法插入元素
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

//删除一个无头单链表的非尾节点(替换法)
void DeleteNotTailNode(PNode deleteNode) {
	assert(deleteNode);
	deleteNode->_data = deleteNode->_pNext->_data;
	PNode p = deleteNode->_pNext;
	deleteNode->_pNext = deleteNode->_pNext->_pNext;
	free(p);
}

//在一个已知表节点前插入一个节点
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

//正常打印单链表
void showSList(PNode head) {
	PNode pCur = head;
	while (pCur) {
		printf("%d ", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("\n");
}


//逆序打印单链表
void reverseShowSList(PNode head) {
	PNode pCur = head;
	if (pCur != NULL) {
		reverseShowSList(pCur->_pNext);
		printf("%d ", pCur->_data);
	}
}


//冒泡排序
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

//找到中间节点
PNode FindMiddleNode(PNode head) {
	assert(head);
	PNode pCurFast = head;
	PNode pCurSlow = head;
	PNode pPreCurSlow = NULL;
	while (pCurFast) {

		pCurFast = pCurFast->_pNext;
		if (pCurFast == NULL) {
			printf("中间节点为%d\n", pCurSlow->_data);
			return pCurSlow;
		}

		pCurFast = pCurFast->_pNext;
		//可能会需要另一个返回值
		pPreCurSlow = pCurSlow;
		pCurSlow = pCurSlow->_pNext;
		if (pCurFast == NULL) {
			printf("中间节点为%d\n", pCurSlow->_data);
			return pCurSlow;
		}
	}
}

//找到倒数第k个节点,一个指针先走k步
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
	printf("倒数第%d个元素为%d\n", k, pCurSlow->_data);
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

//从尾到头打印：递归
//删除无头单链表的非为节点：替换法(只能删除非尾节点)。
//在无头单链表的一个节点钱插入一个节点：先插到后面再交换
//找倒数第k个节点：方法1,先走k步
//找中间的节点：两个指针，有一个一次走两步
//判断两个链表是否相交，第一个链表的最后一个节点指向第二个链表任意的节点，先要两个链表知道长度


//递归法找倒数第几个节点
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

//构建约瑟夫环
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
/**单链表实现约瑟夫环
num表示数到的第几个节点被删除
*/
void JosephCircle(PNode* head, int num) {
	assert(head);

	PNode *pPre = head;
	PNode *pTemp = NULL;
	//构建约瑟夫环
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
		printf("删除节点%d\n", (*pTemp)->_data);
		free(*pTemp);
		if ((*head)->_pNext == *head)
			break;
	}
	(*head)->_pNext = NULL;
}

//逆置单链表
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

//合并两个有序链表
PNode MergeSList(PNode head1, PNode head2) {
	assert(head1);
	assert(head2);

	PNode phead = NULL;
	PNode pPreHead1 = head1;
	PNode pPreHead2 = head2;

	int gap = 0;

	//判断是否有链表为空
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
			//1中的元素小于2中的，就指向1。
			head1 = pPreHead1;
			phead->_pNext = head1;
			//判断下一个元素是否小于2中的,如果还是小于，我就把head1向后移动
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
