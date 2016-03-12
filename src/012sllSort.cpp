/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};
struct node *temp1 = NULL;
void sll_012_sort(struct node *head){
		struct node *p;
		p = (struct node *)malloc(sizeof(struct node));
		temp1 = head;
		p = temp1->next;
		while (temp1 != NULL)
		{
			p = temp1->next;
			while (p != NULL)
			{
				if (temp1->data > p->data)
				{
					temp1->data = temp1->data ^ p->data;
					p->data = temp1->data ^ p->data;
					temp1->data = temp1->data ^ p->data;
				}
				p = p->next;
			}
			temp1 = temp1->next;
		}
	}
