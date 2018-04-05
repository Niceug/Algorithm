#include <stdio.h>


//����������������С�����ͽ�����
//ѡ�������ҵ���С������ֻ��¼�±꣬�����潻��������Ƶ������
//ð������һֱ�������������������������

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
	printf("�ȽϵĴ���Ϊ%d\n", count);
}


//ѡ�������Ż�
void selectSort(int arr[], int len) {
	//��¼�Ƚϴ���
	int count = 0;
	int min = 0;
	int max = 0;
	int length = len - 1;
	for (int i = 0; i < len/2; i++, length--) {
		min = i;
		max = length;
		for (int j = i + 1; j <= length; j++) {
			count++;
			//�ҳ���СԪ�������±�
			if (arr[min] > arr[j]) {
				min = j;
			}

			//�ҳ����Ԫ�������±�
			if (arr[max] < arr[j])
				max = j;
		}

		if (min != i) {
			//������С�ĵ�ǰ��
			int tempMin = arr[min];
			arr[min] = arr[i];
			arr[i] = tempMin;
		}
		
		if (max != length) {
			//�������ĵ������
			int tempMax = arr[max];
			arr[max] = arr[length];
			arr[length] = tempMax;
		}
	}
	printf("�Ƚϴ���Ϊ%d\n", count);
}

//�������򡣶����������Ҫ����n�ν�������������ֻ��Ҫһ�ν�����
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
	printf("�Ƚϴ���Ϊ%d\n", count);
}


//�鲢����
void mergeSort(int arr[], int len) {
	int* arrTemp = (int *)malloc(sizeof(int)*len);

	//������������Ӧ�ô��ڵ����������
	int ElemSize = 2;
	while (len > ElemSize) {
		ElemSize *= 2;
	}

	for (int i = 2; i <= ElemSize; i *= 2) {
		int desc = 0;

		//�������������
		float f_MaxGroupCount = len / (float)i;
		int MaxGroupCount = f_MaxGroupCount;
		if (f_MaxGroupCount - MaxGroupCount > 0.001) {
			++MaxGroupCount;
		}
		
		//���飬��i�ֳ�j��

		for (int j = 0; j < MaxGroupCount; j++) {

			//�ֱ�������¼�鲢���������ڵ����λ��
			int one = 0;
			int two = 0;
			
			//ÿ�����ڵĵ�һ��Ԫ��
			int start = i*j;
			//ÿ�����ڷֽ��ߣ�������� + �յ� / 2
			int divide = i*(2 * j + 1) / 2;
			//ÿ�����ڵ����һ��Ԫ��
			int last = i * (j + 1);

			//�������������һ��Ԫ��������߽�֮������
			if (last > len) {
				last = len - 1;
			}

			//�������ڵĹ鲢����
			while (1) {

				//�����м�Ԫ��λ�ô�������߽�֮������
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
				

				//ʣ�µ�Ԫ��ֱ�ӷŵ�temp��������ȥ
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

				//ʣ�µ�Ԫ��ֱ�ӷŵ�temp��������ȥ
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

		//�������ź�������鸳ֵ��ԭ����
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