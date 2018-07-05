#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define T_MAX 100
#define N_MAX 10000
#define A_MAX 1000000000

int main(int argc, char *argv[]){
	
	if(argc!=2){
		printf("Please enter the path of the file to be created\n");
		return 0;
	}

	FILE *file;
	file = fopen(argv[1], "w");

	srand(time(NULL));

	int i;
	int t = 1 + rand()%T_MAX;
	fprintf(file, "%d\n", t);
	int n, j, temp;
	for(i=0; i<t; i++){
		
		//k = 1 + rand()%K_MAX;
		//c = 1 + rand()%C_MAX;
		n = 1 + rand()%N_MAX;
		fprintf(file, "%d\n", n);
		for(j=0; j<n; j++){
			temp = 1 + rand()%A_MAX;
			fprintf(file, "%d ", temp);
		}
		fprintf(file, "\n");
		//fprintf(file, "%d\n", n);
	}

	fclose(file);
	return 0;
}