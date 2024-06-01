#include "registration.h"

//password verification;
int passwordVerify(char jk[20]){

	char pass[20],ch;
	int i=0;
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
				pass[i]='\0';
				printf("\b \b");
			}
		}
		else
		{
			pass[i]=ch; 
			putch('*');
			i++;
		}
	}
	pass[i]='\0';
	
	if ((strcmp(jk,pass)==0) )return 1;
	else return -1;
	}
	
//date verification
struct date dateVerify(){
	struct date _date;
	yearr:
	printf("\n\tEnter year:");
	scanf("%d",&(_date.year));
	if((_date.year>9999) || (_date.year <= 1 )){
		printf("\n\tplease enter correct year format:");
		goto yearr;
	}
	monthh:
	printf("\tEnter month:");
	scanf("%d",&(_date.month));
		if((_date.month>12 )|| (_date.month<= 1)){
		printf("\n\tplease enter correct month format:");
		goto monthh;
	}
	dayy:
	printf("\tEnter day:");
	scanf("%d",&(_date.day));
		if((_date.day>31 )|| (_date.day<= 1 )){
		printf("\n\tplease enter correct day format:");
		goto dayy;
	}
	return _date;
}


int dateDiff(struct date _date ,int j)
{
    int day1, mon1, year1, day2, mon2, year2;

    int day_diff, mon_diff, year_diff;         
    int diff;
    
//        day1=12;
//    mon1=11;
//    year1=2022;
//    
//    day2=13;
//    mon2=10;
//    year2=2022;
    
    
    day1=pd[j].date1.day;
    mon1=pd[j].date1.month;
    year1=pd[j].date1.year;
    
    day2=_date.day;
    mon2=_date.month;
    year2=_date.year;
    
    if(day2 < day1)
    {
        day2 += 30;
        mon2 = mon2 - 1;
    }

    if (mon2 < mon1)
    {
        mon2 += 12;
        year2 -= 1;
    }       

    day_diff = day2 - day1;
    mon_diff = mon2 - mon1;
    year_diff = year2 - year1;
    diff = (year_diff * 365) + (mon_diff * 30) + day_diff;
    return diff;
	}


long long int phoneVerify(){
	long long int phone;
			
//	system("cls");
		printf("\n\tEnter phone number:");
		phoneverify:
		fflush(stdin);
		scanf("%lld", &phone);				
		//phonenumber check
		{int numberCount = 0;
		 int phonenum =  phone;
		do {
   		phonenum /= 10;
    	++numberCount;
 		 } while (phonenum != 0);
//		printf("%d",numberCount);
		if (numberCount != 10) {
			printf("\n\tInvalid Phone Number,Please Enter Again--");
			printf("\n\tPhone Number:");
			goto phoneverify;
		}
		}
		return phone;
}
	
	
	
	


