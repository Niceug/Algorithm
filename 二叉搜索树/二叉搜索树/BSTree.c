#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

// ��ȡ�ڵ�
BSTreeAppNode* buyBSTreeNodeByString(String data) {
	BSTreeAppNode* node = (BSTreeAppNode*)malloc(sizeof(BSTreeAppNode));
	if (node == NULL)
		return NULL;
	node->word = data;
	node->LChild = NULL;
	node->RChild = NULL;
	return node;
}

// �������������
void inOrderBSTreeByString(BSTreeAppNode* pRoot) {
	if (pRoot != NULL) {
		inOrderBSTreeByString(pRoot->LChild);
		printf("%s ", pRoot->word);
		inOrderBSTreeByString(pRoot->RChild);
	}
}

// ����ڵ�
int insertBSTreeNodeByString(BSTreeAppNode** pRoot, String word) {
	if (*pRoot == NULL) {
		*pRoot = buyBSTreeNodeByString(word);
		return 1;
	}
	if (strcmp((*pRoot)->word, word) == 0) // �Ѿ������ˣ������ٲ����ˡ�
		return 0;
	if (strcmp((*pRoot)->word, word) > 0) {
		return insertBSTreeNodeByString(&(*pRoot)->LChild, word);
	}
	return insertBSTreeNodeByString(&(*pRoot)->RChild, word);
}


// �ж�һ�������Ƿ�ƴд��ȷ
int isCorrectSpelling(BSTreeAppNode* pRoot, String word) {
	if (pRoot == NULL)
		return 0;
	BSTreeAppNode* Cur = pRoot;
	while (Cur) {
		if (strcmp(word, Cur->word) == 0)
			return 1;
		else if (strcmp(word, Cur->word) < 0) {
			Cur = Cur->LChild;
		}
		else if (strcmp(word, Cur->word) > 0) {
			Cur = Cur->RChild;
		}
	}
	return 0;
}
// Ӣ�������ֵ䣨��Ӣ���ַ���������
void EnglishToChinese(BSTreeAppNode* pRoot) {

}

// �ж�һ�������Ƿ�ƴд��ȷ
void testIsCorrectSpelling() {
	String arr[] = {"hellow", "he", "helloword", "hello"};
	int len = sizeof(arr)/ sizeof(arr[0]);
	BSTreeAppNode* pRoot = NULL;
	for (int i = 0; i < len; i++) {
		insertBSTreeNodeByString(&pRoot, arr[i]);
	}
	String word = "hello";
	int ret = isCorrectSpelling(pRoot, word);
	if (ret)
		printf("ƴд��ȷ\n");
	else
		printf("ƴд����\n");
}

// Ӣ�������ֵ䣨��Ӣ���ַ���������
void testEnglishToChinese() {

}

void showHeap(IP* ips, int len) {
	for (int i = 0; i < len; i++) {
		IPCast ipCast;
		ipCast.ip = ips[i].ip;
		printf("%d.%d.%d.%d ���ִ��� %d\n", ipCast.strip.str[3], ipCast.strip.str[2], ipCast.strip.str[1], ipCast.strip.str[0], ips[i].count);
	}
	printf("\n");
}

// �ַ���IPת����
unsigned int StringIPCastToInt(String ip) {
	IPCast ipCast;
	int i = 3;
	int j = 0;
	String cur = ip;
	char preCur[16] = { 0 };
	String root = preCur;
	while (1) {
		if (*cur != '.' && *cur != '\0') {
			preCur[j] = *cur;
			j++;
		}
		else {
			int a = atoi(preCur);
			(ipCast.strip).str[i] = (char)a;
			memset(preCur, 0, 16);
			j = 0;
			i--;
			if (*cur == '\0')
				break;
		}
		cur++;
	}
	return ipCast.ip;
}

// ��ȡ�ڵ�
BSTreeIPNode* buyBSTreeNodeByIP(unsigned int ip) {
	BSTreeIPNode* node = (BSTreeIPNode*)malloc(sizeof(BSTreeIPNode));
	if (node == NULL)
		return NULL;
	node->ip.ip = ip;
	node->ip.count = 0;
	node->LChild = NULL;
	node->RChild = NULL;
	return node;
}

