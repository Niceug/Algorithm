package 基数排序;

import utils.Util;

/**
 * 基数排序
 * @author Z7M-SL7D2
 */
public class RadixSort {
	
	private RadixSort() {}
	
	/**
	 * 基数排序，LSD，从低位向高位排
	 * @param arr
	 */
	public static void radixSort(int[] arr){
		int len = arr.length;
		
		if(len <2)
			return;
		
		// 求出位数
		int digit = getDigit(arr);
		// 用于存放出现的次数
		int[] proxy = new int[10];
		// 用于存放起始地址
		int[] startAddr = new int[10];
		// 临时存放排好序的数组
		int[] tmp = new int[len];
		// 倍数
		int times = 1;
		
		for(int k= 0; k < digit; ++k) {
			// 先求出每个桶里面有多少个元素
			for(int i = 0; i < len; ++i) {
				proxy[(arr[i] / times) % 10]++;
			}
			
			// 求出每个元素在数组中对应的起始地址
			int sum = 0;
			for(int i = 1; i < 10; ++i) {
				sum += proxy[i - 1];
				startAddr[i] = sum;
			}
			
			// 给临时数组赋值
			for(int i = 0; i < len; ++i) {
				int pos = ((arr[i] / times) % 10);
				tmp[startAddr[pos]++] = arr[i];
			}
			
			// 将此次排好序的数组拷贝回原数组。
			Util.copyArr(tmp, arr);
			// 将地址数组清空
			Util.clearArr(startAddr);
			// 存个数的数组清空
			Util.clearArr(proxy);
			Util.printArr(tmp);
			times *= 10;
		}
	}
	
	/**
	 * 用来获取数组最大位数的函数
	 * @param arr
	 * @return
	 */
	public static int getDigit(int[] arr) {
		int len = arr.length;
		int count = 1;
		int times = 10;
		for(int i = 0; i <len; ++i) {
			if(arr[i] > times) {
				times *= 10;
				++count;
			}
		}
		
		return count;
	}
	
	public static void main(String[] args) {
		int[] arr = new int[] {998, 99, 479, 471, 325, 512, 477, 890, 367};
		Util.printArr(arr);
		radixSort(arr);
	}
}
