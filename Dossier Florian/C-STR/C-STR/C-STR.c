#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct String
{
    char* pContent;
    int iLength;
}String;

String Create(const char* str)
{
    String strt;

    int i = 0;
    strt.iLength = 0;
    while (str[i] != '\0')
    {
        strt.iLength++;
        i++;
    }
    
    strt.pContent = (char*)malloc(strt.iLength * sizeof(char));
    for(int j = 0; j < strt.iLength; j++)
    {
        strt.pContent[j] = str[j];
    }
    return strt;
}

void Print(const String* pStr)
{
    for (int i = 0; i < pStr->iLength; i++) {
        printf("%c", pStr->pContent[i]);
    }
    printf("\n");
}

String Concatenate1(const String* pStr1, const String* pStr2)
{
    String strt;
    strt.iLength = pStr1->iLength + pStr2->iLength;
    strt.pContent = (char*)malloc(strt.iLength * sizeof(char));
    for(int i = 0; i < strt.iLength; i++)
    {
        if (i < pStr1->iLength) {
            strt.pContent[i] = pStr1->pContent[i];
        }
        else
        {
            strt.pContent[i] = pStr2->pContent[i-pStr1->iLength];
        }
    }
    return strt;
}

String Concatenate2(const char* str1, const char* str2)
{
    String strt;

    int i = 0;
    strt.iLength = 0;
    int str1l = 0;
    while (str1[i] != '\0')
    {
        strt.iLength++;
        str1l++;
        i++;
    }
    int k = 0;
    while (str2[k] != '\0')
    {
        strt.iLength++;
        k++;
    }

    strt.pContent = (char*)malloc(strt.iLength * sizeof(char));
    for (int j = 0; j < strt.iLength; j++)
    {
        if (j < str1l) {
            strt.pContent[j] = str1[j];
        }
        else
        {
            strt.pContent[j] = str2[j - str1l];
        }
    }
    return strt;
}

String SubString(const String* pStr1, int iStartIndex, int iLength)
{
    String strt;

    int i = 0;
    strt.iLength = iLength;

    strt.pContent = (char*)malloc(strt.iLength * sizeof(char));
    for (int j = 0; j < strt.iLength; j++)
    {
        strt.pContent[j] = pStr1->pContent[j + iStartIndex];
    }
    return strt;
}

String InsertString(const String* pStr1, const String* Pstr2, int iIndex)
{
    String strt;

    int i = 0;
    strt.iLength = pStr1->iLength + Pstr2->iLength;

    strt.pContent = (char*)malloc(strt.iLength * sizeof(char));
    for (int j = 0; j < strt.iLength; j++)
    {
        if (j >= iIndex && j < iIndex + Pstr2->iLength) {
            strt.pContent[j] = Pstr2->pContent[j-iIndex];
        }
        else if (j > Pstr2->iLength)
        {
            strt.pContent[j] = pStr1->pContent[j-Pstr2->iLength];
        }
        else
        {
            strt.pContent[j] = pStr1->pContent[j];
        }
        
    }
    return strt;
}

int AreEquals(const String* pStr1, const String* pStr2)
{
    if (pStr1->iLength != pStr2->iLength) {
        return 0;
    }
    for (int i = 0; i < pStr1->iLength; i++) {
        if (pStr1->pContent[i] != pStr2->pContent[i]) {
            return 0;
        }
    }
    return 1;
}

int TryCastToInt(const String* pStr, int* pResult)
{
    for (int i = 0; i < pStr->iLength; i++) {
        if (pStr->pContent[i] >= 48 && pStr->pContent[i] <= 57) {
            *pResult += (pStr->pContent[i] - 48);
            if (i < pStr->iLength - 1) {
                *pResult = (int)pResult * 10;
            }
        }
        else
        {
            return 0;
        }

    }
    printf("Valeur de pResult : %d\n", *pResult);
    return 1;
}

void DestroyString(String* pStr)
{
    free(pStr->pContent);
}

int main() 
{
    String str1 = Create("Bonjour");
    Print(&str1);
    String str2 = Create("Aurevoir");
    Print(&str2);
    String str3 = Concatenate1(&str1, &str2);
    Print(&str3);
    String str4 = Concatenate2("Bon", "jour");
    Print(&str4);
    String str5 = SubString(&str4, 2, 2);
    Print(&str5);
    String str6 = InsertString(&str4, &str5, 2);
    Print(&str6);
    printf("Comparaison de str1 et str2 : %d\n", AreEquals(&str1, &str2));
    printf("Comparaison de str1 et str4 : %d\n", AreEquals(&str1, &str4));
    String str7 = Create("5");
    int pResult = 0;
    printf("%d", TryCastToInt(&str7, &pResult));

    DestroyString(&str1);
    DestroyString(&str2);
    DestroyString(&str3);
    DestroyString(&str4);
    DestroyString(&str5);
    DestroyString(&str6);
    DestroyString(&str7);
}