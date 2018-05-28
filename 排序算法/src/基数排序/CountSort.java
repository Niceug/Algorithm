package 基数排序;

import utils.Util;

public class CountSort{
	/**
	 * 计数排序
	 * @param arr
	 */
	public static void countSort(int[] arr) {
		int len = arr.length;
		int maxValue = arr[0];
		int minValue = arr[0];
		
		// 找到区间范围
		for(int i = 1; i < len; ++i) {
			if(arr[i] > maxValue) {
				maxValue = arr[i];
			}
			if(arr[i] < minValue) {
				minValue = arr[i];
			}
		}
		
		// 申请计数空间，计数空间大小
		int proxyLen = maxValue - minValue;
		int[] proxy = new int[proxyLen + 1];
		
		// 计数
		for(int i = 0; i < len; ++i) {
			proxy[arr[i] - minValue]++;
		}
		
		// 拷贝回原数组,拷贝次数为原数组元素个数次
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
