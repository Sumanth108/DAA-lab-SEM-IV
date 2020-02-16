#include<stdio.h>
#include<time.h>

int partition(int a[],int low,int high)
{   int pivot=a[low],temp;
    int i=low;
    int j=high+1;
   while(i<=j)
   {
       do
      {
          i++;
      }while(pivot>=a[i]);
      do
      {
          j--;
      }while(pivot<a[j]);
       if(i<j)
      {
       temp=a[i];
       a[i]=a[j];
       a[j]=temp;
      }
   }
  
   temp=a[low];
   a[low]=a[j];
   a[j]=temp;
   return j;
}

void quicksort(int a[],int low,int high)
{  
   if(low<high)
   {
     int mid=partition(a,low,high);
     quicksort(a,low,mid-1);
     quicksort(a,mid+1,high);
  }
}
void main()
{
   int low,high,n,i;
   printf("Enter size of the array:\n");
   scanf("%d",&n);
   int a[n];
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   low=0;
   high=n-1;
   quicksort(a,low,high);
   printf("*******************\n");==
   for(i=0;i<n;i++)
      printf("%d\n",a[i]);
   

}
