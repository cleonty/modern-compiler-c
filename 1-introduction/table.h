#ifndef TABLE_H
#define TABLE_H

#include "util.h"

typedef struct table *Table_;
struct table {
  string id;
  int value;
  Table_ tail;
};

Table_ Table(string id, int value, struct table *tail);
int lookup(Table_ t, string key);
Table_ update(Table_ t, string key, int value);
void print(Table_ t);

#endif