#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * Rstrchr(char * s, char x)  {
  int i = strlen(s);
  if(!(*s))  return 0;
  while(s[i-1]) if(strchr(s + (i - 1), x))  return (s + (i - 1));  else i--;
  return 0;
}

void ToLowerCase(char * s)  {
  while(*s) {
    *s=tolower(*(s++));
    //s++;
  }
}

int main() {
  char str[256] = "HELLO world!!!";
  ToLowerCase(str);
  printf("str3 = %s\n", str);
  
  return 0;
}
