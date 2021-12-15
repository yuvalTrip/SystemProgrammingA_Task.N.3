#include <string.h>
//#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <FuncDef.h>


#define TXT 1024//define max len for the text
#define WORD 30 //define max len for the word

//char word[WORD + 1];//define array in len+1 (because the final add)
//char txt[TXT + 1];
int AlreadyBeen[WORD + 1];//define new array for word , that contain 1 if we already check this letter and 0 if we not been there before

//function check if String contain letter
bool contain (char * word,char  letter)
{
        for (int i = 0; i < sizeof(word); ++i) 
       {
           if (word[i]==letter&&AlreadyBeen[i]==0 )
           {
               AlreadyBeen[i]==1;//we will change the value to 1 because we now already 'visit' this letter
               return true;
           }
       }
       return false;
}
 //in given word , we want to print all the minimal strings that build from the character of the word (and from empty chars)
void Func3(char * word,char * txt)
{
       // fgets(word, sizeof(word), stdin);// get the word from User  
        //fgets(txt, sizeof(txt), stdin);// get the text from User
        char sAns[TXT + 1];//define new array in size of txt (in max)
        int Counter=0;
        for (int i = 0; i < sizeof(txt); i++) 
        {
                char ch_temp = txt[i];
                printf(ch_temp);
                if(contain(word,ch_temp))
                {
                    Counter=0;
                    int k;
                     for (int element=0;element< sizeof(word);element++)
                    {
                        AlreadyBeen[element]=0;//initial the array as we didnt check any letter
                    } 
                    for (k = 0; k < sizeof(word); k++)
                    {
                        while(i+Counter< sizeof(txt)&& txt[i+Counter] == ' '){
                            sAns[Counter]=txt[i+Counter];
                            Counter++;
                        }
                        if(i+Counter<sizeof(txt)&&contain(word,txt[i+Counter]))
                        {
                            sAns[Counter]=txt[i+Counter];
                            Counter++;
                        }
                        else
                        {
                            break;//moove from this FOR
                        }

                    } 
                    if(k==sizeof(word))
                    {
                        printf("\"%s\"\n", sAns) ;//print the char array as String
                        //printf("\"%s\"\n", name);//according to https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c/8465083
                    }

                }

        }
}


