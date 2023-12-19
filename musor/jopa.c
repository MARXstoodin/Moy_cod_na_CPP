#include <stdio.h>
int main(){
	int* a = malloc(10);
	while(1){
		a = realloc(a, 10*sizeof(a));
	}
}
