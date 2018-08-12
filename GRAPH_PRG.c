#include <stdio.h>

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
}GrphNode;

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
        printf("key %d vertex %d ",Heap->heapArr[i]->key,Heap->heapArr[i]->vertex);
    }
    printf("\n\n");
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


void addDirectedEdge(struct AdjNodeGraph *graph,int src,int dest)
{
    struct AdjNode * temp = (struct AdjNode *)malloc(sizeof(struct AdjNode *));
    temp->vertex = dest;
    temp->next = graph->arr[src].head;
    graph->arr[src].head = temp;

    graph->Edge[graph->numEdge].src = src;
    graph->Edge[graph->numEdge].dest = dest;
    graph->numEdge++;
}



void addEdge(struct AdjNodeGraph *graph,int src,int dest)
{
    struct AdjNode * temp = (struct AdjNode *)malloc(sizeof(struct AdjNode *));
    temp->vertex = dest;
    temp->next = graph->arr[src].head;
    graph->arr[src].head = temp;

    temp = (struct AdjNode *)malloc(sizeof(struct AdjNode *));
    temp->vertex = src;
    temp->next = graph->arr[dest].head;
    graph->arr[dest].head = temp;

    graph->Edge[graph->numEdge].src = src;
    graph->Edge[graph->numEdge].src = dest;
    graph->numEdge++;
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
            printf("-> %d", pCrawl->vertex);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void BFS(struct AdjNodeGraph* graph,int start)
{
    struct AdjNode* pCrawl = NULL;
    int i =0;
    int vrtx;
    unsigned char *visited = (unsigned char *)malloc(graph->V * sizeof(unsigned char));
    for (i=0;i<graph->V;i++)
    {
        visited[i] = 0;
    }
    Qinit();
    enqueue(start);
    visited[start] = 1;
    printf("BFS \n");

    while(!isQempty())
    {

        vrtx = dequeue();
        printf("node -- %d ",vrtx);
        pCrawl = graph->arr[vrtx].head;

        while(pCrawl)
        {
            if (!visited[pCrawl->vertex])
            {
                enqueue(pCrawl->vertex);
                visited[pCrawl->vertex] = 1;
             }
            pCrawl = pCrawl->next;
        }

    }

}
void DFS(struct AdjNodeGraph* graph,int vrtx,unsigned char *visited)
{
        struct AdjNode* pCrawl = NULL;
        pCrawl = graph->arr[vrtx].head;
        printf("%d ",vrtx);
        while(pCrawl)
        {
            if (!visited[pCrawl->vertex])
            {
                visited[pCrawl->vertex] = 1;
                DFS(graph,pCrawl->vertex,visited);
            }
            pCrawl = pCrawl->next;
        }

}

void DFSUtil(struct AdjNodeGraph* graph)
{
    struct AdjNode* pCrawl = NULL;
    int i =0;
    int vrtx;
    unsigned char *visited = (unsigned char *)malloc(graph->V * sizeof(unsigned char));
    for (i=0;i<graph->V;i++)
    {
        visited[i] = 0;
    }
    for (i=0;i<graph->V;i++)
    {
        if (!visited[i] && graph->arr[i].head)
        {
            DFS(graph,i,visited);
        }
    }
}



void topologicalSortUtil(struct AdjNodeGraph* graph,int vertex,unsigned char * visited,int V)
{
        struct AdjNode* pCrawl = graph->arr[vertex].head;
        visited[vertex] = 1;

        while(pCrawl)
        {
            if (!visited[pCrawl->vertex])
            {
                topologicalSortUtil(graph,pCrawl->vertex,visited,V);
            }
            pCrawl = pCrawl->next;
        }
        push(vertex);

}


void topologicalSort(struct AdjNodeGraph* graph)
{
    int i =0;
    int vrtx;
    unsigned char *visited = (unsigned char *)malloc(graph->V * sizeof(unsigned char));
    for (i=0;i<graph->V;i++)
    {
        visited[i] = 0;
    }
    printf("TOPOLOGICAL SORT START\n");
    for (i=0;i<graph->V;i++)
    {
        if (!visited[i] && graph->arr[i].head)
        {
            topologicalSortUtil(graph,i,visited,graph->V);
        }
    }

    while(!isEmpty())
    {
        printf("%d ",pop());
    }
    printf("TOPOLOGICAL SORT \n");
}

/*****Kahn’s algorithm for Topological Sorting****/
void KahnTopologicalSort(struct AdjNodeGraph* graph)
{
    int v=0;
    struct AdjNode* pCrawl = NULL;
    unsigned char *inDegree = (unsigned char *)malloc(graph->V * sizeof(unsigned char));
    unsigned char *topOrder = (unsigned char *)malloc(graph->V * sizeof(unsigned char));

    memset(inDegree,0,graph->V * sizeof(unsigned char));
    int TopIndex =0;

    for (v = 0; v < graph->V; ++v)
    {
        pCrawl = graph->arr[v].head;
        while (pCrawl)
        {
            inDegree[pCrawl->vertex]++;
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }

    for (v = 0; v < graph->V; ++v)
    {
            printf("indegree vertex %d indegree %d \n",v,inDegree[v]);

        if (!inDegree[v])
        {
            printf("indegree zero %d ",v);
            enqueue(v);
        }
    }

    while(!isQempty())
    {
        v = dequeue();
        topOrder[TopIndex++] = v;
        pCrawl = graph->arr[v].head;
        while (pCrawl)
        {
            inDegree[pCrawl->vertex]--;
            if (inDegree[pCrawl->vertex] == 0)
            {
                enqueue(pCrawl->vertex);
            }
            pCrawl = pCrawl->next;
        }
    }

    printf("\n");
    for (v=0;v<TopIndex;v++)
    {
        printf("%d->",topOrder[v]);
    }
    printf("\n");

}


/*****Kahn’s algorithm for Topological Sorting****/

/*****Disjoint Set (Or Union-Find) | Set 1 (Detect Cycle in an Undirected Graph)****/

int find(int vertex,int *parent)
{
    if (parent[vertex] == -1)
        return vertex;

    return find(parent[vertex],parent);
}

void Union(int v1, int v2, int *parent)
{
    int p1 , p2;

    p1 =  find(v1,parent);
    p2 =  find(v2,parent);
    parent[p1] = p2;

}

void checkCycle(struct AdjNodeGraph* graph)
{
    int *parent = (int *)malloc(graph->V * sizeof(int));
    int e=0;
    int temp=0;
    struct AdjNode* pCrawl = NULL;
    int src = 0;
    int dest = 0;

    memset(parent,-1,graph->V * sizeof(int));

    for (e = 0 ;e < graph->numEdge;e++)
    {
        src = graph->Edge[e].src;
        dest = graph->Edge[e].dest;
        printf(" %d src %d dest %d \n",e,src,dest);
        if (find(src,parent) == find(dest,parent))
        {
            printf("---- CYCLE DETECTED :-) src %d dest %d p1 %d p2 %d\n --- ",
                       src,dest,find(src,parent),find(dest,parent));
            break;
        }
        else
        {
            Union(src,dest,parent);
        }
        for (temp = 0; temp < graph->V; ++temp)
        {
            printf("vrtx %d parent %d  ",temp,parent[temp]);
        }

		printf("\n");
    }

        printf("\n");
}

/*****Disjoint Set (Or Union-Find) | Set 1 (Detect Cycle in an Undirected Graph)****/


int main()
{
    // create the graph given in above fugure
    int V = 6;
    struct AdjNodeGraph* graph = createGraph(V);
    struct AdjNodeGraph* graph1 = createGraph(V);

    #if 0
    addDirectedEdge(graph, 5, 2);
    addDirectedEdge(graph, 5, 0);
    addDirectedEdge(graph, 4, 0);
    addDirectedEdge(graph, 4, 1);
    addDirectedEdge(graph, 2, 3);
    addDirectedEdge(graph, 3, 1);
    #endif

    addDirectedEdge(graph1, 5, 2);
    addDirectedEdge(graph1, 5, 0);
    addDirectedEdge(graph1, 4, 0);
    addDirectedEdge(graph1, 4, 1);
    addDirectedEdge(graph1, 2, 3);
    addDirectedEdge(graph1, 3, 1);

    // print the adjacency list representation of the above graph
    printGraph(graph);
    printf("\n\n\n\n");
#if 1
    BFS(graph,0);
    printf("\n\n------\n\n");
    DFSUtil(graph);
    printf("\n\n#############\n\n");
    topologicalSort(graph);
    printGraph(graph);
    KahnTopologicalSort(graph);
    printGraph(graph1);
    checkCycle(graph1);
    #endif
    return 0;
}
