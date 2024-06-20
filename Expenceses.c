#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

  char description[255];
  float amount;

}Expense;

typedef struct{

  char name[255];
  Expense* expenses;
  int num_expenses;

}Week;

void addExpense(Week* week, const char* expense_description, float expense_amount){

  week->expenses = realloc(week->expenses, (weel->expenses + 1) * sizeof(Expense));


}


int main(){

return 0;

}
