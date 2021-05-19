
#include <stdio.h>

#define SOME_CONST 0

void fiddleArr(char *, int);


struct collection {
    int x;
    int y;
};

typedef struct collection point;



int main(){

#if SOME_CONST == 1
    printf("some const got set to 1\n");
#endif

    char str[20];
    str[0] = 'h';
    str[1] = 'i';
    str[2] = ' ';
    str[3] = 'm';
    str[4] = 'o';
    str[5] = 'm';
    str[6] = '\0';

    str[2] = '\0';

    printf("%s\n", str);


////////

    int len = 8;
    char a[len];
    // char a[] = { 'a', 'b', 'c' };
    a[0] = '6';

    fiddleArr(a, len);

////////

    //struct collection p;
    point p;
    point * location;
    location = &p;
    p.x = 5;
    p.y = 2;
    location->x = 10;

    printf("x: %d, y: %d\n", p.x, p.y);
    printf("x: %d, y: %d\n", location->x, location->y);

////////

    return 0;
}


void fiddleArr(char * arr, int len){
    for(unsigned char j = 0; j < len; ++j){
        *(arr + j) = j + 'a';
        printf("%2d: %c\n", j, arr[j]);
    }
}



/*

        int newval;
        char inp[10];
        for(int j = 0; j < 9; ++j){
            char c = getchar();
            if((c < '0' || c > '9') && c != '-') break;
            inp[j] = c;
        }
        newval = atoi(inp);

*/