// �������������������������ֵ��ֵ���ṹ������
void inOrderBSTreeByIP(BSTreeIPNode* pRoot, IP* ips, int* index) {
	if (pRoot != NULL) {
		(*index)++;
		inOrderBSTreeByIP(pRoot->LChild, ips, index);
		IPCast ipCast;
		ipCast.ip = pRoot->ip.ip;
		printf("%d.%d.%d.%d ���ִ��� %d\n", ipCast.strip.str[3], ipCast.strip.str[2], ipCast.strip.str[1], ipCast.strip.str[0], pRoot->ip.count);
		if (pRoot->ip.count > 1) {
			ips[*index] = pRoot->ip;
			(*index)++;
		}
		inOrderBSTreeByIP(pRoot->RChild, ips, index);
	}
}

// ����IP��ַ
int insertBSTreeNodeByIP(BSTreeIPNode** pRoot, unsigned int ip) {
	if (*pRoot == NULL) {
		*pRoot = buyBSTreeNodeByIP(ip);
		(*pRoot)->ip.count++;
		return 1;
	}
	if ((*pRoot)->ip.ip == ip) {
		(*pRoot)->ip.count++;
		return 0;
	}
	if ((*pRoot)->ip.ip > ip) {
		return insertBSTreeNodeByIP(&(*pRoot)->LChild, ip);
	}
	return insertBSTreeNodeByIP(&(*pRoot)->RChild, ip);
}

void swap(IP* a, IP* b) {
	IP tmp = *a;
	*a = *b;
	*b = tmp;
}

// ����С���
void createIPHeap(IP* ips, unsigned int len) {
	// �ҵ��ٽ��
	int parrent = 0;
	int flag = ((len - 1) / 2);
	while (flag >= 0) {
		parrent = flag;
		while (1) {
			int child = parrent * 2 + 1;
			if (child + 1 >= len) {
				if (ips[parrent].count > ips[child].count) {
					swap(&ips[parrent], &ips[child]);
				}
				break;
			}
				
			if (ips[child].count > ips[child + 1].count) {
				child++;
			}

			if (ips[parrent].count > ips[child].count) {
				swap(&ips[parrent], &ips[child]);
				parrent = child;
			}
			else {
				break;
			}
		}
		flag--;
	}
}


// ����IP��ַ�����µ�����
void insertIntoHeap(IP* ips, IP insertIP, unsigned int len) {
	if (insertIP.count <= ips[0].count)
		return;
	ips[0] = insertIP;
	int parrent = 0;
	int child = 0;
	//�ҵ���������С�ģ�Ȼ�󽻻�
	while (1) {
		child = parrent * 2 + 1;
		if (child >= len)
			break;
		if (child + 1 >= len) {
			if (ips[parrent].count > ips[child].count) {
				swap(&ips[parrent], &ips[child]);
				break;
			}
		}
		if (ips[child].count > ips[child + 1].count) {
			child++;
		}
		if (ips[parrent].count > ips[child].count) {
			swap(&ips[parrent], &ips[child]);
			parrent = child;
		}
		else {
			break;
		}
	}
}



// �ҵ����ִ�������K���쳣IP��ַ
void getTopKUnusualIP(IP* ips, unsigned int count, unsigned int k) {
	if (count <= k) {
		createIPHeap(ips, count);
		return;
	}
	createIPHeap(ips, k);
	for (int i = k; i < count; i++) {
		insertIntoHeap(ips, ips[i], k);
	}
	showHeap(ips, k);

}

