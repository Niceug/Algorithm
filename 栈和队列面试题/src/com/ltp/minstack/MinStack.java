package com.ltp.minstack;

import java.util.Stack;

/**
 * ʵ��һ��push, pop, minʱ�临�Ӷȶ�Ϊ1
 * ����1������Сֵ��stack����ջ��
 * ����2��ʹ����һ��ջ����������Сֵ����Сֵ��������ȡ�ģ����ܶ���Сջ���г�ջ
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
	 * ʹ��ǰ�����п�
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
	 * ʹ�õ�ʱ������п�
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
