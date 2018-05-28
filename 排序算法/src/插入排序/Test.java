package ��������;

import utils.Util;

public class Test {
	
	// �����Ĳ�������,gap����1
	public static void insertSort(int[] arr, int gap) {
		int len = arr.length;
		for(int i = gap; i < len; i += gap) {
			int key = arr[i];
			while(i - gap >= 0 && arr[i - gap] > key) {
				arr[i] = arr[i - gap];
				i -= gap;
			}
			arr[i] = key;
		}
	}
	
	// ���ֲ�������
	public static void insertSortBinary(int[] arr) {
		int len = arr.length;
		for(int i = 1; i < len; ++i) {
			int key = arr[i];
			// ���ֲ��ҽڵ�����λ��
			int left = 0;
			int right = i - 1;
			while(left < right) {
				// �м�ڵ�
				int mid = (left + right) / 2;
				if(key > arr[mid]) {
					left = mid + 1;
				}
				
				if(key < arr[mid]) {
					right = mid - 1;
				}
			}
			
			//�ڵ�����ƶ���
			for(int j = i; j > left + 1; --j) {
				arr[j] = arr[j - 1];
			}
			arr[left + 1] = key;
		}
	}
	
	// ϣ������gap�Ǳ仯��
	public static void shellSort(int[] arr) {
		int len = arr.length;
		for(int gap = len/2 + 1; gap > 0; --gap) {
			System.out.println(gap);
			insertSort(arr, gap);
			Util.printArr(arr);
		}
	}
	
	public static void main(String[] args) {
		//int[] arr = new int[] {5, 5, 5, 5, 5, 5, 5, 5, 5};
		//int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 0};
		//int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 10};
		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 5};
		int len = arr.length;
		Util.printArr(arr);
		insertSortBinary(arr);
		Util.printArr(arr);
}
}
