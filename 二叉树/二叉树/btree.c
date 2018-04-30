#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "queue.h"
#include "stack.h"


int main() {

	//��ȫ������
	//BTDataType* str = "123###4##56";

	//������ȫ������
	BTDataType* str = "123###56";

	PBTNode pRoot = NULL;
	int index = 0;
	CreateBinTree(&pRoot, str, strlen(str));

	

	printf("���������\n");
	PreOrder(pRoot);
	printf("\n");

	printf("ѭ�����������\n");
	PreOrderNor(pRoot);
	printf("\n\n");


	printf("���������\n");
	InOrder(pRoot);
	printf("\n");


	printf("ѭ�����������\n");
	InOrderNor(pRoot);
	printf("\n\n");


	printf("���������\n");
	PostOrder(pRoot);
	printf("\n");

	printf("ѭ�����������\n");
	PostOrderNor(pRoot);
	printf("\n\n");

	printf("���������");
	LevelOrder(pRoot);
	printf("\n\n");

	int size = BinTreeSize(pRoot);
	printf("�������ڵ����Ϊ%d\n", size);

	int high = BinTreeHeight(pRoot);
	printf("�߶�Ϊ%d\n", high);

	int leafCount = BinTreeLeaf(pRoot);
	printf("Ҷ�ӽڵ����Ϊ%d\n", leafCount);

	int K = 2;
	int KSize = BinTreeKLevelNode(pRoot, K);
	printf("��%d��ڵ����Ϊ%d\n\n", K, KSize);


	/*PBTNode node = Find(pRoot, '5');
	if(node != NULL)
		printf("�ҵ���%c \n", node->data);*/

	if (IsCompleteBinTree(pRoot))
		printf("����ȫ��������\n");
	else
		printf("������ȫ��������\n");

	MirrorBinTreeNor(pRoot);
	printf("����������֮����������\n");
	LevelOrder(pRoot);
	printf("\n\n");

	MirrorBinTreeNor(pRoot);
	printf("�ٴζ���������֮����������\n");
	LevelOrder(pRoot);
	printf("\n\n");

	printf("���������\n");
	PreOrder(pRoot);
	printf("\n");
	PBTNode newRoot = NULL;
	CopyBinTree(pRoot, &newRoot);
	printf("����������֮�����������\n");
	PreOrder(newRoot);
	printf("\n\n");

	printf("ɾ��������֮������������\n");
	DetroyBinTree(&pRoot);
	PreOrder(pRoot);
	return 0;
}

// ���������� 
void CreateBinTree(PBTNode* pRoot, BTDataType array[], int size) {
	int index = 0;
	BTNodeCreate(array, pRoot, size, &index, '#');
}

void BTNodeCreate(BTDataType* array, PBTNode* pRoot, int length, int *index, BTDataType invalid) {
	if (*index < length && array[*index] != invalid) {
		*pRoot = (PBTNode)malloc(sizeof(BTNode));

		if (*pRoot == NULL)
			return;
		(*pRoot)->LChild = NULL;
		(*pRoot)->RChild = NULL;
		(*pRoot)->data = array[*index];

		++(*index);
		BTNodeCreate(array, &(*pRoot)->LChild, length, index, invalid);
		++(*index);
		BTNodeCreate(array, &(*pRoot)->RChild, length, index, invalid);
	}
}
void PreOrder(PBTNode pRoot) {
	if (pRoot) {
		printf("%c ", pRoot->data);
		PreOrder(pRoot->LChild);
		PreOrder(pRoot->RChild);
	}
}
void InOrder(PBTNode pRoot) {
	if (pRoot) {
		InOrder(pRoot->LChild);
		printf("%c ", pRoot->data);
		InOrder(pRoot->RChild);
	}
}
void PostOrder(PBTNode pRoot) {
	if (pRoot) {
		PostOrder(pRoot->LChild);
		PostOrder(pRoot->RChild);
		printf("%c ", pRoot->data);
	}
}

void DetroyBinTree(PBTNode* pRoot) {
	if (*pRoot) {

		DetroyBinTree(&(*pRoot)->LChild);
		DetroyBinTree(&(*pRoot)->RChild);
		free(*pRoot);
		*pRoot = NULL;
	}
}

