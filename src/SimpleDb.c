/*
 * SimpleDb.c
 * Author: Eng_Saad_Redwan
 */

#include "SimpleDb.h"


/*Check database is full or not*/
bool SDB_IsFull(void)
{
    uint8 Is_Full = FALSE;

    if (COUNTER == SDB_SIZE)
    {
        Is_Full = TRUE;
    }

    return Is_Full;
}

uint8 SDB_GetUsedSize(void)
{
    return COUNTER;
}

bool SDB_AddEntry(uint8 id, uint16 year, uint8 *subjects, uint8 *grades)
{

    bool add_success = FALSE;
    if (!(SDB_IsFull()))
    {
        SDB_Entries[COUNTER].Student_ID = id;
        SDB_Entries[COUNTER].Student_year = year;

        SDB_Entries[COUNTER].Subjects[0] = subjects[0];
        SDB_Entries[COUNTER].Subjects[1] = subjects[1];
        SDB_Entries[COUNTER].Subjects[2] = subjects[2];

        SDB_Entries[COUNTER].Grades[0] = grades[0];
        SDB_Entries[COUNTER].Grades[1] = grades[1];
        SDB_Entries[COUNTER].Grades[2] = grades[2];
        /*
                uint8 i = 0;
                for (; i < 3; i++)
                {
                    SDB_Entries[counter].Subjects[i] = subjects[i];
                }

                for (i = 0; i < 3; i++)
                {
                    SDB_Entries[counter].Grades[i] = grades[i];
                }
        */
        add_success = TRUE;
        COUNTER++;
    }

    return add_success;
}

void SDB_DeletEntry(uint8 id)
{
    if (SDB_IsExist(id))
    {
        uint8 i;

        for (i = 0; i < COUNTER; i++)
        {
            if (SDB_Entries[i].Student_ID == id)
            {
                uint8 j;

                for (j = i; j < COUNTER - 1; j++)
                {
                    SDB_Entries[j] = SDB_Entries[j + 1];
                }
                COUNTER--;
                break;
            }
        }
    }
}

bool SDB_ReadEntry(uint8 id, uint16 *year, uint8 *subjects, uint8 *grades)
{
    bool read_succ = FALSE;

    if (SDB_IsExist(id))
    {
        uint8 i;
        for (i = 0; i < COUNTER; i++)
        {
            if (SDB_Entries[i].Student_ID == id)
            {
                *(year) = SDB_Entries[i].Student_year;

                *(subjects) = SDB_Entries[i].Subjects[0];
                *(subjects + 1) = SDB_Entries[i].Subjects[1];
                *(subjects + 2) = SDB_Entries[i].Subjects[2];

                *(grades) = SDB_Entries[i].Grades[0];
                *(grades + 1) = SDB_Entries[i].Grades[1];
                *(grades + 2) = SDB_Entries[i].Grades[2];

                read_succ = TRUE;
            }
        }
    }
    return read_succ;
}

void SDB_GetIdList(uint8 *count, uint8 *list)
{
    if (SDB_IsFull())
    {
        uint8 i;
        for (i = 0; i < COUNTER; i++)
        {
            *(list+i)=SDB_Entries[i].Student_ID;
        }
        *(count)=COUNTER;
    }
}

bool SDB_IsExist(uint8 ID)
{
    bool is_exist = FALSE;
    uint8 i;
    for (i = 0; i < COUNTER; i++)
    {
        if (SDB_Entries[i].Student_ID == ID)
        {
            is_exist = TRUE;
        }
    }
    return is_exist;
}

/*
static uint8 SDB_FindIndex(uint8 id)
{
    int i, id_index=0;

    if (!(SDB_IsFull()))
    {
        for (i = 0; i < COUNTER; i++)
        {
            if (SDB_Entries[i].Student_ID == id)
            {
                id_index=i;
                break;
            }
        }
    }
    return id_index;
}
*/



