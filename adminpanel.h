#include "registration.h"

int adminPanel(){
	
	char pass[20],usrname[20];
	login:
		
	system("cls");
		printf("\n\n\n    ---------------------------------Vaccination Program--------------------------------\n\n");
	printf("                                           Admin Menu   \n");
	printf("                                        -----------------  \n\n\n\n");
	fflush(stdin);
	printf("\t  Enter Username:");
	scanf("%s",usrname);
	printf("\t  Enter password:");
//	
	{
					
	int i=0;
	char ch,passk[20];
//	printf("Enter Password:");
	while(1)
	{
		
		ch=getch();
		if(ch==13)
		break;
		else if(ch==8)
		{
			if(i>0)
			{
				i--;
				passk[i]='\0';
				printf("\b \b");
			}
		}
		else
		{
			passk[i]=ch; 
			putch('*');
			i++;
		}
	}
	passk[i]='\0';
	strcpy(pass,passk);

			}
			
//		printf("%s %s",ad.username,ad.password);
//			getch();
        FILE *adptr;
        adptr = fopen("adminn.txt","rb");
		while (fread(&ad,sizeof(ad),1,adptr)==1){
		if ((strcmp(ad.username,usrname)==0) && (strcmp(ad.password,pass)==0)){
		
			printf("\n\n            Login Successfull  \n\n");
			sleep(1);
			fclose(adptr);
			goto topp;
		}	
	}
	fclose(adptr);
	
			printf("\n\n\t\t\tInvalid Username/Password, Please Try Again.");
		sleep(1);
         goto login;
	
	topp:
	system("cls");
	printf("\n\n\n    ---------------------------------Vaccination Program--------------------------------\n\n");
	printf("                                           Admin Menu   \n");
	printf("                                        -----------------  \n\n\n\n");
	printf("\t  1>Search User Records\n\n");
	printf("\t  2>Edit User Records\n\n");
	printf("\t  3>Delete User Records\n\n");
	printf("\t  4>Update Vaccine Stocks\n\n");
	printf("\t  5>Update Admin\n\n");
	printf("\t  6>Goto MainMenu\n\n");
	int choice;
	printf("\n\t  Enter Your Choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1:
		searchUser();
		printf("\n\n\n\t\t\tPress Any Key to go to Admin Menu");
	    getch();
		goto topp;
		
		case 2:
		editUser();
		printf("\n\n\n\t\t\tPress Any Key to go to Admin Menu");
	    getch();
		goto topp;
		
		case 3:
		 deleteUser();
		printf("\n\n\n\t\t\tPress Any Key to go to Admin Menu");
		getch();
		goto topp;
		
		 case 4:
		 	vacAdd();
		printf("\n\n\n\t\t\tPress Any Key to go to Admin Menu");
	    getch();
		goto topp;
		
		 case 5:
		 	updateAdmin();
		printf("\n\n\n\t\t\tPress Any Key to go to Admin Menu");
	    getch();
		goto topp;
		
		case 6:
		break;
			
		default:
			printf("\n                           Invalid Choice, Please Enter Again    \n");
			sleep(1);
//			getch();
			goto topp;
	}
	bot:
	printf("");
	
}




int vacAdd(){
	FILE *fptrr;
    fptrr = fopen("vaccine.txt","rb");
    fread(&vac,sizeof(vac),1,fptrr);
    fclose(fptrr);
	vaccineAdd:
		system("cls");
 printf("\n\n\t  Update Vaccine Stock:");
 printf("\n\t  1>Verocell");
 printf("\n\t  2>Astrogenica");
 printf("\n\t  Enter Your Choice:");
 
 int choice;
 int verocell,astrogenica;
 scanf("%d",&choice);
 if (choice == 1){
 	printf("\n\t  Enter the number of Verocell Vaccines Arrived:");
 	scanf("%d",&verocell);
 	printf("\n\t    Vaccines updated successfully!!         ");
 	vac.verocellCount +=verocell;
 	printf("\n\t    Verocell Vials Count = %d",vac.verocellCount);
 	printf("\n\t    Astrogenica Vials Count = %d",vac.astrogenicaCount);
 }
 else if (choice == 2){
  	printf("\n\t  Enter the number of Astrogenica Vaccines Arrived:");
 	scanf("%d",&astrogenica);
 	printf("Vaccines updated successfully!");
 	vac.astrogenicaCount +=astrogenica;
 	printf("\n\t    Verocell Vials Remaining = %d",vac.verocellCount);
 	printf("\n\t    Astrogenica Vials Remaining = %d",vac.astrogenicaCount);	
 	
 }
 else{
 printf("\n\n\t\t\t Please Enter The Correct Option.");
 sleep(1);
 goto vaccineAdd;
 }
 fptrr = fopen("vaccine.txt","wb");
    fwrite(&vac,sizeof(vac),1,fptrr);
    fclose(fptrr);	
}
