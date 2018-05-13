#include <stdio.h>
#include <malloc.h>
#include "heap.h"

int main() {
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	if (heap == NULL)
		return 0;
	initHeap(heap);
	HeapDataType arr[] = {53, 17, 78, 9, 45, 65, 87, 23, 31};
	createHeap(heap, arr, sizeof(arr)/sizeof(arr[0]), Less);
	insertIntoHeap(heap, 5, Less);
	insertIntoHeap(heap, 50, Less);
	insertIntoHeap(heap, 13, Less);
	deleteFromHeap(heap, Less);
	printf("������\n");
	printHeap(heap);
	printf("\n��ȡ����5������Ԫ��\n");
	getDataFromGreatData(heap->array, heap->size, 5, Less);
	printf("\n������\n");
	heapSort(heap, Less);
	printHeap(heap);
	printf("\n");
	
	
	return 0;
}

void swap(HeapDataType* data1, HeapDataType* data2) {
	HeapDataType tmp = *data1;
	*data1 = *data2;
	*data2 = tmp;
}

void initHeap(Heap* heap) {
	if (heap == NULL)
		return;
	heap->array = (HeapDataType*)malloc(sizeof(HeapDataType)*INIT_HEAP_SIZE);
	heap->capacity = INIT_HEAP_SIZE;
	heap->size = 0;
	for (int i = 0; i < heap->capacity; i++) {
		heap->array[i] = 0;
	}
}

/**
����С���ѣ����ϵ�����
*/
void createHeap(Heap* heap, HeapDataType* arr, unsigned int len, Compare com) {
	if (heap == NULL)
		return;

	for (int i = 0; i < len; i++) {
		heap->array[i] = arr[i];
		heap->size++;
	}

	// �ҵ�����
	int flag = (len - 1) / 2;

	flag--;
	while (flag >= 0) {
		int parrent = flag;
		while (1) {

			int child = parrent * 2 + 1;
			if (child >= len)
				break;
			if (child + 1 >= len) {
				if (com(heap->array[child], heap->array[parrent])) {
					swap(&heap->array[child], &heap->array[parrent]);
					parrent = child;
					break;
				}
				else {
					break;
				}
			}

			// �����/С�����Һ���
			if (!com(heap->array[child], heap->array[child + 1])) {
				child++;
			}

			// ����ǰ�ڵ�����/С�ĺ��ӱȽϣ���������/С�ĺ���С/���򽻻���
			if (com(heap->array[child], heap->array[parrent])) {
				swap(&heap->array[child], &heap->array[parrent]);
				parrent = child;
			}
			else {
				break;
			}
		}
		flag--;
	}
}

// ����в���Ԫ�أ����ϵ�����
void insertIntoHeap(Heap* heap, HeapDataType insertData, Compare com) {

	// ��Ԫ�ط����β
	heap->size++;
	heap->array[heap->size - 1] = insertData;

	if (heap->size == 1)
		return;

	int child = heap->size - 1;
	while (1) {
		int parrent = (child - 1) / 2;

		//�����ǰԪ�رȸ�Ԫ��С���������ƶ�
		if (com(heap->array[child], heap->array[parrent])) {
			swap(&(heap->array[child]), &(heap->array[parrent]));
			child = parrent;
			if (parrent == 0)
				break;
		}
		else {
			break;
		}
	}
}

HeapDataType getHeapTop(Heap* heap) {
	if (!isEmptyHeap)
		return heap->array[0];
	return -1;
}

int isEmptyHeap(Heap* heap) {
	return heap->size == 0 ? 1 : 0;
}

// ɾ���Ѷ�Ԫ��
void deleteFromHeap(Heap* heap, Compare com) {
	if (heap == NULL)
		return;
	if (isEmptyHeap(heap))
		return;
	heap->size--;
	// �����һ��Ԫ�ظ�ֵ����һ��Ԫ��
	heap->array[0] = heap->array[heap->size];

	// ����Ԫ�ظ�ֵ��parrent
	int parrent = 0;
	// ���µ���
	while (1) {
		int child = parrent * 2 + 1;
		if (child >= heap->size)
			break;
		if (child + 1 >= heap->size) {
			if (com(heap->array[child], heap->array[parrent])) {
				swap(&heap->array[parrent], &heap->array[child]);
				parrent = child;
			}
			else {
				break;
			}
		}
		if (!com(heap->array[child], heap->array[child + 1])) {
			child++;
		}
		if (com(heap->array[child], heap->array[parrent])) {
			swap(&heap->array[parrent], &heap->array[child]);
			parrent = child;
		}
		else {
			break;
		}
	}
}

// ��ӡ����Ԫ��
void printHeap(Heap* heap) {
	int sum = 1;
	int j = 0;
	for (int i = 0; i < heap->size; i++) {
		if (i == sum - 1)
			for (int j = 0; j < heap->size - i; j++) {
				printf(" ");
			}
		else
			printf(" ");
		
		printf("%d", heap->array[i]);
		j++;
		if (sum == j) {
			printf("\n");
			sum *= 2;
			j = 0;
		}
		else if (i == 0)
			printf("\n");
	}
	printf("\n");
}

// ���ݲ��ң��Ӻܶ�������������������С��K������
void getDataFromGreatData(HeapDataType* arr, unsigned int len, unsigned int k, Compare com) {

	Heap* heap = (Heap*)malloc(sizeof(Heap));
	if (heap == NULL || k == 0 || len <= k)
		return;
	initHeap(heap);

	if (len <= k) {
		// ��ǰlen�����������
		createHeap(heap, arr, len, com);
		return;
	}

	// ��ǰK�����������
	createHeap(heap, arr, k, com);
	
	for (int i = k; i < len; i++) {
		// ��ȡ�Ѷ�Ԫ��
		HeapDataType top = getHeapTop(heap);
		if (top < arr[i]) {
			deleteFromHeap(heap, com);
			insertIntoHeap(heap, arr[i], com);
		}
	}

	printHeap(heap);
}

// �����򣬴Ӵ�С
void heapSort(Heap* heap, Compare com) {
	int end = heap->size - 1;
	while (end > 0) {
		swap(&heap->array[0], &heap->array[end]);
		--end;
		topDownHeap(heap, end, com);
	}
}

// С���ѵ����µ���
void topDownHeap(Heap* heap, int size, Compare com) {
	if (size == 0)
		return;
	int parrent = 0;
	int child = 0;
	while (1) {
		child = parrent * 2 + 1;
		if (child > size)
			break;
		if (child + 1 > size) {
			if(com(heap->array[child], heap->array[parrent]))
				swap(&heap->array[parrent], &heap->array[child]);
			break;
		}
		// �ҵ���������֮��Ƚϴ��
		if (!com(heap->array[child], heap->array[child + 1])) {
			child++;
		}
		// ���ڵ�����ĺ��ӱȽϣ�С������ӣ��򽻻�
		if (com(heap->array[child], heap->array[parrent])) {
			swap(&heap->array[parrent], &heap->array[child]);
			parrent = child;
		}
		else {
			break;
		}
	}
}

// ����Ԫ�رȽϵıȽ��� 
// С�ں� 
int Less(HeapDataType left, HeapDataType right) {
	return left < right ? 1 : 0;
}

// ���ں� 
int Greater(HeapDataType left, HeapDataType right) {
	return left > right ? 1 : 0;
}