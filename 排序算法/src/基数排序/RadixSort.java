package ��������;

import utils.Util;

/**
 * ��������
 * @author Z7M-SL7D2
 */
public class RadixSort {
	
	private RadixSort() {}
	
	/**
	 * ��������LSD���ӵ�λ���λ��
	 * @param arr
	 */
	public static void radixSort(int[] arr){
		int len = arr.length;
		
		if(len <2)
			return;
		
		// ���λ��
		int digit = getDigit(arr);
		// ���ڴ�ų��ֵĴ���
		int[] proxy = new int[10];
		// ���ڴ����ʼ��ַ
		int[] startAddr = new int[10];
		// ��ʱ����ź��������
		int[] tmp = new int[len];
		// ����
		int times = 1;
		
		for(int k= 0; k < digit; ++k) {
			// �����ÿ��Ͱ�����ж��ٸ�Ԫ��
			for(int i = 0; i < len; ++i) {
				proxy[(arr[i] / times) % 10]++;
			}
			
			// ���ÿ��Ԫ���������ж�Ӧ����ʼ��ַ
			int sum = 0;
			for(int i = 1; i < 10; ++i) {
				sum += proxy[i - 1];
				startAddr[i] = sum;
			}
			
			// ����ʱ���鸳ֵ
			for(int i = 0; i < len; ++i) {
				int pos = ((arr[i] / times) % 10);
				tmp[startAddr[pos]++] = arr[i];
			}
			
			// ���˴��ź�������鿽����ԭ���顣
			Util.copyArr(tmp, arr);
			// ����ַ�������
			Util.clearArr(startAddr);
			// ��������������
			Util.clearArr(proxy);
			Util.printArr(tmp);
			times *= 10;
		}
	}
	
	/**
	 * ������ȡ�������λ���ĺ���
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
