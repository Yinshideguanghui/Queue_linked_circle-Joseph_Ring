#include"queue_linked_circle.h"
#include"queue_linked_circle.cpp"
#include<iostream>
using namespace std;
void test_Josephring(int n, int start, int step)
{
	cout << "test_Josephring(" << n << ',' << start << ',' << step << ")\n";
	//����ѭ��������ͷΪ��ʼ��
	Queue<int> persons;
	for (int i = start; i <= n; i++)
		persons.append(i);
	for (int i = 1; i < start; i++)
		persons.append(i);
	//���ӹ���
	int count = n;		//��ǰ��������
	int temp;			//��ͷ����β����ʱ�����������ʱ����
	while (count > 1)
	{
		//(����-1)���˳��Ӻ��������
		for (int i = 0; i < step - 1; i++)
		{
			persons.retrieve(temp);
			persons.serve();
			persons.append(temp);
		}
		//��(����)���˳��Ӻ���ӣ����ҵ�ǰ��������-1
		persons.retrieve(temp);
		persons.serve();
		cout << "��" << temp << "���˳���\n";
		count--;
	}
	persons.retrieve(temp);		//�������µ���
	cout << "��" << temp << "��������" << endl;
}
int main()
{
	test_Josephring(10, 2, 2);
	return 0;
}