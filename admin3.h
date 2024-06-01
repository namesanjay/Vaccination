#include "registration.h"

int addAdmin(){
	char usrname[20],pass[20];
				printf("\n\t  Enter username and Password for New Admin:");
			printf("\n\t  Username:");
			scanf("%s",usrname);
			printf("\t  Password:");
			scanf("%s",pass);
			    FILE *adptr;
                FILE *tempptr;
			int found = 0;
			adptr = fopen("adminn.txt","ab+");
			while (fread(&ad,sizeof(ad),1,adptr)==1){
			if ((strcmp(ad.username,usrname)==0)){
				printf("\n\n\t\t\tAdmin with the Same Username Already Exists :(  \n\n");
				found ++;
				
			}
			} //while
			if (found ==1){
				fclose(adptr);
			}
			if (found == 0){
				strcpy(tempAd.username, usrname);
				strcpy(tempAd.password, pass);
				printf("\n\n\t\t\t     New Admin Created.");
				fwrite(&tempAd,sizeof(tempAd),1,adptr);
				fclose(adptr);	
			}
}


int delAdmin(){
	char usrname[20];
	printf("\n\t  Enter username of the Admin:");
			printf("\n\t  Username:");
			scanf("%s",usrname);
			char choice[3];
			int foundd = 0;
			    FILE *ptr;
            ptr = fopen("adminn.txt","rb");
           
            int j = 0;
             while (fread(&ad,sizeof(ad),1,ptr)==1){
            	
            	if (strcmp(ad.username,usrname)==0){
				    j=1;
				}
			}
            fclose(ptr);
                if (j == 0){
				    printf("\n\n\t\t\t\tUser doesn't exist.");
					}
            
                if (j == 1){
                FILE *fptr;
                FILE *tempo;
                printf("\n\n\t\t\t       Do you want to delete this admin?");
                rewind:
					printf("\n\t\t\t         Press Y for 'YES' and N for 'NO'---->");
					scanf("%s", choice);
		        if (strcmp(choice,"y") == 0 || strcmp(choice,"Y") == 0){
	
                fptr = fopen("adminn.txt","rb");	
                tempo = fopen("temp.txt","wb");
            while (fread(&tempAd,sizeof(tempAd),1,fptr)==1){
            	if (strcmp(tempAd.username,usrname)==0){
					printf("\n\n\t\t\t       !!!Admin Removed Sucessfully !!!  \n");
					foundd++;
				}else{
				fwrite(&tempAd,sizeof(struct admin),1,tempo);
				}
				
			}
			
			fclose(fptr);
    		fclose(tempo);
    		
			if (foundd ==1){
				fclose(fptr);
				fclose(tempo);
		    remove("adminn.txt");
			rename("temp.txt", "adminn.txt");
			}
			}
			
			else if ((strcmp(choice,"n")==0) || (strcmp(choice,"N") == 0)){
			printf("\n\t\t\t       Admin User is not deleted.");
		} else goto rewind;
		}			
}


int viewAdmin(){
	FILE *ptr;
	ptr = fopen("adminn.txt","rb");
	int j =1;
		printf("\n\n --------------------------- All Admins -----------------------------\n");
	printf("========================================================================\n");
				 	while (fread(&ad,sizeof(struct admin),1,fp)==1){
			 	printf("\n  %d> %s ",j,ad.username);
				 j++;	
				 }

	fclose(ptr);
	
	
}
