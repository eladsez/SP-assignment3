#include <stdio.h>
#include "string_parse.h"
#define TXT 1024
#define WORD 30

int main() {

  char text[TXT], word[WORD];

  for (int i = 0; i < WORD; ++i){
    scanf("%c",&word[i]);
    if (word[i] == ' ' || word[i] == '\t' || word[i] == '\n')
      break;
  }
  for (int i = 0; i < TXT; ++i){
    scanf("%c",&text[i]);
    if (text[i] == '~')
      break;
  }
  AFunc(word, text);
}
