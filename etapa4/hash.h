//João Pedro Gubert de Souza
//Samuel Rudnicki

#ifndef HASH_HEADER
#define HASH_HEADER

#define HASH_SIZE 997
#define DATATYPE_INT 1
#define DATATYPE_FLOAT 2
#define DATATYPE_CHAR 3
#define SYMBOL_OK 10
#define SYMBOL_IDENTIFIER 1

typedef struct hash_node{
  int type;
  int datatype;
  char *text;
  struct hash_node *next;
} HASH;

void hashInit(void);
HASH* hashInsert(int type, char *text);
void hashPrint(void);
int hashAddress(char *text);
HASH *hashSearch(int address, char *text,int *achou);

#endif
