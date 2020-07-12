
/* Task for today -
Create a linked list with 4 nodes and two functions-
1. Addition/Insertion of a Node
2. Deletion of a Node */

#include<stdio.h>
#include<stdlib.h> 

struct node
{
    int data;
    struct node *next;
};
//deleting node at a particular position
void delete(struct node* temp,struct node* prev)
{
    prev->next=temp->next;
    temp->next=NULL;
    free(temp);
    
}
//deleting at the start
void deletestart(struct node* temp1)
{
     struct node *ptr = (struct node *)malloc(sizeof(struct node *));  
     ptr = temp1;  
     temp1 = ptr->next;  
     free(ptr); 
}
//delete from end
void deleteEnd(struct node* temp)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node *)); 
    while(temp->next != NULL)
    {
          
         ptr=temp;
         temp=temp->next;
    }
    ptr->next=NULL;
    free(temp);
    
}
  // adding a node after any given point
  void insert(struct node* prev, int newdata) 
{ 
   
    struct node* newnode =(struct node*) malloc(sizeof(struct node)); 
  
    newnode->data  = newdata; 
  
    newnode->next = prev->next; 
  
    prev->next = newnode; 
} 
  //adding the node in the beginning
   void insertstart(struct node** temp1,int newdata)
{
    struct node* newnode =(struct node*) malloc(sizeof(struct node)); 
  
    newnode->data  = newdata; 
  
    newnode->next = *temp1;
    
    *temp1=newnode;
    
}
 //adding the node in the end
 void insertend(struct node * temp1, int newdata)
 {
     struct node* newnode =(struct node*) malloc(sizeof(struct node)); 
     newnode->data=newdata;
     newnode->next=NULL;
     temp1->next=newnode;
 }

int main()
{   
    struct node *head = (struct node *)malloc(sizeof(struct node));
    

    head->data = 100;
    head->next = NULL;


    struct node *second_link = (struct node *)malloc(sizeof(struct node));
    second_link->data = 110;
    second_link->next = NULL;

    head -> next = second_link;


    struct node *third_link = (struct node *)malloc(sizeof(struct node));
    third_link->data = 200;
    third_link->next = NULL;
    second_link->next = third_link; 
    
    
    struct node *fourth_link = (struct node *)malloc(sizeof(struct node));
    fourth_link->data = 300;
    fourth_link->next=NULL;
    third_link->next=fourth_link;
    
    
    insert(second_link,300);
    insertstart(&head,400);
    insertend(fourth_link,500);
    delete(third_link,second_link);
    deletestart(head);
    deleteEnd(head);
  
    
    
  

    //printing the linked list
    struct node *temp = head;
    while(temp->next!=NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> NULL ", temp->data);
    
   
   
}


