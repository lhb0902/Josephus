/*
���⣺Լɪ������
�������׺Ʋ�
ѧ�ţ�2019210649
ʱ�䣺2020��3��20��
*/
#include<iostream>
using namespace std;
//���ṹ����Ϊ�ڵ�
struct Node {
	int data;
	struct Node *next;
};
//�����࣬�����������Ϊ����
class list
{
	public:
		Node *front = NULL, *end = NULL, *p = NULL, *current = NULL, *q = NULL;
		//frontΪͷָ�룬endΪβָ�룬p,qΪ����ָ�룬currentΪ��ǰָ��
		void set(int a, int b);
		void build();
		void work();
private:
	int n, m;

};
//�ú���Ϊ��Ĺ��г�Ա�����Գ�ʼ������
void list::set(int a,int b)
{
	if (a == 0 || b == 0 || a < b) { throw 0;}
	n = a;
	m = b;
}
//�ú���Ϊ��Ĺ��г�Ա�����Դ�����������Ϊ�˺��ڷ��㣬����������ͷ�ڵ������
void list::build()
{
	for (int i = 1; i < n + 1; i++) {
		current = new Node;
		if (i == 1) { front = current; end = current; }
		current->next = NULL;
		current->data = i;
		end->next = current;
		end = current;
	}
	end->next = front;//β���ָ��ָ��ͷ���
	p = front;//��ʼ������ָ��
}
void list::work()
{
	int rest = n;//����������Լ���ʣ����������Ϊ�ж�ֹͣ����
	int lastone = 0;
	for (; rest > 0; rest--) {

		for (int i = 0; i < m - 2; i++) {
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		p = p->next;
		lastone = q->data;
		delete(q);
	}
	cout << lastone;
}
//�������������غ����ĵ���
int main()
{
	list ysf;
	int x=0, y=0;
	cin >> x>> y;
	try {
		ysf.set(x, y);
	}
	catch (int) {
		cout << "error:input error,please restart the program";
	}
	ysf.build();
	ysf.work();
	system("pause");
}