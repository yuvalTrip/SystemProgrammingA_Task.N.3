#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "FuncDef.h"
#include <ctype.h>
#include <stdlib.h>

#define TXT 1024 //define max len for the text
#define WORD 30  //define max len for the word

int AlreadyBeen[WORD + 1]; //define new array for word , that contain 1 if we already check this letter and 0 if we not been there before

//function check if String contain letter
bool contain(char *word, char letter)
{
    for (int i = 0; i < sizeof(word); ++i)
    {
        if (word[i] == letter && AlreadyBeen[i] == 0)
        {
            AlreadyBeen[i] = 1; //we will change the value to 1 because we now already 'visit' this letter
            return true;
        }
    }
    return false;
}
//in given word , we want to print all the minimal strings that build from the character of the word (and from empty chars)
void Func3(char *word, char *txt)
{
    int flag = 0;
    int Counter = 0;
    //char destination[TXT];
    //char FinalsAns[TXT + 1]; //define new array in size of txt (in max)

    printf("Anagram Sequences: ");
    for (int i = 0; i < strlen(txt); i++)
    {
        char sAns[TXT +1]=""; //define new array in size of txt (in max)
        //char ch_temp = txt[i];
        Counter = 0;
        int k;
        if (isalpha(txt[i]) == 0)
        {
            continue;
        }
        for (int element = 0; element < strlen(word); element++)
        {
            AlreadyBeen[element] = 0; //initial the array as we didnt check any letter
        }
        for (k = 0; k < strlen(word); k++)
        {
            while (i + Counter < strlen(txt) && isspace(txt[i + Counter])) //if there are spaces we will put it into the answer
            {
                sAns[Counter] = txt[i + Counter];
                Counter++;
            }
            if (i + Counter < strlen(txt) && contain(word, txt[i + Counter]))
            {

                // printf("if contain: %d \n", contain(word,txt[i+Counter]));
                sAns[Counter] = txt[i + Counter];
                Counter++;
            }
            else
            {
                break; //moove from this FOR
            }
        }
        if (k == strlen(word))
        {
            if (flag)
            {
                printf("~");
            }
            printf("%s", sAns); //print the char array as String;
            flag++;
        }
    }
    printf("\n");
}
void Func2(char *word, char *txt)
{
    int flag = 0;
    char sAns[TXT + 1]; //define new array in size of txt (in max)
    int Counter = 0;
    // char desti[TXT];
    char *WordInAtbash = funcToAtbash(word); //define variable for the word we get in atbah
    //char ReverseWord[WORD+1]= funcToreverse(word);//find the reverse of our word
    char ReverseWord[WORD + 1];
    strcpy(ReverseWord, word);
    funcToreverse(ReverseWord);
    char *WordInReverse_Atbash = funcToAtbash(ReverseWord); //define variable for the reverse of the word we get in atbah
    printf("Atbash Sequences: ");
    for (int i = 0; i < strlen(txt); i++)
    {
        //char ch_temp = txt[i];
        Counter = 0;
        int k;
        if (isalpha(txt[i]) == 0)
        {
            continue;
        }
        for (int element = 0; element < strlen(funcToAtbash(word)); element++)
        {
            AlreadyBeen[element] = 0; //initial the array as we didnt check any letter
        }
        for (k = 0; k < strlen(funcToAtbash(word)); k++)
        {
            while (i + Counter < strlen(txt) && isspace(txt[i + Counter])) //if there are spaces we will put it into the answer
            {
                sAns[Counter] = txt[i + Counter];
                Counter++;
            }
            if (i + Counter < strlen(txt) && contain(funcToAtbash(word), txt[i + Counter]))
            {

                sAns[Counter] = txt[i + Counter];
                Counter++;
            }
            else
            {

                break; //moove from this FOR
            }
        }
        if (k == strlen(funcToAtbash(word)))
        {
            char *FixedsAns = StringWithInvalid_Chars(sAns);//we aill send our string to function that return it without chars that are not alphabrtic
            int valueFor_WordInAtbash = strcmp(WordInAtbash, FixedsAns); //if 0 strings are same
            int valueFor_WordInreverse_Atbash = strcmp(WordInReverse_Atbash, FixedsAns);
            if (valueFor_WordInAtbash == 0)

            {
                if (flag)
                {
                    printf("~");
                }

                printf("%s", sAns); //print the char array as String
                flag++;
            }
            if (valueFor_WordInreverse_Atbash == 0)
            {
                if (flag)
                {
                    printf("~");
                }
                printf("%s", sAns); //print the char array as String
                flag++;
            }
        }
    }
    printf("\n"); //moove row
}
 //function chage the word to atbash
