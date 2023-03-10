/*****
*File Name: theOregonTrail.c
*Collaborators: Sam Costello, Fjor Robles, Margo Tollefson
*Purpose: Simulate Oregon Trail type game
*****/

#include <stdio.h>

int main () {
	char start;

	printf("WELCOME TO THE OREGON TRAIL!\n\n");
	
	printf("Press 'y' to start:");
	scanf(" %c", &start);

	while (start == 'y') {
		printf("test.\n");
	}

	return 0;
}
