#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

  int scene;
  int input = 0;
  int day;

  //sets up randomization for whole file
  srand(time(NULL));
  //randomly chooses between the three event
  scene = rand()%3+1;
  
  //use scene number to call correct event
  if( scene == 1 )
  {
  
    //checks to see if all three family memebers are alive from passsed value
    if( input == 0 )
    {
    
      printf("***EVENT***\n");
      //calls event
      day = stuckInMud();
    
    }
  }
  else if( scene == 2 )
  {
  
    printf("***EVENT***\n");
    //calls event
    day = deerCrash();
  
  }
  else
  {
  
    printf("***EVENT***\n");
    //calls event
    day = sadHorse();
  
  } 

  return 0;

}

//function for event 1
int stuckInMud()
{
  
  int answer;
  int error = 0;
  int chance;
  int day;

  printf("As you continue along the trail, your wagon suddenly lurches to a stop. \n");
  printf("You get out and see that one of the wheels has gotten stuck in some mud. \n");
  
  //loop checks for user input errors
  while( error == 0)
  {
     //generates chance out of 20
     chance = rand()%20+1;
     printf("How many family members should help out? (1, 2, or 3?): ");
     scanf("%d", &answer);
  
    //takes user's answer to produce to correct choice
    if( answer == 1)
    {
      
      //uses chance to create randomness in outcomes
      if( chance > 5)
      {
        
        printf("Your family spends the rest of the day trying to free your wagon from the mud. \n");
        printf("*Your trip has been delayed by one day* \n");
        printf("*******\n");
        
        //counts how many days the player will be set back to send back to main
        day = 1;
      
      }
      else
      {
      
        printf("After working for most of the day, you have freed the wagon from the mud! \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //counts how many days the player will be set back to send back to main
        day = 0;
      
      }
      
      //breaks the error checking loop
      error = 1;
      
    }
    else if( answer == 2)
    {
    
      //uses chance to create randomness in outcomes
      if( chance > 10)
      {
        
        printf("Your family spends the rest of the day trying to free your wagon from the mud. \n");
        printf("*Your trip has been delayed by one day* \n");
        printf("*******\n");
      
        //counts how many days the player will be set back to send back to main
        day = 1;
      
      }
      else
      {
      
        printf("After working for a few hours, the two of you have freed the wagon from the mud! \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //counts how many days the player will be set back to send back to main
        day = 0;
      
      }
      
      //breaks the error checking loop
      error = 1;
    
    }
    else if( answer == 3)
    {
    
      //uses chance to create randomness in outcomes
      if( chance > 15)
      {
        
        printf("Your family spends the rest of the day trying to free your wagon from the mud. \n");
        printf("*Your trip has been delayed by one day* \n");
        printf("*******\n");
        
        //counts how many days the player will be set back to send back to main
        day = 1;
      
      }
      else
      {
      
        printf("After working an hour, the three of you have freed the wagon from the mud! \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //counts how many days the player will be set back to send back to main
        day = 0;
      
      }
      
      //breaks the error checking loop
      error = 1;
    }
    else
    {
    
      printf("Invalid answer, try again \n");
      
    }
  }
  
  return day;
  
}

//function for event 2
int deerCrash()
{

  int answer;
  int error = 0;
  int chance;
  int day = 0;

  printf("You continue down the trail, enjoying nice weather. \n");
  printf("Suddenly, a deer jumps out in front of the wagon! \n");
  
  //loop checks for user input errors
  while( error == 0)
  {
  
    //generates chance out of 20
    chance = rand()%20+1;
    printf("What will you do? \n");
    printf("1. Swerve \n2. Attempt to stop \n");
    printf("(Choose a number): ");
    scanf("%d", &answer);
  
    //takes user's answer to produce to correct choice
    if( answer == 1)
    {
      
      //uses chance to create randomness in outcomes
      if( chance > 5)
      {
        
        printf("You yank hard on the reigns, swerving off of the path. \n");
        printf("The wagon slams into a tree, tipping over onto it's side. \n");
        printf("Thankfully, no one is hurt. You spend the rest of the day flipping the wagon. \n");
        printf("*Your trip has been delayed by one day* \n");
        printf("*******\n");
        
        //counts how many days the player will be set back to send back to main
        day = 1;
      
      }
      else
      {
      
        printf("You yank hard on the reigns, swerving off of the path. \n");
        printf("The ride becomes bumpy as you ride over the rough ground. \n");
        printf("You manage to stop the wagon before it slams into a nearby tree. \n");
        printf("Thankfully, no one is hurt. You return to the path. \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //counts how many days the player will be set back to send back to main
        day = 0;
      
      }
      
      //breaks the error checking loop
      error = 1;
      
    }
    else if( answer == 2)
    {
    
      //uses chance to create randomness in outcomes
      if( chance <= 10)
      {
        
        printf("You yank the reigns back, attempting to stop your horses. \n");
        printf("They manage to stop just in time, leaving the deer unharmed. \n");
        printf("It blinks at you, before prancing away into the trees. \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //counts how many days the player will be set back to send back to main
        day = 0;
      
      }
      else
      {
      
        printf("You yank the reigns back, attempting to stop your horses. \n");
        printf("However, you can not stop in time and slam into the deer. \n");
        printf("Everyone is sad. \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //counts how many days the player will be set back to send back to main
        day = 0;
      
      }
      
      //breaks the error checking loop
      error = 1;
    
    }
    else
    {
    
      printf("Invalid answer, try again \n");
      
    }
  }
  
  return day;
  
}

//function for event 3
int sadHorse()
{

  int answer;
  int error = 0;
  int horse = 0;
  int day = 0;
  int chance;

  printf("As you are traveling, you notice that the wagon is slowing down. \n");
  printf("You stop and get out, going up to check on the horses. \n");
  printf("One of the horses looks sad. \n");
  
  //loop checks for user input errors
  while( error == 0)
  {
  
    printf("What will you do? \n");
    printf("1. Be mean \n2. Be nice \n");
    printf("(Choose a number): ");
    scanf("%d", &answer);
  
    //takes user's answer to produce to correct choice
    if( answer == 1)
    {
      
      printf("You insult the horse and demand that he continue walking. \n");
      printf("He seems sadder. \n");
      
      //breaks the error checking loop
      error = 1;
      
    }
    else if( answer == 2)
    {
      
      printf("You encourage the horse, telling him that he's the best. \n");
      printf("He seems a little happier \n");
      
      //adds to horse's happiness
      horse = horse + 1;
      //breaks the error checking loop
      error = 1;
    
    }
    else
    {
    
      printf("Invalid answer, try again \n");
      
    }
  }
  
  //breaks the error checking loop
  error = 0;
  
  while( error == 0)
  {
  
    printf("What will you do? \n");
    printf("1. Be horrible \n2. Be encouraging \n");
    printf("(Choose a number): ");
    scanf("%d", &answer);
  
    //takes user's answer to produce to correct choice
    if( answer == 1)
    {
      
      printf("You begin to yell at the horse, telling him that he is useless. \n");
      
      //breaks the error checking loop
      error = 1;
      
    }
    else if( answer == 2)
    {
      
      printf("You tell the horse that you believe in him and ");
      printf("whould have never gotten here without him. \n");
      
      //adds to horse's happiness
      horse = horse + 1;
      //breaks the error checking loop
      error = 1;
    
    }
    else
    {
    
      printf("Invalid answer, try again \n");
      
    }
  }
  
  //checks horse's happiness to give player correct outcome
  if( horse == 0)
  {
      
    printf("You have broken the horse's spirit. He needs time to recover from your verbial lashing \n");
    printf("*Your trip has been delayed by one day* \n");
    printf("*******\n");
    
    //counts how many days the player will be set back to send back to main
    day = 1;
      
  }
  else if( horse == 1)
  {
      
    printf("The horse isn't feeling the best, but he goes back to pulling the wagon. \n");
    printf("*You continue on the trail* \n");
    printf("*******\n");
    
    //counts how many days the player will be set back to send back to main
    day = 0;
    
  }
  else if(horse == 2)
  {
    
    printf("The horse is glowing from the praise and support you've showed him. \n");
    printf("He works harder than he's ever worked before. \n");
    printf("*Your trip has been shortened by one day* \n");
    printf("*******\n");
    
    //counts how many days the player will be set back to send back to main
    day = -1;
      
  }
    
  return day;
  
}
