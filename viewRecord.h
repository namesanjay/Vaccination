#include "registration.h"
int viewRecord(int check, int j){
	printf("\n\n -------------------------------------- Your Details ----------------------------------------\n");
	printf("==============================================================================================\n");
	printf("\n\tPhone Number: %lld",pd[j].phNumber);
	printf("\n\tName: %s %s",strupr(pd[j].first),strupr(pd[j].last));
	printf("\n\tAge: %d",pd[j].age);
	printf("\n\tGender: %s",pd[j].gender);
	
	if(check == 0){
	printf("\n\tNumber of doses taken: %d",check);	
	}
	
	if(check == 1) {
	printf("\n\tName of Vaccine: %s",pd[j].vaccineName);
	printf("\n\tNumber of doses taken: %d",check);
	printf("\n\t1st date of vaccination: %d /%d /%d",pd[j].date1.year,pd[j].date1.month,pd[j].date1.day);
	
	//printf("\n2nd date of vaccination: %d /%d /%d",pd[j].date2.year,pd[j].date2.month,pd[j].date2.day);
	}
	if (check ==2){
	printf("\n\tName of Vaccine: %s",pd[j].vaccineName);
	printf("\n\t1st date of vaccination: %d /%d /%d",pd[j].date1.year,pd[j].date1.month,pd[j].date1.day);
	printf("\n\t2nd date of vaccination: %d /%d /%d",pd[j].date2.year,pd[j].date2.month,pd[j].date2.day);
	}	
}

int changePass(){
	long long int phone;
//	printf("\n\tPlease Enter Your Phone Number:");
    phone = phoneVerify();
        char oldpass[20];
		char temppass[20];
		char temppass2[20];
		int a =0;	
		int b = 0;	
		int c = 0;
		while(a <=999){
        if(pd[a].phNumber==phone) {
         b = a;
         c = 1;
         break;
		}
        a++;
    	}
    if (c ==1){
       	correctpass:
		printf("\n\tOld Password:");
		scanf("%s",oldpass);
		if(strcmp(oldpass,pd[b].password)==0) { 
		printf("\tNew Password:");
		scanf("%s",temppass);
		confirm:
		printf("\tConfirm New Password:");
		scanf("%s",temppass2);
		if(strcmp(temppass,temppass2)==0)
		{
			printf("\n\n\t            Password Changed Successfully, Press Any Key to go to Main Menu.");
			strcpy(pd[b].password,temppass);
			getch();
		}
		else 
		{
			printf("\n\tError!,Please Enter Same Password:\n");
			goto confirm;
		}
		}else {
		printf("\n\tPlease Enter Corrct Old Password");
		goto correctpass;	
		}		
	}else{
		printf("\n\n\t\t\t\tUser doesn't exist. Press any key to go to Main Menu.");
		getch();
	}

}



	
