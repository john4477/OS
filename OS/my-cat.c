#include<stdio.h>
#include<stdlib.h>

#define LINE_SIZE 100

int main(int argc, char *argv[]){
	int i;
	FILE *fp[argc-1];
	char buffer[LINE_SIZE];// temp reading file
	
	if(argc==1){
		printf("my-cat : cannot open file\n");
		exit(1);
	}
	for(i=1;i<argc;i++){
		fp[i]=fopen(argv[i],"r");
		
		if(fp[i]==NULL){
			printf("my-cat : cannot open file\n");
		exit(1);
		}
		while(1){
			fgets(buffer,sizeof(buffer),fp[i]);
			if(!feof(fp[i]))
				printf("%s",buffer);
			else break;
		}
		fclose(fp[i]); // close
	}
	return 0;
}
