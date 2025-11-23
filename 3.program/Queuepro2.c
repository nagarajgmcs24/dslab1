#include<stdio.h>
#define size 3

int cqueue[size];
int front = -1, rear = -1;

void insert(int value){
    if((front == 0 && rear == size - 1) || (rear+1)%size == front){
        printf("Circular Queue overflow! cannot insert %d\n", value);
    }else{
        if(front == -1){
            front = rear = 0;
        }else{
            rear = (rear+1)%size;
        }
        cqueue[rear] = value;
        printf("Inserted %d\n",value);
    }
}

void delete(){
    if(front == -1){
        printf("Circular Queue underflow! Queue is empty\n");
    }else{
        printf("Deleted %d\n",cqueue[front]);
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front+1)%size;
        }
    }
}

void display(){
    if(front == -1){
        printf("Circular Queue is empty\n");
    }else{
        printf("Circular Queue elements: ");
        int i = front;
        while(1){
            printf("%d ",cqueue[i]);
            if(i == rear) break;
            i = (i+1)%size;
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
