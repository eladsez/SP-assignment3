#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "string_parse.h"
#define TXT 1024
#define WORD 30
#define TRUE 1
#define FALSE 0

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
void printCArr(char* ptr, int n, int flag){
  if (flag) printf("~");
  for (int i = 0; i < n; i++)
    printf("%c",ptr[i]);

}

void AFunc(char word[WORD], char text[TXT]){
  printf("Gematria Sequences: ");
  int flag = FALSE;
  int wordVal = geoValue(word, strlen(word));
  int start = 0;//include
  int end = 1; //not include
  int currVal = geoValue(text, 1);
  for(int i = 0; i < TXT; ++i){
    if (text[start] == '~' || text[end - 1] == '~')
      break;
    if (currVal == wordVal){
      validChack(text,&start);
      printCArr((text + start), end - start, flag);
      currVal -= geoValue(text + start, 1);
      ++start;
      flag = TRUE;
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

void makeAtbash(char word[WORD], char* atbash){
  for (int i = 0; i < strlen(word); i++){
    if (isalpha(word[i])){

      if (isupper(word[i]))
        *(atbash + i) = (char)(91 - ((int)word[i] - 64));

      if (islower(word[i]))
        *(atbash + i) = (char) (123 - ((int)word[i] - 96));
    }
    else *(atbash + i) = word[i];
  }
  *(atbash + strlen(word)) = '\0';
}

void reverse(char* word, int len){
  char temp;
  int i = 0;
  int j = len - 1;
  while(i < j){
    temp = *(word + i);
    *(word + i) = *(word + j);
    *(word + j) = temp;
    j--;
    i++;
  }
}

int atbashcmp(char *atbash, char *text, int end){
  int iAtbash = 0;
  int iText = 0;
  while (iAtbash < strlen(atbash) && iText < end){
    if (text[iText] == ' ') {
      ++iText;
      continue;
    }
    else if(text[iText] != atbash[iAtbash]) return FALSE;
    ++iText;
    ++iAtbash;
  }
  return TRUE;
}

void BFunc(char word[WORD], char text[TXT]){
  printf("Atbash Sequences: ");
  char *atbash = malloc(strlen(word) * sizeof(char) + 1);
  char *reverseAtbash = malloc(strlen(word) * sizeof(char) + 1);

  makeAtbash(word, atbash);
  strcpy(reverseAtbash, atbash);
  reverse(reverseAtbash, strlen(reverseAtbash));

  int start = 0;
  int end = strlen(word);
  int flag = FALSE;
  while (start < strlen(text) - 1 - strlen(word)){
    while (text[end + 1] != '~'){
      if(atbashcmp(atbash, text + start, end - start) || atbashcmp(reverseAtbash, text + start, end - start)){
        printCArr((text + start), end - start, flag);
        flag = TRUE;
        break;
      }
      ++end;
    }
    ++start;
    end = start + strlen(word);
  }

  free(reverseAtbash);
  free(atbash);
}

void CFunc(char word[WORD], char text[TXT]){

}
