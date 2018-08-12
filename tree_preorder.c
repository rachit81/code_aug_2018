#include "bin_tree.h"
#include<stdio.h>
#include<limits.h>
void print_ascii_tree(struct Tnode * t);
#define MAX 100

typedef struct qnode{
  Tnode * queue[MAX];
  int rear;
  int front;
  int size;
}QNODE;

QNODE *Qnode =NULL;

void Qinit()
{
  Qnode = (QNODE *)malloc(sizeof(QNODE));
  Qnode->rear =0;
  Qnode->front =0;
  Qnode->size =0;
}
void Qreset()
{
  Qnode->rear =0;
  Qnode->front =0;
  Qnode->size =0;
}


void enqueue(Tnode * num)
{
  if (Qnode->size == MAX)
  {
    printf(" queue full \n");
    return;
  }
  Qnode->queue[Qnode->rear] = num;
  Qnode->rear = (Qnode->rear+1)%MAX;
  Qnode->size++;
}

int isQempty()
{
  if (Qnode->size == 0)
  {
    return 1 ;
  }
  return 0;
}

Tnode * dequeue()
{
  Tnode * num =0;

  if (Qnode->size == 0)
  {
    printf("queue empty\n");
    return -1 ;
  }
  num = Qnode->queue[Qnode->front];
  Qnode->front = (Qnode->front+1)%MAX;
  Qnode->size--;
  return num;
}

struct Tnode * insertNode(struct Tnode *root, int num)
{
  if (root == NULL)
  {
    Tnode *node = (Tnode *) malloc(sizeof(Tnode));
    node->data = num;
    node->left = NULL;
    node->right = NULL;
    node->right = NULL;
    return node;
  }
   return NULL;
}

Tnode * stk[MAX];
int top =-1;
void push(Tnode * num)
{
  if(top == MAX)
  {
  printf("stack overflow \n");
  return;
  }
stk[++top] = num;
}

Tnode * peek()
{
Tnode * node;
  if(top == -1)
  {
  //printf("stack underflow \n");
  return NULL;
  }
node = stk[top];
return node;

}


Tnode * pop()
{
Tnode * node;
  if(top == -1)
  {
  //printf("stack underflow \n");
  return NULL;
  }
node = stk[top];
top--;
return node;

}
int isEmpty()
{
  if(top == -1)
  {
    //printf("stack underflow \n");
  return 1;
  }
  return 0;
}

void preorder_nonRecursive(struct Tnode * root)
{
    Tnode *node = NULL;
    if (root)
        push(root);

    while(!isEmpty())
    {
        node = pop();
         printf("%d ",node->data);
         if (node->right)
            push(node->right);

         if (node->left)
            push(node->left);

    }

}

void inorder_nonRecursive(struct Tnode * root)
{
    Tnode *node = root;
    if (!root)
         return;

    while (1)
    {
        while(node)
        {
            push(node);
            node =node->left;
        }

        node = pop();
        if (node == NULL)
         break;
        printf(" %d ",node->data);

        node = node->right;
    }


}

void preorder_Recursive(struct Tnode * root)
{
    Tnode *node = NULL;
    if(root)
    {
        printf("%d ",root->data);
        preorder_Recursive(root->left);
        preorder_Recursive(root->right);
    }

}

void postorder_Recursive(struct Tnode * root)
{
    Tnode *node = NULL;
    if(root)
    {
        postorder_Recursive(root->left);
        postorder_Recursive(root->right);
        printf("%d ",root->data);
    }

}
void levelorder(struct Tnode * root)
{
    struct Tnode * curr =NULL;
    Qinit();
    if (root == NULL)
        return;

    enqueue(root);
    printf("level porder \n");
    while(!isQempty())
    {
        curr = dequeue();
        printf("    %d ->",curr->data);
        if (curr->next)
        printf(" %d",curr->next->data);

        if (curr->left)
            enqueue(curr->left);
        if (curr->right)
            enqueue(curr->right);

    }
    printf("\n");

}



int tree_size(struct Tnode * root)
{
    if (root ==NULL)
        return 0;

    return (tree_size(root->left) + 1 + tree_size(root->right));
}
int tree_max(struct Tnode * root)
{
    int max = INT_MIN;
    int max_left;
    int max_right;

    if (root)
    {
        max_left = tree_max(root->left);
        max_right = tree_max(root->right);
        if ( max_right > max_left)
        {
            max = max_right;
        }
        else{
            max = max_left;
        }
        if ( max < root->data)
            max = root->data;
    }
    return max;
}

int tree_find(struct Tnode * root, int data)
{
    if (root == NULL)
        return 0;

    if (root->data == data)
        return 1;
    else
        return (tree_find(root->left,data) || tree_find(root->right,data));

}
void insertNodeTree(struct Tnode ** root,int data)
{
    struct Tnode * curr =NULL;
    struct Tnode * temp =NULL;

    if (*root == NULL)
    {
                Qinit();
        temp = malloc (sizeof(struct Tnode));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        *root =temp;
        //printf ("\n ROOT 0x%x %d left 0x%x right 0x%x \n",temp,temp->data,temp->left,temp->right);
        return;
    }


    enqueue(*root);

    while(!isQempty())
    {
        curr = dequeue();

        if (curr->left)
            enqueue(curr->left);
         else
         {
            temp = malloc (sizeof(struct Tnode));
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;

            curr->left =temp;
            break;
         }
        if (curr->right)
            enqueue(curr->right);
         else
         {
            temp = malloc (sizeof(struct Tnode));
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            curr->right =temp;

            break;
         }
    }

    Qreset();
}

