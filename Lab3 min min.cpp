#include<stdio.h>
int main()
{
	int n,i,process;
	printf("Enter the no. of tasks:\n");
	scanf("%d",&n);
	int num=n;
	int a[100];
	int b[100];
	int min[100],max[100];
	char minCh[100];
	int minm,minIndex;
    char maxCh[100];
    int maxm,maxIndex;
    printf("Executing for min-min algorithm:\n");
    printf("Enter the tasks for VM1:");
	for(i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	}

    printf("Enter the tasks for VM2:");
	for(i=0;i<n;i++)
	{
	    scanf("%d",&b[i]);
	}
	while(num>0)
	{

		for(i=0;i<n;i++)
		{
			if(a[i]<b[i])
			{
				min[i]=a[i];
				minCh[i]='1';
			}
			else
			{
				min[i]=b[i];
				minCh[i]='2';
			}
		}

		minm = findMin(min,n,&minIndex);
		a[minIndex]=b[minIndex]=100000;

		printf("Executing VM%c\'s task %d...",minCh[minIndex],minIndex+1);

		for(i=0;i<n;i++)
		{
			if(minCh[minIndex]=='1')
			{
				if(a[i]<100000)
				{
					a[i]=a[i]+minm;
				}
			}
			else
			{
				if(b[i]<100000)
				{
					b[i]=b[i]+minm;
				}
			}

		}
		num=num-1;
	}
    
}

int findMin(int* a,int n,int* ind)
{    int min=a[0];
     *ind=0;
     int i;
	for(i=1;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			*ind=i;
		}
	}
	return min;
}
