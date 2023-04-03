/*****
*File Name: scenariosH.c
*Collaborators: Sam Costello, Fjor Robles, Margo Tollefson
*Purpose: Simulate Oregon Trail type game
*****/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int scenariosH()
{

  int scene;
  int input = 0;
  int health;

  //sets up randomization for whole file
  srand(time(NULL));
  //randomly chooses between the three event
  scene = rand()%3+1;
  
  //use scene number to call correct event
  if( scene == 1 )
  {
    
    printf("***EVENT***\n");
    //calls event
    health = dysentery();
    
  }
  else if( scene == 2 )
  {
  
    printf("***EVENT***\n");
    //calls event
    health = bearAttack();
  
  }
  else
  {
  
    printf("***EVENT***\n");
    //calls event
    health = stranger();
  
  } 

  return health;

}

//function for event 1
int dysentery()
{

  int health;

  printf("You come across a stream and decide to have a drink. \n");
  printf("Turns out the water was contaminated! \n");
  printf("*One of your family memebers has contracted dysentery* \n");
  
  //determines how much health will be subtracted from family member
  health = 80;
  
  return health;
  
}

//function for event 2
int bearAttack()
{

  int answer;
  int error = 0;
  int chance;
  int health;

  printf("As you pass through a forest, some leaves nearby begin to russle. \n");
  printf("A bear suddenly appears from the bushes! \n");
  printf("It walks onto the trail, blocking your path. \n");
  
  //loop checks for user input errors
  while( error == 0)
  {
    
    //generates chance out of 10
     chance = rand()%10+1;
     printf("What will you do? \n");
     printf("1. Fight the bear \n2. Run away \n3. Hide in the wagon \n");
     printf("(Choose a number): ");
     scanf("%d", &answer);
  
    //takes user's answer to produce to correct choice
    if( answer == 1)
    {
      
      //uses chance to create randomness in outcomes
      if( chance > 2)
      {
        
        printf("Sadly, you are no match for the bear. \n");
        printf("*One of your family memebers has been gravely injured* \n");
        printf("*******\n");
        
        //determines how much health will be subtracted from family member
        health = 50;
      
      }
      else if( chance <=2 )
      {
      
        printf("Miraculously, you have defeated the bear. \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //determines how much health will be subtracted from family member
        health = 0;
      
      }
      
      //breaks the error checking loop
      error = 1;
      
    }
    else if( answer == 2)
    {
    
      printf("You and your family jump out of the wagon and run away. \n");
      printf("This catches the attention of the bear "); 
      printf("who chases after one of your family members. \n");
    
      //uses chance to create randomness in outcomes
      if( chance <= 5)
      {
        
        printf("You manage to lose the bear and everyone returns to the wagon. \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //determines how much health will be subtracted from family member
        health = 0;
      
      }
      else if( chance > 5)
      {
      
        printf("The bear manages to catch up with the person it was chasing. \n");
        printf("*One of your family memebers has been injured* \n");
        printf("*******\n");
        
        //determines how much health will be subtracted from family member
        health = 20;
      
      }
      
      //breaks the error checking loop
      error = 1;
    
    }
    else if( answer == 3)
    {
        
      printf("You hide in the wagon, staying still and silent. \n");
      printf("The bear sniffs around, but eventually becomes bored and leaves. \n");
      printf("*You continue on the trail* \n");
      printf("*******\n");
      
      //determines how much health will be subtracted from family member
      health = 0;
      //breaks the error checking loop
      error = 1;
      
    }
    else
    {
    
      printf("Invalid answer, try again \n");
      
    }
  }
  
  return health;
}

int stranger()
{

  int answer;
  int answer2;
  int error = 0;
  int error2 = 0;
  int health = 0;

  printf("As you are traveling, you begin the hear shouting from the trees. \n");
  printf("A man stumbles onto the road, blocking your way. \n");
  printf("You stop the wagon before it can hit him, and he comes over to you. \n");
  printf("The man begs for your help, saying that some people jumped him in the woods. \n");
  
  //loop checks for user input errors
  while( error == 0)
  {
  
    printf("What will you do? \n");
    printf("1. Try to leave \n2. Agree to help the man \n");
    printf("(Choose a number): ");
    scanf("%d", &answer);
  
    //takes user's answer to produce to correct choice
    if( answer == 1)
    {
      
      printf("You tell that man that you cannot help him. \n");
      printf("He desperately grabs at the reins trying to stop you from leaving. \n");
      printf("He begs and pleads for you to help him. \n");
      
      //loop checks for user input errors
      while( error2 == 0)
      {
  
        printf("What will you do? \n");
        printf("1. Leave \n2. Give in and help him \n");
        printf("(Choose a number): ");
        scanf("%d", &answer2);
  
        //takes user's answer to produce to correct choice
        if( answer2 == 1)
        {
      
          printf("You pry the man's hands off of the reigns and leave him behind. \n");
          printf("*You continue on the trail* \n");
          printf("*******\n");
          
          //determines how much health will be subtracted from family member
          health = 0;
          //breaks first error checking loop
          error2 = 1;
      
        }
        else if( answer2 == 2)
        {
      
          //Allows next if statement to activate
          answer = 2;
          //breaks first error checking loop
          error2 = 1;
    
        }
        else
        {
    
          printf("Invalid answer, try again \n");
      
        }
      }
      
      //breaks the error checking loop
      error = 1;
      
    }
    if( answer == 2)
    {
      
      printf("You agree to help the man. He seems overjoyed. \n");
      printf("You and your family follow the man into the woods. \n");
      printf("As you walk deeper into the forest, you can hear rustling in the leaves around you. \n");
      
      //breaks second error checking loop
      error2 = 0;
      //breaks first error checking loop
      error = 1;
      
      //loop checks for user input errors
      while( error2 == 0)
      {
  
        printf("What will you do? \n");
        printf("1. Leave \n2. Continue following the man \n");
        printf("(Choose a number): ");
        scanf("%d", &answer2);
  
        //takes user's answer to produce to correct choice
        if( answer2 == 1)
        {
      
          printf("You are too suspicious of this whole situation and turn around to leave. \n");
          printf("The man crys and begs you to stay, but you don't listen. \n");
          printf("You return to the wagon and leave. \n");
          printf("*You continue on the trail* \n");
          printf("*******\n");
      
          //determines how much health will be subtracted from family member
          health = 0;
          //breaks second error checking loop
          error2 = 1;
      
        }
        else if( answer2 == 2)
        {
      
          printf("Eventually, you reach and empty clearing. \n");
          printf("You turn to the man, but he suddenly looks guilty. \n");
          printf("Suddenly, a bunch of men jump out of the bushes and begin to pounds you to a pulp. \n");
          printf("You pass out, and wake up hours later to your family calling your name. \n");
          printf("The men are nowhere in sight. \n");
          printf("*One of your family memebers has been injured* \n");
          printf("*******\n");
          
          //determines how much health will be subtracted from family member
          health = 50;
          //breaks second error checking loop
          error2 = 1;
    
        }
        else
        {
    
          printf("Invalid answer, try again \n");
      
        }
      }
    }
    else
    {
    
      printf("Invalid answer, try again \n");
      
    }
  }
    
  return health;

}
