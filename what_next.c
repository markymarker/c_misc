#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv){
  char * questions[] = {
    "So what next?",
    "What did we just do?",
    "What's on the jira board?",
    "What's good in the hood?",
    "Where's David?"
  };
  int choiceCount = 5;
  int choice = -1;

  printf("Choose a question:\n");
  for(int j = 0; j < choiceCount; ++j)
    printf("  %d. %s\n", j + 1, questions[j]);
  printf("\n");

  do{
    char input[5];
    printf("Enter choice: ");
    fgets(input, sizeof(input), stdin);

    if(input[strlen(input) - 1] != '\n'){
      char c;
      while((c = getchar()) != '\n'){
        if(feof(stdin) || c == EOF) break;
      }
    }

    if(sscanf(input, "%d", &choice) == 1 && choice > 0 && choice <= choiceCount) break;

    printf("Invalid input. ");
  } while(1);

  printf("\n%s  I dunno.\n", questions[choice - 1]);

  return 0;
}

