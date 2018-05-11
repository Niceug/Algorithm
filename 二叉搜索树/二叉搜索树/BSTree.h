typedef char* String;


// �ַ���ipתint
typedef union IPCast {
	unsigned int ip;
	struct {
		unsigned char str[4];
	}strip;
}IPCast;

typedef struct IP {
	unsigned int ip; // ip��ַ
	unsigned int count; // ���ֵĴ���
}IP;

typedef struct IP* IPDataType;
// ������������������������
typedef struct BSTreeIPNode {
	struct IP ip;
	struct BSTreeNode* LChild;
	struct BSTreeNode* RChild;
}BSTreeIPNode;


typedef int BSTreeDataType;
// ������������������������
typedef struct BSTreeNode {
	BSTreeDataType data;
	struct BSTreeNode* LChild;
	struct BSTreeNode* RChild;
}BSTreeNode;

// �����ڵ�
BSTreeNode* findBSTreeNode(BSTreeNode* pRoot, BSTreeDataType data);
// �ǵݹ������ڵ�
BSTreeNode* findBSTreeNodeNor(BSTreeNode* pRoot, BSTreeDataType data);
// ����ڵ�
int insertBSTreeNode(BSTreeNode** pRoot, BSTreeDataType data);
// �ǵݹ����ڵ�
int insertBSTreeNodeNor(BSTreeNode** pRoot, BSTreeDataType data);
// ɾ���ڵ�
void deleteBSTreeNode(BSTreeNode** pRoot, BSTreeDataType data);
// �����������������
void inOrderBSTree(BSTreeNode* pRoot);
// ���ٶ���������
void destroyBSTreeNode(BSTreeNode** pRoot);
// ��ȡ�ڵ�
BSTreeNode* buyBSTreeNode(BSTreeDataType data);



// ��������Ӧ��֮���һ�������Ƿ�ƴд��ȷ
typedef struct BSTreeAppNode {
	String word;
	struct BSTreeAppNode* LChild;
	struct BSTreeAppNode* RChild;
}BSTreeAppNode;

// �ж�һ�������Ƿ�ƴд��ȷ
int isCorrectSpelling(BSTreeAppNode* pRoot, String word);



