#include <stdio.h>
#include <stdlib.h>

int zigZag(int width, int initOffset, int n){
	n += initOffset;
	int out = n%(width*2);
	if(out > width){
		out = (width*2) - out;
	}
	return out;
}

int main(int argc, char ** argv){
	int i;
	for(i=0;i<50;i++){
		printf("%d\n", zigZag(9, 9, i));
	}
	return 0;
}
