package �鲢����;

import utils.Util;

public class Test {
	public static void mergeSort(int[] arr) {
		int len = arr.length;
		int left = 0, right = len;
		int[] tmp = new int[len];
		_mergeSort(arr, left, right, tmp);
	}
	
	/**
	 * �����ݽ��з���
	 * @param arr ����
	 * @param left
	 * @param right
	 * @param tmp ��ʱ����
	 */
	public static void _mergeSort(int[] arr, int left, int right, int[] tmp) {
		if(right - left > 1) {
			// ����mid
			int mid = left + ((right - left) >> 1);
			// ����ߵ����ݽ��з���
			_mergeSort(arr, left, mid, tmp);
			// ���ұߵ����ݽ��з���
			_mergeSort(arr, mid, right, tmp);
			// �ϲ����������ֺ��������
			mergeData(arr, left, mid, right, tmp);
			// ��tmp���鿽����arr
			copyArray(tmp, arr, left, right);
		}
	}
	
	/**
	 * ��������֮������ݽ��кϲ���Ȼ��ŵ�tmp��������ȥ
	 * @param arr ��������
	 * @param left ���������߽�
	 * @param mid ��������ұ߽磬����������Ϊ���������߽�ʱ����
	 * @param right ��������ұ߽�
	 * @param tmp ��ŵ�ǰ�źõ����С�
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
	 * ��������
	 * @param src ����������
	 * @param dest Ŀ������
	 * @param start ������ʼ��
	 * @param end �����յ㣬�����䡣
	 */
	public static void copyArray(int[] src, int[] dest, int start,  int end) {
		for(int i = start; i < end; ++i) {
			dest[i] = src[i];
		}
	}
	
	// �ǵݹ�汾�Ĺ鲢����
	public static void mergeSortNor(int[] arr) {
		// �鲢���
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
