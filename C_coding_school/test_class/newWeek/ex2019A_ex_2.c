#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date_type
{
    unsigned Day;
    unsigned Month;
    unsigned Year;
}Date_type;


typedef struct trans_type
{
    unsigned Id_card;
    unsigned Id_store;
    char Name_store[32];
    unsigned Amount;
    Date_type tans_date;
}trans_type;

int main(int argc, char const *argv[])
{
    
    return 0;
}

trans_type *create_trans(unsigned int id_card, unsigned int id_store, char name_store[33], float amount, Date_type tdate)
{
    trans_type *new_trans = (trans_type*)malloc(sizeof(trans_type));
    if (new_trans == NULL){printf("memory out!!!");exit(1);}
    new_trans->Id_card = id_card; new_trans->Id_store = id_store; strcpy(new_trans->Name_store,name_store); new_trans->Amount = amount; new_trans->tans_date = tdate;
    return new_trans;
}

float sum_trans(trans_type *tran_arr,int size,unsigned Id_card,unsigned Year)
{
    float sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (tran_arr[i].Id_card == Id_card && tran_arr[i].tans_date.Year == Year)
        {
            sum += tran_arr[i].Amount;
        }
        
    }
    return sum;
}