int tree_diameter(struct Tnode * root,int *diam)
{
    struct Tnode * temp;
    int ldepth = 0;
    int rdepth = 0;
    if (root == NULL)
        {
           return 0;
        }

    ldepth = tree_diameter(root->left,diam);
    rdepth = tree_diameter(root->right,diam);

    if (*diam < (ldepth +rdepth+1))
    {
        *diam = ldepth + rdepth+1;
    }

    if (ldepth > rdepth)
    {
        return ldepth+1;
    }else
    {
        return rdepth+1;
    }


}


int isHeightBalanced(struct Tnode * root,int *isBal)
{


    int left_height = 0;
    int right_height = 0;

    if (root==NULL)
        return 0;
    if (*isBal == 0)
        return;

    left_height = isHeightBalanced(root->left,isBal);
    right_height = isHeightBalanced(root->right,isBal);


}


int tree_height(struct Tnode * root)
{
    int left_height=0;
    int right_height =0;
    if (root == NULL)
        return 0;

    left_height = tree_height(root->left);
    right_height = tree_height(root->right);

    if (left_height > right_height)
        return left_height +1;
    else
        return right_height +1;
}

int treeDate[100];

void PrintPathTree(struct Tnode * root,int index)
{
    int i =0;
    if (root == NULL)
    {
        return;
    }
    treeDate[index++] = root->data;

    if (root->left == NULL && root->right == NULL)
    {
        for(i=0;i<index;i++)
        {
            printf("%d ",treeDate[i]);
        }
        printf("\n================\n");

        return;
    }
    PrintPathTree(root->left,index);
    PrintPathTree(root->right,index);
}

int countLeaf(struct Tnode * root)
{
    if (root==NULL)
        return;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return (countLeaf(root->left)+ countLeaf(root->right));
}

struct Tnode * inorderSuccessor(struct Tnode * root)
{
  struct Tnode * temp =NULL;
  struct Tnode * temp1 =NULL;
    if (root ==NULL)
        return;
    if (root->left == NULL)
        temp = root;

    temp1 = inorderSuccessor(root->left);

    if (root->left == NULL)
        temp = temp1;

    if (root->left)
        root->left->next = root;

    temp1 = inorderSuccessor(root->right);

    if (temp1)
        root->next = temp1;
    else
        root->next = root->right;
    return temp;
}

int levelNode(struct Tnode * root,int num,int level)
{
    int rlevel =0;
    if (root == NULL)
        return 0;

    if (root->data == num)
        return level;

    rlevel = levelNode(root->left,num,level+1);
    if (!rlevel)
    {
        rlevel = levelNode(root->right,num,level+1);
    }
    return rlevel;
}

void printKdistance(struct Tnode * root,int k,int level)
{
    if (root == NULL)
        return;
    if ( k == level)
      {
         printf("%d ",root->data);
         return;
      }
   printKdistance(root->left,k,level+1);
   printKdistance(root->right,k,level+1);
}

int max_level[100];

void maximumWidth(struct Tnode * root,int level)
{
    if (root == NULL)
        return;

    max_level[level]++;

    maximumWidth(root->left,level+1);
    maximumWidth(root->right,level+1);


}
void doubleTree(struct Tnode * root)
{
    struct Tnode* temp =NULL;
    if (root == NULL)
        return;

    doubleTree(root->left);
    doubleTree(root->right);

    temp = (struct Tnode*)malloc(sizeof(struct Tnode));
    temp->data =root->data;
    temp->left = root->left;
    root->left = temp;
}

int sumLeftLeaf(struct Tnode * root,int *sum)
{
    int isLeaf;

    if (root == NULL)
        return 0;

    if ((root->left == NULL)&& (root->right == NULL))
        return 1;

    isLeaf = sumLeftLeaf(root->left,sum);
    if(isLeaf)
        *sum = *sum + root->left->data;
    isLeaf = sumLeftLeaf(root->right,sum);

    return 0;
}

int getlevel(struct Tnode * root,int data, int level)
{
    int temp_level;

    if (root == NULL)
        return 0;

    if (root->data == data)
        return level;

    temp_level = getlevel(root->left,data,level+1);
    if (temp_level == 0)
        temp_level = getlevel(root->right,data,level+1);

    return temp_level;

}

struct Tnode * parent(struct Tnode * root, int data1)
{
   struct Tnode * temp =NULL;

   if (root == NULL)
        return NULL;

    if (((root->left) && (root->left->data == data1)) || ((root->right) && (root->right->data == data1)))
    {
        return root;
    }

    temp = parent(root->left,data1);
    if (!temp)
        temp =  parent(root->right,data1);

    return temp;


}


int isCousin(struct Tnode * root, int data1, int data2)
{
    int level1,level2;
    struct Tnode * parent1=NULL;
    struct Tnode * parent2=NULL;
    if (root == NULL )
        return 0;

    level1 = getlevel(root,data1, 1);
    level2 = getlevel(root,data2, 1);
    printf("level1 %d level2 %d \n",level1,level2);
    if ((!level1 && !level2) || (level1 != level2))
        return 0;

    parent1 = parent(root,data1);
    parent2 = parent(root,data2);

    if (parent1)
    printf ("parent1 %x  \n",parent1);


    if (parent2)
    printf ("parent2 %x  \n",parent2);

    if (parent1 != parent2)
        return 1;
    else
        return 0;
}

void printLevelRange(struct Tnode * root, int minlvel, int maxlevel,int level )
{
    if ((root == NULL) || (level > maxlevel))
        return;

    if (level >= minlvel && level <= maxlevel)
        printf("%d ",root->data);

    printLevelRange(root->left, minlvel, maxlevel,level+1);
    printLevelRange(root->right, minlvel, maxlevel,level+1);
}

