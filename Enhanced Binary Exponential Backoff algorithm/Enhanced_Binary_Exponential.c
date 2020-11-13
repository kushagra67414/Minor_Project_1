#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
int main()
{
int C = 12, D = 4, E = 8;

int counter = 0 ;
double slot_time = 0.00000166, CW ;
int CWmax = 1024, CWmin = 32;
double BT, G, Total_Backoff_time = 0;


printf("Enter the Curr_BW (CW) by user  :  ");
	scanf("%lf" , &CW) ;

FILE *fp;
   char *f_name = "aaa.txt";
   char ch;
   
   fp = fopen(f_name, "r+");
   if (fp == NULL) {
      printf("%s does not exists \n", f_name);
      return;
   } else {
      printf("%s: opened in read mode.\n\n", f_name);
   
   }
   
	while ((ch = fgetc(fp) )!= EOF) {		
	// end-of-file
    
	if(ch == '0' || ch == '1'){
	   printf("frame %c \n ", ch);	
	
	}
	     
if(ch == '1' || ch =='0')
{
	
if(counter < CWmin){
	
	counter = counter + 1;
	if(CW > CWmin){
		CW = CW - CWmin;
		
	}else{
		CW = CW - 2;
	}
	
	if( CW < (1 / sqrt(CWmin) )  * CWmin   ){
		
		CW = (1 / sqrt(CWmin) )  * CWmin ;
		printf("The value Current CW is : %0.8f\n " ,CW);
		BT = ( CWmin / sqrt(CWmax))* CW * slot_time;
		printf("=> Value of Backoff time is :  %0.8f\n" , BT);
				printf("NODE TRANSMITS SUCCESSFULLY");
	}else{
		
		printf("The value Current CW is : %0.8f\n ", CW);
		
		BT = ( CWmin / sqrt(CWmax))* CW * slot_time;
		printf("=> Value of Backoff time is :  %0.8f\n" , BT);
				printf("NODE TRANSMITS SUCCESSFULLY");
		}
	
	
}else{

counter = 1;

CW =CW + (CWmax / CW)*CWmin	;

if(CW < CWmax){
	
	CW = CWmax;
			printf("The value Current CW is : %0.8f\n ", CW);

		BT = ( CWmin / sqrt(CWmax))* CW * slot_time;
		printf("=> Value of Backoff time is :  %0.8f\n" , BT);
		
		printf("NODE TRANSMITS SUCCESSFULLY");
}else{
	
		BT = ( CWmin / sqrt(CWmax))* CW * slot_time;
		printf("=> Value of Backoff time is :  %0.8f\n" , BT);
				printf("NODE TRANSMITS SUCCESSFULLY");
}
	
}
	
}

if(ch == '1' || ch =='0'){

Total_Backoff_time = Total_Backoff_time + BT;

		
printf("\n");
printf("=>  Total Back_off time for frame is :  %0.8f \n " ,Total_Backoff_time);
printf("\n\n");
	
}



	
}

}
