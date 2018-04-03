//a program to perform the shortest job first ( non preemptive )...
#include"unistd.h"
#include"stdio.h"
#include"stdlib.h"

int pr[1000],bt[1000],wt[1000],tt[1000],pri[1000];

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
		printf("\n");
	}
}

void sortValue(int n)
{
	int i,p,j,t;
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
}

void calcWT(int n)
{
	int i,j;
		wt[0]=0;	
		for (i=1;i<n;i++)
		{
			wt[i]=0;
			for(j=0;j<i;j++)
			{
				wt[i]=wt[i]+bt[j];
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
	
	printf("\nProcess\t\t  Priority\t\t Burst Time\t\tWaiting Time\t\tTurn-around Time\n");
	for(i=0;i<n;i++)
	{
		printf("\nprocess %d\t\t%d\t\t\t%d\t\t\t%d\t\t%d",pr[i],pri[i],bt[i],wt[i],tt[i]);
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
	printf("\nenter the burst time and priorities of processes : \n\n");
	
	getValue(n);
	
	sortValue(n);
		
	calcWT(n);	
	
	calcTT(n);
	
	float awt=calcAWT(n);
	
	float att=calcATT(n);
	
	display(awt,att,n);
}
