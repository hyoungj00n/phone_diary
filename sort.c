//정렬 함수
#include "diary.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void mysort(char *arr[LEN], int left, int right){

	int step, i;
	char temp_arr[LEN];
	
	for(step =0; step< right -1; step++){
		for(i=0; i<(right-1) - step; i++){
			if(strcmp(arr[i],arr[i+1]) > 0){//문자열 비교
				//문자열 교체
				strcpy(temp_arr, arr[i]);
				strcpy(arr[i], arr[i+1]);
				strcpy(arr[i+1],temp_arr);
			}
		}
	}
}