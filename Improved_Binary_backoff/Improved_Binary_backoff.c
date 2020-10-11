
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()

{
int C = 12, D = 4, E = 8;

int counter = 0 , CW ;
int no;
float slot_time = 0.00000166;
int CWmax = 1024;

float backoff_time;
int CWmin = 32;
float G = 0.125*CWmin;
int number;

int i;

// C => successful sending times
// D => Quickly decrease the the CW
// E => linearly inc the CW
// G => Threshold quantity


printf("Enter the Curr_BW (CW)  :  ");
	scanf("%d" , &CW);

//printf("Enter the CWmax  :  ");
//	scanf("%d" , &CWmax);


no = (rand() % (CWmin - CWmax + 1 ) +1 ) ;
		printf("random number is : %d \n " , no);
		backoff_time = no * slot_time;
		printf(" => backoff time at initial  is : %0.8f \n\n " , backoff_time);


FILE *fp;
   char *f_name = "aa.txt";
   char ch;
   
   fp = fopen(f_name, "r+");
   if (fp == NULL) {
      printf("%s does not exists \n", f_name);
      return;
   } else {
      printf("%s: opened in read mode.\n\n", f_name);
   
   }  
    int charToInt(char c){

return c - '0';
}
   
	while ((ch = fgetc(fp) )!= EOF) {		
	// end-of-file
      printf ("frame %c \n ", ch);
      number = charToInt(ch);
      
      
if(number == 1)
{
		if(counter < C){
	
	counter = counter + 1;
		printf("Counter value is :  %d \n" , counter);

	CW = CW / D;
	printf("CW divide by d (4) :  %d \n" , CW );
	
	if(CW < G){
		CW = G;
		printf("CW in CW < G is  :  %d \n" , CW);
		
		no = (rand() % (CW - CWmin + 1 ) +1 ) ;
		printf("random number is : %d \n " , no);
		
		backoff_time = no * slot_time;
		printf(" => backoff time is : %0.8f \n\n " , backoff_time);
		
		
	}
	else{
		
			printf("CW in CW < G (else part ) :  %d \n" , CW);

		
		no = (rand() % (CW - CWmin + 1 ) +1 ) ;
		printf("random number is : %d \n " , no);
		backoff_time = no * slot_time;
		printf(" => backoff time is : %0.8f \n\n " , backoff_time);
	}
	
}
else{
	
	counter = 1;
	
		printf("Counter value when > than C is :  %d \n" , counter);
		
	CW = CW + E*CWmin ;
	
	if(CW > CWmax){
		
		CW = CWmax ;
		printf("CW in CW > CWmax is :  %d \n" , CW);
		
		no = (rand() % (CW - CWmin + 1 ) +1 ) ;
		printf("random number is : %d \n " , no);
		backoff_time = no * slot_time;
		printf(" => backoff time is : %0.8f \n\n " , backoff_time);
	
	}else{
		printf("CW in CW > CWmax (else part ) is  :  %d \n" , CW);
		
		no = (rand() % (CW - CWmin + 1 ) +1 ) ;
		printf("random number is : %d \n " , no);
		backoff_time = no * slot_time;
		printf(" => backoff time is : %0.8f \n\n " , backoff_time);
	
	}
}

}else {
	
	
	printf("\n  data lost data lost...\n\n");
}

	
}






	
}