void testCountUnusualIP() {
	String ip[] = { "111.168.0.1",
		"192.168.0.1" ,
		"253.168.0.1" ,
		"255.168.0.1" ,
		"255.168.0.1",
		"192.168.0.1",
		"192.168.0.1",
		"127.0.0.1",
		"0.0.0.1",
		"128.98.78.1",
		"192.168.0.1" ,
		"253.168.0.1" ,
		"192.168.0.1" ,
		"253.168.0.1" ,
		"192.168.0.1" ,
		"253.168.0.1" ,
		"192.168.0.1" ,
		"253.168.0.1" ,
		"192.168.0.1" ,
		"253.168.0.1" ,
		"192.168.0.1" ,
		"253.168.0.1" ,
		"255.168.0.2" ,
		"255.168.0.1",
		"192.168.0.1",
		"192.168.0.1",
		"127.0.0.1",
		"0.0.0.1",
		"128.98.78.1",
		"192.168.0.1" ,
		"253.168.0.1" ,
		"192.168.0.1" ,
		"253.168.0.1" ,
		"192.168.0.1" ,
		"253.168.0.1" ,
		"192.168.0.1" ,
		"253.168.0.1" ,
		"124.168.0.1",
		"124.168.0.1",
		"124.168.0.1" };
	int len = sizeof(ip) / sizeof(ip[0]);
	BSTreeIPNode* pRoot = NULL;
	for (int i = 0; i < len; i++) {
		unsigned int ret = StringIPCastToInt(ip[i]);
		insertBSTreeNodeByIP(&pRoot, ret);
	}
	IP ips[40] = {0};
	int a = 0;
	printf("���������\n");
	inOrderBSTreeByIP(pRoot, ips, &a);
	printf("\n���ִ�������5��Ԫ��Ϊ��\n");
	getTopKUnusualIP(ips, 40, 5);
}
int main() {
	//testCountUnusualIP();
	//testIsCorrectSpelling();
	//tet
	BSTreeNode* pRoot = NULL;
	BSTreeDataType arr[] = {7, 11, 3, 1, 5, 9, 12, 4, 6, 8, 10};
	int len = sizeof(arr) / sizeof(arr[0]);
	
	for (int i = 0; i < len; i++) {
		insertBSTreeNodeNor(&pRoot, arr[i]);
	}
	printf("�������нڵ�ɹ���\n");
	printf("�������������������\n");
	inOrderBSTree(pRoot);

	
	// �����ڵ�
	BSTreeNode* node = findBSTreeNode(pRoot, 7);
	printf("\n�ҵ���ɾ���ڵ�%d\n", node->data);
	deleteBSTreeNodeNor(&pRoot, node->data);
	printf("�������������������\n");
	inOrderBSTree(pRoot);

	printf("\n�����ڵ�8����5\n");
	pRoot->data = 5;
	int ret = isBSTree(pRoot);
	inOrderBSTree(pRoot);
	if (ret)
		printf("�Ƕ���������\n", ret);
	else
		printf("���Ƕ���������\n");

	printf("�����ڵ�5����11\n");
	pRoot->data = 11;
	ret = isBSTree(pRoot);
	inOrderBSTree(pRoot);
	if (ret)
		printf("�Ƕ���������\n", ret);
	else
		printf("���Ƕ���������\n");

	printf("�����ڵ�5����9\n");
	pRoot->data = 8;
	ret = isBSTree(pRoot);
	inOrderBSTree(pRoot);
	if (ret)
		printf("�Ƕ���������\n", ret);
	else
		printf("���Ƕ���������\n");

	// ���ٶ�����
	printf("\n����֮���������������������\n");
	destroyBSTreeNode(&pRoot);
	inOrderBSTree(pRoot);
	return 0;
}

// ����ڵ�
int insertBSTreeNode(BSTreeNode** pRoot, BSTreeDataType data) {
	if (*pRoot == NULL) {
		*pRoot = buyBSTreeNode(data);
		return 1;
	}
	if ((*pRoot)->data == data)
		return 0;
	if ((*pRoot)->data > data) {
		return insertBSTreeNode(&(*pRoot)->LChild, data);
	}
	return insertBSTreeNode(&(*pRoot)->RChild, data);
}



// �ǵݹ����ڵ㣬���ز���״̬
int insertBSTreeNodeNor(BSTreeNode** pRoot, BSTreeDataType data) {
	BSTreeNode* insertNode = buyBSTreeNode(data);
	if (*pRoot == NULL) {
		*pRoot = insertNode;
		return 1;
	}

	BSTreeNode* Cur = *pRoot;
	BSTreeNode* preCur = NULL;
	while (Cur) {
		if (Cur->data == data) {
			return 0;
		}
		else if (data < Cur->data) {
			preCur = Cur;
			Cur = Cur->LChild;
		}
		else if (data > Cur->data) {
			preCur = Cur;
			Cur = Cur->RChild;
		}
	}
	if (data > preCur->data) {
		preCur->RChild = insertNode;
	}
	else {
		preCur->LChild = insertNode;
	}
	return 0;
}

