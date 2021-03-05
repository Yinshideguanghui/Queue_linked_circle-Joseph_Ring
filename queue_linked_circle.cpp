#include"queue_linked_circle.h"
#include<iostream>
using namespace std;

template <typename Queue_entry>		//来自队列的构造函数
Queue<Queue_entry>::Queue(const Queue& original)
{
	Node<Queue_entry>* new_copy, * original_node = original.last_node;
	if (original_node == NULL)last_node = NULL;
	else
	{
		last_node = new_copy = new Node<Queue_entry>(original_node->entry);
		while (original_node->next != original.last_node)
		{
			original_node = original_node->next;
			new_copy->next = new Node<Queue_entry>(original_node->entry);
			new_copy = new_copy->next;
		}
		new_copy->next = last_node;
	}
}

template <typename Queue_entry>		//安全措施——重载赋值运算符
void Queue<Queue_entry>::operator =(const Queue& original)
{
	Queue new_copy(original);
	while (last_node != NULL)
		serve();
	last_node = new_copy.last_node;
}

template <typename Queue_entry>		//析构函数
Queue<Queue_entry>::~Queue()
{
	while (last_node != NULL)
		serve();
}

template <typename Queue_entry>		//出队
Error_code Queue<Queue_entry>::serve()
{
	if (last_node == NULL) return underflow;	//从空队列出队：下溢
	else if (last_node->next == last_node)		//从只有一个节点的队列出队
	{
		delete last_node;
		last_node = NULL;
	}
	else										//从两个和以上节点的队列出队
	{
		Node<Queue_entry>* first_node = last_node->next;
		last_node->next = first_node->next;
		delete first_node;
		first_node = NULL;
	}
	return success;
}

template <typename Queue_entry>		//入队
Error_code Queue<Queue_entry>::append(const Queue_entry& item)
{
	if (last_node == NULL)		//向空队列入队
	{
		Node<Queue_entry>* new_node = new Node<Queue_entry>(item);
		if (new_node == NULL) return overflow;
		new_node->next = new_node;
		last_node = new_node;
	}
	else						//向非空队列入队
	{
		Node<Queue_entry>* new_node = new Node<Queue_entry>(item, last_node->next);
		if (new_node == NULL) return overflow;
		last_node->next = new_node;
		last_node = new_node;
	}
	return success;
}

template <typename Queue_entry>		//取出队头元素值
Error_code Queue<Queue_entry>::retrieve(Queue_entry& item) const
{
	if (last_node == NULL) return underflow;
	item = (last_node->next)->entry;
	return success;
}

template <typename Queue_entry>		//是否为空
bool Queue<Queue_entry>::empty() const
{
	return last_node == NULL;
}