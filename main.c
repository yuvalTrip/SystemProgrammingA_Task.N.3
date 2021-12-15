#include<stdio.h>
#define TXT 1024
#define WORD 30
#include <FuncDef.h>



char word[WORD + 1];
char txt[TXT + 1];

int main()
{
    printf("Please enter word:");
    // scanf("%s %s", word,txt);
    scanf("%s", word);
    printf("Please enter text:");
    scanf("%s",txt);


    Func3(word,txt);
}