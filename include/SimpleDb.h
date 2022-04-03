/*
 * SimpleDb.h
 * Author: Eng_Saad_Redwan
 */

#ifndef Simple_Db_
#define Simple_Db_


#include "Student.h"

/*Define maximum size of database*/
#define SDB_SIZE   10

/*Define the variable that using to check the number of elements which are exists in the database */
static uint8 COUNTER=0;

/*
*A database is an array of 10 students organized 
*and it is fixed to be hidden from other files 
*so the database can't change without the interface 
*/
static Student SDB_Entries[SDB_SIZE];

bool SDB_IsFull(void);
uint8 SDB_GetUsedSize();
bool SDB_AddEntry(uint8 id, uint16 year, uint8* subjects,uint8* grades);
void SDB_DeletEntry(uint8 id);
bool SDB_ReadEntry(uint8 id, uint16* year, uint8 *subjects, uint8 *grades);
void SDB_GetIdList(uint8* count, uint8* list);
bool SDB_IsExist(uint8 ID);

// static uint8 SDB_FindIndex(uint8 id);


#endif 