package com.ltp.isstacklist;

import java.util.Stack;

public class CheckIsStack {
	public boolean isStackSeq(int[] pushA, int[] popA) {
		Stack<Integer> stack = new Stack<>();
		int pushIndex = 0;
		int popIndex = 0;
		
		int pushLen = pushA.length;
		int popLen = popA.length;
		
		if(pushLen != popLen)
			return false;
		while(popIndex < popLen) {
			if(!stack.isEmpty() && stack.peek() == popA[popIndex]) {
				++popIndex;
				stack.pop();
			} else if (!stack.isEmpty() && stack.peek() != popA[popIndex] && pushIndex >= pushLen) {
				return false;
			} else {
				stack.push(pushA[pushIndex]);
				++pushIndex;
			}
		}
		return true;
	}
	public static void main(String[] args) {
		CheckIsStack checkIsStack = new CheckIsStack();
		int[] pushA =new int[] {1, 2, 3, 4, 5};
		int[] popA = new int[] {4, 3, 5, 1, 2};
		boolean ret = checkIsStack.isStackSeq(pushA, popA);
		System.out.println(ret);
	}
}	