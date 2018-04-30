typedef char BTDataType;

typedef struct BTNode {
	BTDataType data;
	struct BTNode* LChild;
	struct BTNode* RChild;
}*PBTNode, BTNode;

// ���������� 
void CreateBinTree(PBTNode* pRoot, BTDataType array[], int size);

// ���������� 
void CopyBinTree(PBTNode pRoot, PBTNode* newRoot);

// ǰ�����---�ݹ� 
void PreOrder(PBTNode pRoot);

// ǰ�����---�ǵݹ� 
void PreOrderNor(PBTNode pRoot);

// �������---�ݹ� 
void InOrder(PBTNode pRoot);

// �������---�ǵݹ� 
void InOrderNor(PBTNode pRoot);

// ��������---�ݹ� 
void PostOrder(PBTNode pRoot);

// ��������---�ǵݹ� 
void PostOrderNor(PBTNode pRoot);

// ������� 
void LevelOrder(PBTNode pRoot);

// ������������ 
void DetroyBinTree(PBTNode* pRoot);

// �������ľ���---�ǵݹ� 
void MirrorBinTreeNor(PBTNode pRoot);

// �������ľ���---�ݹ� 
void MirrorBinTree(PBTNode pRoot);

// ��������н��ĸ��� 
int BinTreeSize(PBTNode pRoot);

// ���������Ҷ�ӽ��ĸ��� 
int BinTreeLeaf(PBTNode pRoot);

// ��������е�K����ĸ��� 
int BinTreeKLevelNode(PBTNode pRoot, int K);

// ��������ĸ߶� 
int BinTreeHeight(PBTNode pRoot);

// �ڶ������в���ֵΪdata�Ľ�㣬�ҵ����ظý�㣬���򷵻ؿ� 
PBTNode Find(PBTNode pRoot, BTDataType data);

// ���һ���ڵ��Ƿ��ڶ������� 
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode);

// ���һ�����Ƿ�Ϊ��ȫ������ 
int IsCompleteBinTree(PBTNode pRoot);


void BTNodeCreate(BTDataType* array, PBTNode* pRoot, int length, int* index, BTDataType invalid);




void RebuildBTNode(PBTNode* pRoot, BTDataType* array1, BTDataType* array2, int length);

void swapBTNodeNode(PBTNode* node1, PBTNode* node2);
