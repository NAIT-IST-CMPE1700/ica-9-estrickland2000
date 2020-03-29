#pragma once
#ifndef Header
#define Header

typedef struct Student
{
	char* FirstName;
	int IDNum;
	int Marks;
	struct Student* next;
} Student;

typedef struct Student* Stdptr;

Stdptr IDOrderList;
Stdptr MarkOrderList;

static const char * stringArray[] = {"Bob", "Jerry", "Ralph", "Ethan", "Bruno", "Liam", "Raj", "Jesse", "Tim", "Isaac"};
static const int intArray[] = { 567, 999, 2323, 143, 404, 1105, 277, 190, 651, 409 };
static const int markArray[] = {12, 67, 88, 67, 99, 45, 83, 90, 34, 77};

Stdptr BuildIDList();
Stdptr AddItemIDList(Stdptr head, int index);
Stdptr BuildMarksList();
Stdptr AddItemMarkList(Stdptr head, int index);

#endif