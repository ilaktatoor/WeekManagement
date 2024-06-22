#include "expenses.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void addExpense(WeekClass* week, const char* expense_description, float expense_amount){

   week->expenses =  realloc(week->expenses,(week->num_expenses +1)*sizeof(ExpenseClass));
   if(week->expenses == NULL){
    fprintf(stderr, "[!] MEM ALLOC ERROR");
    exit(1);
  }

  strcpy(week->expenses[week->num_expenses].description, expense_description);
  week->expenses[week->num_expenses].amount = expense_amount;
  week->num_expenses++;
}

void get_input(char* prompt, char *input, size_t size){
  printf("%s", prompt);
  fgets(input, size, stdin);
  input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character
  
}

float get_float_input(char *prompt){
  char input[MAX_INPUT_SIZE];
  float value;
  printf("%s",prompt);
  fgets(input,MAX_INPUT_SIZE,stdin);
  sscanf(input, "%f",&value);
  return(value);
}



// rootatkali
