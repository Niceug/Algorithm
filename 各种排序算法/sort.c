#include <stdio.h>


//交换排序：遇到比他小的数就交换。
//选择排序：找到最小的数，只记录下标，在外面交换，不用频繁交换
//冒泡排序：一直交换，把最大的数交换到最后面

void bubbleSort(int arr[], int len) {
	int state = 0;
	int count = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 1; j < len - i; j++) {
			count++;
			if (arr[j] < arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				state = 1;
			}
		}
		if (state == 0)
			break;
		state = 0;
	}
	printf("比较的次数为%d\n", count);
}


//选择排序优化
void selectSort(int arr[], int len) {
	//记录比较次数
	int count = 0;
	int min = 0;
	int max = 0;
	int length = len - 1;
	for (int i = 0; i < len/2; i++, length--) {
		min = i;
		max = length;
		for (int j = i + 1; j <= length; j++) {
			count++;
			//找出最小元素所在下标
			if (arr[min] > arr[j]) {
				min = j;
			}

			//找出最大元素所在下标
			if (arr[max] < arr[j])
				max = j;
		}

		if (min != i) {
			//交换最小的到前面
			int tempMin = arr[min];
			arr[min] = arr[i];
			arr[i] = tempMin;
		}
		
		if (max != length) {
			//交换最大的到最后面
			int tempMax = arr[max];
			arr[max] = arr[length];
			arr[length] = tempMax;
		}
	}
	printf("比较次数为%d\n", count);
}

//插入排序。对于数组可能要进行n次交换，对于链表只需要一次交换。
void insertSort(int arr[], int len) {
	int count = 0;
	//int min = 0;
	for (int i = 1; i < len; i++) {
		//min = i;
		for (int j = i; j > 0; j--) {
			count++;
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
			else {
				break;
			}
			//min--;
		}
	}
	printf("比较次数为%d\n", count);
}


//归并排序
void mergeSort(int arr[], int len) {
	int* arrTemp = (int *)malloc(sizeof(int)*len);

	//处理分组个数，应该大于等于数组个数
	int ElemSize = 2;
	while (len > ElemSize) {
		ElemSize *= 2;
	}

	for (int i = 2; i <= ElemSize; i *= 2) {
		int desc = 0;

		//处理最大分组个数
		float f_MaxGroupCount = len / (float)i;
		int MaxGroupCount = f_MaxGroupCount;
		if (f_MaxGroupCount - MaxGroupCount > 0.001) {
			++MaxGroupCount;
		}
		
		//分组，按i分成j组

		for (int j = 0; j < MaxGroupCount; j++) {

			//分别用来记录归并的两个组内的相对位置
			int one = 0;
			int two = 0;
			
			//每个组内的第一个元素
			int start = i*j;
			//每个组内分界线；等于起点 + 终点 / 2
			int divide = i*(2 * j + 1) / 2;
			//每个组内的最后一个元素
			int last = i * (j + 1);

			//处理计算出的最后一个元素在数组边界之外的情况
			if (last > len) {
				last = len - 1;
			}

			//具体组内的归并排序
			while (1) {

				//处理中间元素位置处于数组边界之外的情况
				if (divide >= len) {
					while (start + one < len) {
						arrTemp[desc] = arr[start + one];
						one++;
						desc++;
					}
					break;
				}

				if (arr[start + one] > arr[divide + two]) {
					arrTemp[desc] = arr[divide + two];
					two++;
					desc++;
				}
				else {
					arrTemp[desc] = arr[start + one];
					one++;
					desc++;
				}
				

				//剩下的元素直接放到temp数组里面去
				if (start + one == divide)
				{
					while (1) {
						if (divide + two >= last)
							break;
						arrTemp[desc] = arr[divide + two];
						desc++;
						two++;
					}
					break;
				}

				//剩下的元素直接放到temp数组里面去
				if (divide + two == last)
				{
					while (1) {
						if (start + one >= divide)
							break;
						arrTemp[desc] = arr[start + one];
						desc++;
						one++;
					}
					break;
				}
			}
		}

		//将本次排好序的数组赋值给原数组
		for (int j = 0; j < len; j++) {
			arr[j] = arrTemp[j];
		}
	}
}

int main() {
	int arr[10] = {1, 8, 10, 4, 5, 3, 5, 8, 9, 10};
	int len = sizeof(arr) / sizeof(arr[0]);
	//selectSort(arr, 10);
	//bubbleSort(arr, 10);
	//insertSort(arr, 10);
	mergeSort(arr, len);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}