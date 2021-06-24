#ifndef  STOH_H
#define  STOH_H

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include <time.h>

#define  Price   15
#define  S_OK 0;
#define  S_FAIL -1;

typedef  struct S_car
{
    char license[20];
    int   hour;
    int   minute;
    int  second;
    int  price;
    struct S_car  *next;

}S_car;

int insert_car(S_car *head);
int display_cars(S_car *head);
int delete_car(S_car *head);
void menu(S_car *head);
#endif