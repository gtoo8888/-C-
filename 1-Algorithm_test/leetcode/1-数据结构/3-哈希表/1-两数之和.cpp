#include<iostream>
#include<malloc.h>
using namespace std;

int* twoSum(int* nums, int numsSize, int target,int* returnSize){
	int  a,b;	
	int* result = NULL; 	
	*returnSize = 2;	
	for(int i = 0;i < numsSize;i++)
		for(int j = i+1;j < numsSize;j++)	
		{
			if((*(nums + i) + *(nums + j)) == target)
			{
                result = (int*)malloc(sizeof(int)*2);
				result[0] = i;
				result[1] = j;
                return result;
			}
		}
    return result;
}


int main() 
{
	int nums[] = {2,7,11,15};
	int numsSize;
	int target = 9;
	int returnSize[100] = {0};

	int *pa = NULL;

	numsSize = sizeof(nums)/sizeof(int);
	
	pa = twoSum(nums,numsSize,target,returnSize);
	
	for(int i = 0;i < 2;i++)
		printf("%d ",*(pa + i) );

	return 0;
}

