/*****
*File Name: theOregonTrail.c
*Collaborators: Sam Costello, Fjor Robles, Margo Tollefson
*Main Contributers for this file: Fjor Robles, Margo Tollefson
*Purpose: Simulate Oregon Trail type game
*****/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sets up scenarios
#include "oregonTrailHeader.h"

//lets user pick occupation
int userOccupation () 
{
	
  int occupation;
  int money;

  printf("Before you start the trail you must choose an occupation: \n1. Farmer\n2. Banker\n3. Carpenter \nWhat occupation would you like to choose? ");
  scanf("%d", &occupation);

  switch (occupation) 
  {
		  
    case 1:
      printf("You have chosen farmer.\n");
      break;
    case 2:
      printf("You have chosen banker.\n");
      break;
    case 3:
      printf("You have chosen carpenter.\n");
      break;
    //error checks the chosen occupation
    default:
      printf("Invalid number selection. You are now a farmer.\n");
      occupation = 1;
		  
  }
  //sets up money based on chosen occupation
  if (occupation == 1) 
  {
	  
    money = 500;
	  
  }
  else if (occupation == 2) 
  {
	  
    money = 1500;
	  
  }
  else 
  {
	  
    money = 1000;
	  
  }
	
  return money;
	
}

struct family 
{
	
  char name[10];
  int memHealth;
	
};

int main () 
{
	
  int day = 1;
  char start;
  int memNum;
  struct family partyMember[4];
  int totalHealth;
  int money;
  int randScenario;	
  int randHealth;
  int d = 0;
  int h = 0;
  int l = 0;
  int m = 0;
  int dayCount;
  int healthCount;
  int moneyCount;
  int life;
  int lifePick;
  int dayCap = 10;
  int finalScore;
  int deathCheck;	

  //opens high score text file, save information
  FILE *f = fopen("highScore.txt", "a+");

  printf("WELCOME TO THE OREGON TRAIL!\n\n");
	
  //initializes game
  printf("Press 'y' to start:");
  scanf(" %c", &start);

  while (start == 'y') 
  {
	  
    money = userOccupation();
    printf("Before you start the trail, you must name your party members.\n");
		
    //loops through array of members for naming
    for (memNum = 0; memNum < 3; memNum++) 
    {
	    
      printf("Party member %d: ", memNum+1);
      scanf("%s", partyMember[memNum].name);
      partyMember[memNum].memHealth = 100;
	    
      //error checks character limit
      if (strlen(partyMember[memNum].name) > 10) 
      {
	      
        printf("Character length exceeded. Please try again.\n");
	memNum--;
	      
      }
			
    }
		
    //initializes day sequence (starts at 10)
    for (day = 1; day <= dayCap; day++) 
    {	
      printf("DAY %d out of %d\n", day, dayCap);
      printf("     NAME      HEALTH\n");
    //cycles through character names and health points
    for (memNum = 0; memNum < 3; memNum++) 
    {		
      printf("%10s %10d\n", partyMember[memNum].name, partyMember[memNum].memHealth);
    }
			
    printf("Family funds: %d\n", money);
			
    //chooses from four scenario C files
    randScenario = rand()%4+1;
    srand(time(NULL));

    //health scenario	
    if (randScenario == 1) 
    {
      healthCount = scenariosH(h);
      while (deathCheck == 0) 
    {
    //randomly chooses member's health to affect
    randHealth = rand()%3+1;
			
    if (randHealth == 1 && partyMember[0].memHealth > 0) 
    {
      partyMember[0].memHealth = partyMember[0].memHealth - healthCount;	
      //makes sure member is not already dead
      if (partyMember[0].memHealth <= 0) 
      {
        partyMember[0].memHealth = 0;
      }
      //stops while loop, continues to next day
      deathCheck = 1;
      }
				
      else if  (randHealth == 2 && partyMember[1].memHealth > 0) 
      {
        partyMember[1].memHealth = partyMember[1].memHealth - healthCount;
	if (partyMember[1].memHealth <= 0) 
	{
  	  partyMember[1].memHealth = 0;
  	}
	deathCheck = 1;\
      }
      else if (randHealth == 3 && partyMember[2].memHealth > 0) 
      {
        partyMember[2].memHealth = partyMember[2].memHealth - healthCount;
	if (partyMember[2].memHealth <= 0) 
	{
          partyMember[2].memHealth = 0;
        }
	deathCheck = 1;
      }
				
    }
    deathCheck = 0;
  }
	
  //life affecting scenarios
  else if (randScenario == 2) 
  {
    //stops marraige scenario
    if (partyMember[2].memHealth == 0) 
    {
      l = 1;
    }
    life = scenariosL(l);
    if (life == 1) 
    {
      //randomly picks member to affect
      lifePick = rand()%3;
      partyMember[lifePick].memHealth = 0;
    }
    if (life == 2) 
    {
      partyMember[2].memHealth = 0;
    }
  }
  //money scenario
			else if (randScenario == 3) 
			{
				//does not affect low funds
				if (money < 400) 
				{
					m = 1;
				}
				moneyCount = scenariosM(m);
				money = money + moneyCount;
				if (money <= 0) 
				{
					moneyCount = 0;
				}
			}
			//day scenario			
			else 
			{
				dayCount = scenarioD(d);
				//allows for user to see how many days left in game
				dayCap = dayCap + dayCount;
			}

		//stops if every character is dead
		if (partyMember[0].memHealth == 0 && partyMember[1].memHealth == 0 && partyMember[2].memHealth == 0) 
		{
			printf("GAME OVER!\n");
        		return 0;
		}
      		
		//scans for user to continue, gives time to read scenarios
		printf("Continue?: ");
		scanf(" %c", &start);
		
		}
	
		//prints end screen, includes final score
		totalHealth = partyMember[0].memHealth + partyMember[1].memHealth + partyMember[2].memHealth;
		printf("GAME OVER!\n");
		printf("Total Days: %d\nFinal Earnings: %d\nTotal Health: %d\n", dayCap, money, totalHealth);
		finalScore = money + totalHealth - dayCap;
		printf("Final Score: %d\n", finalScore);
	
		//saves score to file
		fprintf(f, "Final Score: %d\n", finalScore);
		fclose(f);
		
    		return 0;
  	}
	return 0;
}
