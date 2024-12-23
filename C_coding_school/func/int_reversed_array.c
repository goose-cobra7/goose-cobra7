int reversed_array[ARRAYSIZE]; 
    int j = ARRAYSIZE - 1;
    for (int a = 0; a < ARRAYSIZE; a++) //reverse the array
    {
        reversed_array[j] = array[a]; //array is the array you choose
        j--;
    }
    /*it run from from 0 to ARRAYSIZE on the array and flip it to show in the 
    reversed_array*/
    //pay attention to getting all the elements in the function colored meaning used