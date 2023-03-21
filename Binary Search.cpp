#include <stdio.h>                                               /* Library inclusions */
#include "genlib.h" 
#include "simpio.h"

int binSearch(int val, int numbers[], int size1);                /* prototypes */
void sortArray (int numbers[], int size1);                       
int indexMax (int numbers[], int low, int high);
void swap (int numbers[], int loc, int loc1);
void getArray (int numbers[], int size1);
void displayArray (int numbers[], int size1);

main()
{
  int value, size1;

  printf("Enter the number of elements: ");
  size1=GetInteger(); 
  int numbers[size1];
  getArray(numbers, size1); 
  sortArray(numbers, size1); 
  displayArray(numbers, size1);
  printf("\nEnter value to find: ");
  value=GetInteger();
  binSearch(value, numbers, size1);
  getchar();
}

void sortArray (int numbers[], int size1)                        /*Function sortArray*/
{
 int i , maxInd;

 for (i= size1-1; i>=0;i--)
 {
     maxInd=indexMax(numbers, 0, i);
     swap (numbers, i, maxInd);
 }
}

void displayArray (int numbers[], int size1)                     /*Function displayArray*/
{
 int i;

 printf("This is the sorted set of numbers: \n");
 for (i=0; i< size1; i++)
 {
         printf ("%d\t", numbers[i]); 
     }
}

void getArray (int numbers[], int size1)                         /*Function getArray*/
{
 int i;

 for (i=0; i<size1; i++)
 {
     printf ("Enter the values of the %d elements: ", size1);
     numbers[i]=GetInteger();
 }
}

int indexMax (int numbers[], int low, int high)                  /*Function indexMax*/
{
int i, maxInd;

maxInd=high;
for (i=low;i<=high;i++)
{
    if (numbers[i]>numbers[maxInd]) 
    {
                   maxInd =i;
    }
    }
    return (maxInd);
}

void swap (int numbers[], int loc, int loc1)                     /*Function swap*/
{
 int temp;

 temp=numbers[loc];
 numbers[loc]=numbers[loc1];
 numbers[loc1]=temp;
}

int binSearch(int val, int numbers[], int size1)                 /*Function binSearch*/
{
 int low, high, mid;

 low=0;
 high=size1-1;
 while(low<=high)
 {
                 mid=(low+high)/2;
                 if(val<numbers[mid])
                 {
                                 high=mid-1;                
                 }            
                 else if(val>numbers[mid])
                 {
                                 low=mid+1; 
                 }   
                 else if(val==numbers[mid])
                 {
                                 printf("Your number is in location %d\n", mid+1);break;    
                 } 
                 else
                 {
                                 printf("Your value is not in the array.");        
                 }
   }
}
