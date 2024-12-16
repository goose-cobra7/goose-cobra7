int array_order[10];


int element_digit_count(int arr[],int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        int temp = arr[i];
        array_order[temp%10]++;
        array_order[((temp%100)-(temp%10))/10]++;
        array_order[((temp%1000)-(temp%100))/100]++;
    }
    
}