char *funcToAtbash(char *wordToreverse) 
{
    //  char *input =wordToreverse;
    char *new = malloc(WORD + 1); //[WORD+1];
    int i;
    for (i = 0; i <= strlen(wordToreverse) - 1; i++)
    {
        unsigned char c = wordToreverse[i];
        if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
        {
            new[i] = c;
            continue;
        }
        int flag = 0;
        if (c <= 90)
        {
            c = c + 32;
            flag = 1;
        }
        int off = c - 'a';
        new[i] = 'z' - off;
        if (flag)
            new[i] = new[i] - 32;
    }
    return (new);
}
 //function reverse the word 
void funcToreverse(char *word)
{
    int i, len, temp;
    len = strlen(word);
    for (i = 0; i < len / 2; i++)
    {
        temp = word[i];
        word[i] = word[len - i - 1];
        word[len - i - 1] = temp;
    }
}

//function get string and return it without any invalid chars: a% ^ __ dhg~ --> adhg
char *StringWithInvalid_Chars(char *txt)
{
    //char *valid; // [WORD+1];
     char *valid=malloc(WORD + 1);
    int index = 0;
    for (int i = 0; i < strlen(txt); i++)
    {
        if (isalpha(txt[i]) == 0 || isspace(txt[i])) //if char is not an alphabet
        {
            continue;
        }
        else
        {
            valid[index] = txt[i];
            index++;
        }
    }
    return valid;
}
 // gemetric value 
void Func1(char *word, char *txt)
{
    //char destination[WORD];
    int gemValue_word = 0;
    gemValue_word = GimetricValue(word); //compute the gimetric value
    int flag = 0;
    //char FinalsAns[TXT + 1]; //define new array in size of txt (in max)

    printf("Gematria Sequences: ");
    for (int i = 0; i < strlen(txt); i++) //moove over all txt abcde
    {
        char ans[TXT] = ""; //clear and define again the array
        int k = 0;
        int temp_gemValue = 0; //sum of the letters
        if (isalpha(txt[i]) == 0)
        {
            continue;
        }
        for (int j = i; j < strlen(txt); j++) //moove over all txt bcde
        {
            char ch_temp = txt[j];
            temp_gemValue = temp_gemValue + GimetricValue(&ch_temp); //we will compute the gimetric value of another char
            ans[k] = ch_temp;
            k++;
            if (temp_gemValue == gemValue_word)
            {
                if (flag)
                {
                    printf("~");
                }

                printf("%s", ans);
                flag++;
                break;
            }
            else if (temp_gemValue > gemValue_word)
            {
                break;
            }
        }
    }
    printf("\n"); //move row
}
 //calculate gemetric value of the given word
int GimetricValue(char *word)
{
    int gemValue_word = 0;
    for (int i = 0; i < strlen(word); ++i)
    {
        char ch = word[i];
        if ('Z' >= ch && ch >= 'A')
        {
            gemValue_word += ch - 'A' + 1;
        }
        else if ('z' >= ch && ch >= 'a')
        {
            gemValue_word += ch - 'a' + 1;
        }
        else
        {
            gemValue_word += 0;
        }
    }
    return gemValue_word;
}