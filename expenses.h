#ifdef EXPENSES_H
#define EXPENSES_H

typedef struct{

  char description[255];
  float amount;

}Expense;

typedef{

  char name[255];
  Expense* expenses;
  int num_expenses;

}Week;

void addExpense(Week* week, const char* expense_description, float expense_amount);

#endif // DEBUG
