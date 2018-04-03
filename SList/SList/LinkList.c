#if 1==1
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

//获取第几个节点
PNode getAnyNode(PNode pHead, int num);

// 获取结点 
PNode BuySListNode(DataType _data);

// 获取链表中的最后一个结点，返回该结点的地址 
PNode SListBack(PNode pHead);

void showSList(PNode head);

//逆序打印单链表
void reverseShowSList(PNode head);

//删除指定节点
void DeleteNotTailNode(PNode pos);

// 在链表pos位置前插入值为_data的结点 
void InsertPosFront(PNode pos, DataType _data);

void setJosephCirecle(PNode* head);
// 约瑟夫环 
void JosephCircle(PNode* pHead, const int M);

// 使用冒泡方式对单链表进行排序 
void BubbleSort(PNode pHead);

// 单链表的逆序---三个指针 
void ReverseSList(PNode* pHead);

// 单链表的逆序---使用头插法 
PNode ReverseSListOP(PNode* pHead);

// 合并两个有序链表，合并起来依然要有序 
PNode MergeSList(PNode pHead1, PNode pHead2);

// 查找链表的中间结点，要求只能遍历一次链表 
PNode FindMiddleNode(PNode pHead);

// 查找链表的倒数第K个结点 
PNode FindLastKNode(PNode pHead, int K);
// 删除链表的倒数第K个节点
void DeleteLastKNode(PNode head, int k);

// 获取相交链表的交点
PNode GetCrossNode(PNode pHead1, PNode pHead2);

//判断链表是否带环
PNode hasCircle(PNode pHead);

//魔术扑克牌
void setMagicCard(PNode* pHead);

//拉丁矩阵
int** LatinArray(PNode* pHead, unsigned int n);
//测试合并两个有序链表

void UnionSet(PNode pHead1, PNode pHead2);

PNode isCrossHasCircle(PNode pHead1, PNode pHead2);

void testMerge() {

	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 9);
	showSList(pHead);
	PNode pHead1;
	SListInit(&pHead1);
	SListPushBack(&pHead1, 2);
	SListPushBack(&pHead1, 4);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 8);
	SListPushBack(&pHead1, 10);
	SListPushBack(&pHead1, 15);
	showSList(pHead1);

	PNode head = MergeSList(pHead, pHead1);
	showSList(head);
}

//测试约瑟夫环
void testJosephCircle() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	showSList(pHead);
	JosephCircle(&pHead, 3);
	showSList(pHead);
	
}

//测试逆序打印单链表
void testReverseShowList() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	reverseShowSList(pHead);
}

//测试任意位置的删除
void testDeleteNotTailNode() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	showSList(pHead);
	PNode node = getAnyNode(pHead, 3);
	DeleteNotTailNode(node);
	showSList(pHead);
}

//测试在任意位置前面插入
void testInsertPosFront() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	showSList(pHead);
	PNode node = getAnyNode(pHead, 3);
	InsertPosFront(node, 10);
	showSList(pHead);
}

//测试逆置单链表
void testReverseSList() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	showSList(pHead);
	ReverseSList(&pHead);
	showSList(pHead);
}

//测试冒泡排序
void testBubbleSort() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 9);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 6);
	showSList(pHead);
	BubbleSort(pHead);
	showSList(pHead);
}

//测试找到中间节点
void testFindMiddleNode() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	showSList(pHead);
	PNode pMiddleNode = FindMiddleNode(pHead);
	printf("中间节点为：%d\n", pMiddleNode->_data);
}

//测试找到倒数第几个节点
void testFindLastKNode() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	showSList(pHead);
	int k = 3;
	PNode pLastKNode = FindLastKNode(pHead, k);
	printf("倒数第%d个节点为%d\n", k, pLastKNode->_data);
}

//测试删除倒数第几个节点
void testDeleteLastKNode() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	showSList(pHead);
	int k = 3;
	DeleteLastKNode(pHead, k);
	showSList(pHead);
}

//测试头插法逆置操作
void testReverseSListOP() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	showSList(pHead);
	//ReverseSListOP(&pHead);
	showSList(pHead);
}

