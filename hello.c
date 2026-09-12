#include <stdio.h>
#include <stdlib.h>

int in(int target, int* arr, int len);

int main(){
	int N;
	scanf("%d",&N);
	int singer[N];
	//max frequency calculating algorithm
	for(int i=0; i<N; i++){
		scanf("%d\n",&singer[i]);
	}
	int max=0;
	for(int i=0;i<N;i++){
		int count=0;
		for(int j=0; j<N; j++){
			if(singer[i]==singer[j]){
				count++;
			}
		}
		if(count>max){
			max=count;
		}
	}
	int *sang,*sangnum;
	sang=(int*)calloc(N,sizeof(int));
	sangnum=(int*)calloc(N,sizeof(int));
	int k=0;
	for(int i=0; i<N; i++){
		int temp=singer[i];
		int count=0;
		if(in(temp,sang,k)){
			continue;
		}
		for(int j=0;j<N;j++){
			if(temp==singer[j]){
				count++;
			}
		}
		if(count>0){
			sang[k]=temp;
			sangnum[k]=count;
			k++;
		}
	}
	
	int county=0;
	for(int i=0;i<k;i++){
		if(sangnum[i]==max){
			county++;
		}
	}
	printf("%d\n", county);
	free(sang);
	free(sangnum);
	return 0;
}
int in(int target, int* arr, int len) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] == target) {
            return 1;
        }
    }
    return 0;
}   