// �ݹ������ڵ�
BSTreeNode* findBSTreeNode(BSTreeNode* pRoot, BSTreeDataType data) {
	if (pRoot == NULL)
		return NULL;
	if (pRoot->data == data) {
		return pRoot;
	}

	if (data < pRoot->data) {
		return findBSTreeNode(pRoot->LChild, data);
	}

	return findBSTreeNode(pRoot->RChild, data);
}

// �ǵݹ������ڵ�
BSTreeNode* findBSTreeNodeNor(BSTreeNode* pRoot, BSTreeDataType data) {
	if (pRoot == NULL)
		return NULL;
	BSTreeNode* Cur = pRoot;
	while (Cur) {
		if (Cur->data == data) {
			return Cur;
		}
		else if (data > Cur->data) {
			Cur = Cur->RChild;
		}
		else if (data < Cur->data) {
			Cur = Cur->LChild;
		}
	}
	return NULL;
}

// ɾ���ڵ�
void deleteBSTreeNodeNor(BSTreeNode** pRoot, BSTreeDataType data) {
	// �ҵ��ڵ�
	BSTreeNode* Cur = *pRoot;
	BSTreeNode* preCur = NULL;
	while (Cur) {
		if (Cur->data == data)
			break;
		else if (data < Cur->data) {
			preCur = Cur;
			Cur = Cur->LChild;
		}
		else if (data > Cur->data) {
			preCur = Cur;
			Cur = Cur->RChild;
		}
	}

	if (Cur == NULL)
		return;

	BSTreeNode* delNode = Cur;

	// ���ɾ������Ҷ�ӽڵ�
	if (delNode->RChild == NULL && delNode->LChild == NULL) {
		if (delNode == preCur->LChild) {
			free(delNode);
			delNode = NULL;
			preCur->LChild = NULL;
			return;
		}
		if (delNode == preCur->RChild) {
			free(delNode);
			delNode = NULL;
			preCur->RChild = NULL;
			return;
		}
	}

	//���ɾ���Ľڵ��Ǹ��ڵ�
	if (delNode == *pRoot) {
		if (delNode->LChild == NULL) {
			// ������ڵ�������
			delNode = *pRoot;
			*pRoot = (*pRoot)->RChild;
			free(delNode);
			delNode = NULL;
		}
		else if (delNode->RChild == NULL) {
			// ������ڵ����Һ���
			delNode = *pRoot;
			*pRoot = (*pRoot)->LChild;
			free(delNode);
			delNode = NULL;
		}
		else {
			// ������ڵ������Һ���
			// �ø��ڵ���Һ��ӵ������ӽ���,Ȼ��ɾ�����������
			// �ҵ��Һ��ӵ�������
			delNode = (*pRoot)->RChild;
			while (delNode->LChild) {
				preCur = delNode;
				delNode = delNode->LChild;
			}

			// ��������ֵ��ֵ�����ڵ�
			(*pRoot)->data = delNode->data;

			// ɾ������ڵ�
			if (delNode->RChild != NULL) {
				// ���Ҫɾ���Ľڵ����Һ���
				if (preCur != NULL)
					preCur->LChild = delNode->RChild;
				else {
					(*pRoot)->RChild = delNode->RChild;
				}
				free(delNode);
				delNode = NULL;
			}
			else {
				free(delNode);
				delNode = NULL;
				preCur->LChild = NULL;
			}
		}
	}
	else if (delNode == preCur->LChild) {
		// ���ɾ���Ľڵ��Ǹ��ڵ������
		if (delNode->LChild == NULL) {
			// ���ɾ���Ľڵ�������
			preCur->LChild = delNode->RChild;
			free(delNode);
			delNode = NULL;
		}
		else if (delNode->RChild == NULL) {
			// ���ɾ���Ľڵ����Һ���
			preCur->LChild = delNode->LChild;
			free(delNode);
			delNode = NULL;
		}
		else {
			// ���ɾ���Ľڵ������Һ���

			// �ҵ��Һ��ӵ�������
			delNode = Cur->RChild;

			// ����Һ���������
			if (delNode->LChild == NULL) {
				Cur->data = delNode->data;
				Cur->RChild = delNode->RChild;
				free(delNode);
				delNode = NULL;
				return;
			}

			// ����Һ��������ӣ��ҵ�������
			while (delNode->LChild) {
				preCur = delNode;
				delNode = delNode->LChild;
			}
			

			// ��������ֵ��ֵ�����ڵ�
			Cur->data = delNode->data;

			// ɾ������ڵ�
			if (delNode->RChild != NULL) {
				// ���Ҫɾ���Ľڵ����Һ���
				preCur->LChild = delNode->RChild;
				free(delNode);
				delNode = NULL;
			}
			else {
				free(delNode);
				delNode = NULL;
				preCur->LChild = NULL;
			}
		}
	}

	else if (delNode == preCur->RChild) {
		// ���ɾ���Ľڵ��Ǹ��ڵ���Һ���
		if (delNode->LChild == NULL) {
			// ���ɾ���Ľڵ�������
			preCur->RChild = delNode->RChild;
			free(delNode);
			delNode = NULL;
		}
		else if (delNode->RChild == NULL) {
			// ���ɾ���Ľڵ����Һ���
			preCur->RChild = delNode->LChild;
			free(delNode);
			delNode = NULL;
		}
		else {
			// ���ɾ���Ľڵ������Һ���

			// �ҵ����ӵ����Һ���
			delNode = Cur->LChild;

			// ����������Һ���
			if (delNode->RChild == NULL) {
				Cur->data = delNode->data;
				Cur->LChild = delNode->LChild;
				free(delNode);
				delNode = NULL;
				return;
			}

			// ����������Һ��ӣ��ҵ����Һ���
			while (delNode->RChild) {
				preCur = delNode;
				delNode = delNode->RChild;
			}

			// �����Һ���ֵ��ֵ�����ڵ�
			Cur->data = delNode->data;

			// ɾ������ڵ�
			if (delNode->LChild != NULL) {
				// ���Ҫɾ���Ľڵ�������
				preCur->RChild = delNode->LChild;
				free(delNode);
				delNode = NULL;
			}
			else {
				free(delNode);
				delNode = NULL;
				preCur->RChild = NULL;
			}
		}
	}
}