//测试链表是否相交
void testGetCrossNode() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 9);
	showSList(pHead);

	PNode pHead1;
	SListInit(&pHead1);
	SListPushBack(&pHead1, 2);
	SListPushBack(&pHead1, 4);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 8);
	SListPushBack(&pHead1, 10);
	SListPushBack(&pHead1, 15);
	showSList(pHead1);
	
	PNode pLastNode = SListBack(pHead);
	pLastNode->_pNext = getAnyNode(pHead1, 3);
	showSList(pHead);

	PNode crossNode = GetCrossNode(pHead, pHead1);
	printf("相交节点为%d\n", crossNode->_data);
}

void testHasCircle() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	PNode pTail = SListBack(pHead);
	pTail->_pNext = getAnyNode(pHead, 5);
	//showSList(pHead);
	PNode entrenceNode = hasCircle(pHead);
	printf("入口点为%d\n", entrenceNode->_data);
}

//测试魔术扑克牌
void testSetMagicCard() {
	PNode pHead;
	SListInit(&pHead);
	setMagicCard(&pHead);
}

//测试拉丁矩阵
void testLatinArray() {
	PNode pHead;
	SListInit(&pHead);
	int n = 5;
	int**arr = LatinArray(&pHead, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}


void testUnionSet() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 8);
	showSList(pHead);

	PNode pHead1;
	SListInit(&pHead1);
	SListPushBack(&pHead1, 2);
	SListPushBack(&pHead1, 4);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 8);
	SListPushBack(&pHead1, 10);
	SListPushBack(&pHead1, 15);
	showSList(pHead1);
	UnionSet(pHead1, pHead);
}


//带环相交
testIsCrossHasCircle() {
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 11);
	SListPushBack(&pHead, 12);
	SListPushBack(&pHead, 13);
	SListPushBack(&pHead, 14);
	showSList(pHead);

	PNode pHead1;
	SListInit(&pHead1);
	SListPushBack(&pHead1, 21);
	SListPushBack(&pHead1, 22);
	SListPushBack(&pHead1, 23);
	SListPushBack(&pHead1, 24);
	SListPushBack(&pHead1, 25);
	SListPushBack(&pHead1, 26);
	showSList(pHead1);


	//测试不带环相交
	/*SListBack(pHead)->_pNext = getAnyNode(pHead1, 5);
	PNode crossNode = isCrossHasCircle(pHead, pHead1);
	printf("交点为%d\n", crossNode->_data);*/

	////测试无环不相交
	//PNode crossNode = isCrossHasCircle(pHead, pHead1);
	//if (crossNode != NULL) {
	//	printf("交点为%d\n", crossNode->_data);
	//}
	//else {
	//	printf("无交点\n");
	//}

		
	
	////测试环外相交
	////14->23
	//SListBack(pHead)->_pNext = getAnyNode(pHead1, 3);
	////26->24
	//SListBack(pHead1)->_pNext = getAnyNode(pHead1, 4);
	//PNode crossNode = isCrossHasCircle(pHead, pHead1);
	//printf("交点为%d\n", crossNode->_data);


	//测试环内相交，交点为任意一个入口点
	//26->22
	SListBack(pHead1)->_pNext = getAnyNode(pHead1, 2);
	//14->23
	SListBack(pHead)->_pNext = getAnyNode(pHead1, 3);
	PNode crossNode = isCrossHasCircle(pHead, pHead1);
	printf("交点为%d\n", crossNode->_data);

	

}

int main()
{
	//合并有序链表
	//testMerge();
	//约瑟夫环
	//testJosephCircle();
	//逆序显示单链表
	//testReverseShowList();
	//删除无头链表非尾节点
	//testDeleteNotTailNode();
	//在无头单链表的一个节点前插入一个节点
	//testInsertPosFront();
	//逆置单链表方法1
	//testReverseSList();
	//冒泡排序
	//testBubbleSort();
	//找到中间节点
	//testFindMiddleNode();
	//找到倒数第k个节点
	//testFindLastKNode();
	//删除倒数第k个节点
	//testDeleteLastKNode();
	//获取交点
	//testGetCrossNode();
	//是否带环
	//testHasCircle();
	//魔术扑克牌
	//testSetMagicCard();
	//拉丁矩阵
	//testLatinArray();
	//testUnionSet();
	testIsCrossHasCircle();
	return 0;
}

