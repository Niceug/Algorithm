package utils;

public class Util {
	private Util() {}
	
	// ��������������ֵ
	public static void swap(int[] arr, int index1, int index2) {
		int tmp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = tmp;
	}
	
	// ��ӡ����
	public static void printArr(int[] arr) {
		int len = arr.length;
		for (int i : arr) {
			System.out.print(i + " ");
		}
		System.out.println();
	}
	
	public static void clearArr(int[] arr) {
		for(int i = 0, len = arr.length; i < len; ++i) {
			arr[i] = 0;
		}
	}
	
	public static void copyArr(int[] src, int[] dest) {
		int len = src.length; 
		for(int i = 0; i < len; ++i) {
			dest[i] = src[i];
		}
	}
}
