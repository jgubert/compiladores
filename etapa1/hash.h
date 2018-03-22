//João Pedro Gubert de Souza
//Samuel Rudnicki

#define HASH_SIZE 997

typedef struct hash_node{
  int type;
  char *text;
  struct hash_node *next;
}HASH;

void hashInit(void);
HASH* hashInsert(int type, char *text);
void hashPrint(void);
int hashAddress(char *text);
int hashSearch(int address, char *text);