void CopyBinTree(PBTNode pRoot, PBTNode* newRoot) {
	if (pRoot) {
		*newRoot = (PBTNode)malloc(sizeof(BTNode));
		if (*newRoot == NULL)
			return;
		(*newRoot)->LChild = NULL;
		(*newRoot)->RChild = NULL;

		(*newRoot)->data = pRoot->data;

		CopyBinTree(pRoot->LChild, &(*newRoot)->LChild);
		CopyBinTree(pRoot->RChild, &(*newRoot)->RChild);
	}
}

// ѭ���������������
void PreOrderNor(PBTNode pRoot) {
	if (pRoot == NULL)
		return;
	PBTNode cur = pRoot;
	Stack s;
	StackInit(&s);
	while (1) {
		printf("%c ", cur->data);
		if (cur->RChild != NULL)
			StackPush(&s, cur->RChild);
		cur = cur->LChild;
		if (cur == NULL) {
			int ret = StackPop(&s, &cur);
			if (ret == 0)
				return;
		}
	}
}

//ѭ���������������
void InOrderNor(PBTNode pRoot) {
	if (pRoot == NULL)
		return;
	PBTNode cur = pRoot;
	PBTNode tmp = NULL;
	Stack s;
	StackInit(&s);
	while (1) {

		while (cur != NULL) {
			StackPush(&s, cur);
			cur = cur->LChild;
		}

		// ret��ʾpop��״̬��0��ʾ��ջ
		int ret = StackPop(&s, &tmp);
		if (!ret)
			return;

		printf("%c ", tmp->data);
		if (tmp->RChild)
			cur = tmp->RChild;

	}
	
}

//ѭ����������������
void PostOrderNor(PBTNode pRoot) {
	if (pRoot == NULL)
		return;
	Stack s;
	StackInit(&s);

	PBTNode cur = pRoot;

	// ��ǰ�ڵ�
	PBTNode tmp = NULL;

	// ������¼��һ�γ�ջ�Ľڵ㣬�Ա��ж�����ڵ��Ƿ�Ӧ�ü������±���
	PBTNode preTmp = NULL;

	//������ڵ�
	StackPush(&s, cur);

	while (1) {

		// һֱ������ջ˳��Ϊ��cur cur->RChild  cur->LChild
		while (cur != NULL)
		{
			if (cur->RChild)
				StackPush(&s, cur->RChild);
			if (cur->LChild)
				StackPush(&s, cur->LChild);
			cur = cur->LChild;
		}
		if (cur == NULL) {

			tmp = StackTop(&s);

			//ջΪ���˳�
			if (tmp == NULL)
				return;

			//�жϵ�ǰ����ӽڵ��Ƿ�����һ�α����ġ�������������������ӽڵ��Ѿ��������ˣ���ֱ�������ǰ�ڵ�
			if (tmp->LChild == preTmp || tmp->RChild == preTmp) {
				printf("%c ", tmp->data);
				StackPop(&s, &tmp);
				preTmp = tmp;
				continue;
			}

			// ��ֱ�ӱ������������Һ����Ƿ�Ϊ�գ���Ϊ�վ���ջ
			if (tmp->LChild || tmp->RChild) {
				cur = tmp;
				preTmp = tmp;
				continue;
			}

			//Ҷ�ӽڵ㣬ֱ�Ӵ�ӡ��
			StackPop(&s, &tmp);
			preTmp = tmp;
			printf("%c ", tmp->data);

		}		
	}
}

//// array1Ϊ����array2Ϊ����
//void RebuildBTNode(PBTNode* pRoot, BTDataType* array1, BTDataType* array2, int length) {
//	int i = 0; 
//	int j = 0;
//
//	if (array1[i] == array2[j])
//		return;
//}

// �������������
void LevelOrder(PBTNode pRoot) {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QueueInit(q);
	QueuePush(q, pRoot);
	PBTNode tmp = NULL;
	while (!QueueEmpty(q)) {
		PBTNode cur = QueueFront(q);
		
		printf("%c ", cur->data);
		if (cur->LChild != NULL)
			QueuePush(q, cur->LChild);
		if (cur->RChild != NULL)
			QueuePush(q, cur->RChild);
		QueuePop(q, &tmp);
	}
}


