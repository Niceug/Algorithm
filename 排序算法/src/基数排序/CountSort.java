package ��������;

import utils.Util;

public class CountSort{
	/**
	 * ��������
	 * @param arr
	 */
	public static void countSort(int[] arr) {
		int len = arr.length;
		int maxValue = arr[0];
		int minValue = arr[0];
		
		// �ҵ����䷶Χ
		for(int i = 1; i < len; ++i) {
			if(arr[i] > maxValue) {
				maxValue = arr[i];
			}
			if(arr[i] < minValue) {
				minValue = arr[i];
			}
		}
		
		// ��������ռ䣬�����ռ��С
		int proxyLen = maxValue - minValue;
		int[] proxy = new int[proxyLen + 1];
		
		// ����
		for(int i = 0; i < len; ++i) {
			proxy[arr[i] - minValue]++;
		}
		
		// ������ԭ����,��������Ϊԭ����Ԫ�ظ�����
		for(int j = 0, i = 0; j < len; ++i) {
			int count = proxy[i];
			while(count-- > 0) {
				arr[j++] = i + minValue;
			}
		}
	}
	
	public static void main(String[] args) {
//		int[] arr = new int[] {5, 5, 5, 5, 5, 5, 5, 5, 5};
		int[] arr = new int[] {17, 9, 14};
//		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 10};
//		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 5};
		Util.printArr(arr);
		countSort(arr);
		Util.printArr(arr);
	}
}
