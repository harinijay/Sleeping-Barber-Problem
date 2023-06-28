#include <stdio.h>
#include <stdlib.h>
#define MAX 4  //Number of chairs available


int front =  - 1;
int rear =  - 1;

//Entering a client to the queue
void enqueue(int queue[], int item)
{
    //When the queue is full, no chairs available for clients
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\nNo chairs available...");
        return;
    }
    //In the begining of the queue, the first client have to wakeup the barber
    else if (rear ==  - 1)
    {
        printf("\nBarber is asleep, wakeup barber...");
        rear++;
        front++;
    }
    
    else if (rear == MAX - 1 && front > 0)
    {
        printf("\nClient is added to the queue...");
        rear = 0;
    }
    //Adding clients to the queue
    else
    {
        printf("\nClient is added to the queue...");
        rear++;
    }
    //adding the input to the queue
    queue[rear] = item;
}


//Departure of a client
int dequeue(){
    int e;
    int queue[MAX];
    e = queue[front];

    //When the queue is empty barber goes to sleep
    if(front == -1){
        printf("\nNo clients, barber can go to sleep...");
    }

    else if(front == MAX-1){
        printf("\nNo clients, barber can go to sleep...");
        front = 0;
    }
    else if(front == rear){
        printf("\nNo clients, barber can go to sleep...");
        front = -1;
        rear = -1;
    }
    //Sending the next client in the queue to the barber
    else{
        front++;
        printf("\nNext client can go to the barber...");
        return e;
    }
}


//Main function
int main()
{
    int n=1, option;
    int queue[MAX];
    do
    {
        //List of options
        printf("\nOptions: ");
        printf("\n\t1. Client  arrives.");
        printf("\n\t2. Client departs.");
        printf("\n\t3. Exit.");

        //Taking the user's option
        printf("\n\nEnter the option:");
        scanf("%d", &option);


        switch (option)
        {
            case 1:
                enqueue(queue, n);
                n++;
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                exit(1);
                break;
        }
    }while (option != 0);
}