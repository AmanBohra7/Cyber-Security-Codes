#include<stdio.h>
#include<string.h>

void RailEncrypt(char msg[],int key,int len){
	char matrix[key][len];
	memset(matrix,'_',sizeof(char)*key*len);

	int i , j , direction = -1; // -1 = down || 1 = up
	int row = 0 , col = 0 , ind = 0;
	while(col<len){
		// printf("row : %d col: %d\n ",row,col);
		if(row == key-1 || row == 0)  direction = - direction ;
		matrix[row][col] =  msg[ind];
		if(direction == -1) row -= 1;
		else row += 1;
		col += 1;
		ind += 1;
	}

	// printing matrix
	for(i = 0 ; i < key ; ++i){
		for(j = 0 ; j < len ; ++j){
			printf("%c ",matrix[i][j]);
		}
		printf("\n");
	}

	//printing decrypt data
	for(i = 0 ; i < key ; ++i){
		for(j = 0 ; j < len ; ++j){
			if(matrix[i][j] != '_') printf("%c",matrix[i][j]);
		}
	}
}


void RailDecrypt(char msg[],int key,int len){
	char matrix[key][len];
	memset(matrix,'_',sizeof(char)*key*len);

	// marking places with '*'
	int i , j , direction = -1; // -1 = down || 1 = up
	int row = 0 , col = 0 , ind = 0;
	while(col<len){
		// printf("row : %d col: %d\n ",row,col);
		if(row == key-1 || row == 0)  direction = - direction ;
		matrix[row][col] =  '*';
		if(direction == -1) row -= 1;
		else row += 1;
		col += 1;
		ind += 1;
	}

	ind = 0;
	for(i = 0 ; i < key ; ++i){
		for(j = 0 ; j < len ; ++j){
			if(matrix[i][j] == '*'){
				matrix[i][j] = msg[ind];
				++ind;
			} 
		}
	}

	// printing matrix
	for(i = 0 ; i < key ; ++i){
		for(j = 0 ; j < len ; ++j){
			printf("%c ",matrix[i][j]);
		}
		printf("\n");
	}

	//printing decrypt data
	

}

void main(){
	char message[] = "GeeksforGeeks";
	char cipher[] = "GosefrkesGeke";
	int key = 3;
	int len = sizeof(message) / sizeof(message[0]);
	RailEncrypt(message,key,len-1);
	printf("\n\n\n");
	RailDecrypt(cipher,key,len-1);
}
