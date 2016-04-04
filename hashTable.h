struct hashNode{
  int element;
  struct hashNode *next;
};
typedef struct hashNode * HashNodePtr;
struct hashTable{
  int size;
  HashNodePtr closeHashTable;
};
