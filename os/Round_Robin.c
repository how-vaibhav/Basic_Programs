#include<stdio.h>

int main(){
    int n;
    printf("\nNumber of processes : ");
    scanf("%d" ,&n);
	int bt[n] ,at[n] ,p[n] ,tc ;
	int rem[n] ,tat[n] , ct[n] ,wt[n];
	printf("\nEnter Arival Time & Burst Time: \n");
  for(int i=0 ;i<n ;i++){
	p[i]=i+1;
	printf("\tp%d:", i+1);
	scanf("%d %d",&at[i] , &bt[i]);
}
	printf("Enter the time quantum :");
	scanf("%d",&tc);
//first arrival Time to execute
	int time=at[0];
	for(int i=0 ; i<n ;i++){
	if(at[i]<time)
	 time =at[i];

}

//Calculation
int completed =0;
while(completed <n){
int executed=0;
  for(int i=0 ; i<n;i++){
	if(at[i] <= time && rem[i] >0){
		executed = 1;

		if(tc >= rem[i]){
			time += rem[i];
			rem[i] = 0;
			completed++;
			ct[i]=time;
		 }else{
			time +=tc;
			rem[i]-=tc;
			}
		}
	if(!executed) time++;
	}
}
 float avg_ct=0 , avg_tat=0;
 for(int i=0 ;i<n ;i++){

	tat[i] =ct[i]-at[i];
	wt[i] =tat[i] -bt[i];
	avg_ct +=ct[i];
	avg_tat+=tat[i];
	}
//Display
printf("\n\nPROCESS\t\tARRIVAL\tBURST\tTURNAROUND\tWAITING\tCOMPLETION\n");
for(int i=0 ;i<n ; i++){
	printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n" ,i+1 ,at[i] ,bt[i] ,tat[i] ,wt[i] ,ct[i]);
}
printf("\n");

printf("\nAverage Completion time : %f\n" ,avg_ct/n);
printf("\nAverage TurnAround time : %f\n" ,avg_tat/n);
return 0;
}
