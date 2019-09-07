#include<stdio.h>
#include<stdlib.h>
int m,n,h,a[50],i;
void sort(int qu[])
{
	for(i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(qu[j]>qu[j+1])
			{
				int temp=qu[j];
				qu[j]=qu[j+1];
				qu[j+1]=temp;
			}
		}
	}
}
void fcfs()
{
	int head=h,thm=0;
	for(i=0;i<n;i++)
	{
		int k=abs(a[i]-head);
		head=a[i];
		thm=thm+k;
	}
	printf("\n fcfs thm = %d",thm);
}
void scan()
{
	printf("\n enter prev head : ");
	int ph,arr[50],thm=0,head=h;
	scanf("%d",&ph);
	for(i=0;i<n;i++)	arr[i]=a[i];
	sort(arr);
	
	if(head>ph)
	{	
		if(head<arr[0])		thm=abs(arr[n-1]-head);
		else
			thm=abs(m-head)+abs(m-arr[0]);
	}
	else
	{
		if(head>arr[n-1])	thm=abs(head-arr[0]);
		else 
			thm=abs(head)+abs(arr[n-1]);
	}		
	printf("\nthm in scan = %d",thm);
}
void cscan()
{
	printf("\nenter prev head : ");
	int ph,thm=0,arr[50],head=h;
	scanf("%d",&ph);
	for(i=0;i<n;i++)	arr[i]=a[i];
	sort(arr);
	if(head>ph)
	{
		if(head<arr[0])		thm=abs(arr[n-1]-head);
		else if(head>arr[n-1])
		{
			thm=abs(m-head)+m+arr[n-1];
		}
		else
		{
			thm=abs(head-m)+abs(m);
			for(i=0;i<n;i++)
			{
				if(arr[i]>head)
				{
					thm=thm+arr[i-1];
					break;
				}
			}
		}
	}
	else
	{
		if(head>arr[n-1])	thm=abs(head-arr[0]);
		else if(head<arr[0])
		{
			thm=abs(head-0)+m+abs(m-arr[0]);
		}
			
		else
		{
			thm=abs(head-0+m-0);
			for(i=n-1;i>=0;i--)
			{
				if(arr[i]<head)
				{
					thm=thm+abs(m-arr[i+1]);
					break;
				}
			}
		}
	}
	printf("\nthm in cscan = %d",thm);
}

	
int main()
{
	int ch;
	printf("enter max of disk and no.of elements to insert :  ");
	scanf("%d %d",&m,&n);
	if(m<n)
	{
		printf("\nerror!!!!\n\n");
		exit(0);
	}
	printf("\nenter elements  :  ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nenter head  : ");
	scanf("%d",&h);
	while(1)
	{
		printf("\n\ncurrent head is %d ",h);
		printf("\nenter choice 1.fcfs 2.scan 3.cscan 4.change head :  ");
		scanf("%d",&ch);	
		if(ch==1)	fcfs();
		else if(ch==2)	scan();
		else if(ch==3)	cscan();
		else if(ch==4)	
		{
			int hd;
			printf("\nenter new head : ");
			scanf("%d",&hd);
			h=hd;
		}
		else break;
	}
	return 0;
}

		
