#include "registration.h"
int searchUser(){
	long long int phone;
	phone = phoneVerify();
	int check = userCheck(phone);
	int j = 0,i = 0;
	int k = 0;
	while(i<=999){
     if(pd[i].phNumber==phone) {
      j= i;
      k = 1;
      break;
	 }
      i++;
    }
    if (k == 1){
    system("cls");
    printf("\n\t\t\t\t\t User Found:");
    viewRecord(check,j);
    return j;
//	goto bottom;		
	}else{
		printf("\n\t\t    User Not Found, User isn't registered.");
		return -1;
	}
}

int editUser(){
	int j = searchUser();
	int found = 0;
	char choice[2];
    if (j == -1){
    goto bottom;
	}
	int check = userCheck(pd[j].phNumber);
	char fname[20],lname[20],g[10];
				printf("\n\n\t\t\t       Enter Updated Details:\n\n");	
				printf("\t  First Name: ");
				scanf("%s",fname);
				strcpy(pd[j].first,strupr(fname));
				printf("\t  Last Name: ");
				scanf("%s",lname);
				strcpy(pd[j].last,strupr(lname));
				fflush(stdin);
				printf("\t  Gender: ");
				scanf("%s",g);
				if((strcmp(g,"M")==0)||(strcmp(g,"m")==0)) strcpy(g,"Male");
				if((strcmp(g,"F")==0)||(strcmp(g,"f")==0)) strcpy(g,"Female");
				strcpy(pd[j].gender,strupr(g));
				printf("\t  Age: ");
				scanf("%d",&pd[j].age);

	if(check == 1) {
    printf("\n\t Enter date of 1st dose of vaccination:");
	pd[j].date1 = dateVerify();
	}
	if (check ==2){
	printf("\n\t Enter date of 1st dose of vaccination:");
	pd[j].date1 = dateVerify();
	printf("\n\t Enter date of 2nd dose of vaccination:");
	pd[j].date2 = dateVerify();
	}	
	            printf("\n\n\t\t\t       Record Edited Sucessfully !!!  \n\n");
	FILE *ptr;
	ptr = fopen("details.txt","wb");
    fwrite(pd,sizeof(pd),1,ptr);
	fclose(ptr);
bottom:
printf("\n");
		
}



int deleteUser(){
	int j = searchUser();
	int found = 0;
	char choice[2];
    if (j == -1){
    	goto bottom;
	}
	printf("\n\n\t\t\t       Is this the user you want to delete?");
	rewind:
	printf("\n\t\t\t         Press Y for 'YES' and N for 'NO'---->");
	scanf("%s", choice);
	
	if (strcmp(choice,"y") == 0 || strcmp(choice,"Y") == 0){
	struct patient pd1;
	FILE *ptr,*temp;
	ptr = fopen("details.txt","rb");
    temp = fopen("temp.txt","wb");
	while (fread(&pd1,sizeof(pd1),1,ptr)==1){
		if (pd[j].phNumber == pd1.phNumber){
			printf("\n\n\t\t\t       !!!Record Removed Sucessfully !!!  \n");	
			found ++;
		}else {
			fwrite(&pd1,sizeof(pd1),1,temp);
		}
		
	}
    fclose(ptr);
    fclose(temp);

    if (found == 1){
    remove("details.txt");
	rename("temp.txt", "details.txt");
	ptr = fopen("details.txt","rb");
	fread(pd,sizeof(pd),1,ptr);
	fclose(ptr);
	}
	}
	else if (strcmp(choice,"n")==0 || strcmp(choice,"N") == 0){
			printf("\n\t\t\t       User is not deleted.");
		} else goto rewind;
	
	bottom:
	printf("\n");
}


int updateAdmin(){
    char pass[20],usrname[20];
	int choice;
	top:
	system("cls");
	printf("\n\n\n    ---------------------------------Vaccination Program--------------------------------\n\n");
	printf("                                           Admin Menu   \n\n");
	printf("\t  1>Add New Admin\n\n");
	printf("\t  2>View All Admins\n\n");
	printf("\t  3>Delete Admin\n\n");
	printf("\n\t  Enter Your Choice:");
	scanf("%d",&choice);
	switch (choice){
		case 1:
			addAdmin();
			break;
			
		case 2:
		viewAdmin();
		break;
		
		case 3:
			delAdmin();
			break;
		default:
		    printf("\n\n                           Invalid Choice, Please Enter Again    \n");
		    goto top;
			sleep(1);	
	}//switch
		
	
}	
	
	
	
	
	
	
	

