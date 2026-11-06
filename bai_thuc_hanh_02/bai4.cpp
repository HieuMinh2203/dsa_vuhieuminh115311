#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char hten[50];
    int masv;
    float d1, d2, d3;
}Data;
typedef struct Node
{
    Data infor;
    struct Node *link;
}Node;
typedef struct {
    Node *pHead;
    Node *pTail;
    int spt;
}LList;