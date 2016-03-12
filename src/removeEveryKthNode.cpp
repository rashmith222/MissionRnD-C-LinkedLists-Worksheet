/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/
#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};
struct node * removeEveryKthNode(struct node *head, int K)
{
	if (head == NULL || K<0)
	{
		return NULL;
	}
	if (K == 0)
	{
		return NULL;
	}
	if (K == 1)
		return NULL;
	int *Arr, counter = 0, i = 0, r = 1, k = 1, j = 0, length = 0, q = 1;
	struct node  *temp3 = NULL;
	Arr = (int *)malloc(sizeof(int));
	struct node *prev, *p;
	prev = (struct node *)malloc(sizeof(struct node));
	p = (struct node *)malloc(sizeof(struct node));
	temp3 = head;
	while (temp3->next != NULL)
	{
		length++;
		temp3 = temp3->next;
	}
	while (r<length + 1)
	{
		r = q*K;
		if (r>length + 1)
			break;
		Arr[i] = r;
		counter++;
		q++;
		i++;
	}
	p = head;
	for (j = 0; j < counter; j++)
	{
		while (k < Arr[j])
		{
			prev = p;
			p = p->next;
			k++;
		}
		prev->next = p->next;
	}
	return head;
}