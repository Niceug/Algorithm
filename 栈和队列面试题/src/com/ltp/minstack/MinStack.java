package com.ltp.minstack;

import java.util.Stack;

/**
 * 实现一个push, pop, min时间复杂度都为1
 * 方法1，将最小值和stack都入栈。
 * 方法2，使用另一个栈，来保存最小值，最小值是用来获取的，不能对最小栈进行出栈
 * @author Z7M-SL7D2
 *
 */
public class MinStack {
	private Stack<Element> stack = new Stack<>();
	
	private class Element{
		private int val;
		private int min;
		
		Element(int val, int min) {
			this.val = val;
			this.min = min;
		}
		public int getVal() {
			return val;
		}
		public int getMin() {
			return min;
		}
	}
	
	/**
	 * 使用前必须判空
	 * @return
	 */
	public int getMin() {
		return stack.peek().getMin();
	}
	
	public void push(int value) {
		if(stack.isEmpty())
			stack.push(new Element(value, value));
		else if(value > getMin()) {
			stack.push(new Element(value, getMin()));
		} else {
			stack.push(new Element(value, value));
		}
	}
	
	/**
	 * 使用的时候必须判空
	 * @return
	 */
	public int pop() {
			return stack.pop().getVal();
	}
	
	public static void main(String[] args) {
		MinStack minStack = new MinStack();
		minStack.push(1);
		minStack.push(5);
		System.out.println(minStack.getMin());
		minStack.push(2);
		minStack.push(1);
		System.out.println(minStack.getMin());
		minStack.pop();
		minStack.pop();
		System.out.println(minStack.getMin());
	}
}
