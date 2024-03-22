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
    
    strt.iLength = 20;
    strt.pContent = "";
    for(int i = 0; str[i] != '\0'; i++)
    {
        strt.pContent[i] = str[i] + "";
        printf("%c", strt.pContent[i]);
        strt.iLength = i+1;
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
    for(int i = 0; i < pStr1->iLength; i++)
    {
        strt.pContent[i] = pStr1->pContent[i];
    }
    return strt;
}

String Concatenate2(const char* str1, const char* str2)
{

}

String SubString(const String* pStr1, int iStartIndex, int iLength)
{

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

}

int main() 
{
    String str1 = Create("Bonjour");
    /*Print(&str1);
    String str2 = Create("Aurevoir");
    String str3 = Concatenate1(&str1, &str2);
    Print(&str3);*/
/*
    Destroy(&str1);
    Destroy(&str2);
    Destroy(&str3);*/
}