#include"queue_linked_circle.h"
#include<iostream>
using namespace std;

template <typename Queue_entry>		//���Զ��еĹ��캯��
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

template <typename Queue_entry>		//��ȫ��ʩ�������ظ�ֵ�����
void Queue<Queue_entry>::operator =(const Queue& original)
{
	Queue new_copy(original);
	while (last_node != NULL)
		serve();
	last_node = new_copy.last_node;
}

template <typename Queue_entry>		//��������
Queue<Queue_entry>::~Queue()
{
	while (last_node != NULL)
		serve();
}

template <typename Queue_entry>		//����
Error_code Queue<Queue_entry>::serve()
{
	if (last_node == NULL) return underflow;	//�ӿն��г��ӣ�����
	else if (last_node->next == last_node)		//��ֻ��һ���ڵ�Ķ��г���
	{
		delete last_node;
		last_node = NULL;
	}
	else										//�����������Ͻڵ�Ķ��г���
	{
		Node<Queue_entry>* first_node = last_node->next;
		last_node->next = first_node->next;
		delete first_node;
		first_node = NULL;
	}
	return success;
}

template <typename Queue_entry>		//���
Error_code Queue<Queue_entry>::append(const Queue_entry& item)
{
	if (last_node == NULL)		//��ն������
	{
		Node<Queue_entry>* new_node = new Node<Queue_entry>(item);
		if (new_node == NULL) return overflow;
		new_node->next = new_node;
		last_node = new_node;
	}
	else						//��ǿն������
	{
		Node<Queue_entry>* new_node = new Node<Queue_entry>(item, last_node->next);
		if (new_node == NULL) return overflow;
		last_node->next = new_node;
		last_node = new_node;
	}
	return success;
}

template <typename Queue_entry>		//ȡ����ͷԪ��ֵ
Error_code Queue<Queue_entry>::retrieve(Queue_entry& item) const
{
	if (last_node == NULL) return underflow;
	item = (last_node->next)->entry;
	return success;
}

template <typename Queue_entry>		//�Ƿ�Ϊ��
bool Queue<Queue_entry>::empty() const
{
	return last_node == NULL;
}