#include<stdio.h>
#define size 5

int queue[size];
int front = -1, rear = -1;

void insert(int value){
    if(rear == size - 1){
        printf("Queue overflow! cannot insert %d\n",value);
    }else{
        if(front == -1) front = 0;
        rear ++;
        queue[rear] = value;
        printf("Inserted %d\n",value);
    }
}

void delete(){
    if(front == -1 || front > rear){
        printf("Queue underflow! Queue is empty\n");
    }else{
        printf("Deleted %d\n",queue[front]);
        front++;
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("Queue is empty.\n");
    }else{
        printf("Queue elements: ");
        for(int i = front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice,value;
    while(1){
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter value to insert: \n");
            scanf("%d",&value);
            insert(value);
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("Exiting program.");
            return 0;
            default:
            printf("Invalid choice!\n");
        }
    }
}