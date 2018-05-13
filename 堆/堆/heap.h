#pragma once
#define INIT_HEAP_SIZE 20
typedef int HeapDataType;
typedef struct Heap {
	HeapDataType* array;
	unsigned int capacity;
	unsigned int size;
}Heap;
typedef int(*Compare)(int x, int y);
// 初始化堆
void initHeap(Heap* heap);
// 打印堆的元素
void printHeap(Heap* heap);
// 交换两个元素
void swap(HeapDataType* data1, HeapDataType* data2);
// 创建堆
void createHeap(Heap* heap, HeapDataType* arr, unsigned int len, Compare com);
// 向堆中插入元素
void insertIntoHeap(Heap* heap, HeapDataType data, Compare com);
// 获取堆顶元素
HeapDataType getHeapTop(Heap* heap);
// 删除堆顶元素
void deleteFromHeap(Heap* heap, Compare com);
// 判断是不是空堆
int isEmptyHeap(Heap* heap);
// 小项堆的向下调整
void topDownHeap(Heap* heap, int size, Compare com);
// 堆排序
void heapSort(Heap* heap, Compare com);

// 用于元素比较的比较器 
// 小于号 
int Less(HeapDataType left, HeapDataType right);

// 大于好 
int Greater(HeapDataType left, HeapDataType right);

// 数据查找（从很多个数里面查找最大或者最小的K个数）
void getDataFromGreatData(HeapDataType* arr, unsigned int len, unsigned int k);