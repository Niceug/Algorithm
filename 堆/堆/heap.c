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
	printf("构建堆\n");
	printHeap(heap);
	printf("\n获取堆中5个最大的元素\n");
	getDataFromGreatData(heap->array, heap->size, 5, Less);
	printf("\n堆排序\n");
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
创建小根堆（向上调整）
*/
void createHeap(Heap* heap, HeapDataType* arr, unsigned int len, Compare com) {
	if (heap == NULL)
		return;

	for (int i = 0; i < len; i++) {
		heap->array[i] = arr[i];
		heap->size++;
	}

	// 找到零界点
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

			// 找最大/小的左右孩子
			if (!com(heap->array[child], heap->array[child + 1])) {
				child++;
			}

			// 将当前节点和最大/小的孩子比较，如果比最大/小的孩子小/大则交换。
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

// 向堆中插入元素（向上调整）
void insertIntoHeap(Heap* heap, HeapDataType insertData, Compare com) {

	// 将元素放入堆尾
	heap->size++;
	heap->array[heap->size - 1] = insertData;

	if (heap->size == 1)
		return;

	int child = heap->size - 1;
	while (1) {
		int parrent = (child - 1) / 2;

		//如果当前元素比父元素小，就向上移动
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

// 删除堆顶元素
void deleteFromHeap(Heap* heap, Compare com) {
	if (heap == NULL)
		return;
	if (isEmptyHeap(heap))
		return;
	heap->size--;
	// 将最后一个元素赋值给第一个元素
	heap->array[0] = heap->array[heap->size];

	// 将根元素赋值给parrent
	int parrent = 0;
	// 向下调整
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

// 打印数组元素
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

// 数据查找（从很多个数里面查找最大或者最小的K个数）
void getDataFromGreatData(HeapDataType* arr, unsigned int len, unsigned int k, Compare com) {

	Heap* heap = (Heap*)malloc(sizeof(Heap));
	if (heap == NULL || k == 0 || len <= k)
		return;
	initHeap(heap);

	if (len <= k) {
		// 将前len个数插入堆中
		createHeap(heap, arr, len, com);
		return;
	}

	// 将前K个数插入堆中
	createHeap(heap, arr, k, com);
	
	for (int i = k; i < len; i++) {
		// 获取堆顶元素
		HeapDataType top = getHeapTop(heap);
		if (top < arr[i]) {
			deleteFromHeap(heap, com);
			insertIntoHeap(heap, arr[i], com);
		}
	}

	printHeap(heap);
}

// 堆排序，从大到小
void heapSort(Heap* heap, Compare com) {
	int end = heap->size - 1;
	while (end > 0) {
		swap(&heap->array[0], &heap->array[end]);
		--end;
		topDownHeap(heap, end, com);
	}
}

// 小根堆的向下调整
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
		// 找到两个孩子之间比较大的
		if (!com(heap->array[child], heap->array[child + 1])) {
			child++;
		}
		// 父节点和最大的孩子比较，小于最大孩子，则交换
		if (com(heap->array[child], heap->array[parrent])) {
			swap(&heap->array[parrent], &heap->array[child]);
			parrent = child;
		}
		else {
			break;
		}
	}
}

// 用于元素比较的比较器 
// 小于号 
int Less(HeapDataType left, HeapDataType right) {
	return left < right ? 1 : 0;
}

// 大于好 
int Greater(HeapDataType left, HeapDataType right) {
	return left > right ? 1 : 0;
}