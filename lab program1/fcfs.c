#include<stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
};

int main()
{
    int n,time=0;
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct process p[n];

    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("Enter Arrival Time and Burst Time for P%d: ",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
    }

    for(int i=0;i<n;i++)
    {
        if(time<p[i].at)
            time=p[i].at;

        time+=p[i].bt;
        p[i].ct=time;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;

        avgwt+=p[i].wt;
        avgtat+=p[i].tat;
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);

    return 0;
}
