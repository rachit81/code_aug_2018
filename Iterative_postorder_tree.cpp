#include <iostream>
#include <stack>
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

void postorder(struct Tnode * head)
{
    stack<Tnode *> mystack;
    mystack.push(head);

    struct Tnode * curr =NULL;
    struct Tnode *prev = NULL;
    while (!mystack.empty())
    {
        curr = mystack.top();
        mystack.pop();
        if (!prev || prev->left == curr || prev->right == curr){
            mystack.push(curr);

            if (curr->left)
                mystack.push(curr->left);
            else if (curr->right)
                mystack.push(curr->right);


        }else if (curr->left == prev)
            {
                mystack.push(curr);
                if (curr->right)
                    mystack.push(curr->right);

            }
            else{
                cout<<curr->data<<"\t";


            }




        prev = curr;
    }
    cout<<endl;
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

      postorder(head);

}
