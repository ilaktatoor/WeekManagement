#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expenses.h"

void addExpense(Week* week, const char* expense_description, float expense_amount){

   week-> expenses =  realloc(week->expenses,(week->num_expenses +1)*sizeof(Expense));
   if(week->expenses == NULL){
    fprintf(stderr, "[!] MEM ALLOC ERROR");
    exit(1);
  }

  strcpy(week->expenses[week->num_expenses].descripcion, expense_description);
  week->expenses[week->num_expenses].amount = expense_amount;
  week->num_expenses++;

}