//初始化
void SListInit(PNode* pHead) {
	*pHead = (PNode)malloc(sizeof(Node));
	(*pHead)->_data = 0;
	(*pHead)->_pNext = NULL;

}

// 尾插 
void SListPushBack(PNode* pHead, DataType _data) {
	assert(*pHead);

	PNode insertNode = BuySListNode(_data);

	PNode pTail = *pHead;
	while (pTail->_pNext) {
		pTail = pTail->_pNext;
	}
	pTail->_pNext = insertNode;
}

// 尾删 
void SListPopBack(PNode* pHead) {
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
void SListPushFront(PNode* pHead, DataType _data) {
	assert(*pHead);

	PNode insertNode = BuySListNode(_data);

	PNode head = *pHead;
	insertNode->_pNext = head->_pNext;
	head->_pNext = insertNode;
}

// 头删 
void SListPopFront(PNode* pHead) {
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

//获取指定位置的节点
PNode getAnyNode(PNode pHead, int num) {
	assert(pHead);
	PNode pCur = pHead;
	while (num--) {
		pCur = pCur->_pNext;
	}
	return pCur;
}

// 查找值为_data的结点，返回该结点在链表中的位置 
PNode SListFind(PNode pHead, DataType _data) {
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
void SListInsert(PNode* pHead, PNode pos, DataType _data) {
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
void SListErase(PNode* pHead, PNode pos) {
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
void SListDestroy(PNode* pHead) {
	PNode pPreCur = *pHead;
	if (*pHead == NULL)
		return;
	while (*pHead) {
		pPreCur = *pHead;
		(*pHead) = (*pHead)->_pNext;
		free(pPreCur);
	}
	free(*pHead);
	*pHead = NULL;
	
}

// 求链表中结点的个数 
int SListSize(PNode pHead) {
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
void SListClear(PNode* pHead) {
	assert(*pHead);
	PNode preNode = *pHead;
	while ((*pHead)) {
		preNode = *pHead;
		(*pHead) = (*pHead)->_pNext;
		free(preNode);
		preNode = NULL;
	}
}

// 获取结点 
PNode BuySListNode(DataType _data) {
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
	PNode insertNode = BuySListNode(_data);

	insertNode->_pNext = descNode->_pNext;
	descNode->_pNext = insertNode;

	int temp = descNode->_data;
	descNode->_data = insertNode->_data;
	insertNode->_data = temp;
}

//正常打印单链表
void showSList(PNode head) {
	PNode pCur = head->_pNext;
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
	//如果已经排好序，就不用排了
	int state = 0;
	while (pOut != pTail) {
		pIn = pOut;
		state = 0;
		while (1) {
			if (pIn->_pNext == pTail) {
				break;
			}
			if (pIn->_data > pIn->_pNext->_data) {
				int temp = pIn->_data;
				pIn->_data = pIn->_pNext->_data;
				pIn->_pNext->_data = temp;
				state = 1;
			}
			pIn = pIn->_pNext;
		}
		pTail = pIn;
		if (state == 0)
			break;
	}
}

//找到中间节点
PNode FindMiddleNode(PNode head) {
	assert(head);
	PNode pCurFast = head;
	PNode pCurSlow = head;
	PNode pPreCurSlow = NULL;
	while (pCurFast) {

		pCurFast = pCurFast->_pNext->_pNext;;
		if (pCurFast == NULL) {
			return pCurSlow;
		}
		//可能会需要另一个返回值
		pPreCurSlow = pCurSlow;
		pCurSlow = pCurSlow->_pNext;
		if (pCurFast == NULL) {
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
	return pCurSlow;
}


//删除倒数第几个节点
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


////递归法找倒数第几个节点
//PNode searchDaoshuNode(PNode head) {
//	PNode pCur = head;
//	int k = 5;
//	int all = -5;
//	if (pCur != NULL) {
//		all++;
//		searchDaoshuNode(pCur->_pNext);
//		return pCur;
//	}
//}

//构建约瑟夫环
void setJosephCirecle(PNode* head) {
	assert(*head);
	PNode pTail = *head;
	while (1) {
		pTail = pTail->_pNext;
		if (pTail->_pNext == NULL)
		{
			pTail->_pNext = *head;
			return;
		}
	}
}

/**单链表实现约瑟夫环
num表示数到的第几个节点被删除
*/
void JosephCircle(PNode* head, int num) {
	assert(*head);

	PNode pPre = *head;
	PNode pTemp = NULL;
	//构建约瑟夫环
	setJosephCirecle(head);

	while (1) {
		int count = num;
		while (--count) {
			pPre = *head;
			*head = (*head)->_pNext;
		}
		pTemp = (pPre)->_pNext;
		*head = (pPre)->_pNext->_pNext;
		(pPre)->_pNext = (pPre)->_pNext->_pNext;
		printf("删除节点%d\n", (pTemp)->_data);
		free(pTemp);
		if ((*head)->_pNext == *head)
			break;
	}
	(*head)->_pNext = NULL;
}

//逆置单链表
void ReverseSList(PNode* head) {
	assert(*head);
	PNode preNode = NULL;
	PNode pCur = *head;
	PNode pNextNode = NULL;

	while (pCur != NULL) {
		pNextNode = pCur->_pNext;
		pCur->_pNext = preNode;
		preNode = pCur;
		pCur = pNextNode;
	}
	(*head) = preNode;
}

////头插法
//PNode ReverseSListOP(PNode *pHead) {
//
//	assert(*pHead);
//	PNode pCur = (*pHead)->_pNext->_pNext;
//	PNode pInsertNode = NULL;
//
//	while (pCur) {
//		pInsertNode = pCur;
//		(*pHead)->_pNext = pInsertNode;
//		pInsertNode->_pNext = ((*pHead)->_pNext);
//		pCur = pCur->_pNext;
//	}
//}

//合并两个有序链表
PNode MergeSList(PNode head1, PNode head2) {
	assert(head1);
	assert(head2);

	PNode phead = NULL;

	int gap = 0;

	//判断是否有链表为空
	if (head1->_pNext == NULL) {
		return head2;
	}
	if (head2->_pNext == NULL) {
		return head1;
	}
	phead = head1->_data < head2->_data ? head1 : head2;
	if (phead == head1)
	{
		head1 = head1->_pNext;
	}
	if (phead == head2)
	{
		head2 = head2->_pNext;
	}
	PNode pPreNode = NULL;
	PNode newHead = phead;
	while (1) {
		if (head1->_data < head2->_data) {
			phead->_pNext = head1;
			head1 = head1->_pNext;
		}
		else
		{
			phead->_pNext = head2;
			head2 = head2->_pNext;
		}

		if (head1 == NULL) {
			phead->_pNext->_pNext = head2;
			break;
		}


		if (head2 == NULL) {
			phead->_pNext->_pNext = head1;
			break;
		}

		phead = phead->_pNext;

	}
	return newHead;
}

// 判断两个链表是否相交，链表不带环，若相交获取交点
PNode GetCrossNode(PNode pHead1, PNode pHead2) {
	assert(pHead1);
	assert(pHead2);
	
	PNode pCur1 = pHead1;
	PNode pCur2 = pHead2;

	int len1 = SListSize(pHead1);
	int len2 = SListSize(pHead2);
	int step = len1 - len2;

	if (step > 0) {
		while (step--) {
			pCur1 = pCur1->_pNext;
		}
		while (pCur1) {
			pCur1 = pCur1->_pNext;
			pCur2 = pCur2->_pNext;
			if (pCur1 == pCur2)
				return pCur1;
		}
		return NULL;
	}
	else {
		while (step++) {
			pCur2 = pCur2->_pNext;
		}
		while (pCur2) {
			pCur2 = pCur2->_pNext;
			pCur1 = pCur1->_pNext;
			if (pCur1 == pCur2)
				return pCur2;
		}
		return NULL;
	}
}

//相遇点和起始位置指针同时走，相遇的位置就是环的入口地址
//判断链表是否带环，求入口，求环的长度
PNode hasCircle(PNode pHead) {
	assert(pHead);
	PNode pFast = pHead;
	PNode pSlow = pHead;
	int circleLen = 0;
	while (1) {
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
		if (pFast == NULL)
			return NULL;
		if (pFast == pSlow)
			break;
	}
	pFast = pHead;
	while (pFast != pSlow){
		pFast = pFast->_pNext;
		pSlow = pSlow->_pNext;
	}

	while (1) {
		pSlow = pSlow->_pNext;
		circleLen++;
		if (pSlow == pFast)
			break;
	}
	printf("环的长度为%d\n", circleLen);
	return pFast;
}

//判断两个链表是否相交（可能带环）
PNode isCrossHasCircle(PNode pHead1, PNode pHead2) {
	assert(pHead1);
	assert(pHead2);

	PNode pCur1 = pHead1->_pNext;
	PNode pCur2 = pHead2->_pNext;

	//len1和len2不带环时表示两个链表的长度
	int len1 = 0;
	int len2 = 0;

	PNode pPreCur = NULL;

	PNode pCur1Slow = pHead1->_pNext;
	PNode pCur1Fast = pHead1->_pNext;

	//情况1，在环外相交
	while (1) {

		pCur1Slow = pCur1Slow->_pNext;
		
		if (pCur1Fast == NULL) {
			len1 = len1 * 2;
			break;
		}
		pPreCur = pCur1Fast->_pNext;

		if (pPreCur == NULL) {
			len1 = len1 * 2 + 1;
			pCur1Fast = NULL;
			break;
		}
			
		pCur1Fast = pCur1Fast->_pNext->_pNext;

		len1++;
		if (pCur1Slow == pCur1Fast)
			break;	
	}

	//记录下快慢指针在环内的交点
	PNode cross1 = pCur1Slow;
	
	PNode pCur2Slow = pHead2->_pNext;
	PNode pCur2Fast = pHead2->_pNext;
	
	
	while (1) {

		pCur2Slow = pCur2Slow->_pNext;

		if (pCur2Fast == NULL) {
			len2 = len2 * 2;
			break;
		}

		pPreCur = pCur2Fast->_pNext;

		if (pPreCur == NULL) {
			len2 = len2 * 2 + 1;
			break;
		}

		pCur2Fast = pCur2Fast->_pNext->_pNext;

		len2++;
		
		//判断是否在环内相交
		if (pCur2Slow == pCur2Fast) 
			break;	
	}

	PNode cross2 = pCur2Slow;

	//有一个不带环一个带环，绝对不相交
	if (pCur1Fast == NULL && pCur2Fast != NULL)
		return NULL;
	else if (pCur1Fast != NULL && pCur2Fast == NULL)
		return NULL;
	else if (pCur1Fast == NULL && pCur2Fast == NULL) {
		//都等于空的情况（两个都不带环）
		int len = len1 - len2;
		pCur1 = pHead1->_pNext;
		pCur2 = pHead2->_pNext;
		if (len > 0) {
			//链表1比链表2长
			while (len--) {
				pCur1 = pCur1->_pNext;
			}
			while (pCur1 != pCur2) {
				
				pCur1 = pCur1->_pNext;
				pCur2 = pCur2->_pNext;

				//不相交
				if (pCur1 == NULL)
					return NULL;
			}
			return pCur1;
		}
		else {
			//链表1比链表2短
			while (len++) {
				pCur2 = pCur2->_pNext;
			}
			while (pCur1 != pCur2) {
				
				pCur1 = pCur1->_pNext;
				pCur2 = pCur2->_pNext;

				//不相交
				if (pCur1 == NULL)
					return NULL;
			}
			return pCur2;
		}
	}
	else {
		//都不等于空的情况（两个链表都带环）

		//判断是否属于同一个环
		PNode pTemp = cross1;
		while (1) {
			cross1 = cross1->_pNext;
			
			if (cross1 == pTemp && cross1 != cross2)
				return NULL;
			//相遇了代表在同一个环里面
			if (cross1 == cross2) {
				break;
			}
		}
		
	//如果交点在环外，len1和len2分别表示两个到入口点的距离

		len2 = 0;
		//求带环链表2的入口点，pCur2Slow是环内的一点
		pCur2Fast = pHead2->_pNext;
		//找Cur2环的入口
		while (pCur2Fast != pCur2Slow) {
			len2++;
			pCur2Fast = pCur2Fast->_pNext;
			pCur2Slow = pCur2Slow->_pNext;
		}
		printf("len2=%d \n", len2);
		len1 = 0;
		//判断交点是否在入口点之前
		pCur1 = pHead1->_pNext;
		while (1) {
			pCur1 = pCur1->_pNext;
		
			len1++;
			if (pCur1 == pCur2Fast) {
				printf("len1=%d \n", len1);
				//交点在环外
				int len = len1 - len2;
				pCur1 = pHead1->_pNext;
				pCur2 = pHead2->_pNext;
				if (len > 0) {
					while (len--) {
						pCur1 = pCur1->_pNext;
					}
					while (1) {
						if (pCur2 == pCur1)
							return pCur2;

						pCur2 = pCur2->_pNext;
						pCur1 = pCur1->_pNext;
					}
					
					
				}
				else {
					while (len++) {
						pCur2 = pCur2->_pNext;
					}
					while (1) {
						if (pCur2 == pCur1)
							return pCur2;
						pCur2 = pCur2->_pNext;
						pCur1 = pCur1->_pNext;
						
					}
				}

				if (pCur1 == pTemp)
					//交点在环内
					break;
				break;

			}
		}
		//交点在环内
		return pCur2Fast;
	}
}

//求两个已排序单链表中相同的数据,merge
void UnionSet(PNode pHead1, PNode pHead2) {
	assert(pHead1);
	assert(pHead2);
	PNode pCur1 = pHead1;
	PNode pCur2 = pHead2;
	int data = 0;
	while (1) {
		if (pCur1->_data < pCur2->_data) {
			pCur1 = pCur1->_pNext;
		}
		else {
			if (pCur1->_data == pCur2->_data  && data != pCur1->_data) {
				data = pCur1->_data;
				printf("%d  ", data);
			}
			pCur2 = pCur2->_pNext;
		}

		if (!pCur1)
			break;
		if (!pCur2)
			break;
	
	}
}


//魔术师发牌问题
void setMagicCard(PNode* pHead) {
	assert(*pHead);
	PNode setZero = *pHead;
	PNode insertNode = NULL;
	//初始化13张牌为0(加头结点一共13个节点)
	int cardLen = 13;
	while (--cardLen) {
		insertNode = BuySListNode(0);
		setZero->_pNext = insertNode;
		insertNode->_pNext = NULL;
		setZero = insertNode;
	}

	showSList(*pHead);

	PNode pStart = *pHead;
	PNode pCur = *pHead;

	//让第一张牌等于1
	pCur->_data = 1;
	//获取最后一张牌，以便构成循环链表
	PNode tail = SListBack(*pHead);
	tail->_pNext = pStart;

	int cardID = 0;
	//从第二张牌开始
	int i = 2;

	while (i <= 13) {
		while (cardID<i) {
			pCur = pCur->_pNext;
	 		//遇到了没有赋值的cardID++
			if (pCur->_data == 0) {
				cardID++;
				//printf("%d ", cardID);
			}
		}
		pCur->_data = cardID;
		cardID = 0;
		i++;
	}
	//解环
	tail->_pNext = NULL;
	showSList(*pHead);
}

//n阶拉丁矩阵
int** LatinArray(PNode* pHead, unsigned int n) {
	if (n == 0)
		return;
	//首元素为1
	PNode pCur = *pHead;
	PNode pTail = NULL;

	//先构造一个循环链表
	for (int i = 1; i < n; i++) {
		pCur->_pNext = BuySListNode(i);
		pTail = pCur;
		pCur = pCur->_pNext;
	}
	pCur->_pNext = *pHead;
	PNode pStart = *pHead;
	pCur = *pHead;
	//showSList(*pHead);

	//申请一个n*n大小的数组存放拉丁方阵
	int** arr = NULL;
	arr = (int**)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int *)malloc(sizeof(int *)*n);
	}

	//初始化数组
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}

	int i = 0;
	int j = 0;
	while (i<n) {
		pCur = pStart;
		j = 0;
		while (j < n) {
			arr[i][j] = pCur->_data;
			j++;
			pCur = pCur->_pNext;
		}
		i++;
		pStart = pStart->_pNext;
	}
	return arr;
}

#endif