// �������ľ���---�ǵݹ� 
void MirrorBinTreeNor(PBTNode pRoot) {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QueueInit(q);
	QueuePush(q, pRoot);
	PBTNode tmp = NULL;
	while (!QueueEmpty(q)) {
		PBTNode cur = QueueFront(q);

		if (cur->LChild != NULL)
			QueuePush(q, cur->LChild);
		if (cur->RChild != NULL)
			QueuePush(q, cur->RChild);
		swapBTNodeNode(&(cur->LChild), &(cur->RChild));
		QueuePop(q, &tmp);
	}
}

// �������ľ���---�ݹ� 
void MirrorBinTree(PBTNode pRoot) {

}

// ��������н��ĸ��� 
int BinTreeSize(PBTNode pRoot) {
	if (pRoot == NULL)
		return 0;
	if (pRoot->LChild == NULL && pRoot->RChild == NULL)
		return 1;
	return BinTreeSize(pRoot->LChild) + BinTreeSize(pRoot->RChild) + 1;
}

// ���������Ҷ�ӽ��ĸ��� 
int BinTreeLeaf(PBTNode pRoot) {
	if (pRoot == NULL)
		return 0;
	if (pRoot->LChild == NULL && pRoot->RChild == NULL)
		return 1;
	return BinTreeLeaf(pRoot->LChild) + BinTreeLeaf(pRoot->RChild);
}


// ��������е�K����ĸ��� 
int BinTreeKLevelNode(PBTNode pRoot, int K) {
	if (K <= 0)
		return 0;
	if (K == 1 && pRoot != NULL)
		return 1;
	if (pRoot == NULL)
		return 0;
	return BinTreeKLevelNode(pRoot->LChild, K - 1) + BinTreeKLevelNode(pRoot->RChild, K - 1);
}

// ��������ĸ߶� 
int BinTreeHeight(PBTNode pRoot) {
	int leftHigh, rightHigh;
	if (pRoot == NULL)
		return 0;
	if (pRoot->LChild == NULL && pRoot->RChild == NULL)
		return 1;
	leftHigh = BinTreeHeight(pRoot->LChild);
	rightHigh = BinTreeHeight(pRoot->RChild);
	return leftHigh > rightHigh ? leftHigh + 1 : rightHigh + 1;
}

// �ڶ������в���ֵΪdata�Ľ�㣬�ҵ����ظý�㣬���򷵻ؿ� 
PBTNode Find(PBTNode pRoot, BTDataType data) {
	if (pRoot != NULL) {
		Find(pRoot->LChild, data);
		if (data == pRoot->data)
			return pRoot;
		Find(pRoot->RChild, data);
	}
}

// ���һ���ڵ��Ƿ��ڶ������� 
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode) {

}
// ���һ�����Ƿ�Ϊ��ȫ������ 
int IsCompleteBinTree(PBTNode pRoot) {
	if (pRoot == NULL)
		return 0;
	// ��ʶ�Ƿ��ҵ����������Ľڵ㡣
	int flag = 0;
	PBTNode cur;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q)) {
		QueuePop(&q, &cur);
		if (flag == 1 && (cur->LChild != NULL || cur->RChild != NULL))
			return 0;
		if (cur->LChild != NULL && cur->RChild != NULL && flag == 0) {
			QueuePush(&q, cur->LChild);
			QueuePush(&q, cur->RChild);
		}
		if (cur->LChild == NULL && cur->RChild != NULL)
			return 0;
		if ((cur->RChild == NULL && cur->LChild == NULL) ||
			(cur->RChild == NULL && cur->LChild != NULL))
		{
			// �ҵ��ֽ�㡣
			flag = 1;
		}	
	}
	return 1;
}


//���������ڵ�
void swapBTNodeNode(PBTNode* node1, PBTNode* node2) {
	PBTNode tmp = *node1;
	*node1 = *node2;
	*node2 = tmp;
}