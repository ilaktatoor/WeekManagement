#ifndef EXPENSES_H
#define EXPENSES_H

#include <stddef.h>
#define MAX_INPUT_SIZE 256 // Define MAX_INPUT_SIZE with your desired maximum size
//struct declarations
  
 typedef struct{

  char description[MAX_INPUT_SIZE];
  float amount;

} ExpenseClass;

typedef struct{

  char name[MAX_INPUT_SIZE];
  ExpenseClass* expenses;
  int num_expenses;

} WeekClass;

//function declarations
void addExpense(WeekClass* week, const char* expense_description, float expense_amount);
void get_input(char* prompt, char* input, size_t size );
float get_float_input(char* promt);


#endif // DEBUG
       //
       //
       //
       //
       // rootatkali
