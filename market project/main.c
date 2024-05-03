#include <stdio.h>
#include <stdlib.h>

 // The functions used in the program

void displayMenu(); // menu display
void theMain();    // main IP\OP interface
void addItems();
int choice();     // the product the user choose
void checkCount();// number of purchases
void countTotalCost();
void reciepe();

  //declaring some variable to use along the program

int count= 0;                   // count the number of purchases
static float cost=0;           // total cost
int overnightChoice;          // overnight shipping choice
int items[100];              // stores the items purchased


int main()
{
    printf("WELCOME.\n");
    displayMenu();
    theMain();
    checkCount();
    countTotalCost();
    reciepe();
    return 0;
}


void displayMenu()
{
    printf("########################  MENU  ###################### :\n\n");
    printf("                       #FRUITS# :\n\n");
    printf("1-Apple '20$' 2-Watermelon '10$' 3-Orange '07$' 4-Strawberry '10$'\n");
    printf("5-Mango '50$' 6-Banana     '08$'  7-Lemon '02$' 8-Pineapple '06$'\n\n");
    printf("#################################################################\n\n");
    printf("                      #VEGS# :\n\n");
    printf("9-Cucumber '07$' 10-Onion '02$' 11-Carrot '05$' 12-Tomato '08$' 13-Potato '10$'\n\n");
    printf("#################################################################\n\n");
}


void theMain()
{
    int choice;
    do
        {
          printf("press 1 to add items or 0 to finish : ");
          scanf("%d",&choice);
          if(choice)
          {
             addItems();
          }
          else
          {
             printf("finish\n");
          }
        }while(choice);
}

int choice()
{
    int choice,cost,element;
    printf("Choose a number for a product from the menu :");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Apple added\n");
        cost =20;
        break;
    case 2:
        printf("Watermelon added\n");
        cost =10;
        break;
    case 3:
        printf("Orange added\n");
        cost =7;
        break;
    case 4:
        printf("Strawberry added\n");
        cost =10;
        break;
    case 5:
        printf("Mango added\n");
        cost =50;
        break;
    case 6:
        printf("Banana added\n");
        cost =8;
        break;
    case 7:
        printf("Lemon added\n");
        cost =2;
        break;
    case 8:
        printf("Pineapple added\n");
        cost =6;
        break;
    case 9:
        printf("Cucumber added\n");
        cost =7;
        break;
    case 10:
        printf("Onion added\n");
        cost =2;
        break;
    case 11:
        printf("Carrot added\n");
        cost =5;
        break;
    case 12:
        printf("Tomato added\n");
        cost =8;
        break;
    case 13:
        printf("Potato added\n");
        cost =10;
        break;
    default :
        printf("INVALID INPUT\n");
    }
    items[count]=choice;
    count++;
    return cost;
}


void addItems()
{
    cost+=choice();
}


void checkCount()
{
    if(count==1)
    {
        printf("You must at least buy 2 items\n");
        addItems();
    }
    if(count==0)
    {
        printf("You must at least buy 2 items\n");
        addItems();
        addItems();
    }

}


void countTotalCost()
{
    if(cost<10)
        cost+=2;
    else
        cost+=3;
    printf("Do you want overnight shipping : 1-YES 2-NO : ");
    scanf("%d",&overnightChoice);
    if(overnightChoice==1)
        cost+=5;
    if(count>5)
        cost*=0.8;
}




void reciepe()
{
    printf("\n");
    printf("########################## RECIEPE ###################################\n");
    for(int i=0;i<count;i++)
    {
         switch(items[i])
    {
    case 1:
        printf("1 kg of Apple -> 20$ \n");
        break;
    case 2:
        printf("1 kg of Watermelon -> 10$ \n");
        break;
    case 3:
        printf("1 kg of Orange -> 07$ \n");
        break;
    case 4:
       printf("1 kg of Strawberry -> 10$ \n");
        break;
    case 5:
        printf("1 kg of Mango -> 50$ \n");
        break;
    case 6:
        printf("1 kg of Banana -> 08$ \n");
        break;
    case 7:
        printf("1 kg of Lemon -> 02$ \n");
        break;
    case 8:
        printf("1 kg of Pineapple -> 06$ \n");
        break;
    case 9:
        printf("1 kg of Cucumber -> 07$ \n");
        break;
    case 10:
        printf("1 kg of Onion -> 02$ \n");
        break;
    case 11:
       printf("1 kg of Carrot  -> 05$ \n");
        break;
    case 12:
        printf("1 kg of Tomato -> 08$ \n");
        break;
    case 13:
        printf("1 kg of Potato -> 10$ \n");
        break;
    }
    }
    if(cost<10)
        printf("02$ added for -10$ purchases\n");
    else
        printf("03$ added for +10$ purchases\n");
    if(overnightChoice==1)
        printf("05$ added for overnight shipping\n");
    if(count > 5)
        printf("You got 20% discount for +5 purchases\n");
    printf("##########################################################\n");
    printf("Total : %f\n",cost);
}



