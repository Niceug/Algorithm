typedef char BTDataType;

typedef struct BTNode {
	BTDataType data;
	struct BTNode* LChild;
	struct BTNode* RChild;
}*PBTNode, BTNode;

// 二叉树创建 
void CreateBinTree(PBTNode* pRoot, BTDataType array[], int size);

// 二叉树拷贝 
void CopyBinTree(PBTNode pRoot, PBTNode* newRoot);

// 前序遍历---递归 
void PreOrder(PBTNode pRoot);

// 前序遍历---非递归 
void PreOrderNor(PBTNode pRoot);

// 中序遍历---递归 
void InOrder(PBTNode pRoot);

// 中序遍历---非递归 
void InOrderNor(PBTNode pRoot);

// 后续遍历---递归 
void PostOrder(PBTNode pRoot);

// 后续遍历---非递归 
void PostOrderNor(PBTNode pRoot);

// 层序遍历 
void LevelOrder(PBTNode pRoot);

// 二叉树的销毁 
void DetroyBinTree(PBTNode* pRoot);

// 二叉树的镜像---非递归 
void MirrorBinTreeNor(PBTNode pRoot);

// 二叉树的镜像---递归 
void MirrorBinTree(PBTNode pRoot);

// 求二叉树中结点的个数 
int BinTreeSize(PBTNode pRoot);

// 求二叉树中叶子结点的个数 
int BinTreeLeaf(PBTNode pRoot);

// 求二叉树中第K层结点的个数 
int BinTreeKLevelNode(PBTNode pRoot, int K);

// 求二叉树的高度 
int BinTreeHeight(PBTNode pRoot);

// 在二叉树中查找值为data的结点，找到返回该结点，否则返回空 
PBTNode Find(PBTNode pRoot, BTDataType data);

// 检测一个节点是否在二叉树中 
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode);

// 检测一棵树是否为完全二叉树 
int IsCompleteBinTree(PBTNode pRoot);


void BTNodeCreate(BTDataType* array, PBTNode* pRoot, int length, int* index, BTDataType invalid);




void RebuildBTNode(PBTNode* pRoot, BTDataType* array1, BTDataType* array2, int length);

void swapBTNodeNode(PBTNode* node1, PBTNode* node2);