// ��ȡ�ڵ�
BSTreeNode* buyBSTreeNode(BSTreeDataType data) {
	BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (node == NULL)
		return NULL;
	node->data = data;
	node->LChild = NULL;
	node->RChild = NULL;
	return node;
}

// �������������
void inOrderBSTree(BSTreeNode* pRoot) {
	if (pRoot != NULL) {
		inOrderBSTree(pRoot->LChild);
		printf("%d ", pRoot->data);
		inOrderBSTree(pRoot->RChild);
	}
}

// ���ٶ���������
void destroyBSTreeNode(BSTreeNode** pRoot) {
	// ������������
	if (*pRoot != NULL) {
		destroyBSTreeNode(&(*pRoot)->LChild);
		destroyBSTreeNode(&(*pRoot)->RChild);
		free(*pRoot);
		*pRoot = NULL;
	}
}

// �ж�һ�����ǲ��Ƕ���������(����Ķ���������)
int isBSTree(BSTreeNode* pRoot) {
	// ��ǰ�ڵ�������Һ��ӣ���ǰ�ڵ��ֵһ��С�ڵ����Һ��ӵ������ӡ�
	if (pRoot == NULL)
		return 1;
	if (pRoot->RChild != NULL) {
		BSTreeNode* cur = pRoot->RChild;
		if (cur->data < pRoot->data)
			return 0;
		while (cur->LChild) {
			cur = cur->LChild;
		}
		if (cur->data < pRoot->data) {
			return 0;
		}
		isBSTree(pRoot->LChild);
	}
	// ��ǰ�ڵ���������ӣ���ǰ�ڵ��ֵһ�����ڵ������ӵ����Һ��ӡ�
	if (pRoot->LChild != NULL) {
		BSTreeNode* cur = pRoot->LChild;
		if (cur->data > pRoot->data)
			return 0;
		while (cur->RChild) {
			cur = cur->RChild;
		}
		if (cur->data > pRoot->data) {
			return 0;
		}
		isBSTree(pRoot->RChild);
	}
}