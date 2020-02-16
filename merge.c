#include<stdio.h>
#include<time.h>
void merge(int arr[],int low,int mid,int high)
{    int c[2000000];
     int k=low;
     int i=low;
     int j=mid+1;
      while(i<=mid&&j<=high)
      {
         if(arr[i]<=arr[j])
         {
            c[k++]=arr[i++];
         }
         else
               c[k++]=arr[j++];
      }
      while(i<=mid)
        c[k++]=arr[i++];
      while(j<=high)
         c[k++]=arr[j++];
     for(i=low;i<=high;i++)
        arr[i]=c[i];
   
   
}  






void Mergesort(int arr[],int low,int high)
{   
     if(low<high)
     {
        int mid=(low+high)/2;
        Mergesort(arr,low,mid);
	Mergesort(arr,mid+1,high);
         merge(arr,low,mid,high);
      }
    
   
}
		
void main()
{
    int low,mid,high,i,size;
    printf("Enter size of array\n");
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++)
    {
          arr[i]=rand();
    }
    clock_t start,end;
    double t_time; 
    low=0;
    high=size-1;
    
    start=clock();
    Mergesort(arr,low,high);
    end=clock();
    printf("Sorted array is \n");
    for(i=0;i<size;i++)
       printf("%d\n",arr[i]);
   t_time=(double)(end-start)/CLOCKS_PER_SEC;
   printf("Time taken is %lf\n",t_time);

}

