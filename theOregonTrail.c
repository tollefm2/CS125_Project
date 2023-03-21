/*****
*File Name: theOregonTrail.c
*Collaborators: Sam Costello, Fjor Robles, Margo Tollefson
*Purpose: Simulate Oregon Trail type game
*****/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct family {
	char name[10];
	int memHealth;
};

int main () {
	int memHealth = 100;
	int day = 1;
	char start;
	int memNum;
	struct family partyMember[4];
	
	printf("WELCOME TO THE OREGON TRAIL!\n\n");
	
	printf("Press 'y' to start:");
	scanf(" %c", &start);

	while (start == 'y') {
		userOccupation();
		printf("Before you start the trail, you must name your party members.\n");
		
		for (memNum = 1; memNum < 4; memNum++) {
			printf("Party member %d: ", memNum);
			scanf("%s", partyMember[memNum].name);
			
			if (strlen(partyMember[memNum].name) > 10) {
				printf("Character length exceeded. Please try again.\n");
				memNum--;
			}
			
		}
		
		printf("DAY %d\n", day);
		printf("%d", partyMember[1].memHealth);
	return 0;
	}

	return 0;
}
