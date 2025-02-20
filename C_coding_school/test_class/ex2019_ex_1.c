#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_store_name
typedef struct Date_type
{
    unsigned Day;
    unsigned Month;
    unsigned Year;
}Date_type;

typedef struct trans
{
    int Id_card;
    int Id_store;
    char Name_store[max_store_name+1];
    float Amount;
    Date_type trans_date;
}trans;

trans_type *create_trans(unsigned int id_card, unsigned int id_store, char name_store[33], float amount, Date_type tdate)
{
    trans *new_trans = malloc(sizeof(trans));
    if (new_trans == NULL) {return NULL}
    new_trans->Id_card = id_card;
    new_trans->Id_store = id_store;
    strcpy(new_trans->Name_store,name_store);
    new_trans->Amount = amount;
    new_trans->trans_date = tdate;
    return new_trans;
}

float sum_trans(trans *trans_arr,int size,unsigned Id_card,unsigned year)
{
    float sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (trans_arr[i].Id_card = Id_card && trans_arr[i].trans_date.Year = year)
        {
            sum += trans_arr[i].Amount;
        }
    }
    return sun;
}
