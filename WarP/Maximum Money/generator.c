#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define T_MAX 100
#define N_MAX 1000
#define M_MAX 100
#define A_MAX 1000

typedef struct{
	int u, v;
} edge;

int containsEdge(edge *edges, int low, int high, edge tempEdge){
	for(int i=low; i<=high; i++){
		if(edges[i].u==tempEdge.u && edges[i].v==tempEdge.v)
			return 1;
	}
	return 0;
}

edge generateDistinctEdge(edge *edges, int i, int n){
	int u, v;
	edge tempEdge;

	do{
		u = 1 + rand()%n;

		v = 1 + rand()%n;
		while(v==u)
			v = 1 + rand()%n;

		if(u>v){
			int temp = u;
			u = v;
			v = temp;
		}

		tempEdge.u = u;
		tempEdge.v = v;
	}while(containsEdge(edges, 0, i-1, tempEdge));

	return tempEdge;
}

int main(int argc, char *argv[]){
	
	if(argc!=2){
		printf("Please enter the path of the file to be created\n");
		return 0;
	}

	FILE *file;
	file = fopen(argv[1], "w");

	edge edges[M_MAX+1];
	edge tempEdge;

	srand(time(NULL));

	int i;
	int t = 1 + rand()%T_MAX;
	fprintf(file, "%d\n", t);
	int n, m, j, temp;

	int u, v;
	for(i=0; i<t; i++){
		n = 1 + rand()%N_MAX;
		m = 1 + rand()%M_MAX;
		fprintf(file, "%d %d\n", n, m);

		for(j=0; j<n; j++){
			temp = 1 + rand()%A_MAX;
			fprintf(file, "%d ", temp);
		}
		fprintf(file, "\n");

		for(j=0; j<m; j++){
			tempEdge = generateDistinctEdge(edges, j, n);
			edges[j] = tempEdge;
			fprintf(file, "%d %d\n", tempEdge.u, tempEdge.v);
		}
	}

	fclose(file);
	return 0;
}