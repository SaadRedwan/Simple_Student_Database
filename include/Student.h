/*
 * Student.h
 * Author: Eng_Saad_Redwan
 */

#ifndef STUDENT_H
#define STUDENT_H

#include "Std_Types.h"

/*Declere studen as data type using it as a element in the database*/
typedef struct  
{
    uint8 Student_ID;
    /*
    *I use uint16 insteade of uint8 because uint8 have max int 255 
    *i.e: we cant write 2020 as a yeare if we using uint8
    */
    uint16 Student_year;
    uint8 Subjects[3];
    uint8 Grades[3];
}Student;

#endif 
