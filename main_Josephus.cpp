#include"queue_linked_circle.h"
#include"queue_linked_circle.cpp"
#include<iostream>
using namespace std;
void test_Josephring(int n, int start, int step)
{
	cout << "test_Josephring(" << n << ',' << start << ',' << step << ")\n";
	//创建循环链表，队头为起始者
	Queue<int> persons;
	for (int i = start; i <= n; i++)
		persons.append(i);
	for (int i = 1; i < start; i++)
		persons.append(i);
	//出队过程
	int count = n;		//当前队中人数
	int temp;			//队头到队尾的临时变量，输出临时变量
	while (count > 1)
	{
		//(步长-1)个人出队后立刻入队
		for (int i = 0; i < step - 1; i++)
		{
			persons.retrieve(temp);
			persons.serve();
			persons.append(temp);
		}
		//第(步长)个人出队后不入队，并且当前队中人数-1
		persons.retrieve(temp);
		persons.serve();
		cout << "第" << temp << "个人出队\n";
		count--;
	}
	persons.retrieve(temp);		//最终留下的人
	cout << "第" << temp << "个人留下" << endl;
}
int main()
{
	test_Josephring(10, 2, 2);
	return 0;
}