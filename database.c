#include "expenses.h"
#include <cstddef>
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

void handle_errmsg(int rc, char *errmsg){
  if(rc != SQLITE_OK){
    fprintf(stderr, "[!] SQL error: %s\n",errmsg);
    sqlite3_free(errmsg);
  }else{
    fprintf(stdout, "[✓] Operation compleated successfully!\n");
  }

}

void initialize_db(sqlite3 **db){
  int rc = sqlite3_open("expenses.db", db);
  if(rc){
    fprintf(stderr,"[!] Can't open db : %s\n",sqlite3_errmsg(*db));
    sqlite3_close(*db);
    exit(1);
  }else{
    fprintf(stdout, "[✓] Opened DB successfully!\n");
  }
  create_table_if_not_exist(*db);
}


void create_table_if_not_exist(sqlite3 *db){
  //Sql querty to create table 
  const char *sql = "CREATE TABLE IF NOT EXISTS weeks(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL); CREATE TABLE IF NOT EXISTS expenses(id INTEGER PRIMARY KEY AUTOINCREMENT, week_id INTEGER NOT NULL ,description TEXT NOT NULL,amout REAL NOT NULL, FOREIGN KEY(week_id) REFERENCES weeks(id));";

  //execute statement
  int rc = sqlite3_exec(db, sql, NULL, 0, NULL);
  if(rc != SQLITE_OK){
    fprintf(stderr, "[!] SQL error %s\n",sqlite3_errmsg(db));
  }else{
    fprintf(stdout, "[✓] TABLES created successfully!\n");
  }

}  

void insert_expense(sqlite3 *db,const char* description, float amout){
  char sql[256];
  snprintf(sql, sizeof(sql), "INSERT INTO expenses(description, amout) VALUES ('%s',%.2f);", description, amout);

  char *errmsg = NULL;
  int rc = sqlite3_exec(db, sql, NULL, 0, &errmsg);
  handle_errmsg(rc, errmsg);  
}


void insert_week_to_db(sqlite3 *db, const char* week_name){
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO weeks (name) VALUES ('%s');",week_name);
    char *errmsg = NULL;
    int rc = sqlite3_exec(db, sql, NULL, 0, &errmsg);
    handle_errmsg(rc, errmsg);
}

void edit_expense_on_db(sqlite3 *db, int expense_id, const char *new_expense_descriptoin, float new_amount){
  char sql[256];
  snprintf(sql, sizeof(sql), "UPDATE expenses SET description = '%s', amout = '%.2f' WHERE id = %d;",new_expense_descriptoin,new_amount,expense_id);

  char *errmsg;
  int rc = sqlite3_exec(db, sql, NULL, 0, &errmsg);
  handle_errmsg(rc, errmsg);

} 

void show_expenses_of_week(sqlite3 *db, int week_id){
  char sql[256];
  snprintf(sql, sizeof(sql), "SELECT id, description, amout FROM expenses WHERE week_id = %d;",week_id);
  
  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
  
  if(rc != SQLITE_OK){
    fprintf(stderr, "[!] SQLITE err: %s\n",sqlite3_errmsg(db));
    return;
  }

  while(sqlite3_step(stmt) == SQLITE_ROW){
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char *description = sqlite3_column_text(stmt, 1);
    float amout = sqlite3_column_duoble(stmt, 2);
    printf("Expense id: %d, Description: %s, Amount: %.2f\n",id,description,amout);

  }
  sqlite3_finalize(stmt);

}