int printAncestors(struct Tnode * root, int data)
{
    if (root == NULL)
        return 0;

    if (root->data == data)
        return 1;

    if(printAncestors(root->left,data))
    {
        printf("%d ",root->data);
        return 1;
    }
    if(printAncestors(root->right,data))
    {
        printf("%d ",root->data);
        return 1;
    }
    return 0;
}

void minimumDepth(struct Tnode * root, int level,int *minlevel)
{
    if (root == NULL)
        return;

    if (!root->left && !root->right)
    {
        if (*minlevel > level)
            *minlevel = level;
        return;
    }
    minimumDepth(root->left,level+1,minlevel);
    minimumDepth(root->right,level+1,minlevel);
    return;
}
int leafarr[100];
int visited[100];

void distanceKleaf(struct Tnode * root,int level,int k)
{
    int lleft =0;
    int lright=0;
    int print =0;
    if (root == NULL)
        return 0;

    leafarr[level]= root->data;
    visited[level] =0;

    if((root->left == NULL) && (root->right == NULL))
    {
        if ((visited[level-k] == 0) && (level-k > 0))
            {
                printf("%d ",leafarr[level-k]);
            }
        visited[level-k] =1;
        return;
    }

    distanceKleaf(root->left,level+1,k);
    distanceKleaf(root->right,level+1,k);

    return;

}

 int LeafAtSameLevel(struct Tnode * root,int level,int *leafLevel)
 {
     if (root == NULL)
        return;

     if ((root->left == NULL) && (root->right == NULL))
     {
        if ((!*leafLevel) || (*leafLevel == level))
        {
            *leafLevel = level;
            return 1;
        }else
        {
            return 0;
        }

     }

    return ((LeafAtSameLevel(root->left,level+1,leafLevel)) &&
            (LeafAtSameLevel(root->right,level+1,leafLevel)));

 }

 void noSibling(struct Tnode * root)
 {
     if (root == NULL)
        return;

     if (root->left && root->right)
     {
         noSibling(root->left);
         noSibling(root->right);
     }else if (root->left)
     {
        printf("%d ",root->left->data);
        noSibling(root->left);
     }else if (root->right)
     {
        printf("%d ",root->right->data);
        noSibling(root->right);
     }
     return;
 }

 int isSumTree(struct Tnode * root,int *isSum)
 {
     int lsum=0;
     int rsum=0;

    if (root == NULL)
    {
        *isSum =1;
        return 0;
    }

    lsum =isSumTree(root->left,isSum);

    if (*isSum == 0)
        return 0;

    rsum = isSumTree(root->right,isSum);

    if (*isSum == 0)
        return 0;

    *isSum = ((root->left == NULL && root->right == NULL) ||(root->data == (lsum + rsum)));
    return (root->data + lsum + rsum);
 }

 int isSameTree(struct Tnode * root,struct Tnode * sub)
{
    if ((root == NULL) && (sub == NULL))
        return 1;

    if ((root == NULL) || (sub == NULL))
        return 0;

    return ((root->data == sub->data) && isSameTree(root->left,sub->left) && isSameTree(root->right,sub->right));
}

 int subtree(struct Tnode * root,struct Tnode * sub)
 {
    if (root == NULL)
        return (root == sub);

    if(root->data == sub->data)
    {
        if (isSameTree(root,sub))
            return 1;
    }else
    {
        return (subtree(root->left,sub) ||subtree(root->right,sub));
    }
 }

 void maxSumLeaf(struct Tnode * root,int tempSum,int *maxSum)
 {
    if (root == NULL)
        return;

   tempSum =  tempSum + root->data;

   if ((root->left == NULL) && (root->right ==NULL))
   {
       if (tempSum > *maxSum)
       {
            *maxSum = tempSum;
       }

       return;
   }


   maxSumLeaf(root->left,tempSum,maxSum);
   maxSumLeaf(root->right,tempSum,maxSum);
 }

 struct Tnode * extractLeafLDLL(struct Tnode * root, struct Tnode **head)
 {
    if (root == NULL)
    {
        return NULL;
    }

    if ((root->left == NULL) && (root->right== NULL))
    {
        if (*head)
        {
            root->right = *head;
            (*head)->left = root;
        }
        *head =root;
        return NULL;
    }
    root->left = extractLeafLDLL(root->left,head);
    root->right = extractLeafLDLL(root->right,head);

    return root;
 }

int deepLeftLeaf(struct Tnode * root,int level,int *maxlevel)
{
    int  isLeaf=0;
    if (root == NULL)
        return 0;
    if ((root->left == NULL) && (root->right == NULL))
    {
        return 1;
    }

    isLeaf = deepLeftLeaf(root->left,level+1,maxlevel);
    if (isLeaf)
    {
        if ((level+1) > *maxlevel)
        {
            *maxlevel = level+1;
        }
    }
    isLeaf = deepLeftLeaf(root->right,level+1,maxlevel);
    return 0;
}

void printLeftView(struct Tnode * root,int level,int *levelPrint)
{
    if (root == NULL)
        return;
    if (*levelPrint < level)
    {
        printf("%d ",root->data);
        *levelPrint = level;
    }
    printLeftView(root->left,level+1,levelPrint);
    printLeftView(root->right,level+1,levelPrint);

    return;
}

void printRightView(struct Tnode * root,int level,int *levelPrint)
{
    if (root == NULL)
        return;
    if (*levelPrint < level)
    {
        printf("%d ",root->data);
        *levelPrint = level;
    }
    printRightView(root->right,level+1,levelPrint);
    printRightView(root->left,level+1,levelPrint);

    return;
}


