#include <string.h>

char *my_strdup(char *src) {
  char *dest;
  int  i;

  dest = malloc(sizeof(*src) * strlen(src));
  i = 0;
  while (i < strlen(src)) {
      dest[i] = src[i];
      ++i;
    }
    dest[i] = '\0';
    return dest; 
}
