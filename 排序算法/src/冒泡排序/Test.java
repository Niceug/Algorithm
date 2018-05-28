package √∞≈›≈≈–Ú;

import utils.Util;

public class Test {
	public static void bubbleSort(int[] arr) {
		
		for(int i = 0, len = arr.length; i < len; ++i) {
			boolean finish = true;
			for(int j = 0; j < len - i - 1; ++j) {
				if(arr[j] > arr[j + 1]) {
					finish = false;
					Util.swap(arr, j, j + 1);
				}
			}
			if(finish)
				break;
		}
	}
	public static void main(String[] args) {
//		int[] arr = new int[] {5, 5, 5, 5, 5, 5, 5, 5, 5};
//		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 0};
//		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 10};
		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 5};
		int len = arr.length;
		Util.printArr(arr);
		bubbleSort(arr);
		Util.printArr(arr);
	}
}