void calculateHorizontalLevel(struct Tnode * root, int *min, int *max , int level)
{
    if (root == NULL)
        return;

    if (level < *min)
         *min= level;

    if (level > *max)
        *max = level;

    calculateHorizontalLevel(root->left,min,max,level-1);
    calculateHorizontalLevel(root->right,min,max,level+1);


}


void PrintVerticalLevel(struct Tnode * root, int level,int printLevel)
{
    if (root == NULL)
        return;

    if (printLevel == level)
    {
        printf("%d ",root->data);
    }

    PrintVerticalLevel(root->left,level-1,printLevel);
    PrintVerticalLevel(root->right,level+1,printLevel);

    return;
}


void PrintVerticalLevelSum(struct Tnode * root, int level,int printLevel,int *sum)
{
    if (root == NULL)
        return;

    if (printLevel == level)
    {
        *sum = *sum + root->data;
    }

    PrintVerticalLevelSum(root->left,level-1,printLevel,sum);
    PrintVerticalLevelSum(root->right,level+1,printLevel,sum);

    return;
}


void printVerticalTree(struct Tnode * root)
{
    int minLevel = 0;
    int maxLevel = 0;
    int hlevel = 0;
    int i =0;
    int sum =0;
    calculateHorizontalLevel(root,&minLevel,&maxLevel,hlevel);
    printf("min %d max %d \n",minLevel,maxLevel);

    for (i = minLevel;i <= maxLevel;i++)
    {
        sum =0;
        PrintVerticalLevel(root,0,i);
        printf("=====\n");
        PrintVerticalLevelSum(root,0,i,&sum);
        printf("\n %d <-------->\n",sum);
    }

}

void Connectlevelorder(struct Tnode * root)
{
    struct Tnode * curr =NULL;
    struct Tnode * prev =NULL;
    int level=1;
    Qinit();
    if (root == NULL)
        return;
    root->next = NULL;
    enqueue(root);
    enqueue(NULL);
    printf("Connection -- level porder \n");
    while(!isQempty())
    {
        curr = dequeue();
        if (curr == NULL)
        {
           printf("======================================= level %d\n",level);
           level++;
           if (!isQempty())
           {
                enqueue(NULL);
           }
           if (prev)
            {
                prev->next = NULL;
            }
            printf("NULL in queue prev 0x%x \n",prev);
           prev = NULL;
        }
        else
        {
            if (prev)
            {
                prev->next = curr;
            }
            prev =curr;
            printf(" %d ->",curr->data);

            if (curr->left)
                enqueue(curr->left);
            if (curr->right)
                enqueue(curr->right);
        }
    }
    printf("\n");

}

void tracelevelorder(struct Tnode * root)
{
  struct Tnode * curr =NULL;
    struct Tnode * prev =NULL;
    struct Tnode * temp =NULL;
    int start =1;
    int level=1;
    Qinit();
    if (root == NULL)
        return;

    enqueue(root);
    enqueue(NULL);
    printf("Connection -- level porder \n");
    while(!isQempty())
    {
        curr = dequeue();
        if (curr == NULL)
        {
           printf("======================================= level %d\n",level);
           level++;
           if (!isQempty())
           {
                enqueue(NULL);
           }
           start =1;
        }
        else
        {
            temp = curr;
            while (start && temp){
                 printf(" %d ->",temp->data);
                temp = temp->next;
            }
            start =0;
            if (curr->left)
                enqueue(curr->left);
            if (curr->right)
                enqueue(curr->right);
        }
    }
    printf("\n");

}

      struct Tnode *first = NULL;

void populateInorderSucessor(struct Tnode * root, struct Tnode **prev)
{
    if (root == NULL)
        return;

    populateInorderSucessor(root->left,prev);

    if (*prev)
    {
        (*prev)->next = root;
    }
    else{

        first = root;
    }
    *prev =root;
    printf("%d ",root->data);

    populateInorderSucessor(root->right,prev);
}

/********************Diagonal Traversal of Binary Tree*********************/
int numOfDiagonals(struct Tnode * root, int curr)
{
    int LeftDiag =0;
    int RightDiag =0;
    int maxDiag =0;

    if (root == NULL)
        return curr-1;

    LeftDiag = numOfDiagonals(root->left, curr+1);
    RightDiag = numOfDiagonals(root->right, curr);

    if(LeftDiag > RightDiag )
        return LeftDiag;
    else
        return RightDiag;

}

void PrintLeft(struct Tnode * root, int curr,int printDiag)
{

    if (root == NULL)
        return;

    if (printDiag== curr)
    {
        printf("%d ",root->data);
    }

    PrintLeft(root->left, curr+1,printDiag);
    PrintLeft(root->right, curr,printDiag);

}

void Printdiagonal(struct Tnode * root)
{
    int depthleft =0;
    int i=0;
    depthleft =  numOfDiagonals(root,0);
    printf(" depth %d ",depthleft);

    for(i=0;i<=depthleft;i++)
    {
        PrintLeft(root,0,i);
        printf("\n\////////////////n");
    }
}
/**********************Diagonal Traversal of Binary Tree******************/

/**********************given Binary Tree is Complete or not******************/

