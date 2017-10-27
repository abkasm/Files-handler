#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>



char new_file_name[20];
char file_name[20];
char ch,t[1];
static char *file_containt=t;

void data_info(char *file1,char *file2,char *name,char *new_name,char operation){
	time_t t;
	t=time(NULL);
	FILE *data=fopen("data_base.txt","a");
	
	if(file2!=NULL)
		fprintf(data,"First file : %sSecond file : %s \nOperation : %c  \n",file1,file2,operation);
	if(name!=NULL)
		fprintf(data,"File : %s\nName to search : %s \nOperation : %c  \n",file1,name,operation);
	if(new_name != NULL)
		fprintf(data,"File : %s\nNew name : %s \nOperation : %c  \n",file1,new_name,operation);
	else
		fprintf(data,"File : %s \nOperation : %c \n",file1,operation);

		fprintf(data," In  %s ",asctime(localtime(&t)));
		fprintf(data,"\n-----------------------------");
		fclose(data);
}
	
int main(int argc,char **argv){


	
		

char chois;
puts("\n              ******* Welcom to our open source software ******* ");
puts("                            By Meduino_Geek_AbKasm \n");
options_table:
	puts("\n|Options -------------------------------------> Key Press\n");
	puts("|Read the containt of the file -----------------> 'r' or 'R'");
	puts("|Copy a file to another 'append' or 'replace'---> 'p' or 'P'");
	puts("|Write to the file -----------------------------> 'w' or 'W'");
	puts("|Search a name in a file -----------------------> 's' or 'S'");
	puts("|Modify a file name ----------------------------> 'm' or 'M'");
	puts("|Modify a contain of a file --------------------> 'c' or 'C'");
	puts("|Delete a file ---------------------------------> 'd' or 'D'");
	puts("|Create new file -------------------------------> 'a' or 'A'");
	puts("|Show text files in current directory ----------> 'h' or 'H'");
	puts("|Show all files in current directory -----------> 'e' or 'E'");
	puts("|Read the table containt -----------------------> 't' or 'T'");
	puts("|Save data in a file ---------------------------> 'i' or 'I'");
	puts("|Desplay options table -------------------------> 'o' or 'O'");
	puts("|Clear the screen ------------------------------> 'l' or 'L'");
	puts("|Quit ------------------------------------------> 'q' or 'Q'");
-
	puts("    \nRemark :  Don't use the '@' character in the file, instead you can use '^' character \n ");

int i=0;
char choise;

while(1){
	
	printf("\n Put your option choise : ");
	scanf(" %c",&chois);
	puts(" ");
	fflush(stdin);
	switch(chois){
		case 'A'  :
		case 'a'  :{
			
			printf(" Give the file name with its extention : ");
			scanf("%s",file_name);
			FILE *file=fopen(file_name,"w");
			if(file ==NULL){
				puts("Can't create the file in current directory ");
				break;
				}
			fclose(file);
			data_info(file_name,NULL,NULL,NULL,chois);
			break;
			}
		case 'R' :
		case 'r' :{
			printf(" Give the file name with its extention : ");
			scanf("%s",file_name);
			FILE *file=fopen(file_name,"r");
			if(file ==NULL){
				puts("Can't find the file in current directory ");
				break;
				}
			while((ch=fgetc(file))!=EOF){
				putchar(ch);
				file_containt[i]=ch;
				i++;
				}
			data_info(file_name,NULL,NULL,NULL,chois);
					break;	
		}
		case 's' :
		case 'S' :{
			char name[20];
			char word[20];
			int number_of_names=0;
			printf(" Give the file name with its extention : ");
			scanf("%s",file_name);
			FILE *file=fopen(file_name,"r");
			if(file==NULL){
				puts(" Can't open this file / Can't find this file ");
				break;
				}
			printf(" Give the name to search : ");
			scanf("%s",name);
			
			
			while(!feof(file)){
				fscanf(file,"%s",word);
				if(strcmp(word,name)==0)
					number_of_names++;
			}
			if(number_of_names)
					printf(" \n\n there is %d of '%s' in the file '%s'\n ",number_of_names,name,file_name);
			else
					printf(" no '%s' in the file '%s' \n",name,file_name);

			data_info(file_name,NULL,name,NULL,chois);
			break;
			}
		case 'i' :
		case 'I' :{
			printf(" Give the file name with its extention : ");
			scanf("%s",file_name);
			FILE *file=fopen(file_name,"w");
			if(file ==NULL){
			puts("Can't create this file ");
			break;
			}
			puts(" Write....[@ Enter] to stop writing\n");
	
			while((ch=fgetc(stdin))!=EOF){
				if(ch=='@'){
					fclose(file);
					break;
				}
				if(ch=='^')
					fputc('@',file);
					
				else
					fputc(ch,file);
		
		}
			data_info(file_name,NULL,NULL,NULL,chois);
			break;
			}
		case 'W' :
		case 'w' :{
			char choise;
			printf(" Give the file name with its extention : ");
			scanf("%s",file_name);
			FILE *file_read=fopen(file_name,"r");
			if(file_read ==NULL){
				puts("Can't find this file in current directory ");
				break;
				}
			FILE *file=fopen(file_name,"a");
			printf(" rewrite all the containt of the file with 'r' or appand the file with 'a' : ");
			
			
			scanf(" %c",&choise);
			puts(" write .... [@ Enter] to stop writing "); 
			switch(choise){
			case 'A' : 
			case 'a' :{
				while((ch=fgetc(stdin))!=EOF){
					if(ch=='@'){
						fclose(file);
						break;
					}
					if(ch=='^')
						fputc('@',file);
					else
						fputc(ch,file);
					
					}
				
				break;
				}
			case 'R' :
			case 'r' :{
				FILE *file=fopen(file_name,"w");
				while((ch=fgetc(stdin))!=EOF){
					if(ch=='@'){
						fclose(file);
						break;
					}
					if(ch=='^')
						fputc('@',file);
					else
						fputc(ch,file);
					
				}
			break;
			}
			default :{
				printf(" Invalide option %c \n",choise);
				break;
				}
			}
			data_info(file_name,NULL,NULL,NULL,chois);
			break;
			}
		case 'm' :
		case 'M' :{
			printf(" Give the file name with its extention : ");
			scanf("%s",file_name);
			printf(" Give the new file name with its extention : ");
			scanf("%s",new_file_name);
			FILE *file=fopen(file_name,"r");
			FILE *new_file=fopen(new_file_name,"w");
			if(file == NULL){
				puts("Can't modify the file name of this file ");
				break;
				}

			rename(file_name,new_file_name);
			data_info(file_name,NULL,NULL,new_file_name,chois);
			break;
			}
		case 'c' :
		case 'C' :{
			printf(" Give the file name with its extention : ");
			scanf("%s",file_name);
			remove(file_name);
			FILE *file=fopen(file_name,"w");
			if(file ==NULL){
				puts("Can't modify the containt of this file ");
				break;
				}
			puts("Write.....\n");
			puts(" '@ Enter' to stop writing ");
	
			while((ch=fgetc(stdin))!=EOF){
				if(ch=='@'){
					fclose(file);
					break;
				}
				if(ch=='^')
					fputc('@',file);
				else
					fputc(ch,file);
		
				}
			data_info(file_name,NULL,NULL,NULL,chois);
			break;
			}
		case 'd' :
		case 'D' :{
			printf(" Give the file name with its extention : ");
			scanf("%s",file_name);
			remove(file_name);
			data_info(file_name,NULL,NULL,NULL,chois);
			break;
			}

		case 'H' :
		case 'h' :{
			system("dir *.txt ");
			break;
			}
		case 'E' :
		case 'e' :{
			system("dir ");
			break;
			}
		case 'q' :
		case 'Q' :{
				puts(" *** Thank you for using our open source sofware ");
				puts("                      MOhaméd ABkasm ***\n\n");
				exit(2);
				}
		case 'p' :
		case 'P' :{
				printf(" Give the first file name with its extention : ");
				scanf("%s",file_name);
				printf(" Give the second file name with its extention : ");
				scanf("%s",new_file_name);
				puts(" Append the second file 'a' or 'A' replace the containt 'r' or 'R' : ");
				scanf(" %c",&choise);
				FILE *file=fopen(file_name,"r");
				FILE *file2=fopen(new_file_name,"r");
					if(file==NULL){
						printf("Can't find the %s file \n",file_name);
						break;
							}
					else if(file2==NULL){
						printf("Can't find the %s file \n",new_file_name);
						break;
						}
				switch(choise){
					case 'a' :
					case 'A' :{
						FILE *file2=fopen(new_file_name,"a");
						while((ch=fgetc(file))!=EOF){
							fputc(ch,file2);
								}
						fclose(file);
						fclose(file2);
						break;
					}
					case 'r' :
					case 'R' :{
						FILE *file2=fopen(new_file_name,"w");
						while((ch=fgetc(file))!=EOF){
							fputc(ch,file2);
								}
						fclose(file);
						fclose(file2);
						break;
							}
						
					default :{
						printf("Invalide option %c \n ",choise);
						break;
							}
				}
					
				data_info(file_name,new_file_name,NULL,NULL,chois);
				break;
				}
					
		case 't' :
		case 'T' :{	
				puts(" string containt : ");
				puts(file_containt);	
				break;
			}
		case 'o' :
		case 'O' :{
			goto options_table;
			break;
		}
		case 'l' :
		case 'L' :{
			system("clear || cls ");
			break;
			}
	

		default : {
			printf(" Invalide option   %c \n ",chois);
			goto options_table;
		}
	}
}






return 0;
}
