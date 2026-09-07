#include<stdio.h>
int main(){
    int n , bt[10] ,tat[10] ,wt[10] ,p[10];
    float avg_tat =0.0, avg_wt =0.0;

    printf("\nEnter the number of processes : ");
    scanf("%d" ,&n);
    for(int i=0 ; i<n ; i++){
        printf("\nEnter Burst time for process %d : " , i+1);
        scanf("%d" , &bt[i]);
        p[i] = i+1;
    }
//sort
int temp = 0; 
for(int i=0 ; i<n-1 ;i++){
    for(int j=i+1 ;j<n ; j++){
        if(bt[i] > bt[j]){
            temp = bt[i];
            bt[i] = bt[j];
            bt[j] = temp;

            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }
    }

}
    wt[0] =0;
    for(int j=1 ; j<n ; j++){
        wt[j] = wt[j-1] + bt[j-1];
    }

    //TAT calculate 
    for(int i=0 ; i<n ; i++){
        tat[i] = wt[i] + bt[i] ;
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    //result
    printf("\nProcess \t Burst Time \t Waiting time  \t Turnaround Time ");
    for(int i=0 ; i<n ; i++){
        printf("\n%d \t\t %d \t\t %d \t\t %d \t" ,p[i], bt[i] , wt[i] , tat[i]);
    }
    printf("\n Avg turn around time is %2f ",avg_tat/n);
    printf("\n Avg  waiting  time is %2f",avg_wt/n);
}