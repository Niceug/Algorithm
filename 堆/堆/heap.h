#pragma once
#define INIT_HEAP_SIZE 20
typedef int HeapDataType;
typedef struct Heap {
	HeapDataType* array;
	unsigned int capacity;
	unsigned int size;
}Heap;
typedef int(*Compare)(int x, int y);
// ��ʼ����
void initHeap(Heap* heap);
// ��ӡ�ѵ�Ԫ��
void printHeap(Heap* heap);
// ��������Ԫ��
void swap(HeapDataType* data1, HeapDataType* data2);
// ������
void createHeap(Heap* heap, HeapDataType* arr, unsigned int len, Compare com);
// ����в���Ԫ��
void insertIntoHeap(Heap* heap, HeapDataType data, Compare com);
// ��ȡ�Ѷ�Ԫ��
HeapDataType getHeapTop(Heap* heap);
// ɾ���Ѷ�Ԫ��
void deleteFromHeap(Heap* heap, Compare com);
// �ж��ǲ��ǿն�
int isEmptyHeap(Heap* heap);
// С��ѵ����µ���
void topDownHeap(Heap* heap, int size, Compare com);
// ������
void heapSort(Heap* heap, Compare com);

// ����Ԫ�رȽϵıȽ��� 
// С�ں� 
int Less(HeapDataType left, HeapDataType right);

// ���ں� 
int Greater(HeapDataType left, HeapDataType right);

// ���ݲ��ң��Ӻܶ�������������������С��K������
void getDataFromGreatData(HeapDataType* arr, unsigned int len, unsigned int k);