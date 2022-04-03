/*
 * Std_Types.h
 * Author: Eng_Saad_Redwan
 */

#ifndef SDT_TYPES_H
#define SDT_TYPES_H

/*Generic configuration of data types which we want to use*/
typedef unsigned char uint8;
typedef unsigned short int uint16;

/*Define bool as new type using enum to use it because c doesn't has a bool type*/
typedef enum
{
	FALSE,
	TRUE
}bool;


#endif 