
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


void Slow_Start_Algo(float Wm, float Wo, float Wn, float Curr_BW){
	
	
	float slot_time = 0.00000166;
	
	float Backoff_time;
	float Total_Backoff_time = 0;
	
	FILE *fp;
   char *f_name = "aa_5000.txt";
   char ch;
   int x = 0, y = 0, frame = 0;
   
   fp = fopen(f_name, "r+");
   if (fp == NULL) {
      printf("%s does not exists \n", f_name);
      return;
   } else {
      printf("%s: opened in read mode.\n\n", f_name);
   
   }  
    
   
	while ((ch = fgetc(fp) )!= EOF) {		
	// end-of-file

    
if(ch == '1' || ch =='0'){
	 printf ("frame %c \n ", ch);
 }
    
	if(ch== '1'){
		
		x = x + 1;
		printf("Successful Transmission\n");
	
		if(Curr_BW <= Wm){
			if( Curr_BW == Wo){
				Curr_BW = Wo;
				printf("BackOff Window Size is = %0.8f \n", Curr_BW);
				
				Backoff_time = Curr_BW * slot_time;
				printf("=>  backoff time is  : %0.8f  \n",Backoff_time);
				
			}
			else{
				Curr_BW = Curr_BW / 2;
								printf("BackOff Window Size is = %0.8f \n", Curr_BW);
								
								Backoff_time = Curr_BW * slot_time;
				printf("=>  backoff time is  : %0.8f  \n",Backoff_time);
			}
		}
		else{
			Curr_BW = Curr_BW - Wo;
							printf("BackOff Window Size is = %0.8f \n", Curr_BW);
							
							Backoff_time = Curr_BW * slot_time;
				printf("=>  backoff time is  : %0.8f  \n",Backoff_time);
			
		}
	}
	else if(ch == '0'){
		
		y = y +1;
		printf("   UnSuccessful Transmission\n");
		if( Curr_BW < Wm){
			Curr_BW = Curr_BW * 2;
				
		
		
				printf("BackOff Window Size is = %0.8f \n", Curr_BW);
				
					Backoff_time = Curr_BW * slot_time;
				printf("=>  backoff time is  : %0.8f  \n",Backoff_time);
				
			
		
		
		}
		else{
			printf("Frame Lost Due To Collision or interference\n");
			frame = frame + 1;
		
		if( Curr_BW == Wn){
			Curr_BW= Wn;
			
			printf("BackOff Window Size is = %0.8f \n", Curr_BW);
			
			Backoff_time = Curr_BW * slot_time;
				printf("=>  backoff time is  : %0.8f  \n",  Backoff_time);
		}
		else{
			
			Curr_BW= Curr_BW + Wo;
							printf("BackOff Window Size is = %0.8f \n", Curr_BW);
							
							Backoff_time = Curr_BW * slot_time;
				printf("=>  backoff time is  : %0.8f  \n",  Backoff_time);
		
		}
	}
}


if(ch == '1' || ch =='0'){

Backoff_time = Curr_BW * slot_time;
Total_Backoff_time = Total_Backoff_time + Backoff_time;

		
printf("\n");
printf("=>  Total Back_off time for frame is :  %0.8f \n " ,Total_Backoff_time);
printf("\n\n");

}

	

}

printf(" success num : %d\n" , x);	
printf(" unsuccess num : %d\n" , y);
printf(" Frames are : %d\n" , frame);


printf("At last total BT is ==  %0.8f \n", Total_Backoff_time);

if (!fclose(fp)){
      printf("\n%s: closed.\n", f_name);

}

}



int main()
{
    
    
	float Wm, Wo = 32, Wn = 1024, Curr_BW;
	
	// int slot_time;
	// Wm is Threshold Back-off Window Size
	//Wn is Max Back-off Window Size
	// Wo is initial Back-off Window Size
	printf("Enter the Curr_BW  :  ");
	scanf("%f" , &Curr_BW);
	
	printf("Enter the Threshold backoff win size  :  ");
	scanf("%f" , &Wm);	
	
	// printf("Enter the Slot_time :  ");
	// scanf("%d" , &slot_time);
	
	
	Slow_Start_Algo(Wm, Wo, Wn, Curr_BW);
	
	return 0;  
}
