#include <stdio.h>
#include "string_parse.h"
#define TXT 1024
#define WORD 30

int main() {

  char text[TXT], word[WORD];

  for (int i = 0; i < WORD; ++i){
    scanf("%c",&word[i]);
    if (word[i] == ' ' || word[i] == '\t' || word[i] == '\n'){
      word[i] = '\0';
      break;
    }
  }
  for (int i = 0; i < TXT; ++i){
    scanf("%c",&text[i]);
    if (text[i] == '~'){
      text[i + 1] = '\0';
      break;
    }
  }

  AFunc(word, text);
  printf("\n");
  BFunc(word, text);
}
