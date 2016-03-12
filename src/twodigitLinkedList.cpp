/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>
struct node {
	int digit1;
	int digit2;
	struct node *next;
};
struct node  *temp2=NULL;
int convert_sll_2digit_to_int(struct node *head){
	int *N, i = 0, counter = 0, num = 0;
	temp2 = (struct node *)malloc(sizeof(struct node));
	temp2 = head;
	while (temp2 != NULL){
		temp2 = temp2->next;
		counter++;
	}
	N = (int *)malloc(sizeof(int));
	temp2 = head;
	if (counter == 1 && temp2->digit1 == 0 && temp2->digit2 == 0){
		N[0] = temp2->digit1;
		N[1] = temp2->digit2;
	}
	if (counter != 0 && temp2->digit1 == 0 && temp2->digit2 == 0){
		temp2 = temp2->next;
		counter--;
	}
	while (temp2!= NULL){
		if (temp2->digit1 == temp2->digit2 || temp2->digit1 != temp2->digit2){
			N[i] = temp2->digit1;
			N[i + 1] = temp2->digit2;
			temp2 = temp2->next;
			i = i + 2;
		}
	}
	for (i = 0; i < 2 * counter; i++)
		num = num * 10 + N[i];
	return num;
}

