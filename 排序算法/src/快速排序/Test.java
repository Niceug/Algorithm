package 快速排序;

import utils.Util;

public class Test {
	/**
	 * 获取中间元素
	 * @param arr
	 * @param left
	 * @param right
	 * @return
	 */
	public static int getMidIndex(int[] arr, int left, int right) {
		int mid = left + ((right - left)>>1);
		if(arr[mid] > arr[left]) {
			if(arr[left] > arr[right]) {
				return left;
			} else {
				if(arr[mid] > arr[right])
					return right;
				else 
					return mid;
			}
		} else {
			if(arr[left] > arr[right]) {
				if(arr[right] > arr[mid])
					return right;
				else {
					return mid;
				}
			} else {
				return left;
			}
		}
	}
	/**
	 * 前后指针法，cur是当前指针，pre总是指向小于key的元素，pre的下一个一定是大于key的元素，cur一直向后找，如果遇到比key小的，
	 * ++cur， ++pre
	 * 如果遇到比key大的，就只是cur++，pre不变，如果cur再次遇到比key小的，如果pre不等于cur，就交换pre的下一个元素和cur
	 * @param arr
	 * @param left
	 * @param right
	 */
	public static int split1(int[] arr, int left, int right) {
		int cur = left;
		int pre = left - 1;
		
		int mid = getMidIndex(arr, left, right - 1);
		Util.swap(arr, mid, right - 1);
		
		int key = arr[right - 1];
		while(cur < right) {
			// 看当前元素是否大于
			if(arr[cur] < key && ++pre != cur) {
				Util.swap(arr, cur, pre);
			}
			++cur;
		}
		
		// 交换pre的下一个和key
		if(++pre < right) {
			Util.swap(arr, pre, right - 1);
		}
		return pre;
	}
	
	/**
	 * 挖坑法
	 * 先将right所在位置设置为坑，并记录他的元素大小，作为一个分界（key），
	 * 然后left向右找，如果遇到了比key大的，则把当前元素赋值给坑，并把当前位置设置为坑，然后right向左找，如果遇到了
	 * 比key小的，就把当前元素赋值给坑，然后把当前位置设置为坑。
	 */
	public static int split2(int[] arr, int left, int right) {
		int begin = left;
		int end = right - 1;
		
		int mid = getMidIndex(arr, left, end);
		Util.swap(arr, mid, end);
		
		int key = arr[end];
		while(begin < end) {
			
			// 向后找
			while(begin < end && key > arr[begin]) {
				++begin;
			}
			
			// 当前位置设置为坑，然后把坑填住，并不再访问这个元素。
			if(begin < end) {
				arr[end] = arr[begin];
				--end;
			}
			
			// 向前找
			while(begin < end && key < arr[end]) {
				--end;
			}
			
			// 当前位置设置为坑，然后把坑填住，并不再访问这个元素。
			if(begin < end) {
				arr[begin] = arr[end];
				++begin;
			}
		}
		
		arr[begin] = key;
		
		return begin;
	}
	
	/**
	 * 聚合法，同时从两端开始找，左边找到大于key的，右边找到小于key的，然后交换这两个元素
	 * @param arr
	 * @param left
	 * @param right
	 * @return
	 */
	public static int split3(int[] arr, int left, int right) {
		int begin = left;
		int end = right - 1;
		
		int mid = getMidIndex(arr, left, end);
		Util.swap(arr, mid, end);
		
		int key = arr[end];
		while(begin < end) {
			// 向后找比key大的
			while(begin < end && arr[begin] <= key) {
				++begin;
			}
			// 向前找比key小的
			while(begin < end && arr[end] >= key) {
				--end;
			}
			// 交换两个找到的元素
			if(begin < end)
				Util.swap(arr, begin, end);
		}
		Util.swap(arr, begin, right - 1);
		return begin;
	}
	
	public static void quickSort(int[] arr, int left, int right) {
		// 大于一个元素才排序
		if(right > left) {
			int mid = split3(arr, left, right);
			Util.printArr(arr);
			quickSort(arr, left, mid);
			quickSort(arr, mid + 1, right);
		}
	}
	
	public static void main(String[] args) {
		//int[] arr = new int[] {5, 5, 5, 5, 5, 5, 5, 5, 5};
		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 0};
		//int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 10};
//		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 5};
		int len = arr.length;
		Util.printArr(arr);
		quickSort(arr, 0, len);
		Util.printArr(arr);
	}
}
