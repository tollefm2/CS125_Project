/*****
*File Name: theOregonTrail.c
*Collaborators: Sam Costello, Fjor Robles, Margo Tollefson
*Purpose: Simulate Oregon Trail type game
*****/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "oregonTrailHeader.h"

int userOccupation () {
	int occupation;
	int money;

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
		default:
			printf("Invalid number selection. You are now a farmer.\n");
			occupation = 1;
	}
	if (occupation == 1) {
		money = 500;
	}
	else if (occupation == 2) {
		money = 1500;
	}
	else {
		money = 1000;
	}
	return money;
}

struct family {
	char name[10];
	int memHealth;
};

int main () {
	int day = 1;
	char start;
	int memNum;
	struct family partyMember[4];
	int money;
	int randScenario;
	
	int something = 0;
	int dayCount;
	int dayCap = 10;

	printf("WELCOME TO THE OREGON TRAIL!\n\n");
	
	printf("Press 'y' to start:");
	scanf(" %c", &start);

	while (start == 'y') {
		money = userOccupation();
		printf("Before you start the trail, you must name your party members.\n");
		
		for (memNum = 0; memNum < 3; memNum++) {
			printf("Party member %d: ", memNum+1);
			scanf("%s", partyMember[memNum].name);
			partyMember[memNum].memHealth = 100;
			if (strlen(partyMember[memNum].name) > 10) {
				printf("Character length exceeded. Please try again.\n");
				memNum--;
			}
			
		}

		for (day = 1; day <= dayCap; day++) {	
			printf("DAY %d out of %d\n", day, dayCap);
			printf("    NAME   HEALTH\n");
			
			for (memNum = 0; memNum < 3; memNum++) {		
				printf("%10s %5d\n", partyMember[memNum].name, partyMember[memNum].memHealth);
			}
			
			printf("Family funds: %d\n", money);
			
			randScenario = rand()%4+1;
			
			dayCount = scenarioD(something);
			dayCap = dayCap + dayCount;

			FILE *f = fopen("randScenario", "w");
			fprintf(f, "test.");
			fclose(f);
		}

		return 0;
	}

	return 0;
}
