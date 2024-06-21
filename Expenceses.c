#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expenses.h" 


int main(){
  Week semana1;
  strcpy(semana1.name, "semana1");
  semana1.expenses=NULL;
  semana1.num_expenses = 0;

  addExpense(&semana1,"wallmart",1576.89);
  addExpense(&semana1,"heb",150.00);

  for(int i = 0; i<semana1.num_expenses; i++ ){
    printf("Expense %d: %s, %.2f\n",i + 1,week.expenses[i].description,week.expenses[i].amount);  
  }

  free(semana1.expenses);
  return(0);

}
