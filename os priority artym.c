//a program to perform the shortest job first ( non preemptive )...
#include"unistd.h"
#include"stdio.h"
#include"stdlib.h"

int pr[1000],bt[1000],wt[1000],tt[1000],pri[1000],at[1000],start[1000];

void getValue(int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		pr[i]=i+1;
		printf("burst time of process %d : ",i+1);
		scanf("%d",&bt[i]);
		printf("priority of process %d : ",i+1);
		scanf("%d",&pri[i]);
		printf("arrival time of process %d : ",i+1);
		scanf("%d",&at[i]);
		printf("\n");
	}
}

void sortValue(int n)
{
	int i,p,j,t;
	start[0]=0;
	for (i=0;i<n;i++)
		{
			p=i;
			for (j=i+1;j<n;j++)
			{
				if(at[j]==at[p])
				{
					if(pri[j]<pri[p])
						p=j;
				}
				else if(at[j]<at[p])
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
			
			t=at[i];
			at[i]=at[p];
			at[p]=t;
			
			start[i]=start[i]+bt[i-1];
		}
}

void calcWT(int n)
{
	int i,j;
		wt[0]=0;	
		for (i=1;i<n;i++)
		{
			wt[i]=start[i]-at[i];
			for(j=0;j<i;j++)
			{
				wt[i]=start[i]-at[i];
			}
		} 
}

void calcTT(int n)
{
	int i;
	tt[0]=bt[0];
	for(i=1;i<n;i++)
	{
		tt[i]=bt[i]+wt[i];
	}
}

float calcAWT(int n)
{
	int i,sum=0;
	for(i=0;i<n;i++)				//average waiting time
	{
		sum=sum+wt[i];
	}
	float avgwt=(float)sum/n;
	return avgwt;
}

float calcATT(int n)
{
	int i,sum=0;
	for(i=1;i<n;i++)				//average turn around time
	{
		sum=sum+tt[i];
	}
	float avgtt=(float)sum/n;
	return avgtt;
}

void display(float awt,float att,int n)
{
	int i;
	printf("\nGantt Chart : \n\n");
	for(i=0;i<n;i++)
	{
		printf("|  P %d  ",pr[i]);
	} 
	printf("|\n");
	
	printf("\nProcess\t\t  Priority\t\t Burst Time\t\tArrival Time\t\tWaiting Time\t\tTurn-around Time\n");
	for(i=0;i<n;i++)
	{
		printf("\nprocess %d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t%d",pr[i],pri[i],bt[i],at[i],wt[i],tt[i]);
	}
	printf("\n\nAverage waiting time : %g",awt);
	printf("\nAverage turn around time : %g",att);
}

int main()
{

	printf("\n\t\t\t\t\t\t-------------SHORTEST JOB FIRST (NON PREEMPTIVE)-------------\n\n");
	printf("\n\t\t\t\t\t\t\t-------------With Process Priorities-------------\n\n");
	printf("enter the total number of processes : ");
	int n;
	scanf("%d",&n);
	printf("\nenter the burst time, priorities and arrival time of processes : \n\n");
	
	getValue(n);
	
	sortValue(n);
		
	calcWT(n);	
	
	calcTT(n);
	
	float awt=calcAWT(n);
	
	float att=calcATT(n);
	
	display(awt,att,n);
}
