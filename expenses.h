#ifndef EXPENSES_H
#define EXPENSES_H

#include <sqlite3.h>
#include <stddef.h> //for size_t
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
 
//db functions

void initialize_db(sqlite3 **db);
void create_table_if_not_exist(sqlite3 *db);
void insert_expense(sqlite3 *db,const char* description, float amount);
void insert_week_to_db(sqlite3 *db, const char* week_name);
void show_expenses_of_week(sqlite3 *db, int week_id);
void edit_expense_on_db(sqlite3 *db, int expense_id,const char* new_expense_descriptoin, float new_amount);
void list_weeks(sqlite3 *db);
void handle_errmsg(int rc, char *errmsg);
void close_db(sqlite3 **db);

#endif // DEBUG
       //
       //
       //
       //
       // rootatkali
