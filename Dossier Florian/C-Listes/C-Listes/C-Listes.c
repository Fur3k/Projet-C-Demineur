#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    Node* pNext;
    Node* pPrevious;

    int iValue;
} Node;

typedef struct List
{
    Node* pFirst;

    int iCount;
} List;

void Init(List* pList)
{
    //
    pList->iCount = 0;
    pList->pFirst = NULL;
}

void AddFirst(List* pList, int iValue)
{
    //
    pList->iCount += 1;
    pList->pFirst->iValue = iValue;
    pList->pFirst->pNext = &pList[pList->iCount + 1];
    pList->pFirst->pPrevious = &pList[pList->iCount - 1];
}

void AddLast(List* pList, int iValue)
{
    //
    pList->iCount += 1;
    pList->pFirst->iValue = iValue;
    pList->pFirst->pNext = &pList[pList->iCount + 1];
    pList->pFirst->pPrevious = &pList[pList->iCount - 1];
}

void AddAfterNode(List* pList, Node* pNode, int iValue)
{
    //
}

void Insert(List* pList, int iValue, int iIndex)
{
    //
}

void Remove(List* pList, int iIndex)
{
    //
}

void RemoveNode(List* pList, Node* pNode)
{
    //
}

Node* GetNode(List* pList, int iIndex)
{
    //
    return pList[iIndex].pFirst;
}

void Print(List* pList)
{
    //
}

void Destroy(List* pList)
{
    //
}

int main()
{
    List oList;
    init(&oList);

    AddLast(&oList, 1);
    AddLast(&oList, 2);
    AddLast(&oList, 3);

    AddFirst(&oList, 0);

    Destroy(&oList);
}