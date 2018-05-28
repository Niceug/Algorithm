package ��������;

import utils.Util;

public class Test {
	/**
	 * ��ȡ�м�Ԫ��
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
	 * ǰ��ָ�뷨��cur�ǵ�ǰָ�룬pre����ָ��С��key��Ԫ�أ�pre����һ��һ���Ǵ���key��Ԫ�أ�curһֱ����ң����������keyС�ģ�
	 * ++cur�� ++pre
	 * ���������key��ģ���ֻ��cur++��pre���䣬���cur�ٴ�������keyС�ģ����pre������cur���ͽ���pre����һ��Ԫ�غ�cur
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
			// ����ǰԪ���Ƿ����
			if(arr[cur] < key && ++pre != cur) {
				Util.swap(arr, cur, pre);
			}
			++cur;
		}
		
		// ����pre����һ����key
		if(++pre < right) {
			Util.swap(arr, pre, right - 1);
		}
		return pre;
	}
	
	/**
	 * �ڿӷ�
	 * �Ƚ�right����λ������Ϊ�ӣ�����¼����Ԫ�ش�С����Ϊһ���ֽ磨key����
	 * Ȼ��left�����ң���������˱�key��ģ���ѵ�ǰԪ�ظ�ֵ���ӣ����ѵ�ǰλ������Ϊ�ӣ�Ȼ��right�����ң����������
	 * ��keyС�ģ��Ͱѵ�ǰԪ�ظ�ֵ���ӣ�Ȼ��ѵ�ǰλ������Ϊ�ӡ�
	 */
	public static int split2(int[] arr, int left, int right) {
		int begin = left;
		int end = right - 1;
		
		int mid = getMidIndex(arr, left, end);
		Util.swap(arr, mid, end);
		
		int key = arr[end];
		while(begin < end) {
			
			// �����
			while(begin < end && key > arr[begin]) {
				++begin;
			}
			
			// ��ǰλ������Ϊ�ӣ�Ȼ��ѿ���ס�������ٷ������Ԫ�ء�
			if(begin < end) {
				arr[end] = arr[begin];
				--end;
			}
			
			// ��ǰ��
			while(begin < end && key < arr[end]) {
				--end;
			}
			
			// ��ǰλ������Ϊ�ӣ�Ȼ��ѿ���ס�������ٷ������Ԫ�ء�
			if(begin < end) {
				arr[begin] = arr[end];
				++begin;
			}
		}
		
		arr[begin] = key;
		
		return begin;
	}
	
	/**
	 * �ۺϷ���ͬʱ�����˿�ʼ�ң�����ҵ�����key�ģ��ұ��ҵ�С��key�ģ�Ȼ�󽻻�������Ԫ��
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
			// ����ұ�key���
			while(begin < end && arr[begin] <= key) {
				++begin;
			}
			// ��ǰ�ұ�keyС��
			while(begin < end && arr[end] >= key) {
				--end;
			}
			// ���������ҵ���Ԫ��
			if(begin < end)
				Util.swap(arr, begin, end);
		}
		Util.swap(arr, begin, right - 1);
		return begin;
	}
	
	public static void quickSort(int[] arr, int left, int right) {
		// ����һ��Ԫ�ز�����
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
