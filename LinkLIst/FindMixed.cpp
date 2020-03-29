#include<stdio.h>
#include<iostream>
#include <set>
using namespace std;

/*
程序说明：这个程序将两个数组先转换为单向链表，并且将两个单向链表的交集给放到集合中

思路说明：我程序里用的数组是[1,2,3,4,5]和[2,3,4,5]
先用数组1中的第一个元素，固定不变，去遍历第二个数组的每一个元素
当获取到两者元素相同时，将相同元素加入到集合set中。以此循环数组1中的各个元素
操作用的都是单向链表中while 遍历操作
因为我这里用的数据不是很多，题目中又给出条件，数组是有序的
那么如果利用数组是有序的话，就可以用二分查找法。
但是题目要求用链表操作，便不采用二分查找法。
*/
typedef struct node
{
	struct node* next;
	int value;

} Node;
/*
创建链表*/
Node* create(int* s, int length) {
	int i = 0;
	Node* head = NULL;
	Node* temp = NULL;//临时变量
	for (i = 0; i < length; ++i)
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->value = s[i];
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
链表遍历操作
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
	set<int> s;//用于存放交集
	Node *head=create(arr, size(arr));
	Node *head2=create(arr2, size(arr2));
	//这里用arr 第一个数组去遍历第二个数组
	
	while (head!=NULL){
		Node* head2 = create(arr2, size(arr2));//因为head在遍历的时候已经被修改了，要重新设置
	
		while (head2 != NULL && head->value != head2->value) {
			head2 = head2->next;
			if (head2 != NULL && head->value == head2->value) {
				break;
			}
		}
		if (head2 != NULL && head->value == head2->value){
			//说明有一样的元素
			s.insert(head->value);
		}
		head = head->next;

	}
	delete1(head);
	delete1(head2);
	//对集合进行遍历
	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++) {

		cout << *it << endl;
	}

}
















