#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "string_parse.h"
#define TXT 1024
#define WORD 30
#define TRUE 1

//return the geo value of *word until *(word + n) not include
int geoValue(char* word, int n){
  int sum = 0;
  for (int i = 0; i < n; ++i){
    if(isupper(word[i]))
      sum+= word[i] - 64;
    if(islower(word[i]))
      sum+= word[i] - 96;
  }
  return sum;
}

void validChack(char* text, int* start){
  while (!isalpha(text[*start]))
    *start += 1;
}

//print *word until *(word + n) not include
void printCArr(char* ptr, int n){
  for (int i = 0; i < n; i++)
    printf("%c",ptr[i]);
  printf("~");
}

void AFunc(char word[WORD], char text[TXT]){
  char ans[TXT] = "";
  int wordVal = geoValue(word, strlen(word));
  int start = 0;//include
  int end = 1; //not include
  int currVal = geoValue(text, 1);
  for(int i = 0; i < TXT; ++i){
    if (text[start] == '~' || text[end - 1] == '~')
      break;
    if (currVal == wordVal){
      validChack(text,&start);
      printCArr((text + start), end - start);
      currVal -= geoValue(text + start, 1);
      ++start;
    }
    if (currVal > wordVal){
      currVal -= geoValue(text + start, 1);
      ++start;
    }
    if (currVal < wordVal){
      currVal += geoValue(text + end, 1);
      ++end;
    }
  }
}

void BFunc(char word[WORD], char text[TXT]){

}

void CFunc(char word[WORD], char text[TXT]){

}
