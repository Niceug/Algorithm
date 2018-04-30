#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "queue.h"
#include "stack.h"


int main() {

	//完全二叉树
	//BTDataType* str = "123###4##56";

	//不是完全二叉树
	BTDataType* str = "123###56";

	PBTNode pRoot = NULL;
	int index = 0;
	CreateBinTree(&pRoot, str, strlen(str));

	

	printf("先序遍历：\n");
	PreOrder(pRoot);
	printf("\n");

	printf("循环先序遍历：\n");
	PreOrderNor(pRoot);
	printf("\n\n");


	printf("中序遍历：\n");
	InOrder(pRoot);
	printf("\n");


	printf("循环中序遍历：\n");
	InOrderNor(pRoot);
	printf("\n\n");


	printf("后序遍历：\n");
	PostOrder(pRoot);
	printf("\n");

	printf("循环后序遍历：\n");
	PostOrderNor(pRoot);
	printf("\n\n");

	printf("层序遍历：");
	LevelOrder(pRoot);
	printf("\n\n");

	int size = BinTreeSize(pRoot);
	printf("二叉树节点个数为%d\n", size);

	int high = BinTreeHeight(pRoot);
	printf("高度为%d\n", high);

	int leafCount = BinTreeLeaf(pRoot);
	printf("叶子节点个数为%d\n", leafCount);

	int K = 2;
	int KSize = BinTreeKLevelNode(pRoot, K);
	printf("第%d层节点个数为%d\n\n", K, KSize);


	/*PBTNode node = Find(pRoot, '5');
	if(node != NULL)
		printf("找到了%c \n", node->data);*/

	if (IsCompleteBinTree(pRoot))
		printf("是完全二叉树！\n");
	else
		printf("不是完全二叉树！\n");

	MirrorBinTreeNor(pRoot);
	printf("二叉树镜像之后层序遍历：\n");
	LevelOrder(pRoot);
	printf("\n\n");

	MirrorBinTreeNor(pRoot);
	printf("再次二叉树镜像之后层序遍历：\n");
	LevelOrder(pRoot);
	printf("\n\n");

	printf("先序遍历：\n");
	PreOrder(pRoot);
	printf("\n");
	PBTNode newRoot = NULL;
	CopyBinTree(pRoot, &newRoot);
	printf("拷贝二叉树之后先序遍历：\n");
	PreOrder(newRoot);
	printf("\n\n");

	printf("删除二叉树之后的先序遍历：\n");
	DetroyBinTree(&pRoot);
	PreOrder(pRoot);
	return 0;
}

// 二叉树创建 
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

// 循环先序遍历二叉树
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

//循环中序遍历二叉树
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

		// ret表示pop的状态，0表示空栈
		int ret = StackPop(&s, &tmp);
		if (!ret)
			return;

		printf("%c ", tmp->data);
		if (tmp->RChild)
			cur = tmp->RChild;

	}
	
}

//循环后续遍历二叉树
void PostOrderNor(PBTNode pRoot) {
	if (pRoot == NULL)
		return;
	Stack s;
	StackInit(&s);

	PBTNode cur = pRoot;

	// 当前节点
	PBTNode tmp = NULL;

	// 用来记录上一次出栈的节点，以便判断这个节点是否应该继续向下遍历
	PBTNode preTmp = NULL;

	//放入根节点
	StackPush(&s, cur);

	while (1) {

		// 一直向左，入栈顺序为，cur cur->RChild  cur->LChild
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

			//栈为空退出
			if (tmp == NULL)
				return;

			//判断当前点的子节点是否是上一次遍历的。如果是则代表这颗树的子节点已经遍历完了，就直接输出当前节点
			if (tmp->LChild == preTmp || tmp->RChild == preTmp) {
				printf("%c ", tmp->data);
				StackPop(&s, &tmp);
				preTmp = tmp;
				continue;
			}

			// 不直接遍历则看他的左右孩子是否为空，不为空就入栈
			if (tmp->LChild || tmp->RChild) {
				cur = tmp;
				preTmp = tmp;
				continue;
			}

			//叶子节点，直接打印。
			StackPop(&s, &tmp);
			preTmp = tmp;
			printf("%c ", tmp->data);

		}		
	}
}

//// array1为先序，array2为中序
//void RebuildBTNode(PBTNode* pRoot, BTDataType* array1, BTDataType* array2, int length) {
//	int i = 0; 
//	int j = 0;
//
//	if (array1[i] == array2[j])
//		return;
//}

// 层序遍历二叉树
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


// 二叉树的镜像---非递归 
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

// 二叉树的镜像---递归 
void MirrorBinTree(PBTNode pRoot) {

}

// 求二叉树中结点的个数 
int BinTreeSize(PBTNode pRoot) {
	if (pRoot == NULL)
		return 0;
	if (pRoot->LChild == NULL && pRoot->RChild == NULL)
		return 1;
	return BinTreeSize(pRoot->LChild) + BinTreeSize(pRoot->RChild) + 1;
}

// 求二叉树中叶子结点的个数 
int BinTreeLeaf(PBTNode pRoot) {
	if (pRoot == NULL)
		return 0;
	if (pRoot->LChild == NULL && pRoot->RChild == NULL)
		return 1;
	return BinTreeLeaf(pRoot->LChild) + BinTreeLeaf(pRoot->RChild);
}


// 求二叉树中第K层结点的个数 
int BinTreeKLevelNode(PBTNode pRoot, int K) {
	if (K <= 0)
		return 0;
	if (K == 1 && pRoot != NULL)
		return 1;
	if (pRoot == NULL)
		return 0;
	return BinTreeKLevelNode(pRoot->LChild, K - 1) + BinTreeKLevelNode(pRoot->RChild, K - 1);
}

// 求二叉树的高度 
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

// 在二叉树中查找值为data的结点，找到返回该结点，否则返回空 
PBTNode Find(PBTNode pRoot, BTDataType data) {
	if (pRoot != NULL) {
		Find(pRoot->LChild, data);
		if (data == pRoot->data)
			return pRoot;
		Find(pRoot->RChild, data);
	}
}

// 检测一个节点是否在二叉树中 
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode) {

}
// 检测一棵树是否为完全二叉树 
int IsCompleteBinTree(PBTNode pRoot) {
	if (pRoot == NULL)
		return 0;
	// 标识是否找到了这个特殊的节点。
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
			// 找到分界点。
			flag = 1;
		}	
	}
	return 1;
}


//交换两个节点
void swapBTNodeNode(PBTNode* node1, PBTNode* node2) {
	PBTNode tmp = *node1;
	*node1 = *node2;
	*node2 = tmp;
}