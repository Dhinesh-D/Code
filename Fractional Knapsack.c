#include<stdio.h>
#include<conio.h>
void sort(int n,float wt[],float pt[],float rat[])
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(rat[i]<rat[j])
			{
				t=rat[j];
				rat[j]=rat[i];
				rat[i]=t;
				
				t=wt[j];
				wt[j]=wt[i];
				wt[i]=t;
				
				t=pt[j];
				pt[j]=pt[i];
				pt[i]=t;
				
			}
		}
	}
}
void knapsack(int n,float wt[],float pt[],float cap)
{
	float temp[20],gain=0;
	int i,j,k,c;
	k=cap;
	for(i=0;i<n;i++)
		temp[i]=0.0;
	for(i=0;i<n;i++)
	{
		if(wt[i]>k)
		{
		break;
		}
		else
		{
			temp[i]=1.0;
			gain=gain+pt[i];
			k=k-wt[i];
			
		}
	}
	if(i<n)
		temp[i]=k/wt[i];
	gain=gain+(temp[i]*pt[i]);		
	c=gain;
	printf("\nTHE MAXIMUM PROFIT:%d",c);
}
void main()
{
	float wt[20],pt[20],cap;
	int n,i,j;
	float rat[20],temp;
	printf("\nENTER N:");
	scanf("%d",&n);
	printf("\nENTER WEIGHT AND PROFIT:");
	for(i=0;i<n;i++)
	{
		scanf("%f %f",&wt[i],&pt[i]);
	}
	printf("\nENTER CAPACITY:");
	scanf("%f",&cap);
	for(i=0;i<n;i++)
		rat[i]=pt[i]/wt[i];
	sort(n,wt,pt,rat);
	knapsack(n,wt,pt,cap);
	getch();
}
