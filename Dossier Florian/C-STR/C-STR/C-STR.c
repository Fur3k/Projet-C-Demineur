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
        i++;
    }

    strt.pContent = (char*)malloc(strt.iLength * sizeof(char));
    for (int j = 0; j < strt.iLength; j++)
    {
        if (i < str1l) {
            strt.pContent[i] = str1[i];
        }
        else
        {
            strt.pContent[i] = str2[i - str1l];
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
    for (int j = iStartIndex; j < strt.iLength; j++)
    {
        strt.pContent[j- iStartIndex] = pStr1->pContent[j];
    }
    return strt;
}

String InsertString(const String* pStr1, const String* Pstr2, int iIndex)
{

}

int AreEquals(const String* pStr1, const String* pStr2)
{

}

int TryCastToInt(const String* pStr, int* pResult)
{

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

    DestroyString(&str1);
    DestroyString(&str2);
    DestroyString(&str3);
}