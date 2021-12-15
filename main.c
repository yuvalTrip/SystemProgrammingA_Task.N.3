#include<stdio.h>
#define TXT 1024
#define WORD 30


char word[WORD + 1];
char txt[TXT + 1];

int main()
{
    printf("Please enter word and than text:");
    scanf("%d %d", &word,&txt);
    Func3(word,txt);
}