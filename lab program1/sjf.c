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
    int n,time=0,completed=0;
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct process p[n];
    int visited[n];

    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("Enter Arrival Time and Burst Time for P%d: ",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
        visited[i]=0;
    }

    while(completed<n)
    {
        int min=9999,index=-1;

        for(int i=0;i<n;i++)
        {
            if(p[i].at<=time && visited[i]==0 && p[i].bt<min)
            {
                min=p[i].bt;
                index=i;
            }
        }

        if(index!=-1)
        {
            time+=p[index].bt;

            p[index].ct=time;
            p[index].tat=p[index].ct-p[index].at;
            p[index].wt=p[index].tat-p[index].bt;

            avgwt+=p[index].wt;
            avgtat+=p[index].tat;

            visited[index]=1;
            completed++;
        }
        else
        {
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);

    return 0;
}
