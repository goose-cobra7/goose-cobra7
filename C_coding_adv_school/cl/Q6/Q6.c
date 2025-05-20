#include "List.c"
#include "Queue.c"

# define arr_len 8


Queue order_q(Queue *queue);
void print_q(Queue queue);

int main()
{
    Queue my_que;
    my_que = makeEmptyQueue();
    int arr[] = { 7 ,-3 ,9 ,-4 ,0 ,6 ,-2 ,0 };
    for (size_t i = 0; i < arr_len; i++)
    {
        enqueue(&my_que,arr[i]);
    }
    order_q(&my_que);
    print_q(my_que);

    return 0;
}

Queue order_q(Queue *queue)
{
    Queue min;
    Queue max;
    Queue zero;
    min = makeEmptyQueue();
    max = makeEmptyQueue();
    zero = makeEmptyQueue();
    int temp;
    while (queue->list.head)
    {
        temp = dequeue(queue);
        if(temp > 0)
        {
            enqueue(&max,temp);
        }else if (temp < 0)
        {
            enqueue(&min,temp);
        }else
        {
            enqueue(&zero,temp);
        }
    }
    while(min.list.head)
    {
        enqueue(queue,dequeue(&min));
    }
    while(zero.list.head)
    {
        enqueue(queue,dequeue(&zero));
    }
    while(max.list.head)
    {
        enqueue(queue,dequeue(&max));
    }
    return *queue;
}

void print_q(Queue queue)
{
    while (queue.list.head)
    {
        printf("%d,",dequeue(&queue));
    }
    
}