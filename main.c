#include "expenses.h"
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 


int main(){
  WeekClass semana1;

  // get user input
  get_input("enter name of the week: ",semana1.name, sizeof(semana1.name));
  semana1.expenses=NULL;
  semana1.num_expenses = 0;

  // add expenses
  char add_more = 'y';
  while(add_more == 'y' || add_more == 'Y'){

    char description[MAX_INPUT_SIZE];
    get_input("Expense description: ", description, sizeof(description));
    float amout = get_float_input("Expense Amout: $");
    addExpense(&semana1, description, amout);

    printf("Do you want to add anther expense? (y/n): ");
    scanf("%c",&add_more);
    getchar();

  }

  for(int i = 0; i<semana1.num_expenses; i++ ){
    printf("Expense %d: %s, %.2f\n",i + 1,semana1.expenses[i].description,semana1.expenses[i].amount);  
  }

  free(semana1.expenses);
  return(0);

}








// rootatkali
