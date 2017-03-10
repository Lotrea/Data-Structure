/*****************************************************************************
* @file : E:\C++Workspace\C++learning\C++learning\temp_test\t1.cpp
* @author : Li weihao
* @date : 2017/3/8 19:30
* @describe : list µœ÷
*****************************************************************************/
#include<string>
#include<iostream>
#include <limits.h>

using namespace std;

struct Data 
{
	string info;
};

struct Node
{
	Data n_data;
	Node* next;
};

Node* init_list()
{
	Node *head = new Node;
	head->n_data = {"111"};
	head->next = NULL;
	return head;
}

Node* Insert_node(Node* head,int pos,Node* node)
{
	int flag = 1;
	if (head == NULL)
	{
		head = node;
		head->next = NULL;
		return head;
	}
	if (pos == 1)
	{
		node->next = head;
		return node;
	}

	Node* temp = head;
	while (flag < pos-1)
	{
		if (temp->next== NULL )
		{
			cout << "Position beyond list,can't insert!";
			return head;
		}

		temp = temp->next;
		flag++;
	}

	node->next = temp->next;
	temp->next = node;

	return head;

}

Node* Insert_node(Node* head, Node* node)
{
	if (head == NULL)
	{
		head = node;
		head->next = NULL;
		return head;
	}
	Node* temp = head;
	while (temp->next!=NULL)
	{
		temp = temp->next;
	}

	temp->next = node;
	return head;
}

Node* Remove_node(Node* head,Data val)
{
	if(head==NULL)
	{
		cout << "Empty list!Can't remove." << endl;
	}

	Node* temp = head;

	while (temp != NULL) 
	{
		if (temp->next->n_data.info == val.info)
		{
			temp->next = temp->next->next;
			cout << "Delete " << val.info << " succeed." << endl;
			return head;
		}
		temp = temp->next;
	}

	cout << "Not find " << val.info << " ,removal failed\n";
	return head;
	
}

Node* Reverse_list(Node* head)
{
	if (head == NULL)
	{
		cout << "List is empty!" << endl;
		return head;
	}

	Node* temp1=head ,*temp2,*temp3=NULL;

	while (temp1!=NULL)
	{
		temp2 = temp1->next;
		temp1->next = temp3;
		temp3 = temp1;
		temp1 = temp2;
	}
	return temp3;

}

void Print_list(Node* head)
{
	if (head == NULL)
		cout << "head is NULL" << endl;
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->n_data.info << endl;
		temp = temp->next;
	}
}

int main()
{

	Node *head = init_list();
	Node *n1=new Node;
	n1->n_data.info = "n1";
	n1->next=NULL;
	Node *n2 = new Node;
	n2->n_data.info = "n2";
	n2->next = NULL;
	Node *n3 = new Node;
	n3->n_data.info = "n3";
	n3->next = NULL;
	Node *n4 = new Node;
	n4->n_data.info = "n4";
	n4->next = NULL;
	head = Insert_node(head, n1);
	head = Insert_node(head, n2);
	head = Insert_node(head, n3);
	head = Insert_node(head, n4);
	head = Remove_node(head, n3->n_data);
	//head->next = n1;
	head = Reverse_list(head);
	Print_list(head);
	std::cin.get();
	return 0;
}