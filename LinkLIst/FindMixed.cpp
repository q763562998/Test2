#include<stdio.h>
#include<iostream>
#include <set>
using namespace std;

/*
����˵���������������������ת��Ϊ�����������ҽ�������������Ľ������ŵ�������

˼·˵�����ҳ������õ�������[1,2,3,4,5]��[2,3,4,5]
��������1�еĵ�һ��Ԫ�أ��̶����䣬ȥ�����ڶ��������ÿһ��Ԫ��
����ȡ������Ԫ����ͬʱ������ͬԪ�ؼ��뵽����set�С��Դ�ѭ������1�еĸ���Ԫ��
�����õĶ��ǵ���������while ��������
��Ϊ�������õ����ݲ��Ǻܶ࣬��Ŀ���ָ��������������������
��ô�����������������Ļ����Ϳ����ö��ֲ��ҷ���
������ĿҪ��������������㲻���ö��ֲ��ҷ���
*/
typedef struct node
{
	struct node* next;
	int value;

} Node;
/*
��������*/
Node* create(int* s, int length) {
	int i = 0;
	Node* head = NULL;
	Node* temp = NULL;//��ʱ����
	for (i = 0; i < length; ++i)
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->value = s[i];
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
�����������
*/
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << endl;
		head = head->next;
	}
}
void delete1(Node* head) {
	while (head != NULL)
	{
		Node* temp = head;
		head = head->next;
		free(temp);
	}
}

int main() {
	int arr[] = { 1,2,3,4,5 };
	int arr2[] = { 3,4,5,6 };
	set<int> s;//���ڴ�Ž���
	Node *head=create(arr, size(arr));
	Node *head2=create(arr2, size(arr2));
	//������arr ��һ������ȥ�����ڶ�������
	
	while (head!=NULL){
		Node* head2 = create(arr2, size(arr2));//��Ϊhead�ڱ�����ʱ���Ѿ����޸��ˣ�Ҫ��������
	
		while (head2 != NULL && head->value != head2->value) {
			head2 = head2->next;
			if (head2 != NULL && head->value == head2->value) {
				break;
			}
		}
		if (head2 != NULL && head->value == head2->value){
			//˵����һ����Ԫ��
			s.insert(head->value);
		}
		head = head->next;

	}
	delete1(head);
	delete1(head2);
	//�Լ��Ͻ��б���
	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++) {

		cout << *it << endl;
	}

}
















