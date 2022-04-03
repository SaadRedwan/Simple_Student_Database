/*
 * test.c
 * Author: Eng_Saad_Redwan
 */



#include<stdio.h>
#include <stdlib.h>
#include "SimpleDb.h"


int main()
{
    uint8 size=SDB_IsFull();
    uint8 arr[3]={8,5,9};
    uint8 arr2[3]={6,2,4};

    uint8 arr3[3]={7,6,2};
    uint8 arr4[3]={2,9,8};

    bool succ=SDB_AddEntry(1,2001,arr,arr2);
    bool succ2=SDB_AddEntry(2,2001,arr3,arr4);

    uint16 *year; 
    uint8 *subjects=NULL; 
    uint8 *grades=NULL;

    year= (uint16*)malloc(sizeof(uint16));
    subjects=(uint8*)malloc(3*sizeof(uint8)); 
    grades=(uint8*)malloc(3*sizeof(uint8));

    bool succ3=SDB_ReadEntry(2, year, subjects, grades);
    
    SDB_DeletEntry(2);

    bool succ4=SDB_ReadEntry(2, year, subjects, grades);

    uint8 coun=SDB_GetUsedSize();

    printf("size of SDB is: %d   %d   %d",size, succ4, subjects[1]);



 return 0;   
}