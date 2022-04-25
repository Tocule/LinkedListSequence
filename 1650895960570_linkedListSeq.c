#include<stdio.h>
#include<stdlib.h>


/*
 * ************* Maximum Points: 10 ***************** 
 *
 * ********** PENALTY: -15 (negative 15) ************** 
 *  In following cases you will get penalty
 *  (a) Not submitted, 
 *  (b) Copied, 
 *  (c) Late submission
 *  (d) Submission is not as per the instructions
 *
 * ***************** Instructions *******************
 * (1) Implement ALL methods without any changes in input arguments. You are
 *      NOT allowed to add or remove any arguments of any method.
 * (2) DO NOT CHANGE names of structures, functions or arguments.
 * (3) You can add helper method. Add comments to describe its purpose.
 * (4) You can make assumptions if something is not clear. Make sure you write 
 *     your assumptions wherever required as comments. If you make assumptions but 
 *     HAVE NOT mentioned then it may lead to loss of points.
 * (5) While submitting the code DO NOT KEEP any code in main method. Also DO 
 *     NOT CHANGE filename while submitting the code.
*/

/* README
   This implementation of integer sequence uses linked list.
   Every node has pointer to next node. 
   items are referred as 0,1,2...n-1. (meaning, index start from 0)
*/

typedef struct Node {
  int item;           // item
  struct Node *next;  // Pointer to next node
}Node;

typedef struct LinkedList {
  Node *head;   // Pointer to first node of list
  int len;      // Length of linked list
}LinkedList;


////Helper Functions///

void print(LinkedList *s)                   //For printing the sequence
{
   if(s->len>0)
   {	   
     Node *temp;
     temp=s->head;
     printf("Your printed elements are: ");
     while(temp!=NULL)
     {
       printf("%d ",temp->item);
       temp=temp->next;
     }
   }  
   printf("\n");
}   

// Read 'len' number of integers and create LinkedList from it.
// Return address of the sequence.

LinkedList *build(int len) 
{
    LinkedList *s;	
    Node *first,*temp,*ptr;
    s=(LinkedList *)malloc(sizeof(LinkedList));
    s->head=NULL;
    first=NULL;
    int i;
    printf("Enter the elements\n");
    for(i=0;i<len;i++)
    {
        ptr=(Node *)malloc(sizeof(Node));
	ptr->next=NULL;
	scanf("%d",&ptr->item);
	if(first==NULL)
	{
	   first=ptr;
	   temp=ptr;
	   s->head=ptr;
	   s->len=len;
	}
	else
	{
	  temp->next=ptr;
          temp=ptr;
        }
    }
    
    return(s);    
}

// Replace 'i'th node of the sequence with new item 'x'.
void set_at(int i, Node *x, LinkedList *s)    
{                                              
   Node *temp;                                
   temp=s->head;
   int j;
   x=(Node *)malloc(sizeof(Node));
   printf("Enter the item\n");
   scanf("%d",&x->item);
   x->next=NULL;
   for(j=0;j<i;j++)
   {
      temp=temp->next;
   }
   temp->item=x->item;   
}

Node *get_at(int i, LinkedList s)     //it is assumed that for second argument the *s from main function is passed, thereby causing pass by   
{                                     //value the assumptions regarding i is same as in set_at function
   Node *temp;                        //*s is example of LinkedList Variable
   temp=s.head;
   int j;
   for(j=0;j<i;j++)
   {
      temp=temp->next;
   }
   return(temp);   
}

// Return Length of sequence 
int length(LinkedList s)            //assumption regarding 1st argument is same as get_at function 2nd argument
{
   return(s.len);	  
}

// insert 'x' at i th position in sequence s (REMEBER ith ITEM OF SEQUENCE NOT ARRAY).
void insert_at(int i, Node *x, LinkedList *s) 
{
   Node *temp;
   int j=s->len;
   int k;
   if(i<0 || i>j)
   {
      printf("Error:Out of bounds.The size of array is %d\n",j);
   }
   else if(i==0 || i==j)
   {
      printf("Make use of insert_first/insert_last functions\n");
   }
   else
   {
      temp=s->head;
      for(k=0;k<i-1;k++)
      {
         temp=temp->next;
      }
      x=(Node *)malloc(sizeof(Node));
      printf("Enter the item to insert\n");
      scanf("%d",&x->item);
      x->next=temp->next;
      temp->next=x;
    
      (s->len)++;

    }               
}

// removes the ith element of the sequence and returns the pointer to deleted item.
Node *delete_at(int i, LinkedList *s) 
{
   Node *temp,*prev,*deleted;
   deleted=(Node *)malloc(sizeof(Node));
   temp=s->head;
   int k;
   int j=s->len;
   if(i<0 || i>=j)
   {
      printf("Error:Out of bounds.The size of array is %d\n",j);
      deleted->item=-9999;
      deleted->next=NULL;
      return(deleted);
   }
   else if(i==0 || i==j-1)
   {
      printf("Make use of delete_first/delete_last functions\n");
      deleted->item=-9999;
      deleted->next=NULL;
      return(deleted);
   }
   else
   {
      temp=s->head;
      for(k=0;k<i;k++)
      {
         prev=temp;
         temp=temp->next;
      }
      deleted->item=temp->item;
      deleted->next=NULL;
      prev->next=temp->next;
      free(temp);
      (s->len)--;
      return(deleted);
   }      

}

// insert item 'x' at the start of the sequence.
void insert_first(Node *x, LinkedList *s) 
{ 
    x=(Node *)malloc(sizeof(Node));
    printf("Enter the data to be inserted\n");
    scanf("%d",&x->item);    
    x->next=s->head;
    s->head=x;
    (s->len)++;
}

// insert item 'x' at the end of the sequence.
void insert_last(Node *x, LinkedList *s)
{
   x=(Node *)malloc(sizeof(Node));
   printf("Enter the data to be inserted\n");
   scanf("%d",&x->item);
   Node *temp;
   temp=s->head;
   while(temp->next!=NULL)
   {
     temp=temp->next;
   }
   temp->next=x;
   x->next=NULL;
   (s->len)++;   
}

// delete first item of sequence and return pointer to deleted item.
Node *delete_first(LinkedList *s) 
{
   Node *temp,*deleted;
   temp=s->head;
   deleted=(Node *)malloc(sizeof(Node));
   deleted->item=temp->item;
   deleted->next=NULL;
   s->head=s->head->next;
   free(temp);
   (s->len)--;
   return(deleted);
}

// delete last item of sequence and return pointer to deleted item.
Node *delete_last(LinkedList *s) 
{
   Node *temp,*prev,*deleted;
   temp=s->head;
   deleted=(Node *)malloc(sizeof(Node));
   //int end=s->len;
   if(s->len==1)
   {
      deleted->item=temp->item;
      deleted->next=NULL;
      free(temp);
      (s->len)--;
      return(deleted);
   }	   
   while(temp->next!=NULL)
   {
     prev=temp;
     temp=temp->next;
   }
   prev->next=NULL;
   deleted->item=temp->item;
   deleted->next=NULL;
   free(temp);
   (s->len)--;
   return(deleted);   
}

int main(void) 
{
 
}
