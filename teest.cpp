#include<stdio.h>
int i,j,n;
float totser,ttur;
struct pr
{char name[2];
	int tservice,turn,twait;
	
	
}pr[10],temp;
main()
{printf("Enter the no of process");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the details\n");
		printf("Name\t");
		scanf("%s",&pr[i].name);
		printf("service time\t");
		scanf("%d",&pr[i].tservice);
		
	}
	
	for(i=0;i<n;i++)
    for(j=0;j<n-i-1;j++)
    {
        if(pr[j].tservice>pr[j+1].tservice)
        {
            temp=pr[j];
            pr[j]=pr[j+1];
            pr[j+1]=temp;
        }
    }
	pr[0].twait=0;totser=0;totser=pr[0].turn=pr[0].tservice;
	for(i=1;i<n;i++)
	{
		pr[i].twait=pr[i-1].tservice+pr[i-1].twait;
		totser+=pr[i].twait;
		pr[i].turn=pr[i].twait+pr[i].tservice;
		ttur+=pr[i].turn;
	}
	
	printf("name \t service time \t wait time \t turnaround time \n");
	for(i=0;i<n;i++)
	{
		printf("%s \t\t%d \t\t%d \t\t%d\n",pr[i].name,pr[i].tservice,pr[i].twait,pr[i].turn);
	}
}

