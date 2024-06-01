#ifndef REGISTRATION.H
#define REGISTRATION.H
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <ctype.h>
struct date {
	int year;
	int month;
	int day;
};

//structure for patient details
struct patient{
	long long int phNumber;
	char gender[10],first[20],last[20];
    int age;
    char password[20];
    char vaccineName[15];  //type of vaccine used;
    int doses;
    struct date date1;
    struct date date2;
};

struct vaccine{
int totalUserCount,verocellCount,astrogenicaCount;
};

struct admin{
	char username[20];
	char password[20];
}ad;

struct admin tempAd;
struct vaccine vac;
struct patient pd[1001]; //patient details upto 10
struct patient temp;
struct date tempDate;

FILE *fp;
int datafetch();
int defaultUser();
int userCheck(long long int ps);
int vaccinationPage();
int passwordVerify(char j[20]);
struct date dateVerify();
int changePass();
int vaccinationTime();
int viewRecord(int check,int j);
long long int phoneVerify();
int adminPanel();
int vacAdd();
int searchUser();
int deleteUser();
int editUser();
int updateAdmin();
int dateDiff(struct date tempDate, int j);
int viewAdmin();
int addAdmin();
int delAdmin();
int registration(int _age){
	fflush(stdin);
	 int i = 0;
		while(i<=999){
			if(pd[i].phNumber==0){
				system("cls");
				printf("\n\n\n    ---------------------------------Registration Page--------------------------------\n\n\n");
				pd[i].phNumber = temp.phNumber;
				pd[i].age = _age;
				char fname[20],lname[20],g[10];
//				printf("Registration Page::\n");
				printf("\t  Enter Following Details:\n\n");
				printf("\t  Phone Number: %lld\n", pd[i].phNumber );
				printf("\t  Age: %d\n",pd[i].age);	
				printf("\t  First Name: ");
				scanf("%s",fname);
				strcpy(pd[i].first,strupr(fname));
				printf("\t  Last Name: ");
				scanf("%s",lname);
				strcpy(pd[i].last,strupr(lname));
				fflush(stdin);
				printf("\t  Password: ");
				scanf("%s",&pd[i].password);
				printf("\t  Gender: ");
				scanf("%s",g);
				if((strcmp(g,"M")==0)||(strcmp(g,"m")==0)) strcpy(g,"Male");
				if((strcmp(g,"F")==0)||(strcmp(g,"f")==0)) strcpy(g,"Female");
				strcpy(pd[i].gender,strupr(g));
			printf("\n\n\t  Your Login Details:");
			printf("\n\t  Phone Number: %lld",pd[i].phNumber);
			printf("\n\t  Password: %s",&pd[i].password);
			strcpy(pd[i].vaccineName,"");
			pd[i].doses=0;
			pd[i].date1.year=0;
			pd[i].date1.month=0;
			pd[i].date1.day=0;
			pd[i].date2.year=0;
			pd[i].date2.month=0;
			pd[i].date2.day=0;
			getch();
			
		FILE *ptr;
		ptr = fopen("details.txt", "wb+");
		fwrite(pd, sizeof(pd), 1, ptr);
		fclose(ptr);
			break;
			}			
			i++;
		}
}
#endif	
