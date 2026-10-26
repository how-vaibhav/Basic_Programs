#include<stdio.h>
int main(){
	int n,m;
	printf("\nEnter the number of RESOURCES and PROCESSES : ");
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

	


return  0;
}



	
