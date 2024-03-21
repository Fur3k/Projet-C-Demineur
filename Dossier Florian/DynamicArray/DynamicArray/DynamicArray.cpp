#include <stdio.h>
#include <stdlib.h>

// EXERCICE : Tableau Dynamique (Cf Python)

typedef struct IntArray
{
	int* pContent;

	int iSize;
	int iCapacity;
} IntArray;

void Init(IntArray* pIntArray)
{	
	pIntArray->iSize = 0;
	pIntArray->iCapacity = 5;

	pIntArray->pContent = (int*)malloc(pIntArray->iCapacity * sizeof(int));
	if (pIntArray->pContent == NULL)
	{
		exit(1);
	}
}

void Add(IntArray* pIntArray, int iValue)
{
	for (int i = 0; i < pIntArray->iCapacity; i++) {
		if (pIntArray->pContent[i] == NULL) {
			pIntArray->pContent[i] = iValue;
			exit(1);
		}
	}
}

void Insert(IntArray* pIntArray, int iValue, int iIndex)
{
	for (int i = pIntArray->iCapacity-1; i > iIndex; i--) {
		if (!(pIntArray->pContent[i + 1] == pIntArray->pContent[i]) && !(pIntArray->pContent[i + 1] == NULL))
		{
			pIntArray->pContent[i + 1] = pIntArray->pContent[i];
		}
	}
	pIntArray->pContent[iIndex] = iValue;
}

void Remove(IntArray* pIntArray, int iIndex)
{
	//
}

void Print(IntArray* pIntArray)
{
	//
}

void Destroy(IntArray* pIntArray)
{
	//
}

int main()
{
    return 0;
}
