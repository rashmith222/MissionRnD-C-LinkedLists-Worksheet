/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};
struct node *temp = NULL;
struct node * sortLinkedList(struct node *head) 
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	if (head->next != NULL)
	{
		struct node *p;
		p = (struct node *)malloc(sizeof(struct node));
		temp = head;
		p = temp->next;
		while (temp!= NULL)
		{
			p = temp->next;
			while (p!= NULL)
			{
				if (temp->num > p->num)
				{
					temp->num = temp->num ^ p->num;
					p->num = temp->num ^ p->num;
					temp->num = temp->num ^ p->num;
				}
				p = p->next;
			}
			temp = temp->next;
		}
		return head;
	}
	
}