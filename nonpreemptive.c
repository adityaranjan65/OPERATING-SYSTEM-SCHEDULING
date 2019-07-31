#include<stdio.h>
int i,j,n;float totwt,totserv;
struct pr
    {
        char name[5];
        float tservice;
        int priority;
        float twait;
        float trnd;
    };
    struct pr temp;
    struct pr pr1[20];
void init()
{
    printf("\nEnter the number of processes:");
    scanf("%d",&n);
   
    for(i=0;i<n;i++)
    {
        printf("\nEnter the details of process %d:\n1.Name: ",i+1);
        scanf("%s",pr1[i].name);
        printf("2.Service time: ");
        scanf("%f",&pr1[i].tservice);
        printf("3.Priority: ");
        scanf("%d",&pr1[i].priority);
    }
}
void prioritysort()
{
    for(i=0;i<n;i++)
    for(j=0;j<n-i-1;j++)
    {
        if(pr1[j].priority>pr1[j+1].priority)
        {
            temp=pr1[j];
            pr1[j]=pr1[j+1];
            pr1[j+1]=temp;
        }
    }
}
void sjnsort()
{
for(i=0;i<n;i++)
    for(j=0;j<n-i-1;j++)
    {
        if(pr1[j].tservice>pr1[j+1].tservice)
        {
            temp=pr1[j];
            pr1[j]=pr1[j+1];
            pr1[j+1]=temp;
        }
    }
}
void calculation()
{
pr1[0].twait=0;totwt=0;totserv=pr1[0].trnd=pr1[0].tservice;
    for(i=1;i<n;i++)
    {
        //printf("\nwait= %f",totwt);
        pr1[i].twait=pr1[i-1].twait+pr1[i-1].tservice;
        totwt+=pr1[i].twait;
        pr1[i].trnd=pr1[i].twait+pr1[i].tservice;
        totserv+=pr1[i].trnd;

    }
}
void printing()
{
    printf("Name \tPriority \tServiceTime \t WaitTime \t TurnAroundTime\n");
    for(i=0;i<n;i++)
        {
        printf("%s \t %d \t\t %f \t %f \t %f\n",pr1[i].name,pr1[i].priority,pr1[i].tservice,pr1[i].twait,pr1[i].trnd);
        }
        printf("\nAverage wait:%f \tAverage turnaround:%f \n",totwt/n,totserv/n);
}

main()
{
    int ch,exit=0;
    init();
   
    while(exit==0)
    {
    printf("\n---MENU---\n1.FIRST COME FIRST SERVED (FCFS)\n\t2.PRIORITY SCHEDULING\n\t\t3.SHORTEST JOB NEXT (SJN)\n\t\t\t5.Exit\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\t<<<FCFS SCHEDULING>>>\n");
            break;
        case 2:printf("\t<<<PRIORITY SCHEDULING>>>\n");
            prioritysort();
            break;
        case 3:printf("\t<<<SJN SCHEDULING>>>\n");
            sjnsort();
            break;
        case 5:    printf("\nExiting...\n");
        default: exit=1;
           
            break;
    }
    if(exit==0)
    {
        calculation();
        printing();   
    }

    }

}
