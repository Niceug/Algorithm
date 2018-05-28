package Ñ¡ÔñÅÅÐò;

import utils.Util;

public class Test {
	public static void selectSort(int[] arr) {
		int len = arr.length;
		int max = 0;
		int min = 0;
		for(int i = len - 1; i >= 0; --i) {
			min = len - 1 - i;
			max = i;
			
			if(max == min)
				break;
			
			for(int j = len - 1 - i; j <= i; ++j) {
				if(arr[j] > arr[max])
					max = j;
				if(arr[j] < arr[min])
					min = j;
			}
			
			if(min != len - 1 - i) {
				Util.swap(arr, min, len - 1 - i);
				if(max == len - 1 - i)
					max = min;
			}
			
			if(max != i) {
				Util.swap(arr, max, i);
			}
		}
	}
	
	public static void main(String[] args) {
		int[] arr = new int[] {5, 5, 5, 5, 5, 5, 5, 5, 5};
//		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 0};
//		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 10};
//		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 5};
		int len = arr.length;
		Util.printArr(arr);
		selectSort(arr);
		Util.printArr(arr);
	}
}
