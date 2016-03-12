/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	struct node *temp, *p, *first=NULL;
	if (N == 0){
		first = (struct node *)malloc(sizeof(struct node));
		first->num = N;
		first->next = NULL;
		return first;
	}
	if (N < 0){
		N = -N;
	}
	if (N > 0){
		temp = (struct node *)malloc(sizeof(struct node));
		int data = 0;
		while (N != 0){
			data = N % 10;
			if (first == NULL)
			{
				temp = (struct node*)malloc(sizeof(struct node));
				temp->num = data;
				temp->next = NULL;
				first = temp;
			}
			else
			{
				temp = first;
				while (temp->next != NULL){
					temp = temp->next;
				}
				p = (struct node*)malloc(sizeof(struct node));
				p->num = data;
				p->next = first;
				first = p;
			}
			N = N / 10;
		}
		return first;
	}
}
