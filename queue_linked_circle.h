#pragma once

#include<iostream>
template <typename Node_entry>
struct Node {
	Node_entry entry;
	Node* next;

	Node() {}
	Node(Node_entry item, Node* add_on = NULL)
	{
		entry = item;
		next = add_on;
	}
};


enum Error_code { success, overflow, underflow };

template <typename Queue_entry>
class Queue
{
public:
	//构造函数
	Queue() { last_node = NULL; }
	Queue(const Queue& original);									//来自队列
	//析构函数
	~Queue();
	//基本操作
	bool empty() const;
	Error_code serve();
	Error_code append(const Queue_entry& item);
	Error_code retrieve(Queue_entry& item) const;
	//安全措施——重载赋值运算符
	void operator =(const Queue& original);
protected:
	Node <Queue_entry>* last_node;
};