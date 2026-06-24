#ifndef LINKED_H_INCLUDED
#define LINKED_H_INCLUDED
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <conio.h>

#include <stdbool.h>

#include <stdlib.h>

typedef struct STUDENT{

int id;

char name[30];

char department[30];

int age;

}STU;

typedef struct mynode{

struct mynode * next;

STU data;

}node;

typedef struct LINKED_LIST{

node * head;

node * current;

}link;

void CREATELIST(link * s);

void SCANSANDAPPEND(link * s,STU e);

void SORTDATA(link * s,STU e);

void SEARCHDATA(link * s,STU e);

void UPDATE(link * s,STU e);

bool ISEMPTY(link * s);

void SELECTALLDATA(link * s);

void DELETE(link * s,STU e);

void INSERTATMIDDLE(link * s,STU e);

void INSERTATFIRST(link * s,STU e);

void DELETELIST(link * s,STU e);

void INSERT(link * s,STU e);

#endif // LINKED_H_INCLUDED