int IsCompletelevelorder(struct Tnode * root)
{
    struct Tnode * curr =NULL;
    int onlyLeaf =0;
    Qinit();
    if (root == NULL)
        return 1;

    enqueue(root);
    printf("IS COMPLETE :-) \n");
    while(!isQempty())
    {
        curr = dequeue();
        printf(" %d ->",curr->data);

        if (onlyLeaf)
        {
            if (curr->left || curr->right)
                return 0;
        }
        if (curr->left == NULL && curr->right!= NULL)
            return 0;
        if (curr->left!=NULL && curr->right == NULL)
        {
            onlyLeaf =1;
        }

        if (curr->left)
            enqueue(curr->left);
        if (curr->right)
            enqueue(curr->right);

    }
    printf("\n");
    return 1;
}

/**********************given Binary Tree is Complete or not******************/



/*****************Reverse alternate levels of a perfect binary tree*****************/

int inordArr[100];
int inIndex=0;

void populateArray(struct Tnode * root,int level)
{
    if (root == NULL)
        return;

    populateArray(root->left,level+1);

   // if (!(level & 0x1))
    {
        inordArr[inIndex++] = root->data;
    }

    populateArray(root->right,level+1);

}


void populateTreeInorder(struct Tnode * root,int level)
{
    if (root == NULL)
        return;

    populateTreeInorder(root->left,level+1);

 //   if (!(level & 0x1))
    {
        root->data = inordArr[--inIndex];
    }

    populateTreeInorder(root->right,level+1);

}


void reverseAltLevels(struct Tnode * root)
{
    int i =0;
    int end =0;
    int temp;
    populateArray(root,1);
    for (i=0;i<inIndex;i++)
    {
     //   printf(" %d",inordArr[i]);
    }
    populateTreeInorder(root,1);
}


/*****************Reverse alternate levels of a perfect binary tree*****************/

/*****************Deletion/Insertion/Search of a key perfect binary search tree*****************/

int nextInorderNode(struct Tnode *root)
{
    struct Tnode *temp =root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp->data;
}


struct Tnode *deleteBST(struct Tnode *root, int key)
{
    int inorder_data;
    struct Tnode *temp =NULL;
    if (root == NULL)
        return NULL;

    if (root->data == key)
    {
        if((root->left == NULL) && (root->right == NULL))
        {
            free(root);
            return NULL;
        }
        else if(root->left && root->right)
        {
            inorder_data = nextInorderNode(root->right);
            root->right = deleteBST(root->right,inorder_data);
            root->data = inorder_data;
        }
        else
        {
            if (root->left)
            {
                temp = root->left;
            }else
            {
                temp = root->right;
            }
            free(root);
            return temp;
        }
    }
    else if (root->data > key)
    {
        root->left = deleteBST(root->left,key);
    }
    else
    {
        root->right = deleteBST(root->right,key);
    }
    return root;
}

struct Tnode *insertBST(struct Tnode *root, int key)
{
    struct Tnode *temp =NULL;
    if (root == NULL)
    {
        temp = (struct Tnode *)malloc(sizeof(struct Tnode));
        temp->left = NULL;
        temp->right = NULL;
        temp->data = key;
        return temp;
    }
    if (key < root->data){
        root->left = insertBST(root->left,key);
    }else {
        root->right = insertBST(root->right,key);
    }
    return root;
};

struct Tnode *searchBST(struct Tnode *root, int key)
{
    struct Tnode *temp =NULL;
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->data){
        return searchBST(root->left,key);
    }
    else if (key > root->data){
        return searchBST(root->right,key);
    }
    else
    {
        return root;
    }

};


/*****************Insertion/Search of a key perfect binary search tree*****************/

/*****************Check if it is a BST *****************/

int isBST(struct Tnode *root,int min, int max)
{
    if (root == NULL)
        return 1;

    if (root->data < min || root->data > max)
        return 0;

    return ((isBST(root->left,min,root->data)) && (isBST(root->right,root->data,max)));

}


/*****************Check if it is a BST *****************/


/*****************Sorted Array to Balanced BST *****************/

struct Tnode * sortedArrBST(struct Tnode *root,int arr[],int start,int end)
{
    int mid;

    if (start > end )
        return NULL;
    mid = (start + end)/2;

    root = insertBST(root,arr[mid]);


    root->left = sortedArrBST(root->left,arr,start,mid-1);
    root->right = sortedArrBST(root->right,arr,mid+1,end);

    return root;
};

/*****************Sorted Array to Balanced BST *****************/

/*******Largest number in BST which is less than or equal to N ********/

int LargestNumBST(struct Tnode *root, int number)
{
    if (root == NULL)
        return -1;

    if (root->data < number)
    {
        if (!root->right || ((root->right)&& (root->right->data > number)))
            return root->data;
        else
            return LargestNumBST(root->right,number);
    }
    else
    {
        if ((root->left == NULL) && (number < root->data))
            return -1;
        else
            return LargestNumBST(root->left,number);

    }
}

/*******Largest number in BST which is less than or equal to N ********/


/*******BST internal node has exactly one child ********/

int oneChildBST(struct Tnode *root)
{
    if (root == NULL)
        return 1;

    if (root->left && root->right)
        return 0;

    return ((oneChildBST(root->left)) && (oneChildBST(root->right)));
}

/*******BST internal node has exactly one child ********/

/******* Kth smallest element in BST ********/

void KthSmallestBST(struct Tnode *root,int k, int *curr,int *num )
{
    if (root == NULL)
        return;

    KthSmallestBST(root->left,k,curr,num);

    (*curr)++;

    if (*curr == k)
        *num = root->data;

    if (*curr > k)
        return;

    KthSmallestBST(root->right,k,curr,num);
}

/******* Kth smallest element in BST ********/

/*******Convert a BST to a Binary Tree such that sum of all greater keys is added to every key********/

