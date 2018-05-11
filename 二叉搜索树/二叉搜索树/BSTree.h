typedef char* String;


// 字符串ip转int
typedef union IPCast {
	unsigned int ip;
	struct {
		unsigned char str[4];
	}strip;
}IPCast;

typedef struct IP {
	unsigned int ip; // ip地址
	unsigned int count; // 出现的次数
}IP;

typedef struct IP* IPDataType;
// 二叉搜索树（二叉排序树）
typedef struct BSTreeIPNode {
	struct IP ip;
	struct BSTreeNode* LChild;
	struct BSTreeNode* RChild;
}BSTreeIPNode;


typedef int BSTreeDataType;
// 二叉搜索树（二叉排序树）
typedef struct BSTreeNode {
	BSTreeDataType data;
	struct BSTreeNode* LChild;
	struct BSTreeNode* RChild;
}BSTreeNode;

// 搜索节点
BSTreeNode* findBSTreeNode(BSTreeNode* pRoot, BSTreeDataType data);
// 非递归搜索节点
BSTreeNode* findBSTreeNodeNor(BSTreeNode* pRoot, BSTreeDataType data);
// 插入节点
int insertBSTreeNode(BSTreeNode** pRoot, BSTreeDataType data);
// 非递归插入节点
int insertBSTreeNodeNor(BSTreeNode** pRoot, BSTreeDataType data);
// 删除节点
void deleteBSTreeNode(BSTreeNode** pRoot, BSTreeDataType data);
// 中序遍历二叉排序树
void inOrderBSTree(BSTreeNode* pRoot);
// 销毁二叉排序树
void destroyBSTreeNode(BSTreeNode** pRoot);
// 获取节点
BSTreeNode* buyBSTreeNode(BSTreeDataType data);



// 二叉树的应用之检测一个单词是否拼写正确
typedef struct BSTreeAppNode {
	String word;
	struct BSTreeAppNode* LChild;
	struct BSTreeAppNode* RChild;
}BSTreeAppNode;

// 判断一个单词是否拼写正确
int isCorrectSpelling(BSTreeAppNode* pRoot, String word);



