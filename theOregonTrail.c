/*****
*File Name: theOregonTrail.c
*Collaborators: Sam Costello, Fjor Robles, Margo Tollefson
*Purpose: Simulate Oregon Trail type game
*****/

#include <stdio.h>

void userOccupation () {
	int occupation;

	printf("Before you start the trail you must choose an occupation: \n1. Farmer\n2. Banker\n3. Carpenter \nWhat occupation would you like to choose? ");
	scanf("%d", &occupation);

	switch (occupation) {
		case 1:
			printf("You have chosen farmer.\n");
			break;
		case 2:
			printf("You have chosen banker.\n");
			break;
		case 3:
			printf("You have chosen carpenter.\n");
			break;
	}
}
int main () {
	char start;

	printf("WELCOME TO THE OREGON TRAIL!\n\n");
	
	printf("Press 'y' to start:");
	scanf(" %c", &start);

	while (start == 'y') {
		userOccupation();
	}

	return 0;
}
