
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


void Data_Signals(int ACK[5]){
	int i;
	
	srand(time(0));
    for (i = 0; i < 5; i++) { 
        ACK[i] = rand() % 2; 
    }
    int k;
	for(k=0; k < 5; k++){
		printf(" ACK are's : %d\n", ACK[k]);
	} 
}



void Slow_Start_Algo(float Wm, float Wo, float Wn, float Curr_BW, int ACK[5]){
	
	
	float Backoff_time;
	float Total_Backoff_time = 0;
	int j;
	float slot_time = 0.00000166 ;
	
	
	for(j= 0; j < 5; j++ ){
	if(ACK[j] == 1){
		printf("Successful Transmission\n");
		if(Curr_BW <= Wm){
			if( Curr_BW == Wo){
				Curr_BW	 = Wo;
				printf("BackOff Window Size is = %0.8f \n", Curr_BW);
				
				Backoff_time = Curr_BW * slot_time;
				printf("=>  backoff time is  : %0.8f  \n\n",Backoff_time);
			}
			else{
				Curr_BW = Curr_BW / 2;
								printf("BackOff Window Size is = %0.8f \n", Curr_BW);
								
								Backoff_time = Curr_BW * slot_time;
				printf("=>  backoff time is  : %0.8f  \n\n",Backoff_time);
			}
		}
		else{
			Curr_BW = Curr_BW - Wo;
							printf("BackOff Window Size is = %0.8f \n", Curr_BW);
							
							Backoff_time = Curr_BW * slot_time;
				printf("=>  backoff time is  : %0.8f  \n\n",Backoff_time);
			
		}
	}
	else{
		if( Curr_BW < Wm){
			Curr_BW = Curr_BW * 2;
							printf("BackOff Window Size is = %0.8f \n", Curr_BW);
							
							Backoff_time = Curr_BW * slot_time;
				printf("=>  backoff time is  : %0.8f  \n\n",Backoff_time);
			
		}
		else{
			printf("Frame Lost Due To Collision or interference\n");
		
		if( Curr_BW == Wn){
			Curr_BW= Wn;
				printf("BackOff Window Size is = %0.8f \n", Curr_BW);
			
			Backoff_time = Curr_BW * slot_time;
				printf("=>  backoff time is  : %0.8f  \n\n",Backoff_time);
		}
		else{
			Curr_BW= Curr_BW + Wo;
							printf("BackOff Window Size is = %0.8f \n", Curr_BW);
							
							Backoff_time = Curr_BW * slot_time;
				printf("=>  backoff time is  : %0.8f  \n\n",Backoff_time);
		
		}
	}
}

Total_Backoff_time = Total_Backoff_time + Backoff_time;
printf("=>  Total Back_off time for frame is : %0.8f\n\n",Total_Backoff_time);


}
printf("\n"); 
printf("=>  at last Back_off time for frame is : %0.8f\n\n",Total_Backoff_time);
printf("\n\n");





}


int main()
{
    
    
	float Wm, Wo = 32, Wn = 1024, Curr_BW;
	int ACK[5];
	
	// Wm is Threshold Back-off Window Size
	//Wn is Max Back-off Window Size
	// Wo is initial Back-off Window Size


	printf("Enter the Curr_BW  :  ");
	scanf("%f" , &Curr_BW);
	
	
	printf("Enter the Threshld backoff win size  :  ");
	scanf("%f" , &Wm);
	
	
	
	Data_Signals(ACK);
	
	Slow_Start_Algo(Wm, Wo, Wn, Curr_BW, ACK);
	
	return 0;
    
    
}

