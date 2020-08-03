/*
主题：约瑟夫环问题
姓名：雷浩波
学号：2019210649
时间：2020年3月20日
*/
#include<iostream>
using namespace std;
//将结构体作为节点
struct Node {
	int data;
	struct Node *next;
};
//创建类，这里的链表作为对象
class list
{
	public:
		Node *front = NULL, *end = NULL, *p = NULL, *current = NULL, *q = NULL;
		//front为头指针，end为尾指针，p,q为工作指针，current为当前指针
		void set(int a, int b);
		void build();
		void work();
private:
	int n, m;

};
//该函数为类的公有成员，用以初始化数据
void list::set(int a,int b)
{
	if (a == 0 || b == 0 || a < b) { throw 0;}
	n = a;
	m = b;
}
//该函数为类的公有成员，用以创建链表，这里为了后期方便，创建的是无头节点的链表
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
	end->next = front;//尾结点指针指向头结点
	p = front;//初始化工作指针
}
void list::work()
{
	int rest = n;//定义变量用以计算剩余人数，作为判断停止条件
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
//主函数，完成相关函数的调用
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