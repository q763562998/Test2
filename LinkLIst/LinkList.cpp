#include<stdio.h>
#include<iostream>
#include <stdlib.h>
using namespace std;
/*
����˵������������ȴ�����һ�����飬��������Ϊ�˷��㴴���������˫�����������鸳��ֵ
����Ϊ[0,1,2,3]��������Ԫ�ض�һ����������4��Ԫ��Ϊ��
����ʵ�֣����������ڵ�Ԫ�ػ���λ�ã���0 1������ 2 3����
���������˫��������ִ�С�


*/
/*
������������ṹ��
*/
typedef struct node
{
	struct node* next;
	int index;
	
} Node;


/*
����˫������ṹ��
*/
typedef struct node2
{
	struct node2* next;
	struct node2* previous;
	int index;

} Node2;

/*
���������������
*/
void print(Node* head) {
	while (head != NULL) {
		cout << head->index << endl;
		head = head->next;
	}
}
/*
˫�������������
*/
void print2(Node2* head2) {
	while (head2 != NULL) {
		cout << head2->index << endl;
		head2 = head2->next;
	}
}
//��������������
//����Ϊһ�飬���н���
Node* swapSingle(Node* head,int length) {
	//��������С�ڵ���1�����轻��
	if (length<=1)
	{
		cout << "��ǰ����Ԫ�ظ���С��2�����轻��" << endl;
	}
	else if(length==2)//������һ����ڶ�����λ��
	{
		//Node tempHead = *head;//����ָ��
		head->next->next = head;
		head = head->next;
		head->next = NULL;
	}
	else 
	{
		Node* q = head;
		Node* before = NULL;//�ж��Ƿ�Ϊ��һ��Ԫ��
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
˫������������
*/
Node2* swapDouble(Node2* head2, int length) {
	if (length <= 1)
	{
		cout << "��ǰ����Ԫ�ظ���С��2�����轻��" << endl;
	}
	else if (length == 2)//������һ����ڶ�����λ��
	{
		//Node tempHead = *head;//����ָ��
		//�����ڶ���Ԫ��
		head2->next->next = head2;
		head2->next->previous = NULL;

		//������һ��Ԫ��
		head2->previous = head2->next;

		head2 = head2->next;
		head2->next = NULL;
	}
	else
	{
		Node2* q = head2;
		Node2* before = NULL;//�ж��Ƿ�Ϊ��һ��Ԫ��
		while (q && q->next)
		{
			Node2* r = q;
			Node2* p = q->next;
			q = p->next;


			r->next = p->next;
			r->previous = p;

			p->next = r;
			//��p��ֵǰ���ڵ��ʱ����Ҫע���Ƿ�r����ǰ���ڵ㣬������ָ��
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
������������*/
Node* createSingle(int* s, int length) {
	int i = 0;
	Node* head = NULL;
	Node* temp = NULL;//��ʱ����
	for (i = 0; i < length; ++i)
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->index = s[i];
		node->next = NULL;
		if (head == NULL)//��ǰ����û��Ԫ�أ�ֱ�Ӹ���head
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
����˫������*/
Node2* createDouble(int* s, int length) {
	int i = 0;
	Node2* head = NULL;
	Node2* temp = NULL;//��ʱ����
	Node2* tempHead;
	tempHead = head;
	for (i = 0; i < length; ++i)
	{
		Node2* node2 = (Node2*)malloc(sizeof(Node2));
		node2->index = s[i];
		node2->next = NULL;
		node2->previous = tempHead;//�����ﴴ��ǰ���ڵ�
		if (head == NULL)//��ǰ����û��Ԫ�أ�ֱ�Ӹ���head
		{
			head = node2;
			temp = node2;
			tempHead= node2;//����ǰ���ڵ�
		}
		else
		{
			temp->next = node2;
			temp = node2;
			tempHead = node2;//����ǰ���ڵ�
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

	bool userSingle = false;//����ѡ�����ĸ����� 
	if (userSingle)
	{
	Node *head=createSingle(s, length);
	head=swapSingle(head, 4);
	print(head);
	cout << "���ǵ�������ı���" << endl;
	delete1(head);

	}
	else
	{
		Node2* head2 = createDouble(s, length);
		head2 = swapDouble(head2, 4);
		print2(head2);
		cout << "����˫������ı���" << endl;
		delete2(head2);
	}

	return 0;

}























