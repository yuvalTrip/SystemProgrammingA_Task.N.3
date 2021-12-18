#include<stdio.h>
#define TXT 1024
#define WORD 30
#include "FuncDef.h"
#include <string.h>



char word[WORD + 1];
char txt[TXT + 1];

int main()
{


    int indexOfletter_Word=0;
    char ch1;
    ch1= getchar();
    while (ch1!=' ' && ch1!='\t' && ch1!='\n'){
        word[indexOfletter_Word]=ch1;
        ch1=getchar();
        indexOfletter_Word++;
    }
    word[indexOfletter_Word]='\0';
    int indexOfletter_Text=0;
    char ch2;
    ch2 = getchar();
    while(ch2!= '~'){
        txt[indexOfletter_Text]=ch2;
        ch2 = getchar();
        indexOfletter_Text++;
    }


    Func1(word,txt);//gimetria
    Func2(word,txt);
    Func3(word,txt);

}