package 归并排序;

import utils.Util;

public class Test {
	public static void mergeSort(int[] arr) {
		int len = arr.length;
		int left = 0, right = len;
		int[] tmp = new int[len];
		_mergeSort(arr, left, right, tmp);
	}
	
	/**
	 * 对数据进行分组
	 * @param arr 数据
	 * @param left
	 * @param right
	 * @param tmp 临时数组
	 */
	public static void _mergeSort(int[] arr, int left, int right, int[] tmp) {
		if(right - left > 1) {
			// 先求mid
			int mid = left + ((right - left) >> 1);
			// 将左边的数据进行分组
			_mergeSort(arr, left, mid, tmp);
			// 将右边的数据进行分组
			_mergeSort(arr, mid, right, tmp);
			// 合并左右两个分好组的数据
			mergeData(arr, left, mid, right, tmp);
			// 将tmp数组拷贝给arr
			copyArray(tmp, arr, left, right);
		}
	}
	
	/**
	 * 对两区间之间的数据进行合并，然后放到tmp数组里面去
	 * @param arr 待排序列
	 * @param left 左区间的左边界
	 * @param mid 左区间的右边界，不包含，作为右区间的左边界时包含
	 * @param right 右区间的右边界
	 * @param tmp 存放当前排好的序列。
	 */
	public static void mergeData(int[] arr, int left, int mid, int right, int[] tmp) {
		int len = tmp.length;
		int i = left;
		int cur = mid;
		while(i < len) {
			if (arr[left] <= arr[cur]) {
				tmp[i++] = arr[left++];
			} else {
				tmp[i++] = arr[cur++];
			}
			
			if(left == mid) {
				while(cur < right) {
					tmp[i++] = arr[cur++];
				}
				break;
			}
			if(cur == right) {
				while(left < mid) {
					tmp[i++] = arr[left++];
				}
				break;
			}
			
		}
	}
	
	/**
	 * 拷贝数组
	 * @param src 待拷贝数组
	 * @param dest 目的数组
	 * @param start 拷贝起始点
	 * @param end 拷贝终点，开区间。
	 */
	public static void copyArray(int[] src, int[] dest, int start,  int end) {
		for(int i = start; i < end; ++i) {
			dest[i] = src[i];
		}
	}
	
	// 非递归版本的归并排序
	public static void mergeSortNor(int[] arr) {
		// 归并间隔
		int gap = 1;
		int len = arr.length;
		int[] tmp = new int[len];
		while(gap < len) {
			for(int i = 0; i < len; i += (2*gap)) {
				int left = i;
				int right = i + gap;
				if(right > len)
					right = len;
				int mid = left + ((right - left) >> 1);
				mergeData(arr, left, mid, right, tmp);
				copyArray(tmp, arr, left, right);
				Util.printArr(tmp);
			}
			gap *= 2;
		}
		
	}
	
	public static void main(String[] args) {
//		int[] arr = new int[] {5, 5, 5, 5, 5, 5, 5, 5, 5};
		int[] arr = new int[] {7, 2, 4, 1, 8, 5, 6, 9, 3};
//		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 10};
//		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 5};
		Util.printArr(arr);
		mergeSortNor(arr);
		Util.printArr(arr);
	}
}
