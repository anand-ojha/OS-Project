//a program to perform the shortest job first ( non preemptive )...
#include"unistd.h"
#include"stdio.h"
#include"stdlib.h"

int main()
{
	int pr[100],bt[100],wt[100],tt[100],pri[100];
	printf("\n\t\t\t\t\t\t-------------SHORTEST JOB FIRST (NON PREEMPTIVE)-------------\n\n");
	printf("\n\t\t\t\t\t\t\t-------------With Process Priorities-------------\n\n");
	printf("enter the total number of processes : ");
	int i,n,j;
	scanf("%d",&n);
	printf("\nenter the burst time and priorities of processes : \n\n");
	for (i=0;i<n;i++)
	{
		pr[i]=i+1;
		printf("burst time of process %d : ",i+1);
		scanf("%d",&bt[i]);
		printf("priority of process %d : ",i+1);
		scanf("%d",&pri[i]);
		printf("\n");
	}
	
	int p,t;
	
	for (i=0;i<n;i++)
		{
			p=i;
			for (j=i+1;j<n;j++)
			{
				if(pri[j]==pri[p])
				{
					if(bt[j]<bt[p])
						p=j;
				}
				else if(pri[j]<pri[p])
				{
					p=j;
				}
			}
			t=bt[i];
			bt[i]=bt[p];
			bt[p]=t;
			
			t=pr[i];
			pr[i]=pr[p];
			pr[p]=t;
			
			t=pri[i];
			pri[i]=pri[p];
			pri[p]=t;
			
		}
		
	wt[0]=0;	
	for (i=1;i<n;i++)
		{
			wt[i]=0;
			for(j=0;j<i;j++)
			{
				wt[i]=wt[i]+bt[j];
			}
		}	
		
	int sum=0;	
	for(i=0;i<n;i++)
	{
		sum=sum+wt[i];
	}
	float avgwt=(float)sum/n;
	
	tt[0]=bt[0];
	sum=0;
	for(i=1;i<n;i++)
	{
		tt[i]=bt[i]+wt[i];
		sum=sum+tt[i];
	}
	float avgtt=(float)sum/n;
	
	printf("\nProcess\t\t  Priority\t\t Burst Time\t\tWaiting Time\t\tTurn-around Time\n");
	for(i=0;i<n;i++)
	{
		printf("\nprocess %d\t\t%d\t\t\t%d\t\t\t%d\t\t%d",i+1,pri[i],bt[i],wt[i],tt[i]);
	}
	printf("\n\nAverage waiting time : %g",avgwt);
	printf("\nAverage turn around time : %g",avgtt);
}

