#include "expenses.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 


int main(){
  sqlite3 *db;
  initialize_db(&db);
  
  while (1) {
    printf("\n 1. Add week\n 2. Select week to add expense\n3. Edit expense\n4. Show expenses of a week\n5. List weeks\n6. Exit\n");
    int choise;
    printf("Enter your choise:");
    scanf("%d",&choise);
    getchar();

    if(choise == 1){
      //Add Week
      char week_name[MAX_INPUT_SIZE];
      get_input("Enter name of the week", week_name, sizeof(week_name));
      insert_week_to_db(db, week_name);

    }else if(choise == 2) {
      //week to add expense
      int week_id;
      printf("Enter week id to add expenses: ");
      scanf("%d",&week_id);
      getchar();

      char description[MAX_INPUT_SIZE];
      float amount;
      get_input("Enter expense description", description, sizeof(description));
      printf("Enter expense amount:$ ");
      scanf("%f",&amount);
      getchar();

      insert_week_to_db(db, week_id,description, amount);
    
    }else if(choise == 3){
      //Edit expenses
      int expense_id;
      printf("Enter expense id to edit it: ");
      scanf("%d",expense_id);
      getchar();

      char new_description[MAX_INPUT_SIZE];
      float new_amount;
      get_input("Enter new expense description: ", new_description, sizeof(new_description));
      printf("Enter new amount value:$ ");
      scanf("%f",&new_amount);
      getchar();

      edit_expense_on_db(db, expense_id, new_description, new_amount);

    }else if(choise == 4){
      //show expenses of a week
      int week_id;
      printf("Enter Week id to show expenses: ");
      scanf("%d",&week_id);
      getchar();

      show_expenses_of_week(db, week_id);

    }else if(choise == 5){
      //list weeks
      list_weeks(db);
    }else if(choise == 6){
      //exit
      break;
    }else{
      printf("[!] Invalid choise. try again");
    }
  
  }
  
  close_db(db);
  return 0;
}








// rootatkali
