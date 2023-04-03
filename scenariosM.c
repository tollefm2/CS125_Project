/*****
*File Name: scenarios.c
*Collaborators: Sam Costello, Fjor Robles, Margo Tollefson
*Main Contributers for this file: Sam Costello
*Purpose: Holds events that deal with money
*****/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int scenariosM(input)
{

  int scene;
  int money;
  int randNumber = 2;

  //sets up randomization for whole file
  srand(time(NULL));
  //checks to see if money is below 400 from passed value
  if( input == 1)
  {
  
    randNumber = 1;

  }

  //randomly chooses between the three event
  scene = rand()%randNumber+1;
  
  //use scene number to call correct event
  if( scene == 1 )
  {
    
    printf("***EVENT***\n");
    //calls event
    money = helpPerson();
  
  }
  else if( scene == 2 )
  {
  
    printf("***EVENT***\n");
    //calls event
    money = bandits();
  
  }

  return money;

}

//function for event 1
int bandits()
{

  int answer;
  int error = 0;
  int chance;
  int money;

  printf("You travel down the path, enjoying the nice weather. \n");
  printf("Suddenly, several men jump out of the bushes wielding weapons. \n");
  printf("They demand all of your money. \n");
  
  //loop checks for user input errors
  while( error == 0)
  {
  
    //generates chance out of 10
    chance = rand()%10+1;
    printf("What do you do? \n");
    printf("1. Lie to them \n2. Give up some money \n");
    printf("(Choose a number): ");
    scanf("%d", &answer);
  
    //takes user's answer to produce to correct choice
    if( answer == 1)
    {
      
      //uses chance to create randomness in outcomes
      if( chance > 3)
      {
        
        printf("You tell the men that you do not have any money. \n");
        printf("They laugh at you and your pathetic attempt to lie to them. \n");
        printf("They ransack your wagon, searching for money. \n");
        printf("They take all that they can find. \n");
        printf("*You have lost a lot money* \n");
        printf("*******\n");
        
        //determines how much money to add
        money = -400;
      
      }
      else if( chance <= 3 )
      {
      
        printf("You tell the men that your wife is very sick. \n");
        printf("All of your money has been poured into her treatment. \n");
        printf("They believe you and are disappointed. They let you go. \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //determines how much money to add
        money = 0;
      
      }
      
      //breaks the error checking loop
      error = 1;
      
    }
    else if( answer == 2)
    {
        
      printf("You give the men a little money to try and get them to leave. \n");
      printf("They believe that you have given them everything, call you a sucker, and leave. ");
      printf("*You have lost money* \n");
      printf("*******\n");
        
      //determines how much money to add
      money = -100;
      //breaks the error checking loop
      error = 1;
      
    }
    else
    {
    
      printf("Invalid answer, try again \n");
      
    }
  }
  
  return money;
  
}

//function for event 2
int helpPerson()
{
  
  int error1 = 0;
  int error2 =0;
  int answer1;
  int answer2;
  int money;

  printf("As you continue on your way you come across a man lying");
  printf("on the side of the trail. He isn't moving. \n");

  //loop checks for user input errors
  while( error1 == 0)
  {
  
     printf("What will you do? \n");
     printf("1. Ignore him and keep going \n2. Get out and check on him \n");
     printf("(Choose a number): ");
     scanf("%d", &answer1);
  
    //takes user's answer to produce to correct choice
    if( answer1 == 1)
    {
      
      printf("You ignore the man and drive right past him. \n");
      printf("*You continue on the trail* \n");
      printf("*******\n");
      
      //determines how much money to add
      money = 0;
      //breaks first error checking loop
      error1 = 1;
      
    }
    else if( answer1 == 2)
    {
    
      printf("You stop the wagon and get out to go check on the man. \n");
      printf("Once you get closer, you see that the man is dressed in fancy clothes. \n");
      printf("He is unresponsive when you call for him. \n");
      
      //loop checks for user input errors
      while( error2 == 0)
      {
      
        printf("What will you do? \n");
        printf("1. Attempt to wake him \n2. Give up and leave \n");
        printf("(Choose a number): ");
        scanf("%d", &answer2);
        
        //takes user's answer to produce to correct choice
        if( answer2 == 1)
        {
      
          printf("You walk over to the man and shake his shoulder. \n");
          printf("The man slowly wakes up, groaning in pain. \n");
          printf("You help him to the wagon and bandage his wounds. \n");
          printf("He explains that his carriage was robbed and he got hurt trying to stop them. \n");
          printf("He thanks you for helping him and gives you a reward. \n");
          printf("*You have gained money!* \n");
          printf("*******\n");
          
          //determines how much money to add
          money = 500;
          //breaks second error checking loop
          error2 = 1;
      
        }
        else if( answer2 == 2)
        {
      
          printf("You decide that the situation is too sketchy and return to your wagon. \n");
          printf("*You continue on the trail* \n");
          printf("*******\n");
          
          //determines how much money to add
          money = 0;
          //breaks second error checking loop
          error2 = 1;
      
        }
        else
        {
    
          printf("Invalid answer, try again \n");
      
        }
      
        //breaks first error checking loop
        error1 = 1;
        
      }
    }
    else
    {
    
      printf("Invalid answer, try again \n");
      
    }
  }
  
  return money;
}




