/*
 ============================================================================
 Name        : Prompt.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT_SUCESS 0;

typedef struct Node { 
    int val; 
    struct Node* next; 
} node_t;

void print_list(node_t * entry) {
	while (entry != NULL) 
    {
        printf("Value: %d -> ", entry->val);
        entry = entry->next;
    }
    printf("\n");
}

int pop(node_t * head) {
    int retval = -1;

    node_t * next_node = NULL;
    node_t * current = head;
    node_t * previous = head;

    while (current->next != NULL) { //Verify if in fact next is NULL.
        previous = current;
        current = current->next;
    }

    next_node = current->next;
    retval = current->val;
    
    free(previous->next);
    previous->next = NULL;

    return retval;
}

int getValue(node_t * head, int position) 
{
    if (position == 0) 
    {
        return head->val;
    } else 
    {
        getValue(head->next, position-1);
    }
}

void setValue(node_t * head, int position, int value) 
{
    if (position == 0) 
    {
        head->val = value;
    } else 
    {
        setValue(head->next, position-1, value);
    }
}

int removeByIndex(node_t * head, int index) 
{
        node_t * current = head;
        node_t * temp = NULL;
        int retval = -1;

        for (int i = 0; i < index - 1; i++) 
        {
            current = current->next;
        }

        if (index == 0) 
        {
            retval = current->val;
            current = current->next;
            head->val = current->val;
            head->next = current->next;
        } else 
        {
            temp = current->next;
            retval = temp->val;
            current->next = temp->next;
            free(temp);
        }
        
    return retval;

}

node_t * insertByIndex(node_t * head, int index, int value) 
{
        node_t * current = head;
        node_t * temp = NULL;
        int temporary = 0;

        for (int i = 0; i < index - 1; i++) 
        {
            current = current->next;
        }

        if (index == 0) 
        {
            temp = current;
            current = (node_t *) malloc(sizeof(node_t));
            current->val = value;
            current->next = temp;
            head = current;
        } else 
        {
            temp = current->next;
            current->next = (node_t *) malloc(sizeof(node_t));
            current->next->val = value;
            current->next->next = temp;
        }
        
    return head;
}

node_t * createLinkedList(int n) 
{
	int i = 0;
	node_t * head = NULL;
	node_t * temp = NULL;
    node_t * temp1 = NULL;

	for(i=0; i<n; i++) 
	{
		temp = (node_t *) malloc(sizeof(node_t));
		printf("\nEnter the data for the number %d: ", i+1);
		scanf("%d",&(temp->val));
		temp->next = NULL;

		if (head == NULL) 
		{
			head = temp;
		} else 
		{
            temp1 = head;
			while(temp1->next != NULL)
				temp1 = temp1->next;
            temp1->next = temp;  
		}


	}

    return head;
}

int sizeOfList(node_t * head) 
{
    int i = 1;
    node_t * current = head;
    
    while (current->next != NULL) 
    { 
        current = current->next;
        i++;
    }

    return i;
}

// Function to push node at head 
int push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) { //Verify if in fact next is NULL.
        current = current->next;
    }

    /* Now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;

    return val;
}

int main(int argc, char *argv[]) {

    int n = 0;
    int value = 0;
	node_t * head = NULL;
	printf("\nHow many nodes:");
    scanf("%d",&n);
    head = createLinkedList(n);
    printf("Pushed Value: %d.\n", push(head, 15));
    printf("Erased value: %d.\n", pop(head));
    printf("Position to delete:");
    scanf("%d",&n);
    printf("Removed value: %d.\n", removeByIndex(head, n));
    printf("Position to insert:");
    scanf("%d",&n);
    printf("Value to insert:");
    scanf("%d",&value);
    head = insertByIndex(head, n, value);
    printf("Get a value at position:");
    scanf("%d",&n);
    printf("Value at position n: %d\n", getValue(head, n));
    printf("Set a value:");
    scanf("%d",&value);
    printf("At position:"); 
    scanf("%d",&n);
    setValue(head, n, value);
    printf("Size of the list: %d\n", sizeOfList(head));

    print_list(head);

	return EXIT_SUCCESS;
}
