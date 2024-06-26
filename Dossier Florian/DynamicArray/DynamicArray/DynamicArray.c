#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
}

void Add(IntArray* pIntArray, int iValue)
{

	pIntArray->iSize++;
	if (pIntArray->iSize > pIntArray->iCapacity) {
		pIntArray->iCapacity = pIntArray->iSize * 2;
		int* p_temp = (int*)malloc(pIntArray->iCapacity * sizeof(int));
		for (int i = 0; i < pIntArray->iSize-1; i++) {
			p_temp[i] = pIntArray->pContent[i];
		}
		free(pIntArray->pContent);
		pIntArray->pContent = (int*)malloc(pIntArray->iCapacity * sizeof(int));
		pIntArray->pContent = p_temp;
	}
	pIntArray->pContent[pIntArray->iSize-1] = iValue;
}

void Insert(IntArray* pIntArray, int iValue, int iIndex)
{
	pIntArray->iSize++;
	if (pIntArray->iSize > pIntArray->iCapacity) {
		pIntArray->iCapacity = pIntArray->iSize * 2;
		int* p_temp = (int*)malloc(pIntArray->iCapacity * sizeof(int));
		for (int i = 0; i < pIntArray->iSize - 1; i++) {
			p_temp[i] = pIntArray->pContent[i];
		}
		free(pIntArray->pContent);
		pIntArray->pContent = (int*)malloc(pIntArray->iCapacity * sizeof(int));
		pIntArray->pContent = p_temp;
	}
	for (int i = pIntArray->iSize-1 ; i > iIndex; i--) {
		pIntArray->pContent[i] = pIntArray->pContent[i-1];
	}

	pIntArray->pContent[iIndex] = iValue;
}

void Remove(IntArray* pIntArray, int iIndex)
{
	
	for (int i = iIndex; i < pIntArray->iSize-1; i++) {
		pIntArray->pContent[i] = pIntArray->pContent[i + 1];
	}
	pIntArray->iSize--;
	
}

int Get(IntArray* pIntArray, int iIndex) {
	if (iIndex < pIntArray->iSize && iIndex > 0) {
		return pIntArray->pContent[iIndex];
	}
}

void Print(IntArray* pIntArray)
{
	for (int i = 0; pIntArray->iSize > i; i++) {
		printf("%d | ", pIntArray->pContent[i]);
	}
}

void Destroy(IntArray* pIntArray)
{
	free(pIntArray->pContent);
}

int main()
{
	IntArray l;
	Init(&l);
	Add(&l, 10);
	Add(&l, 15);
	Add(&l, 10);
	Add(&l, 15);
	Add(&l, 10);
	Add(&l, 15);
	Insert(&l, 20, 1);
	Remove(&l, 1);
	Print(&l);
	Destroy(&l);
    return 0;
}