void sumBstToBinaryTree(struct Tnode *root, int *sum)
{
    if (root == NULL)
        return;
    sumBstToBinaryTree(root->right,sum);

    *sum = *sum + root->data;
    root->data = *sum;

    sumBstToBinaryTree(root->left,sum);
    return;
}

/*******Convert a BST to a Binary Tree such that sum of all greater keys is added to every key********/


/*******Construct BST from its given level order traversal**************************************/
int sumBstTo(struct Tnode *root)
{

}




/*******Construct BST from its given level order traversal**************************************/

/*******Construct BST from its given PREorder traversal**************************************/

struct Tnode *preorderToBST1(struct Tnode *root, int min, int max, int arr[],int curr, int total)
{
    int Index;
    if (curr > total)
        return NULL;

    if (root == NULL)
    {
        root = (struct Tnode *)malloc(sizeof(struct Tnode));
        root->data = arr[curr];
        root->left = NULL;
        root->right = NULL;
    }
    Index =curr+1;
    while(Index < total)
    {
        if (arr[Index] > root->data)
            break;
        Index++;
    }


    root->left = preorderToBST1(root->left,min,root->data-1,arr,curr+1,Index-1);
    root->right = preorderToBST1(root->right,root->data+1,max,arr,Index,total);

    return root;
}

void InitpreorderToBST1(void)
{
    struct Tnode *root =NULL;
    int arr[6] ={10, 5, 1, 7, 40, 50};

    root =preorderToBST1(root,INT_MIN,INT_MAX,arr,0,5);
    print_ascii_tree(root);
}

/*******Inorder predecessor and successor for a given key in BST*******/
void PrePostBST(struct Tnode *root, int *pre, int *post, int key)
{
    if (root == NULL)
        return;

    PrePostBST(root->left,pre,post,key);

    if (root->data < key)
        *pre = root->data;
    else if ((root->data > key) && (*post == 0))
        *post = root->data;

    PrePostBST(root->right,pre,post,key);
}


/*******Inorder predecessor and successor for a given key in BST*******/


/******* Morris Inorder traversal in binary tree *******/

void MorrisInorderTraversal(struct Tnode *root)
{
    struct Tnode *current =NULL;
    struct Tnode *Pre = NULL;

    current = root;

    while(current)
    {
        if (current->left == NULL)
        {
            printf(" %d",current->data);
            current = current->right;
        }
        else
        {
            Pre = current->left;
            while((Pre->right!= NULL) && (Pre->right != current))
            {
                Pre = Pre->right;
            }
            if(Pre->right == current)
            {
                Pre->right = NULL;
                printf(" %d",current->data);
                current = current->right;
            }else
            {
                Pre->right = current;
                current = current->left;
            }
        }

    }

}

/******* Morris Inorder traversal in binary tree *******/

/******* LCA of BST *******/
struct Tnode * LcaBst(struct Tnode *root, int num1, int num2)
{
    if (root == NULL)
        return NULL;

    if (root->data >= num1 && root->data <= num2)
    {
        return root;
    }
    if (root->data < num1 )
        return (LcaBst(root->right,num1,num2));
    else
        return (LcaBst(root->left,num1,num2));

};

/******* LCA of BST *******/

/******* LCA of Binary Tree *******/
struct Tnode * LcaBinaryTree(struct Tnode *root, int num1, int num2)
{
    struct Tnode *lnode =NULL;
    struct Tnode *rnode =NULL;

    if (root == NULL)
        return NULL;

    if (root->data == num1 || root->data == num2)
        return root;


    lnode = LcaBinaryTree(root->left,num1,num2);
    rnode = LcaBinaryTree(root->right,num1,num2);

    if (lnode && rnode)
    {
        return root;
    }
    else if (lnode)
        return lnode;
    else
        return rnode;
}
/******* LCA of Binary Tree *******/

/******* PostOrder Iterative with one stack *******/

void postIterative(struct Tnode *root)
{
    struct Tnode *curr =NULL;
    struct Tnode *prev = NULL;
    if (root == NULL)
        return;

    push(root);
    while(!isEmpty() || curr !=NULL)
    {
        if (!curr)
            curr = peek();

        if (curr->left)
        {
            push(curr->left);
            prev =curr;
            curr = curr->left;
        }
        else if (curr->right == prev || curr->right == NULL)
        {
            printf(" %d",curr->data);
            pop();
            prev = curr;
        }else if (curr->right)
        {
            prev = curr;
            curr= curr->right;
        }else{
            printf(" %d",curr->data);
            pop();
            curr = NULL;
        }



    }


};


/******* PostOrder Iterative with one stack *******/

