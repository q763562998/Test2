#include<stdio.h>
#include<iostream>
#include <stdlib.h>
using namespace std;
/*
程序说明：这个程序先创建了一个数组，我在这里为了方便创建单向或者双向链表，给数组赋了值
数组为[0,1,2,3]，创几个元素都一样，这里以4个元素为例
程序实现：将两两相邻的元素互换位置，如0 1互换， 2 3互换
单向链表和双向链表都能执行。


*/
/*
创建单向链表结构体
*/
typedef struct node
{
	struct node* next;
	int index;
	
} Node;


/*
创建双向链表结构体
*/
typedef struct node2
{
	struct node2* next;
	struct node2* previous;
	int index;

} Node2;

/*
单向链表遍历操作
*/
void print(Node* head) {
	while (head != NULL) {
		cout << head->index << endl;
		head = head->next;
	}
}
/*
双向链表遍历操作
*/
void print2(Node2* head2) {
	while (head2 != NULL) {
		cout << head2->index << endl;
		head2 = head2->next;
	}
}
//单向链表交换代码
//两两为一组，进行交换
Node* swapSingle(Node* head,int length) {
	//当链表长度小于等于1，无需交换
	if (length<=1)
	{
		cout << "当前链表元素个数小于2，无需交换" << endl;
	}
	else if(length==2)//交换第一个与第二个的位置
	{
		//Node tempHead = *head;//辅助指针
		head->next->next = head;
		head = head->next;
		head->next = NULL;
	}
	else 
	{
		Node* q = head;
		Node* before = NULL;//判断是否为第一个元素
		while (q && q->next)
		{
			Node* r = q;
			Node* p = q->next;
			q = p->next;
			r->next = p->next;
			p->next = r;
			if (before == NULL) {
				head = p;
			}
			else {
				before->next = p;
			}
			before = r;
		}
		return head;
		
	}
	
	
	
	return head;
}
/*
双向链表交换代码
*/
Node2* swapDouble(Node2* head2, int length) {
	if (length <= 1)
	{
		cout << "当前链表元素个数小于2，无需交换" << endl;
	}
	else if (length == 2)//交换第一个与第二个的位置
	{
		//Node tempHead = *head;//辅助指针
		//操作第二个元素
		head2->next->next = head2;
		head2->next->previous = NULL;

		//操作第一个元素
		head2->previous = head2->next;

		head2 = head2->next;
		head2->next = NULL;
	}
	else
	{
		Node2* q = head2;
		Node2* before = NULL;//判断是否为第一个元素
		while (q && q->next)
		{
			Node2* r = q;
			Node2* p = q->next;
			q = p->next;


			r->next = p->next;
			r->previous = p;

			p->next = r;
			//给p赋值前驱节点的时候，需要注意是否r具有前驱节点，否则会空指针
			if (r->previous!=NULL)
			{
			p->previous = r->previous;

			}
			if (before == NULL) {
				head2 = p;
			}
			else {
				before->next = p;
			}
			before = r;
		}
		return head2;

	}
}
/*
创建单向链表*/
Node* createSingle(int* s, int length) {
	int i = 0;
	Node* head = NULL;
	Node* temp = NULL;//临时变量
	for (i = 0; i < length; ++i)
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->index = s[i];
		node->next = NULL;
		if (head == NULL)//当前链表没有元素，直接赋给head
		{
			head = node;
			temp = node;
		}
		else
		{
			temp->next = node;
			temp = node;
		}
	}
	return head;
}
/*
创建双向链表*/
Node2* createDouble(int* s, int length) {
	int i = 0;
	Node2* head = NULL;
	Node2* temp = NULL;//临时变量
	Node2* tempHead;
	tempHead = head;
	for (i = 0; i < length; ++i)
	{
		Node2* node2 = (Node2*)malloc(sizeof(Node2));
		node2->index = s[i];
		node2->next = NULL;
		node2->previous = tempHead;//在这里创建前驱节点
		if (head == NULL)//当前链表没有元素，直接赋给head
		{
			head = node2;
			temp = node2;
			tempHead= node2;//更新前驱节点
		}
		else
		{
			temp->next = node2;
			temp = node2;
			tempHead = node2;//更新前驱节点
		}
	}
	return head;
}
void delete1(Node *head) {
	while (head!=NULL)
	{
		Node* temp = head;
		head = head->next;
		free(temp);
	}
}
void delete2(Node2* head2) {
	while (head2 != NULL)
	{
		Node2* temp2 = head2;
		head2 = head2->next;
		free(temp2);
	}
}
int main() {

	int s[] = { 0,1,2,3};
	int length = sizeof(s) / sizeof(*s);

	bool userSingle = false;//用于选择用哪个链表 
	if (userSingle)
	{
	Node *head=createSingle(s, length);
	head=swapSingle(head, 4);
	print(head);
	cout << "这是单向链表的遍历" << endl;
	delete1(head);

	}
	else
	{
		Node2* head2 = createDouble(s, length);
		head2 = swapDouble(head2, 4);
		print2(head2);
		cout << "这是双向链表的遍历" << endl;
		delete2(head2);
	}

	return 0;

}























