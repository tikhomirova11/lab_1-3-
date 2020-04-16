#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct Person_ID
{
    int seria;
    int nomer;
} Person_ID;

typedef struct birthdate
{
    int date;
    int month;
    int year;
} birthdate;

typedef struct persone
{
    struct Person_ID id;
    char firstname[20];
    char lastname[20];
    struct birthdate bd;
} persone;

persone* toFebruary(persone* list, persone* persone);

bool* AfterMay(persone* list, persone* persone);

persone* FuncApril(persone* list, persone* persone);

bool* FuncAprilForWhere(persone* list, persone* persone);