#include<stdio.h>
int main(){
	int n,m;
	printf("\nEnter the number of PROCESSES and RESOURCES : ");
	scanf("%d %d",&n ,&m);

	int allo[n][m] , max[n][m] , need[n][m];
	int work[m] , avail[m];

	printf("\nEnter the ALLOCATION:\n");
	for(int i=0 ; i<n ;i++){
		printf("P%d: ",i);
		for(int j=0 ;j<m ;j++){
			scanf("%d" ,&allo[i][j]);
			}
	}


	printf("\nEnter the MAXIMUM:\n");
	for(int i=0 ; i<n ;i++){
		printf("P%d: ",i);
		for(int j=0 ;j<m ;j++){
			scanf("%d" ,&max[i][j]);
			}
	}


	printf("\nEnter the AVAILABLE:\n");
	for(int i=0 ; i<m;i++){
		scanf("%d" ,&avail[i]);
		work[i] = avail[i];
	}
	
	printf("\nNEED matrix:\n");
	for(int i=0 ; i<n ; i++){
		printf("p%d: " ,i);
		for(int j=0 ; j<m ; j++){
		  need[i][j]=max[i][j] - allo[i][j];
		  printf("%d ",need[i][j]);
		}
		printf("\n");
	}

int count=0 ,safe[n] ;
int finish[n];
for(int i=0 ; i<n ; i++) 
	finish[i] =0; // beacuse C does not alows variable length array to be initialized with 0 directly


while(count<n){
	int found =0;
	for(int i=0 ; i<n ;i++){
		int possible =1;
		if(finish[i] == 0){
			for(int j=0 ;j<m ; j++){
				if(work[j] <need[i][j]){
					possible =0;
					break;
				}
			}
			if(possible){
				for(int j=0 ; j<m ; j++)
					work[j] += allo[i][j];
				finish[i]=1;
				safe[count]=i;
				count++;
				found=1;
			}
		}
	}
if(!found) break; // deadlock is there
}


//deadlock check
if(count == n){
	printf("\n NO deadlock  \n Safe Sequence :\n");
	for(int i=0 ;i<n ;i++){
		printf("P%d ",safe[i]);
		if(count != i+1) printf("->");
	}
}else
	printf("\nDeadlock has occured!!!!\n");
return  0;
}
	
