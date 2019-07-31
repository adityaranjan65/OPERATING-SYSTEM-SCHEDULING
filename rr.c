#include<stdio.h>
struct process
{
	char na[20];
	int at,bt,ft,tat,rem;
	float ntat;
}Q[5],temp;
int rr[20],q,x,k;
void main()
{
	int f,r,n,i,j,tt=0,qt,t,flag,wt=0;
	float awt=0,antat=0,atat=0;
	printf("Enter the no. of jobs:");
	scanf("%d",&n);
	for(r=0;r<n;r++)
	{
		printf("\nEnter process name:");
		scanf("%s",Q[r].na);
		printf("\narrival time:");
		scanf("%d",&Q[r].at);
		printf("\nBurst time:");
		scanf("%d",&Q[r].bt);
	}
	printf("Enter quantum:\n");
	scanf("%d",&qt);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(Q[i].bt>Q[j].bt)
			{
				temp=Q[i];
				Q[i]=Q[j];
				Q[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		Q[i].rem=Q[i].bt;
		Q[i].ft=0;
	}
tt=0;
q=0;
rr[q]=0;
do
{
	for(j=0;j<n;j++)
	if(tt>=Q[j].at)
	{
		x=0;
		for(k=0;k<=q;k++)
		if(rr[k]==j)
		x++;
		if(x==0)
		{
			q++;
			rr[q]=j;
		}
	}
	if(q==0)
	i=0;
	if(Q[i].rem==0)
	i++;
	if(i>q)
	i=(i-1)%q;
	if(i<=q)
	{
		if(Q[i].rem>0)
		{
			if(Q[i].rem<qt)
			{
				tt+=Q[i].rem;
				Q[i].rem=0;
			}
			else
			{
				tt+=qt;
				Q[i].rem-=qt;
			}
			Q[i].ft=tt;
		}
		i++;
	}
	flag=0;
	for(j=0;j<n;j++)
	if(Q[j].rem>0)
	flag++;
}while(flag!=0);
printf("\nprocesses Arrival_time burst_time finish_time turnaround_time waiting time");
for(f=0;f<n;f++)
{
	wt=Q[f].ft-Q[f].bt-Q[f].at;
	Q[f].tat=Q[f].ft-Q[f].at;
	Q[f].ntat=(float)Q[f].tat/Q[f].bt;
	antat+=Q[f].ntat;
	atat+=Q[f].tat;
	awt+=wt;
	printf("\n\t%s\t%d\t\t%d\t%d\t\t%d\t\%d ",
	Q[f].na,Q[f].at,Q[f].bt,Q[f].ft,Q[f].tat,wt);
}
antat/=n;
atat/=n;
awt/=n;
printf("\nAverage tat is %f",atat);
printf("\n average waiting time is %f",awt);
}
  
