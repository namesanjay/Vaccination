#include "registration.h" 
#include "userCheck.h" 
#include "verification.h"
#include "viewRecord.h"
#include "adminpanel.h"
#include "admin2.h"
#include "admin3.h"
int main(){
	{	
int i,j;
printf("\n\n\n\n\n\n\t\t\t");
char d[20]="Vaccination Program";
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
for(j=0;j<20;j++)
{
Sleep(55);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(60);
printf("*");
}
}
		fp = fopen("details.txt","rb");
	fread(&pd,sizeof(pd),1,fp);
	fclose(fp);
system("cls");
int option;
mainPage:
	fp = fopen("details.txt","wb");
	fwrite(pd,sizeof(pd),1,fp); 		
 	fclose(fp);
system("cls");	
printf("\n\n\n    ---------------------------------Vaccination Program--------------------------------\n\n");
	printf("                                          Main Menu    \n");
	printf("                                        -------------  \n\n\n\n");
 printf("\t  1.Vaccination\n\n");
 printf("\t  2.Change Your Password\n\n");
 printf("\t  3.Admin Panel\n\n");
 printf("\t  4.Exit Program\n\n");
 printf("\t  Enter Your Choice:");
 scanf("%d",&option);
 if (option !=1 && option != 2 && option != 3 && option != 4)
 {
 	printf("\n                           Invalid Choice, Please Enter Again    \n");
 	
 	 sleep(1);
system("cls");
goto mainPage;
	
}

switch(option)
 {
 	case 1:
 		vaccinationPage();
 		break;
 		
 	case 2:
 		system("cls");
	    changePass();
	    break;
 	case 3:
 		system("cls");
 		adminPanel();
 		break;
 	
 	case 4:
 		fp = fopen("details.txt","wb");
 		fwrite(pd,sizeof(pd),1,fp); 		
 		fclose(fp);
 		exit(0);
 		
 }	
goto mainPage;
 }
 
int vaccinationPage(){
		long long int phone;
	int check;
		frontPage:
			system("cls");
		 printf("\n\n\n    ---------------------------------Vaccination Program--------------------------------\n\n\n");
		phone = phoneVerify();
		check = userCheck(phone);
		int i = 0;
		int j = 0;
		int k = 0;
		 while(i<=999){
        if(pd[i].phNumber==phone) {
        	j= i;
		}
        i++;
    	}
    
    
		if (check == -99){  //new user detected
		printf("\n\tEnter Your Age:");
		int _age;
		scanf("%d",&_age);
		if (_age <18){
			printf("\n\n\t\t\t\tYou are not eligible for the vaccination.");
			printf("\n\n\t\t\t\tPress any key to go to Main Menu");
			getch();
			goto bottom;
			
			}
		else{
		registration(_age);
		goto frontPage;
		}
		
		}
	 
		verification:
		printf("\n\tPlease Enter Your Correct Password to Verify: \n\tPassword:");
		fflush(stdin);
		if(passwordVerify(pd[j].password)==1) {
		system("cls");
		printf("\n\n\n    ---------------------------------Vaccination Program--------------------------------\n\n\n");
		viewRecord(check,j);
		printf("\n");
		vaccinationTime(check,j);
		}else {
		goto verification;
	}
	bottom:
		printf("");
		}
