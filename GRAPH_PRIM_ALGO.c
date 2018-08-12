#include <stdio.h>
#include <limits.h>
#define MAX 100

typedef struct qnode{
  int queue[MAX];
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


void enqueue(int num)
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

int dequeue()
{
  int  num =0;

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



int stk[MAX];
int top =-1;
void push(int num)
{
  if(top == MAX)
  {
  printf("stack overflow \n");
  return;
  }
stk[++top] = num;
}

int peek()
{
int node;
  if(top == -1)
  {
  //printf("stack underflow \n");
  return NULL;
  }
node = stk[top];
return node;

}


int pop()
{
    int node;
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

typedef struct AdjNode
{
    int vertex;
    int weight;
    struct AdjNode * next;
}AdjNode;

struct AdjNodeList
{
    struct AdjNode * head;
};

typedef struct edge
{
    int src;
    int dest;
}edge;

struct AdjNodeGraph
{
    int V;
    int numEdge;
    struct edge Edge[100];
    struct AdjNodeList *arr;
};


typedef struct heapNode{

	int vertex;
	int key;

}heapNode;

typedef struct minHeap{
	int heapIndx;
	int totalHeap;
	int *pos;
	heapNode **heapArr;
}minHeap;


struct heapNode * newHeapNode(int vertex, int key)
{

	struct heapNode * temp = (struct heapNode *)malloc(sizeof(struct heapNode));
	temp->vertex = vertex;
	temp->key = key;
	return temp;
}

struct minHeap * createHeap(int totalVertex)
{

	struct minHeap *temp = (struct minHeap *)malloc(sizeof(struct minHeap));
	temp->totalHeap = totalVertex;
	temp->heapIndx = 0;
	temp->pos = malloc(totalVertex * sizeof(int));
	temp->heapArr = (struct heapNode *)malloc(totalVertex * sizeof(struct heapNode *));

}

void swapMinNode(struct heapNode **hNode1,struct heapNode **hNode2 )
{
	struct heapNode *temp = *hNode1;
	*hNode1 = *hNode2;
	*hNode2 = temp;
}

void printHeap(struct minHeap *Heap)
{
    int i =0;
    for(i=0;i<Heap->heapIndx;i++)
    {
        printf("key %d --> vertex %d \n",Heap->heapArr[i]->key,Heap->heapArr[i]->vertex);
    }
	for(i=0;i<10;i++)
    {
        printf("vertex %d --> Position %d \n",i,Heap->pos[i]);
    }
    printf("\n\n");
}

void HeapInsert(struct minHeap *Heap,struct heapNode *hVal)
{
    int parent =0;
    int temp;
    int index = Heap->heapIndx;

	Heap->pos[hVal->vertex] = Heap->heapIndx;
	Heap->heapArr[Heap->heapIndx++] = hVal;

    while(index !=0)
    {
        parent = index/2;
        if (Heap->heapArr[parent]->key > Heap->heapArr[index]->key)
        {
            swapMinNode(&Heap->heapArr[parent],&Heap->heapArr[index]);
			Heap->pos[Heap->heapArr[parent]->vertex] = parent;
			Heap->pos[Heap->heapArr[index]->vertex] = index;

        }else{
            break;
        }
        index = parent;
    }
}



int extractMin(struct minHeap *Heap)
{
    int lson =0;
    int rson =0;
    int temp;
    int index = 0;
    int min;
    int last = 0;
    if (Heap->heapIndx == 0)
    {
        printf("NO ELEMENT FOUND \n");
        return INT_MIN;
    }
    min = Heap->heapArr[0]->vertex;
	Heap->pos[min] = -1;
    free(Heap->heapArr[0]);
    Heap->heapArr[0] = Heap->heapArr[--Heap->heapIndx];
    lson = index*2+1;
    rson = index*2+2;

    while (lson < Heap->heapIndx)
    {
        if (rson < Heap->heapIndx)
        {
            if (Heap->heapArr[lson]->key < Heap->heapArr[rson]->key)
            {
                if (Heap->heapArr[lson]->key < Heap->heapArr[index]->key)
                {
                    swapMinNode(&Heap->heapArr[lson],&Heap->heapArr[index]);
					Heap->pos[Heap->heapArr[lson]->vertex] = lson;
					Heap->pos[Heap->heapArr[index]->vertex] = index;
					index = lson;
                }
                else
                    break;
            }else
            {
                if (Heap->heapArr[rson]->key < Heap->heapArr[index]->key)
                {
                    swapMinNode(&Heap->heapArr[rson],&Heap->heapArr[index]);
					Heap->pos[Heap->heapArr[rson]->vertex] = rson;
					Heap->pos[Heap->heapArr[index]->vertex] = index;
                    index =rson;
                }
                else
                    break;
            }

        }else
        {
                if (Heap->heapArr[lson]->key < Heap->heapArr[index]->key)
                {
                    swapMinNode(&Heap->heapArr[lson],&Heap->heapArr[index]);
					Heap->pos[Heap->heapArr[lson]->vertex] = lson;
					Heap->pos[Heap->heapArr[index]->vertex] = index;
                    index = lson;
                }
                else
                break;
        }
            lson = index*2+1;
            rson = index*2+2;
    }

    return min;
}


void decreaseKey(struct minHeap *Heap,int v, int key)
{
    int pos;
    int parent;
    pos = Heap->pos[v];
    Heap->heapArr[pos]->key = key;

    while (pos !=0)
    {
        parent = pos/2;
        if (Heap->heapArr[parent]->key > Heap->heapArr[pos]->key)
        {
            swapMinNode(&Heap->heapArr[parent],&Heap->heapArr[pos]);
            Heap->pos[Heap->heapArr[parent]->vertex] = parent;
            Heap->pos[Heap->heapArr[pos]->vertex] = pos;
        }else{
            break;
        }
        pos = parent;
    }

}

struct AdjNodeGraph * createGraph(int V)
{
    int i=0;

    struct AdjNodeGraph *graph = (struct AdjNodeGraph *)malloc(sizeof(struct AdjNodeGraph));
    graph->V = V;
    graph->arr = (struct AdjNodeList *)malloc(V * sizeof(struct AdjNodeList));
    graph->numEdge = 0;
    for(i=0;i<V;i++)
    {
        graph->arr[i].head = NULL;
    }
    return graph;
}


void addWeightedEdge(struct AdjNodeGraph *graph,int src,int dest,int weight)
{
    struct AdjNode * temp = (struct AdjNode *)malloc(sizeof(struct AdjNode *));

    temp->vertex = dest;
    temp->next = graph->arr[src].head;
    temp->weight =weight;
    graph->arr[src].head = temp;

    temp = (struct AdjNode *)malloc(sizeof(struct AdjNode *));
    temp->vertex = src;
    temp->weight= weight;
    temp->next = graph->arr[dest].head;
    graph->arr[dest].head = temp;

    graph->Edge[graph->numEdge].src = src;
    graph->Edge[graph->numEdge].src = dest;
    graph->numEdge++;
}


// A utility function to print the adjacenncy list representation of graph
void printGraph(struct AdjNodeGraph* graph)
{
    int v;
    struct AdjNode* pCrawl = NULL;

    for (v = 0; v < graph->V; ++v)
    {
        pCrawl = graph->arr[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d(%d)", pCrawl->vertex,pCrawl->weight);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}


void primTraversal(struct AdjNodeGraph*graph)
{
    int i=0,j=0;
    struct AdjNode* pCrawl = NULL;
    int *parent = malloc(sizeof(int) * graph->V);
    struct minHeap *heap =  createHeap(graph->V);
    int *isMst = malloc(sizeof(int) * graph->V);
	int min_vertex;
	int indx;
    for (i=0;i<graph->V;i++)
    {
        heap->pos[i] =i;
        heap->heapArr[i] = newHeapNode(i,INT_MAX);
		isMst[i] = 0;
		parent[i] =-1;
	}

    heap->heapArr[0]->key = 0;
    heap->heapIndx = graph->V;

    for (i=0;i<graph->V;i++)
    {
		min_vertex = extractMin(heap);
		isMst =1;
        pCrawl = graph->arr[min_vertex].head;

        while (pCrawl)
    	{
    		indx = heap->pos[pCrawl->vertex];
			if (!isMst[pCrawl->vertex] && (heap->heapArr[indx]->key > pCrawl->weight))
			{
				decreaseKey(heap,pCrawl->vertex,pCrawl->weight);
				parent[pCrawl->vertex] = min_vertex;
			}
			pCrawl = pCrawl->next;
		}
    }

}

void printGraphMatrix(int **graph,int vertex)
{
    int i ,j;
    int index =0;

     printf("%9      ");

    for(j=0;j<vertex;j++)
    {
            printf("%3d  ", j);
    }
            printf("\n      ======================================\n");

    for(i=0;i<vertex;i++)
    {
        printf("%3d-> ", i);

        for(j=0;j<vertex;j++)
        {
            printf("%3d  ", graph[i][j]);
        }
        printf("\n");
    }



}
int ** createGraphMatrix(int vertex)
{
    int** graph;
    graph = (int **) malloc(vertex*sizeof(int*));
    int i ,j;
    int index =0;
    for (i=0; i<vertex; i++){

         graph[i] = (int *)malloc(vertex * sizeof(int));
         memset(graph[i],0,vertex * sizeof(int));
    }
    return graph;
}

void matrixUndirectedEdge(int **graph, int src,int dest, int weight)
{
    graph[src][dest] = weight;
    graph[dest][src] = weight;

}

int findMin(int *min,int vertex, int *isMst)
{
   int temp;
   int minimum = INT_MAX;
   int i=0;
   int index =0;
   for(i=0;i<vertex;i++)
   {
        if ((isMst[i] == 0) && min[i] < minimum)
        {
            minimum = min[i];
            index = i;
        }
   }
    return index;
}

void primMSTMatrix(int **graph,int vertex)
{
    int *parent = (int *)malloc(sizeof(int)*vertex);
    int *isMst = (int *)malloc(sizeof(int)*vertex);
    int *min = (int *)malloc(sizeof(int)*vertex);
    int i =0;
    int minimum =0;
    int j=0;

    for (i=0;i<vertex;i++)
    {
        parent[i] = -1;
        isMst[i] = 0;
        min[i] = INT_MAX;
    }
    min[0] = 0;

    for (i=0;i<vertex;i++)
    {
        minimum =findMin(min,vertex,isMst);
        isMst[minimum] = 1;
        for (j=0;j<vertex;j++)
        {
            if (!isMst[j] && graph[minimum][j] && (graph[minimum][j] < min[j]))
            {
                printf("graph[minimum][j] %d min[j] %d min%d j %d \n ",
                       graph[minimum][j],min[j],minimum, j);

                min[j] = graph[minimum][j];
                parent[j] = minimum;
            }
         }
                    printf("=================\n");
    }

    for (i=0;i<vertex;i++)
    {
        printf("vertex %d parent %d \n",i,parent[i]);
    }
}



/*** Dijkstra’s shortest path algorithm ****/

int printSolution(int dist[], int n)
{
    int i=0;
   printf("\nVertex   Distance from Source\n");
   for (i = 0; i < n; i++)
      printf("%d tt %d\n", i, dist[i]);
}


void dijkstraMatrix(int **graph,int vertex)
{
    int *dist = (int *)malloc(sizeof(int)*vertex);
    int *isShort = (int *)malloc(sizeof(int)*vertex);

	int i =0,j=0;
	int min_dist;
	for (i=0;i<vertex;i++)
	{
		dist[i] = INT_MAX;
		isShort[i] = 0;
 	}

	dist[0] =0;

	for(i=0;i<vertex;i++)
	{

		min_dist = findMin(dist,vertex,isShort);
		isShort[min_dist] = 1;

		for (j=0;j<vertex;j++)
		{

			if(!isShort[j] && graph[min_dist][j] &&
                (dist[min_dist] + graph[min_dist][j]) < dist[j])
			{
				dist[j] = dist[min_dist] + graph[min_dist][j];

			}

		}

	}
	printSolution(dist, vertex);


}

/*** Dijkstra’s shortest path algorithm ****/

void testHeap()
{
	int i =0;
	struct heapNode *temp = NULL;
	struct minHeap * HEAP;

	HEAP = createHeap(10);




	temp  =  newHeapNode(0,600);
	HeapInsert(HEAP,temp);

	temp  =  newHeapNode(1,800);
	HeapInsert(HEAP,temp);
	temp  =  newHeapNode(2,700);
	HeapInsert(HEAP,temp);
	temp  =  newHeapNode(3,500);
	HeapInsert(HEAP,temp);
	temp  =  newHeapNode(4,900);
	HeapInsert(HEAP,temp);
	temp  =  newHeapNode(5,100);
	HeapInsert(HEAP,temp);
	temp  =  newHeapNode(6,400);
	HeapInsert(HEAP,temp);
	temp  =  newHeapNode(7,300);
	HeapInsert(HEAP,temp);
	temp  =  newHeapNode(8,200);
	HeapInsert(HEAP,temp);
	temp  =  newHeapNode(9,1000);
	HeapInsert(HEAP,temp);


	printHeap(HEAP);

	printf("%d <---",extractMin(HEAP));
	printf("%d <---",extractMin(HEAP));
	printf("%d <---",extractMin(HEAP));

	printf("\n");

	printHeap(HEAP);

#if 1
	for (i=0;i<10;i++)
		printf("%d <--->",extractMin(HEAP));
#endif


}


int main()
{
    // create the graph given in above fugure
    int V = 9;
    int **mgraph;
#if 0
    struct AdjNodeGraph* graph = createGraph(V);
    addWeightedEdge(graph,0,1,4);
    addWeightedEdge(graph,0,7,8);
    addWeightedEdge(graph,1,2,8);
    addWeightedEdge(graph,1,7,11);
    addWeightedEdge(graph,7,6,1);
    addWeightedEdge(graph,7,8,7);
    addWeightedEdge(graph,8,2,2);
    addWeightedEdge(graph,8,6,6);
    addWeightedEdge(graph,6,5,2);
    addWeightedEdge(graph,2,5,4);
    addWeightedEdge(graph,2,3,7);
    addWeightedEdge(graph,3,5,14);
    addWeightedEdge(graph,3,4,9);
    addWeightedEdge(graph,5,4,10);



    // print the adjacency list representation of the above graph
    printGraph(graph);

#endif
    mgraph = createGraphMatrix(9);

    matrixUndirectedEdge(mgraph,0,1,4);
    matrixUndirectedEdge(mgraph,0,7,8);
    matrixUndirectedEdge(mgraph,1,2,8);
    matrixUndirectedEdge(mgraph,1,7,11);
    matrixUndirectedEdge(mgraph,7,6,1);
    matrixUndirectedEdge(mgraph,7,8,7);
    matrixUndirectedEdge(mgraph,8,2,2);
    matrixUndirectedEdge(mgraph,8,6,6);
    matrixUndirectedEdge(mgraph,6,5,2);
    matrixUndirectedEdge(mgraph,2,5,4);
    matrixUndirectedEdge(mgraph,2,3,7);
    matrixUndirectedEdge(mgraph,3,5,14);
    matrixUndirectedEdge(mgraph,3,4,9);
    matrixUndirectedEdge(mgraph,5,4,10);

    printGraphMatrix(mgraph,9);
    printf("\n\n\n\n");

    primMSTMatrix(mgraph,9);

    printf("\n\n\n\n");



	testHeap();

	dijkstraMatrix(mgraph,9);

	return 0;
}
