package com.ltp.utils;


public class Util {
	private Util() {}
	
	// 交换两个变量的值
	public static void swap(int[] arr, int index1, int index2) {
		int tmp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = tmp;
	}
	
	// 打印数组
	public static void printArr(int[] arr) {
		int len = arr.length;
		for (int i : arr) {
			System.out.print(i + " ");
		}
		System.out.println();
	}
}
