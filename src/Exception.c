#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdarg.h>
#include "CException.h"
#include "Exception.h"

void throwException(int errorCode, char *message, ...) {
  va_list args;
  char *buffer;
  int length;
  Exception *e;

  va_start(args, message);
  e = malloc(sizeof(Exception));

  length = vsnprintf(buffer, 0, message, args);
  buffer = malloc(length + 1);
  vsnprintf(buffer, length, message, args);

  e->msg = buffer;
  e->errorCode = errorCode;

  Throw(e);
}

void freeException(Exception *e) {
  if(e) {
    if(e->msg)
      free(e->msg);
    free(e);
  }
}

void dumpException(Exception *e) {
  printf("%s (err=%d)\n", e->msg, e->errorCode);
}
