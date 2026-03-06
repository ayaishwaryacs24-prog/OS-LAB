#include<stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int rt;
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

    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("Enter Arrival Time and Burst Time for P%d: ",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].rt=p[i].bt;
    }

    while(completed<n)
    {
        int min=9999,index=-1;

        for(int i=0;i<n;i++)
        {
            if(p[i].at<=time && p[i].rt>0 && p[i].rt<min)
            {
                min=p[i].rt;
                index=i;
            }
        }

        if(index!=-1)
        {
            p[index].rt--;
            time++;

            if(p[index].rt==0)
            {
                completed++;

                p[index].ct=time;
                p[index].tat=p[index].ct-p[index].at;
                p[index].wt=p[index].tat-p[index].bt;

                avgwt+=p[index].wt;
                avgtat+=p[index].tat;
            }
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