int main()
{
    int diam =-1;
    int sum = 0;
    int minDepth =INT_MAX   ;
      struct Tnode *head = NULL;
      struct Tnode *head1 = NULL;
     struct Tnode *head2 = NULL;
      struct Tnode *root = NULL;
        struct Tnode *rootDiag = NULL;
        struct Tnode *rootCOMPL = NULL;
      struct Tnode *temp = NULL;
      struct Tnode *temp1 = NULL;
      struct Tnode *BSTRoot = NULL;
      struct Tnode *BSTRoot1 = NULL;
    int num=0;
      int max_width = -1;
    int i;
    int isSum =0;
    int leafLevel=0;
    int leaf_level=0;
    int tempSum =0;
    int maxSum = INT_MIN;
    struct Tnode *headDLL =NULL;
    int level =1;
    int maxlevel =0;
    int levelPrint=0;
    int isComplete=0;
    int arr[] ={1000,2000,3000,4000,5000,6000};
    int isBSTree =0;
    int curr;
    int key=0;
    int pre=0;
    int post=0;
    struct Tnode *LCA = NULL;
    #if 1
      insertNodeTree(&head2,1);
      insertNodeTree(&head2,2);

      insertNodeTree(&head2,3);
      insertNodeTree(&head2,4);
      insertNodeTree(&head2,5);
      insertNodeTree(&head2,6);
      insertNodeTree(&head2,7);
      insertNodeTree(&head2,8);
      insertNodeTree(&head2,9);
      insertNodeTree(&head2,10);
       insertNodeTree(&head2,11);
       insertNodeTree(&head2,12);
       insertNodeTree(&head2,13);
       insertNodeTree(&head2,14);
       insertNodeTree(&head2,15);
//       insertNodeTree(&head,60);
 //      insertNodeTree(&head,70);
   //    insertNodeTree(&head,80);
#endif


    rootDiag = insertNode(NULL,8);
    rootDiag->left = insertNode(NULL,3);
    rootDiag->right = insertNode(NULL,10);
    rootDiag->left->left = insertNode(NULL,1);
    rootDiag->left->right = insertNode(NULL,6);
    rootDiag->right->right = insertNode(NULL,14);
    rootDiag->right->right->left = insertNode(NULL,13);
    rootDiag->left->right->left = insertNode(NULL,4);
    rootDiag->left->right->right = insertNode(NULL,7);


    rootCOMPL = insertNode(NULL,1);
    rootCOMPL->left = insertNode(NULL,2);
    rootCOMPL->right = insertNode(NULL,3);
    rootCOMPL->left->left = insertNode(NULL,4);
    rootCOMPL->left->right = insertNode(NULL,5);
    rootCOMPL->right->left = insertNode(NULL,6);
    rootCOMPL->right->right = insertNode(NULL,7);
    rootCOMPL->left->left->left = insertNode(NULL,8);
    //rootCOMPL->left->left->right = insertNode(NULL,9);
    rootCOMPL->left->right->left = insertNode(NULL,10 );


#if 1
    root = insertNode(NULL,555);
    root->left = insertNode(NULL,-707);
    root->right = insertNode(NULL,101);
    root->right->left = insertNode(NULL,202);
    root->right->left->left = insertNode(NULL,303);
    root->right->left->left->left = insertNode(NULL,404);
    root->right->left->left->left->left = insertNode(NULL,505);
    root->right->left->left->left->left->left = insertNode(NULL,606);

    root->right->left->left->left->left->left->left = insertNode(NULL,707);

    head = insertNode(NULL,38);
    head->left = insertNode(NULL,16);
    head->left->left = insertNode(NULL,4);
        head->left->left->right = insertNode(NULL,800);
    head->left->right = insertNode(NULL,6);
    //head->left->right->left = insertNode(NULL,5);
    head->left->right->right = insertNode(NULL,1);
    head->right = insertNode(NULL,30);
    head->right->right = insertNode(NULL,3);

    root->left->left = head;

#endif // 1

#if 1
    head1 = insertNode(NULL,38);
    head1->left = insertNode(NULL,16);
    head1->left->left = insertNode(NULL,4);
    head1->left->right = insertNode(NULL,6);
    head1->left->right->left = insertNode(NULL,5);
    head1->left->right->right = insertNode(NULL,100);
    head1->right = insertNode(NULL,30);
    head1->right->right = insertNode(NULL,3);

#endif // 1


#if 0
    head = insertNode(NULL,5);
    head->left = insertNode(NULL,10);
    head->right = insertNode(NULL,11);
    temp = head->right;
    temp->right = insertNode(NULL,12);
    temp = head->left;
    temp->left = insertNode(NULL,13);
    temp->right = insertNode(NULL,14);
    temp1= temp->left;

    temp = temp->right;
    temp->right = insertNode(NULL,20);
    temp = temp->right;
    temp->left = insertNode(NULL,21);
    temp->right = insertNode(NULL,22);
    temp = temp->right;
    temp->right = insertNode(NULL,23);

    temp1->left= insertNode(NULL,15);
    temp1->right = insertNode(NULL,16);
    temp1 =temp1->right;
    temp1->left = insertNode(NULL,17);
    temp1 = temp1->left;
    temp1->left = insertNode(NULL,18);
    temp1->right = insertNode(NULL,19);
#endif // 0
printf ("\n\n >>>>>>>>>>>>>>>>.\n\n");


      print_ascii_tree(head);

//preorder_nonRecursive(head);
//preorder_Recursive(head);
//    print_ascii_tree(head);
printf ("\n\n\n\n");
//postorder_Recursive(head);
printf ("\n\n INORDER >>>>>>>>>>>>>>>>.\n\n");
//inorder_nonRecursive(head);

//printf(" size of the tree is %d max is %d \n",tree_size(head),tree_max(head));

//printf(" data is found %d ",tree_find(head,610));

//printf("==================== %d",tree_height(head));
//levelorder(head);
//PrintPathTree(head,0);
    tree_diameter(head,&diam);
printf("========diam============ %d\n ",diam);
printf("========countLeaf============ %d\n ",countLeaf(head));
//inorderSuccessor(head);
//levelorder(head);
printf("========lebelof the node ============ %d \n",levelNode(head,20,1));
//printKdistance(head,2,0);

maximumWidth(head,1);

for (i=0;i<100;i++)
{
    if (max_width < max_level[i])
        max_width = max_level[i];
}

printf("Maximum width  ********** %d \n",max_width);

sumLeftLeaf(head,&sum);

printf("SUM LEFT LEAF %d \n",sum);

//doubleTree(head);
print_ascii_tree(head);
isCousin(head,80,20);
printf("+++++++++++++++++++++++++\n");
    printLevelRange(head, 3, 3,1);

    printf("$$$$$$$$$$$$$$$$$$$$$$\n");
    minimumDepth(head,1,&minDepth);
    printf("----> %d \n",minDepth);

//printAncestors(head, 20);
printf("\n #############################----\n");

//distanceKleaf(head,1,3);
printf("\n ############################# leaf at same level %d \n",LeafAtSameLevel(head,1,&leafLevel));

//noSibling(head);

//rintf("\n isSumTree --> %d \n",isSumTree(head,&isSum));

//printf("\n Is this a sum tree %d \n",isSum);


print_ascii_tree(root);
//print_ascii_tree(head1);

 //printf("\n Is this a twin tree %d \n",isSameTree(head,head1));

 //printf("\n Is this a sub tree %d \n",subtree(root,head1));

 //maxSumLeaf(root,tempSum,&maxSum);

 //printf("\n <---------- maxSum %d ---------> \n",maxSum);


// printf("\n ==== ARe WE COUSINS %d ==== \n",isCousin(root,4,6));
#if 0
 root = extractLeafLDLL(root, &headDLL);
 printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 0x%x\n",headDLL);
 print_ascii_tree(root);
#endif

 deepLeftLeaf(root,level,&maxlevel);

 printf("left level %d \n",maxlevel);

 printLeftView(root,1,&levelPrint);
 levelPrint=0;
 printf("@@@@@@@@@@@@@@\n");
 printRightView(root,1,&levelPrint);
 printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
 //printVerticalTree(root);

 //Connectlevelorder(root);
 //tracelevelorder(root);

 temp1 = NULL;

 populateInorderSucessor(root,&temp1);
 temp1->next = NULL;

 while(first){
    printf(" %d ",first->data);
    first= first->next;
    }

print_ascii_tree(rootDiag);
 printf("\n||||||||||||||||||||||||||||||||||\n");
 Printdiagonal(rootDiag);

 isComplete = IsCompletelevelorder(rootCOMPL);

 print_ascii_tree(rootCOMPL);


 printf("ISCOMPLETE %d \n",isComplete);


 print_ascii_tree(head2);
 reverseAltLevels(head2);
 print_ascii_tree(head2);


 BSTRoot = insertBST(NULL,500);
 BSTRoot = insertBST(BSTRoot,600);
 BSTRoot = insertBST(BSTRoot,325);
 BSTRoot = insertBST(BSTRoot,800);
 BSTRoot = insertBST(BSTRoot,400);
 BSTRoot = insertBST(BSTRoot,850);
 BSTRoot = insertBST(BSTRoot,450);
 BSTRoot = insertBST(BSTRoot,550);
 BSTRoot = insertBST(BSTRoot,650);
 BSTRoot = insertBST(BSTRoot,300);
 BSTRoot = insertBST(BSTRoot,350);
 BSTRoot = insertBST(BSTRoot,700);
 BSTRoot = insertBST(BSTRoot,675);
 BSTRoot = insertBST(BSTRoot,375);

 print_ascii_tree(BSTRoot);

 temp = searchBST(BSTRoot,51150);

 if (temp)
    printf("%d ",temp->data);

  BSTRoot = deleteBST(BSTRoot,800);

 printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
 print_ascii_tree(BSTRoot);

// BSTRoot = sortedArrBST(NULL,arr,0,5);
 //print_ascii_tree(BSTRoot);
 isBSTree = isBST(BSTRoot,INT_MIN,INT_MAX);
 printf("IS THJIS BST %d \n",isBSTree);

 BSTRoot1 = insertBST(NULL,7);
 BSTRoot1 = insertBST(BSTRoot1,4);
 BSTRoot1 = insertBST(BSTRoot1,12);
 BSTRoot1 = insertBST(BSTRoot1,3);
 BSTRoot1 = insertBST(BSTRoot1,6);
 BSTRoot1 = insertBST(BSTRoot1,8);
 BSTRoot1 = insertBST(BSTRoot1,1);
 BSTRoot1 = insertBST(BSTRoot1,5);
 BSTRoot1 = insertBST(BSTRoot1,10);
 BSTRoot1 = insertBST(BSTRoot1,15);

print_ascii_tree(BSTRoot1);

num = LargestNumBST(BSTRoot1,16);
 printf("Largest number less than  %d \n",num);
 num = oneChildBST(BSTRoot1);
 printf("  one child BST %d \n",num);
print_ascii_tree(BSTRoot);

 num  = 0;
 curr = 0;
 KthSmallestBST(BSTRoot,7, &curr,&num );
 printf("Kth smallest number in BST %d \n",num);

 InitpreorderToBST1();
print_ascii_tree(BSTRoot1);
num=0;
//sumBstToBinaryTree(BSTRoot1,&num);
print_ascii_tree(BSTRoot1);

key =650;

PrePostBST(BSTRoot,&pre,&post,key);

printf("PrEdecessor %d postdecessor %d key %d \n",pre,post,key);
print_ascii_tree(BSTRoot);
MorrisInorderTraversal(BSTRoot);

printf("\n\n\n");
print_ascii_tree(BSTRoot1);

LCA = LcaBst(BSTRoot1,10,20);

if (LCA)
    printf("\n LCA  BST %d \n",LCA->data);
LCA = LcaBinaryTree(BSTRoot1,10,20);

if (LCA)
    printf("LCA  Binary tree %d \n",LCA->data);

print_ascii_tree(BSTRoot1);
postIterative(BSTRoot1);

return 1;

}


