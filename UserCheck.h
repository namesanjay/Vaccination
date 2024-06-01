#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include "registration.h"


int userCheck(long long int p){
 temp.phNumber = p;
	int i=0;
	while(i<=1000){
		if(pd[i].phNumber == temp.phNumber){  //existing user
			if (pd[i].doses == 0) return 0; //vaccinated 0 dose vaccine
			else if (pd[i].doses == 1) return 1; //vaccinated 1 dose vaccine
		
			else return 2; //vaccinated 2 doses
			} 
			i++;
		}
	
		return -99;  //new user
		} 
		
		
int vaccinationTime(int check, int j){
	FILE *fptrr;

    fptrr = fopen("vaccine.txt","rb");
    fread(&vac,sizeof(vac),1,fptrr);
    fclose(fptrr);
		int option;
	if (check == 2){
		printf("\n\n\n\t\t\t\t\t\tAlready vaccinated all doses!\n");
//		printf("You have already been vaccinated twice with vaccine %s \n",pd[j].vaccineName);
//		printf("\n1st date of vaccination: %d /%d /%d",pd[j].date1.year,pd[j].date1.month,pd[j].date1.day);
//		printf("\n2nd date of vaccination: %d /%d /%d",pd[j].date2.year,pd[j].date2.month,pd[j].date2.day);
		printf("\n\t\t\t\t\t\t\tStay Safe!!");
	}
     vac.totalUserCount = 100;
     if (check !=2){

     if (vac.totalUserCount != 0){
	 
	if (check == 0 || check == 1){
		if (check == 0){
//	printf("You are already registered.\n");

	if (vac.verocellCount != 0 && vac.astrogenicaCount != 0){			
	printf("\n\n -------------------------------------- Please Choose Your Vaccine ----------------------------------------");
	printf("\n\t1>Verocell\n\t2>Astrogenica\n");
	scanf("%d",&option);
	
	switch(option){
	case 1: 
	vac.verocellCount -= 1;
	strcpy(pd[j].vaccineName,"Verocell");
	pd[j].doses +=1;
	break;
	case 2: 
	vac.astrogenicaCount -=1;
	strcpy(pd[j].vaccineName,"Astrogenica");
	pd[j].doses +=1;
	break;
	default:
	printf("Please choose 1 option");
	break;
	}
	
	
	printf("\n\tEnter date of 1st dose of vaccination:");
	pd[j].date1 = dateVerify();
	printf("\n\tThanks for vaccination, please come after 21 days for another vaccination:");
	vac.totalUserCount -= 1;
		


	}	//here
    else if(vac.verocellCount != 0){
    printf("\n\tOnly Verocell Vaccine Is Available, and we are vaccinating you with Verocell!");
    vac.verocellCount -= 1;
	strcpy(pd[j].vaccineName,"Verocell");
	pd[j].doses +=1;
	
	printf("\n\tEnter date of 1st dose of vaccination:");
	pd[j].date1 = dateVerify();
	printf("\n\tThanks for vaccination, please come after 21 days for another vaccination:");
	vac.totalUserCount -= 1;
	
	}
	
	
	else if(vac.astrogenicaCount != 0){
	printf("\n\tOnly Astrogenica Vaccine Is Available, and we are vaccinating you with Astrogenica!");
	vac.astrogenicaCount -= 1;
	strcpy(pd[j].vaccineName,"Astrogenica");
	pd[j].doses +=1;
	
	printf("\n\tEnter date of 1st dose of vaccination:");
	pd[j].date1 = dateVerify();
	printf("\n\tThanks for vaccination, please come after 21 days for another vaccination:");
	vac.totalUserCount -= 1;
	}
	 
}
	
	
	if (check == 1){
		char tempVaccine[15];
		strcpy(tempVaccine,pd[j].vaccineName);
		
		if (strcmp(tempVaccine,"Verocell")==0){
			
						if (vac.verocellCount != 0){
//				printf("\n\tYou have already vaccinated once with vaccine %s\n",pd[j].vaccineName);
//				printf("\n\t1st date of vaccination: %d /%d /%d",pd[j].date1.year,pd[j].date1.month,pd[j].date1.day);
				printf("\n\n\tEnter date of 2nd dose of vaccination:");

			    //printf("%d",_date.year);
				tempDate = dateVerify();
				if (dateDiff(tempDate,j) > 22){
				pd[j].date2 = tempDate;
				pd[j].doses +=1;
//				printf("\n\tYou have been vaccinated by 2nd dose of vaccine %s:",pd[j].vaccineName);	
				vac.verocellCount -= 1;
				vac.totalUserCount -= 1;
				printf("\n\t\t\t\t\tYou have been now vaccinated by all doses.\n");
				printf("\t\t\t\t\t\t\tStay Safe!!");
				}else {
					printf("\n\t\t\t\t\tYou are too soon for 2nd dose of vaccine.");
					goto bot;
				}
				

			}else{
				printf("\nVerocell out of stock!!");
			}
			
		}else {
			if (vac.astrogenicaCount != 0){
//				printf("\nYou have already vaccinated once with vaccine %s\n",pd[j].vaccineName);
//				printf("\n1st date of vaccination: %d /%d /%d",pd[j].date1.year,pd[j].date1.month,pd[j].date1.day);
				printf("\n\n\tEnter date of 2nd dose of vaccination:");
				tempDate = dateVerify();
				if (dateDiff(tempDate,j) > 22){
				pd[j].date2 = tempDate;
				pd[j].doses +=1;
//				printf("\n\tYou have been vaccinated by 2nd dose of vaccine %s:",pd[j].vaccineName);	
				vac.verocellCount -= 1;
				vac.totalUserCount -= 1;
				printf("\n\t\t\t\t\tYou have been now vaccinated by all doses.\n");
				printf("\t\t\t\t\t\t\tStay Safe!!");
				}else {
					printf("\n\t\t\t\t\tYou are too soon for 2nd dose of vaccine.");
					goto bot;
				}			
			}else{
				printf("\n\t\t\t\t\t\tAstrogenica out of stock!!");
			}
		}
		

	}
		
}
 
}// after this
else {
	printf("\n\t\t\t\tThe vaccines are out of stock, Please visit tomorrow!");
}
	 }

	


fptrr = fopen("details.txt","wb");
fwrite(pd,sizeof(pd),1,fptrr); 		
fclose(fptrr);
fptrr = fopen("vaccine.txt","wb");
fwrite(&vac,sizeof(vac),1,fptrr);
fclose(fptrr);
   bot:
	printf("\n\n\t\t\t\t\tPlese Enter Any Key To Goto Main Menu");
	getch();
	
//	return check;
} //main bracket
