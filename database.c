#include "expenses.h"
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


sqlite3 *db;


void initialize_db(){}

void create_table_if_not_exist(){}  

void insert_expense(const char* description, float amout){}

void close_db(){
  sqlite3_close(db);
}
