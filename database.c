#include "expenses.h"
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>


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
  const char *sql = "CREATE TABLE IF NOT EXISTS expenses(id INTEGER PRIMARY KEY AUTOINCREMENT,description TEXT NOT NULL,amout REAL NOT NULL);";

  //execute statement
  int rc = sqlite3_exec(db, sql, NULL, 0, NULL);
  if(rc != SQLITE_OK){
    fprintf(stderr, "[!] SQL error %s\n",sqlite3_errmsg(db));
  }else{
    fprintf(stdout, "[✓] Record created successfully!\n");
  }

}  

void insert_expense(sqlite3 *db,const char* description, float amout){
  char sql[256];
  snprintf(sql, sizeof(sql), "INSERT INTO expenses(description, amout) VALUES ('%s',%.2f);", description, amout);

  char *errmsg = NULL;
  int rc = sqlite3_exec(db, sql, NULL, 0, &errmsg);
  if(rc != SQLITE_OK){
    fprintf(stderr, "[!] SQL error: %s\n",errmsg);
    sqlite3_free(errmsg);
  }else{
    fprintf(stdout, "[✓]  Record created successfully!\n");
  }
  
}


