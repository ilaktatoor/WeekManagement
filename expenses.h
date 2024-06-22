#ifndef EXPENSES_H
#define EXPENSES_H

//struct declarations
  
 typedef struct{

  char description[255];
  float amount;

} ExpenseClass;

typedef struct{

  char name[255];
  ExpenseClass* expenses;
  int num_expenses;

} WeekClass;

//function declarations
void addExpense(WeekClass* week, const char* expense_description, float expense_amount);

#endif // DEBUG
       //
       //
       //
       //
       // rootatkali
