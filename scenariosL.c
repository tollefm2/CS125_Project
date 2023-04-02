#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int scenariosL()
{

  int scene;
  int input = 0;
  int life;
  int randNumber = 3;

  //sets up randomization for whole file
  srand(time(NULL));
  //checks to see if all three family members are alive from passed value
  if( input == 1)
  {
  
    randNumber = 1;

  }

  //randomly chooses between the three event
  scene = rand()%randNumber+1;
  
  //use scene number to call correct event
  if( scene <= 2 )
  {
    
      printf("***EVENT***\n");
      //calls event
      life = flashFlood();
  
  }
  else if( scene == 3 )
  {
  
    printf("***EVENT***\n");
    //calls event
    life = otherFamily();
  
  }

  return life;

}

//function for event 1
int flashFlood()
{

  int answer;
  int error = 0;
  int chance;
  int life;

  printf("It has been storming all day. \n");
  printf("The weather continues to get worse and worse. \n");
  printf("As the wagon trudges through the rain, you hear the sound of rushing water. \n");
  printf("You turn around and from behind you comes a huge flood. \n");
  
  //loop checks for user input errors
  while( error == 0)
  {
  
    //generates chance out of 10
    chance = rand()%10+1;
    printf("What do you do? \n");
    printf("1. Get out and climb a nearby tree \n2. Speed away in the wagon \n");
    printf("(Choose a number): ");
    scanf("%d", &answer);
  
    //takes user's answer to produce to correct choice
    if( answer == 1)
    {
      
      //uses chance to create randomness in outcomes
      if( chance > 3)
      {
        
        printf("You scramble out of the wagon and into the nearby trees. \n");
        printf("The water crashes through where the wagon is, causing it to tip over. \n");
        printf("The trees that your family are in in stay strong. \n");
        printf("You wait for the water to pass by and then climb down. \n");
        printf("You right the wagon, check your belogings, and leave. \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //determines if family member has died to pass to main script
        life = 0;
      
      }
      else if( chance <= 3 )
      {
      
        printf("You head for the trees, but not everyone makes it in time. \n");
        printf("One of your family memebers is swept away by the current. \n");
        printf("They are never seen again. \n");
        printf("*You have lost a family memeber* \n");
        printf("*******\n");
        
        //determines if family member has died to pass to main script
        life = 1;
      
      }
      
      //breaks the error checking loop
      error = 1;
      
    }
    else if( answer == 2)
    {
      
      //uses chance to create randomness in outcomes
      if( chance <= 6)
      {
        
        printf("You stay in the wagon and begin to go as fast as you can. \n");
        printf("Despite how hard the horses are working, you can't out run the water. ");
        printf("It crashes into the wagon, tipping it over. \n");
        printf("One of your family memebers is swept away by the current. \n");
        printf("They are never seen again. \n");
        printf("*You have lost a family memeber* \n");
        printf("*******\n");
        
        //determines if family member has died to pass to main script
        life = 1;
      
      }
      else if( chance > 6)
      {
      
        printf("You stay in the wagon and begin to go as fast as you can. \n");
        printf("The horses push themselves to the limit, ");
        printf("just barely staying in front of the water. \n");
        printf("You eventually come upon an open area, ");
        printf("which helps to dispel the water. \n");
        printf("The little bit that's left rushes harmlessly by the wagon. \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //determines if family member has died to pass to main script
        life = 0;
      
      }
      
      //breaks the error checking loop
      error = 1;
    
    }
    else
    {
    
      printf("Invalid answer, try again \n");
      
    }
  }
  
  return life;

}

//function for event 2
int otherFamily()
{

  int answer;
  int error = 0;
  int chance;
  int life;

  printf("While stopping to rest in a small town, you meet another family ");
  printf("who is also traveling along the trail. \n");
  printf("You share drinks and tell stories of your adventures. \n");
  printf("Everyone has a great time, especally your child who hits it off with ");
  printf("someone from the other family. \n");
  printf("At the end of the night, the two of them come up to you ");
  printf("and declare that they are in love and want to get married. \n");
  
  //loop checks for user input errors
  while( error == 0)
  {
  
    //generates chance out of 10
    chance = rand()%10+1;
    printf("How do you respond? \n");
    printf("1. Absolutely not. \n2. Take some time to think about it. \n");
    printf("3. When's the wedding? \n");
    printf("(Choose a number): ");
    scanf("%d", &answer);
  
    //takes user's answer to produce to correct choice
    if( answer == 1)
    {
      
      //uses chance to create randomness in outcomes
      if( chance > 2)
      {
        
        printf("You tell the two that you will not let them get married. \n");
        printf("You take your child and return to your wagon to sleep. \n");
        printf("When you wake up, you find that your child is missing. \n");
        printf("In the middle of the night, the two of them met up and decided to run away together. \n");
        printf("They didn't want to be around people that didn't support their relationship. \n");
        printf("*You have lost a family memeber* \n");
        printf("*******\n"); 
        
        //determines if family member has left to pass to main script
        life = 2;
      
      }
      else if( chance <= 2 )
      {
      
        printf("You tell the two that you will not let them get married. \n");
        printf("You take your child and return to your wagon to sleep. \n");
        printf("In the morning you watch the two say their tearful goodbyes and leave the town \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //determines if family member has left to pass to main script
        life = 0;
      
      }
      
      //breaks the error checking loop
      error = 1;
      
    }
    else if( answer == 2)
    {
    
      printf("The two agree but don't look happy. \n");
      printf("Everyone turns in for the night. \n"); 
      
      //uses chance to create randomness in outcomes
      if( chance <= 5)
      {
        
        printf("In the morning, your child comes to you. \n");
        printf("They say that in the night, the two of them talked it through and ");
        printf("decided that they didn't actually want to get married. \n");
        printf("You congratulate your child on making the mature decision. \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //determines if family member has left to pass to main script
        life = 0;
      
      }
      else if( chance > 5)
      {
      
        printf("In the morning, both of them come to talk to you. \n");
        printf("They say that in the night, the two of them talked it through and ");
        printf("decided that they really do love each other and want to get married. \n");
        printf("You and your spouse tearfully say goodbye to your child as they leave ");
        printf("with the other family. \n");
        printf("*You have lost a family memeber* \n");
        printf("*******\n");
        
        //determines if family member has left to pass to main script
        life = 2;
      
      }
      
      //breaks the error checking loop
      error = 1;
    
    }
    else if( answer == 3)
    {
      
      //uses chance to create randomness in outcomes
      if( chance > 2 )
      {
        
        printf("The two of them seem surprised by your answer, but are overjoyed. \n");
        printf("They decide to travel with the other family while planning. \n");
        printf("You are sad, but happy that you child is happy. \n");
        printf("The next morning, ");
        printf("you say tearful goodbyes and they promise to invite you to the wedding. \n");
        printf("*You have lost a family memeber* \n");
        printf("*******\n");
        
        //determines if family member has left to pass to main script
        life = 2;
      
      }
      else if( chance <= 2 )
      {
      
        printf("The two of them seem surprised by your answer. \n");
        printf("Everyone goes to sleep but in the middle of the night your child comes to you. \n");
        printf("They say that they didn't expect for you to be immediately supportive ");
        printf("and that they proposed just to make you upset. \n");
        printf("You lightly scold your child but thank them for telling the truth. \n");
        printf("To avoid the other family, the three of you leave in the night. \n");
        printf("*You continue on the trail* \n");
        printf("*******\n");
        
        //determines if family member has left to pass to main script
        life = 0;
      
      }
      
      //breaks the error checking loop
      error = 1;
      
    }
    else
    {
    
      printf("Invalid answer, try again \n");
      
    }
  }

  return life;

}
