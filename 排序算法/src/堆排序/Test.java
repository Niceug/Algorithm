package 堆排序;

import utils.Util;

import java.util.List;
import java.util.LinkedList;
import java.util.Scanner;

public class Test {
	// 建堆
	public static void buildHeap(int[] arr) {
		int len = arr.length;
		int parrent = (len - 2) >> 1; //第一个非叶子节点
		while(parrent >= 0) {
			adapter(arr, len, parrent);
			--parrent;
		}
	}
	
	// 堆排序
	public static void heapSort(int[] arr) {
		buildHeap(arr);
		for(int i = arr.length - 1; i > 0; --i) {
			Util.swap(arr, 0, i);
			adapter(arr, i, 0); 
		}
	}
	
	// 向下调整, len为开区间
	public static void adapter(int[] arr, int len, int parrent) {
		int child = 0;
		while(true) {
			child = parrent * 2 + 1;
			if(child >= len)
				break;
			// 找最大的孩子
			if(child + 1 < len && arr[child + 1] > arr[child])
				++child;
			// 判断最大的孩子是否大于parrent
			if(arr[parrent] < arr[child]) {
				Util.swap(arr, parrent, child);
				parrent = child;
			} else {
				break;
			}
		}
	}
	
	public static int getAppearenceOnce(String str){
        if(str == null || "".equals(str))
            return -1;
        int len = str.length();
        if(len == 1)
            return str.charAt(0);
        byte[] arr = new byte[256];
        
        for(int i = 0; i < len; ++i){
            char c = str.charAt(i);
            arr[c]++;
        }
        
        for(int i = 0; i < len; ++i){
            char c = str.charAt(i);
            if(arr[c] == 1)
                return c;
        }
        return -1;
    }
	
//	public static void MoreThanHalfNum_Solution(int[] arr) {
//		List<Integer> list = new LinkedList<>();
//		int len = arr.length;
//		for(int i = 0; i < len - 1; ++i) {
//			if(arr[i] != arr[i + 1]) {
//				arr[]
//			}
//		}
//	}
	
	public static int MoreThanHalfNum_Solution(int [] array) {
        int len = array.length;
        int count = 1;
        int cur = array[0];
        for(int i = 1; i < len; ++i){
            if(count == 0){
                cur = array[i];
                count = 1;
            }
            else if(cur == array[i])
                ++count;
            else{
                --count;
            }
        }
        
        count = 0;
        for(int i = 0; i < len; ++i){
            if(cur == array[i]){
                ++count;
            }
        }
        if(count >= len/2 + 1)
            return cur;
        else 
            return 0;
        
    }
	
    public static void main(String[] args){
    	int ret = MoreThanHalfNum_Solution(new int[] {1, 2, 5, 2, 3 ,2, 2, 2});
    	System.out.println(ret);
//    	Scanner input = new Scanner(System.in);
//        String str;
//        while(true){
//            str = input.next();
//            if(str != null && ("".equals(str) == false))
//                break;
//        }
//        
//        String str1 = "-1";
//        System.out.println((char)(~1));
//        int ret = getAppearenceOnce(str);
//        if(ret == -1)
//            System.out.println(-1);
//        else {
//            System.out.println((char)ret);
//        }
    }

//	public static void main(String[] args) {
////		int[] arr = new int[] {5, 5, 5, 5, 5, 5, 5, 5, 5};
////		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 0};
////		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 10};
//		int[] arr = new int[] {5, 7, 4, 1, 8, 7, 4, 3, 5};
//		Util.printArr(arr);
//		heapSort(arr);
//		Util.printArr(arr);
//	}
}
