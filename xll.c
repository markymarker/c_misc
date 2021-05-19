// Mark Fletcher
// 2020-05-22
// ___ please note this code is outside what we agreed to on the ip policy, so hands off!

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Linked list node definition

typedef struct node_s {
    struct node_s * both;
    int value;
} node;


// Linked list node functionality

node * getXOR(node * n, node * other){
    return (node *)((uintptr_t)n->both ^ (uintptr_t)other);
}

node * find_end(node * start){
    node * cursor = start;
    node * prev = NULL;
    node * next;

    while((next = getXOR(cursor, prev)) != NULL){
        prev = cursor;
        cursor = next;
    }

    return cursor;
}

void add(node * start, int val){
    node * end = find_end(start);

    node * new = (node *)malloc(sizeof(node));
    new->both = end;
    new->value = val;

    end->both = getXOR(end, new);
}

int get(node * start, int index){
    node * cursor = start;
    node * prev = NULL;

    for(int count = 0; count < index; ++count){
        node * next = getXOR(cursor, prev);
        if(next == NULL) return -1;

        prev = cursor;
        cursor = next;
    }

    return cursor->value;
}


////////////////////////
////////////////////////


int main(){

    node start = {
        .both = NULL,
        .value = -1
    };
    node * s = &start;

    // Get some user input to test the add function
    do {
        int newval;
        printf("Enter new value (negative to stop): ");
        scanf("%d", &newval);

        if(newval < 0 || feof(stdin)) break;
        if(start.value < 0) start.value = newval;
        else add(s, newval);
    } while(1);

    // Show what's in the list
    printf("\nHere's the list:\n");
    int i = 0;
    node * cursor = s, * prev = NULL;
    while(cursor != NULL){
        printf("  %2d: %d\n", i++, cursor->value);
        node * next = getXOR(cursor, prev);
        prev = cursor;
        cursor = next;
    }
    printf("\n");

    // Get some user input to test the get function
    do {
        int find;
        printf("Enter index (negative to stop): ");
        scanf("%d", &find);

        if(find < 0 || feof(stdin)) break;

        int value = get(s, find);
        if(value < 0) printf("Invalid index, try again\n");
        else printf("value: %d\n", value);
    } while(1);

    // See ya!
    return 0;
}

