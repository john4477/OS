#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define False 0
#define MAX 100
int main(int argc, char *argv[]){


	FILE *fp;
	char buffer[MAX];
	if(argc==2){
		fp=stdin;
		goto next;
	}
	if(argc==1||argc>3){
		printf("my-grep: searchterm[file...]");
		exit(1);
	}
	
	
	fp=fopen(argv[2],"r");
	
	
	if(fp==NULL){
		printf("my-grep: cannot open file");
		exit(1);
	}	
	next:
	while(1){
		fgets(buffer,sizeof(buffer),fp);
		if(argv[1]==NULL){
			printf("%s",buffer);
			exit(0);
		}
		else if(!feof(fp)){
				if(strstr(buffer,argv[1])!=False)
					printf("%s",buffer);
			}else break;
	}
	fclose(fp);

	return 0;
}

