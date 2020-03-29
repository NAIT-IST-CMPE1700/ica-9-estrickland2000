#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Stdptr BuildIDList() 
{
	Stdptr head = NULL;
	for (int i = 0; i < 10; i++)
	{
		head = AddItemIDList(head, i);
	}

	return head;
}

Stdptr AddItemIDList(Stdptr head, int index)
{
	Stdptr current;
	Stdptr temp;

	temp = (Stdptr)malloc(sizeof(Student));
	temp->FirstName = stringArray[index];
	temp->IDNum = intArray[index];
	temp->Marks = markArray[index];
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
	}
	if (intArray[index] > head->IDNum)
	{
		current = head;

		while (current->next != NULL && temp->IDNum > current->next->IDNum)
		{
			current = current->next;
		}

		temp->next = current->next;
		current->next = temp;
	}
	if (intArray[index] < head->IDNum)
	{
		temp->next = head;
		head = temp;
	}

	return head;
}

Stdptr BuildMarksList()
{
	Stdptr head = NULL;
	for (int i = 0; i < 10; i++)
	{
		head = AddItemMarkList(head, i);
	}

	return head;
}

Stdptr AddItemMarkList(Stdptr head, int index)
{
	Stdptr current;
	Stdptr temp;

	temp = (Stdptr)malloc(sizeof(Student));
	temp->FirstName = stringArray[index];
	temp->IDNum = intArray[index];
	temp->Marks = markArray[index];
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
	}
	if (markArray[index] > head->Marks)
	{
		temp->next = head;
		head = temp;
	}
	if (markArray[index] < head->Marks)
	{
		current = head;

		while (current->next != NULL && temp->Marks < current->next->Marks)
		{
			current = current->next;
		}

		temp->next = current->next;
		current->next = temp;
	}

	return head;
}

void displayList(Stdptr head) {
	Stdptr current;
	current = head;
	while (current != NULL) {
		printf("\n-----\nName: %s\nID: %d\nMark: %d\n-----\n", current->FirstName, current->IDNum, current->Marks);
		current = current->next;
	}
	printf("\n");
}

void FindID(Stdptr head)
{
	int id;
	int rank = 0;
	Stdptr current;

	printf("\n\nEnter the ID of the user you want: ");
	scanf_s("%d", &id, sizeof(int));

	current = head;
	while (current != NULL) 
	{
		if (current->IDNum == id)
		{
			printf("\n-----\nName: %s\nID: %d\nMark: %d\nRank: %d\n-----\n", current->FirstName, current->IDNum, current->Marks, rank);
			return;
		}
		current = current->next;
		rank++;
	}

	printf("\nError: There is no user with the %d ID.\n\n", id);
}

void FindMarks(Stdptr head)
{
	int mark;
	int numMarksAboveThres = 0;
	Stdptr current;

	printf("\n\nEnter the mark threshold you want: ");
	scanf_s("%d", &mark, sizeof(int));

	current = head;
	while (current != NULL)
	{
		if (current->Marks > mark)
		{
			printf("\n-----\nName: %s\nID: %d\nMark: %d\n-----\n", current->FirstName, current->IDNum, current->Marks);
			numMarksAboveThres++;
		}
		current = current->next;
	}

	if (numMarksAboveThres == 0)
		printf("\nError: There is no user with a mark above %d.\n\n", mark);
}

int Menu()
{
	int input;

	printf("\nPlease select one of the following options:\n\n");
	printf("1. Display list in order of IDs\n");
	printf("2. Display list in descending order of marks\n"); 
	printf("3. Display the names, marks, and rank of person using their ID\n");
	printf("4. Display the names and marks of all people above a certain mark value\n");
	printf("5. Exit\n\n");

	printf("Your selection: ");
	scanf_s("%d", &input, sizeof(int));

	switch (input)
	{
	case 1:
		displayList(IDOrderList);
		return 1;
		break;
	case 2:
		displayList(MarkOrderList);
		return 1;
		break;
	case 3:
		FindID(MarkOrderList);
		return 1;
		break;
	case 4:
		FindMarks(MarkOrderList);
		return 1;
		break;
	case 5:
		printf("\n\nClosing...");
		return 0;
		break;
	default:
		printf("\nInvalid Selection.\n");
		return 1;
		break;
	}
}

