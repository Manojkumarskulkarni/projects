// Linked list insertion opertions
// c program to make  all insertion  operations on linked list


#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>/*preprocessor directives*/
/*structure specification for node*/
struct node
{
    int info;
    struct node* next;
};

/*Fuction prototypes*/
struct node* fnGetNode(void);
struct node* fnInsertFront(struct node*,int);
struct node* fnInsertRear(struct node*,int);
struct node* fnInsertAfter(struct node*,int,int);
struct node* fnInsertBefore(struct node*,int,int);
struct node* fnSearch(struct node*,int);
void fnDisplay(struct node*);

/*Function name:main
  Arguments:void
  return type:int
  Author:Manojkimar S Kulkarni
  Date:01-10-2023
 */
 int main(void)
 {
     struct node* first=NULL,*temp;
     int data,choice,key;
     for(;;)
     {
         printf("Menu\n");
         printf("1:Insert front\n2:Insert Rear\n3:Insert After\n4:Insert Before\n5:Search\n6:Display\n7:Exit\n");
         printf("Enter your choice\n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:
                        printf("Enter the element to be inserted at front\n");
                        scanf("%d",&data);
                        first=fnInsertFront(first,data);
                        break;
            case 2:
                        printf("Enter the element to be inserted at rear\n");
                        scanf("%d",&data);
                        first=fnInsertRear(first,data);
                        break;
            case 3:
                        
                        if(first==NULL)
                        {
                            printf("List is empty can not insert\n");
                        }
                        else
                        {
                            printf("Enter the key after which you want to insert\n");
                            scanf("%d",&key);
                            printf("Enter the element to be inserted after %d\n",key);
                            scanf("%d",&data);
                            first=fnInsertAfter(first,data,key);
                        }
                        break;
            case 4:
                        printf("Enter the key before which you want to insert\n");
                        scanf("%d",&key);
                        printf("Enter the element to be inserted before %d\n",key);
                        scanf("%d",&data);
                        first=fnInsertBefore(first,data,key);
                        break;
            case 5:
                        printf("Enter the element to be searched\n");
                        scanf("%d",&key);
                        temp=fnSearch(first,key);
                        if(temp==NULL)
                        {
                            printf("Element is not found in the list\n");
                        }
                        else
                        {
                            printf("Element %d is found\n",temp->info);
                        }
                        break;
            case 6:
                        fnDisplay(first);
                        break;
            case 7:
                        printf("Thank you for using my app\n");
                        exit(0);
            default :
                        printf("Invlid choice\n");
                        break;
         }
     }
 }
 
 /*Function name:fnGetNode
   Argumets:void
   Return type:struct node*
   Author:Manojkumar S Kulkarni
   Date:01-10-2023
  */
  struct node* fnGetNode()
  {
      struct node* p;
      p=(struct node*) malloc(sizeof(struct node));
      return p;
  }/*End of fnGetNode*/
  
  /*Function name:fnInsertFront
  Arguments:struct node*,int
  return type: struct node*
  Author:Manojkumar S Kulkarni
  Date:01-10-2923
*/
struct node* fnInsertFront(struct node* p,int x)
{
    struct node* q;
    q=fnGetNode();
    q->info=x;
    q->next=NULL;
    if(p==NULL)
        return q;
    q->next=p;
    return q;
}
/*Function name:fnInsertRear
  Arguments:struct node*,int
  return type: struct node*
  Author:Manojkumar S Kulkarni
  Date:01-10-2923
*/
struct node* fnInsertRear(struct node* p,int x)
{
    struct node *q,*temp;
    q=fnGetNode();
    q->info=x;
    q->next=NULL;
    if(p==NULL)
        return q;
    temp=p;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=q;
    return p;
}
/*Function name:fnSearch
  Arguments:struct node*,int
  return type: struct node*
  Author:Manojkumar S Kulkarni
  Date:01-10-2923
*/
struct node* fnSearch(struct node* p, int k)
{
    struct node* temp;
    if(p==NULL)
        return NULL;
    temp=p;
    while(temp!=NULL)
    {
        if(temp->info==k)
        {
            return temp;
        }
        temp=temp->next;
    }
    return temp;
}
/*Function name:fnDisplay
  Arguments:struct node*
  return type: void
  Author:Manojkumar S Kulkarni
  Date:01-10-2923
*/
void fnDisplay(struct node *p)
{
   struct node* temp;
   temp=p;
   while(temp!=NULL)
   {
       printf("%d->",temp->info);
       temp=temp->next;
       
   }
   printf("\n");
}

struct node* fnInsertAfter(struct node *p,int x,int k)
{
    struct node *temp,*q;
     q=fnGetNode();
     q->info=x;
     q->next=NULL;
     
     if(p==NULL)
        return NULL;
    temp=p;
    while(temp!=NULL&&temp->info!=k)
    {
            temp=temp->next;
    }
    if(temp!=NULL)
    {
        q->next=temp->next;
        temp->next=q;
        
    }
     
    return p;
     
}
struct node* fnInsertBefore(struct node *p,int x,int k)
{
    struct node *temp,*q,*r;
    q=fnGetNode();
    q->info=x;
    q->next=NULL;
    if(p==NULL)
    {
        return NULL;
    }
    temp=p;
    while(temp!=NULL&&temp->info==k)
    {
        temp=temp->next;
    }
    if(temp!=NULL)
    {
        q->next=temp->next;
         temp->next=q;
    }
    return p ;
}

























