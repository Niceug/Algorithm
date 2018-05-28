package com.ltp.queuetostack;

import java.util.LinkedList;
import java.util.Queue;

/**
 * ��������ʵ��ջ
 * @author Z7M-SL7D2
 *
 * @param <T>
 */
public class QueueToStack<T> {
	
	Queue<T> q1 = new LinkedList<>();
	Queue<T> q2 = new LinkedList<>();
	
	public boolean isEmpty() {
		return q1.size() + q2.size() == 0 ? true : false;
	}
	public int size() {
		return q1.size() + q2.size();
		
	}
	public T pop() {
		if(q1.size() == 0 && q2.size() == 0)
			return null;
		T t = null;
		
		// һ��q1Ϊ�գ��ͽ�q2�ķŵ�q1����ȥ��ʣ��һ��
		if (q1.size() == 0) {
			while(q2.size() > 1) {
				q1.add(q2.poll());
			}
			t = q2.poll();
		// q1�����ڿգ��ͽ�q1ȫ���ŵ�q2����ȥ��ʣ��һ��
		} else {
			while(q1.size() > 1) {
				q2.add(q1.poll());
			}
			t = q1.poll();
		}
		return t;
	}
	public void push(T value) {
		q1.add(value);
		
	}
	public static void main(String[] args) {
		QueueToStack<Integer> queueToStack = new QueueToStack<>();
		queueToStack.push(5);
		queueToStack.push(10);
		queueToStack.push(12);
		queueToStack.push(17);
		System.out.println(queueToStack.pop());
		queueToStack.push(15);
		queueToStack.push(20);
		System.out.println(queueToStack.pop());
		System.out.println(queueToStack.pop());
		System.out.println(queueToStack.pop());
		System.out.println(queueToStack.pop());
		queueToStack.push(55);
		queueToStack.push(100);
		System.out.println(queueToStack.pop());
	}
}
