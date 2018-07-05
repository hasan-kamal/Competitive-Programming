#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// #define T_MAX 100000
// #define K_MAX 100000
// #define C_MAX 100000

#define T_MAX 100000
#define N_MAX (1000000000-1)

int isValid(int n){
	while(n){
		if(n%10==3)
			return 0;

		n/=10;
	}
	return 1;
}

int main(int argc, char *argv[]){
	
	if(argc!=2){
		printf("Please enter the path of the file to be created\n");
		return 0;
	}

	FILE *file;
	file = fopen(argv[1], "w");

	srand(time(NULL));

	// int i;
	// int t = 1 + rand()%T_MAX;
	// fprintf(file, "%d\n", t);
	// int k, c;
	// for(i=0; i<t; i++){
	// 	k = 1 + rand()%K_MAX;
	// 	c = 1 + rand()%C_MAX;
	// 	fprintf(file, "%d %d\n", k, c);
	// }

	int i;
	int t = 1 + rand()%T_MAX;
	fprintf(file, "%d\n", t);

	int n;
	for(i=0; i<t; i++){
		n = 1 + rand()%N_MAX;
		while(!isValid(n))
			n = 1 + rand()%N_MAX;
		fprintf(file, "%d\n", n);
	}

	fclose(file);
	return 0;
}