#include "expenses.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 


int main(){
  sqlite3 *db;
  initialize_db(&db);
  create_table_if_not_exist(db);

  WeekClass semana1;
  get_input("Enter the name of the week: ", semana1.name, sizeof(semana1.name));
  semana1.expenses = NULL;
  semana1.num_expenses = 0;

  char description[MAX_INPUT_SIZE];
  float amount;

  while (1){
    get_input("Enter expense description (or 'exit' to finish): ", description, sizeof(description));

    if (strcmp(description, "exit")==0) {
      break;    
    }

    printf("Enter expense amount: ");
    scanf("%f",&amount);

    while(getchar() != '\n');

    addExpense(&semana1, description, amount);
    insert_expense(db, description, amount);

  }
  for(int i = 0; i< semana1.num_expenses; i++){
    printf("Expense %d: %s, %.2f\n",i+1,semana1.expenses[i].description,semana1.expenses[i].amount);

  }
  free(semana1.expenses);
  sqlite3_close(db);
  return 0;
}








// rootatkali
