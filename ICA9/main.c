#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main(int argc, char* argv)
{
	int programRun = 1;

	IDOrderList = BuildIDList();
	MarkOrderList = BuildMarksList();

	do 
	{
		programRun = Menu();

	} while (programRun);

	exit(EXIT_SUCCESS);
}