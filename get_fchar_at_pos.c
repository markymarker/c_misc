// 2020-11-12

#include <stdio.h>

int main(int argl, char ** argv){

  if(argl < 3){
    printf("\
  usage: %s <filename> <position>\n\
  Gets the character at the given position in the given file\n", argv[0]);
    return 1;
  }

  long int p = 0;
  FILE * f;

  f= fopen(argv[1], "r");
  if(f == NULL){
    fprintf(stderr, "Error opening file: %s\n", argv[1]);
    return 1;
  }

  int matched = sscanf(argv[2], "%ld", &p);
  if(matched != 1 || p < 0 || p == EOF){
    fprintf(stderr, "What a strange position: %s (%ld)\n", argv[2], p);
    return 1;
  }

  if(fseek(f, p, SEEK_SET) || feof(f)){
    perror("Error seeking to position");
    return 2;
  }

  char c = fgetc(f);

  if(c == EOF){
    printf("Got EOF character\n");
    if(ferror(f))
      perror("Along with error");
    return 2;
  }

  printf("Char at position %ld : (%d) %c\n", p, (int)c, c);

  return 0;
}

