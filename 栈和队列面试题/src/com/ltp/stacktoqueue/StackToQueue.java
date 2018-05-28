package com.ltp.stacktoqueue;
import java.util.Stack;

/**
 * 两个栈实现一个队列
 * @author Z7M-SL7D2
 *
 */
public class StackToQueue<T> {
	
	private Stack<T> stack1 = new Stack<>();
	private Stack<T> stack2 = new Stack<>();
	
	public void push(T value) {
		stack1.push(value);
	}
	
	public T pop() {
		if(stack2.isEmpty()) {
			while(!stack1.isEmpty()) {
				stack2.push(stack1.pop());
			}
		}
		return stack2.pop();
	}
	
	public static void main(String[] args) {
		StackToQueue<Integer> stackToQueue = new StackToQueue<>();
		stackToQueue.push(5);
		stackToQueue.push(100);
		System.out.println(stackToQueue.pop());
		stackToQueue.push(1);
		System.out.println(stackToQueue.pop());
		stackToQueue.push(10);
		stackToQueue.push(12);
		stackToQueue.push(13);
		System.out.println(stackToQueue.pop());
		System.out.println(stackToQueue.pop());
	}
	
}
