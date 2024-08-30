#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* head = NULL; //Initializing Head

void randominsert(int n) {
	for (int i = 0; i < n; i++) {
		struct node* newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = rand();
		newnode->next = NULL;
		if (head == NULL) {
			head = newnode;
			newnode->next = head;
		}
		else {
			struct node* temp = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->next = head;
		}
	}
	printf("Successfully Added %d random nodes\n", n);
}


void addnodeend(int data) { // Also works as Insertion at end of the list
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //Initializing a new node with memory allocation

	newnode->data = data;
	newnode->next = NULL;

	if (head == NULL) {
		head = newnode;
		newnode->next = head;
	}
	else {
		struct node* temp = head; //Creating a temp pointer to traverse the linked list to find last node
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = head;
	}
	printf("Successfully Added the node in the End\n");
}

void addnodebegin(int data) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node)); //Initializing a new node with memory allocation

	newnode->data = data;
	newnode->next = NULL;

	if (head == NULL) {
		head = newnode;
		newnode->next = head;
	}
	else {
		struct node* temp = head; //Creating a temp pointer to traverse the linked list to find first node
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = head;
		head = newnode;

	}
	printf("Successfully Added the node in the Beginning\n");
}

void addafterspecific(int position, int data) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;

	struct node* temp = head;
	for (int i = 0; i < position; i++) {
		temp = temp->next;

		if (temp == head) {
			printf("Error: Overflow \n");
			printf("The given position %d is past the size of the Linked List\n", position);
			return;
		}
	}
	newnode->next = temp->next;
	temp->next = newnode;
	printf("Successfully Added the node after %d position\n", position);
}

void deletebegin() {
	struct node* temp = head;
	if (head == NULL) {
		printf("The Linked List is empty \n");
		return;
	}
	else {
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = head->next;
		free(head);
		head = temp->next;
	}
	printf("Successfully Deleted the node in the Beginning\n");
}

void deleteend() {
	struct node* temp = head;
	struct node* temp1 = temp;

	if (head == NULL) {
		printf("The Linked List is empty \n");
		return;
	}
	while (temp->next != head) {
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = head;
	free(temp);
	printf("Successfully Deleted the node in the End\n");
}

void deletespecific(int position) {
	struct node* temp = head;
	struct node* ptr = temp;
	if (head == NULL) {
		printf("The Linked List is empty \n");
		return;
	}
	if (position == 0) {
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = head->next;
		free(head);
		head = temp->next;
		printf("Successfully Deleted the node at position %d\n", position);
		return;
	}
	for (int i = 0; i < position; i++) {
		ptr = temp;
		temp = temp->next;

		if (temp == head) {
			printf("Overflow \n");
			printf("The given position %d is past the size of the Linked List\n", position);
			return;
		}
	}
	ptr->next = temp->next;
	free(temp);
	printf("Successfully Deleted the node at position %d\n", position);
}

void display() {
	struct node* temp = head;

	if (head == NULL) {
		printf("The Linked List is empty \n");
		return;
	}
	printf("Head-> %d \n", head);
	while (temp->next != head) {
		printf("Data-> %d Next-> %d \n", temp->data, temp->next);
		temp = temp->next;
	}
	printf("Data-> %d Next-> %d \n", temp->data, temp->next);
}

void search(int data) {
	struct node* temp = head;
	int i = 0;
	if (head == NULL) {
		printf("The Linked List is empty \n");
		return;
	}
	while (temp->next != head) {
		if (data == temp->data) {
			printf("The data %d found at node %d \n", data, i);
			return;
		}
		i += 1;
		temp = temp->next;
	}
	if (data = temp->data) {
		printf("The data %d found at node %d \n", data, i);
		return;
	}

	printf("The data %d was not found in the Linked List\n", data);
}


int main() {
	int choice = -1;
	int data, position;
	printf("*****Circular Single Linked List*****");
	printf("\n-------------------------------------\n");

	while (choice != 0) {
		printf("1.Random Insert \n2.Add node in the beginning \n3.Add node in the end \n4.Add node after a specific node \n5.Delete node in the beginning \n6.Delete node in the end \n7.Delete node a specific node \n8.Search an node \n9.Traverse/Display Linked List \n0.Exit \n");
		printf("Enter your choice \n");
		scanf_s("%d", &choice);
		printf("\n");
		switch (choice)
		{
		case 1:
			printf("Enter your the number of nodes you want to randomly add \n");
			scanf_s("%d", &data);
			randominsert(data);
			printf("\n");
			break;
		case 2:
			printf("Enter the data \n");
			scanf_s("%d", &data);
			addnodebegin(data);
			printf("\n");
			break;
		case 3:
			printf("Enter the data \n");
			scanf_s("%d", &data);
			addnodeend(data);
			printf("\n");
			break;
		case 4:
			printf("Enter after which node to insert \n");
			scanf_s("%d", &position);
			printf("Enter the data \n");
			scanf_s("%d", &data);
			addafterspecific(position, data);
			printf("\n");
			break;
		case 5:
			deletebegin();
			printf("\n");
			break;
		case 6:
			deleteend();
			printf("\n");
			break;
		case 7:
			printf("Enter which node to delete \n");
			scanf_s("%d", &position);
			deletespecific(position);
			printf("\n");
			break;
		case 8:
			printf("Enter the data to search\n");
			scanf_s("%d", &data);
			search(data);
			printf("\n");
			break;
		case 9:
			display();
			printf("\n");
			break;
		case 0:
			printf("Thank you \n");
			return;
		default:
			printf("Try again \n");
		}
	}
	return 0;
}