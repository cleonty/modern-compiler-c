#include <stdio.h>
#include <string.h>
#include "table.h"

Table_ Table(string id, int value, struct table *tail) {
  Table_ t = checked_malloc(sizeof(*t));
  t->id = id;
  t->value = value;
  t->tail = tail;
  return t;
}

int lookup(Table_ t, string key) {
  while (t != NULL) {
    if (0 == strcmp(t->id, key)) {
      return t->value;
    }
    t = t->tail;
  }
  return 0;
}

Table_ update(Table_ t, string key, int value) {
  return Table(key, value, t);
}

void print(Table_ t) {
  if (t == NULL) {
    printf ("[Empty table]");
  }
  while (t != NULL) {
    printf ("%s = %d\n", t->id, t->value);
    t = t->tail;
  }
}