//João Pedro Gubert de Souza
//Samuel Rudnicki

#ifndef HASH_HEADER
#define HASH_HEADER


#define HASH_SIZE 997

#define DATATYPE_FLOAT 1
#define DATATYPE_INT 2
#define DATATYPE_CHAR 3
#define DATATYPE_STR 4

#define SYMBOL_UNDEFINED 0
#define SYMBOL_IDENTIFIER 1
#define SYMBOL_LIT_INTEGER 2
#define SYMBOL_LIT_REAL 3
#define SYMBOL_LIT_CHAR 4
#define SYMBOL_LIT_STRING 5

#define SYMBOL_VAR 6
#define SYMBOL_VECTOR 7
#define SYMBOL_FUNC 8
#define SYMBOL_POINT 9
#define SYMBOL_PARAM 10

#define SYMBOL_LABEL 11


typedef struct hash_node{
  int type;
  char *text;
  int datatype;
  struct hash_node *next;
} HASH;

void hashInit(void);
HASH* hashInsert(int type, char *text);
void hashPrint(void);
int hashAddress(char *text);
HASH *hashSearch(int address, char *text,int *achou);
HASH *makeTemp();
HASH *makeUm();
HASH *makeLabel();
#endif
