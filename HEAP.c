#include <stdio.h>
#include <limits.h>

typedef struct heap{

    int heapArr[100];
    int num;
}heap;

void printHeap(struct heap *Heap)
{
    int i =0;
    for(i=0;i<Heap->num;i++)
    {
        printf("%d ",Heap->heapArr[i]);
    }
    printf("\n\n");
}


int extractMin(struct heap *Heap)
{
    int lson =0;
    int rson =0;
    int temp;
    int index = 0;
    int min;
    int last = 0;
    if (Heap->num == 0)
    {
        printf("NO ELEMENT FOUND \n");
        return INT_MIN;
    }
    min = Heap->heapArr[0];
    Heap->heapArr[0] = Heap->heapArr[--Heap->num];;
    lson = index*2+1;
    rson = index*2+2;
    while (lson < Heap->num)
    {
        if (rson < Heap->num)
        {
            if (Heap->heapArr[lson] < Heap->heapArr[rson])
            {
                if (Heap->heapArr[lson] < Heap->heapArr[index])
                {
                    temp = Heap->heapArr[lson];
                    Heap->heapArr[lson] = Heap->heapArr[index];
                    Heap->heapArr[index] = temp;
                    index = lson;
                }
                else
                    break;
            }else
            {
                if (Heap->heapArr[rson] < Heap->heapArr[index])
                {
                    temp = Heap->heapArr[rson];
                    Heap->heapArr[rson] = Heap->heapArr[index];
                    Heap->heapArr[index] = temp;
                    index =rson;
                }
                else
                    break;
            }

        }else
        {
                if (Heap->heapArr[lson] < Heap->heapArr[index])
                {
                    temp = Heap->heapArr[lson];
                    Heap->heapArr[lson] = Heap->heapArr[index];
                    Heap->heapArr[index] = temp;
                    index = lson;
                }
                else
                break;
        }
            lson = index*2+1;
            rson = index*2+2;
    }
//    printHeap(Heap);
    printf("----");
    return min;
}

void HeapInsert(struct heap *Heap,int val)
{
    int parent =0;
    int temp;
    int index = Heap->num;
    Heap->heapArr[Heap->num++] = val;
    while(index !=0)
    {
        parent = index/2;
        if (Heap->heapArr[parent] > Heap->heapArr[index])
        {
            temp = Heap->heapArr[parent];
            Heap->heapArr[parent] = Heap->heapArr[index];
            Heap->heapArr[index] = temp;
        }else{
            break;
        }
        index = parent;
    }
}

int main()
{
    struct heap Heap;
    memset(&Heap,0,sizeof(struct heap));
    HeapInsert(&Heap,10);
    HeapInsert(&Heap,20);
    HeapInsert(&Heap,50);
    HeapInsert(&Heap,100);
    HeapInsert(&Heap,5);
    HeapInsert(&Heap,25);
    HeapInsert(&Heap,35);
    HeapInsert(&Heap,45);
    HeapInsert(&Heap,145);

    HeapInsert(&Heap,45);
    HeapInsert(&Heap,75);
    HeapInsert(&Heap,80);

    printHeap(&Heap);

    #if 1
printf("\n\n");
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
printf("%d\n ",extractMin(&Heap));
    #endif // 0


}
