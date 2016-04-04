#include <iostream>
#include <queue>
#include "bin_tree.h"
#include <cstdlib>

extern "C"
{
    void print_ascii_tree(struct Tnode * t);
}
using namespace std;

struct Tnode * insertNode(struct Tnode *root, int num)
{
  if (root == NULL)
  {
    Tnode *node = (Tnode *) malloc(sizeof(Tnode));
    node->data = num;
    node->left = NULL;
    node->right = NULL;
    return node;
  }
   return NULL;
}

void levelorder(struct Tnode * head,int data)
{
    queue<Tnode *> myqueue;
    myqueue.push(head);

    struct Tnode *temp = NULL;

    while (!myqueue.empty())
    {
        temp = myqueue.front();
        myqueue.pop();
        if (temp->left)
            myqueue.push(temp->left);
        else{
            temp->left = insertNode(NULL,data);break;
        }

        if (temp->right)
            myqueue.push(temp->right);
        else{
            temp->right = insertNode(NULL,data);break;
        }
    }
    cout<<endl;
}

int size(struct Tnode *head)
{
    if (!head)
        return 0;
    return (size(head->left) + 1 + size(head->right));

}
int main()
{
      struct Tnode *head = NULL;
      struct Tnode *temp = NULL;

      head = insertNode(NULL,1);
      head->left = insertNode(NULL,2);
      head->right = insertNode(NULL,3);

      temp= head->left;
      temp->left = insertNode(NULL,4);
      temp->right = insertNode(NULL,5);

      temp->right->left = insertNode(NULL,8);
      temp->right->right = insertNode(NULL,9);


      temp= head->right;
      temp->left = insertNode(NULL,6);
      temp->right = insertNode(NULL,7);

      print_ascii_tree(head);

        cout<<endl<<endl;
        cout<<endl<<endl;


      levelorder(head,10);
    levelorder(head,11);
    print_ascii_tree(head);

    cout<<size(head)<<"the size of tree \n"<<endl;

    return 1;
}

