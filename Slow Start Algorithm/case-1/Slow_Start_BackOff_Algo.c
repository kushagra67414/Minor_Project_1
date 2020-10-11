
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



void Slow_Start_Algo(int Wm, int Wo, int Wn, int Curr_BW, int ACK[5] , int slot_time){
	
	
	int Back_off_Win_Size = 0; 
	int Backoff_time;
	int Total_Backoff_time = 0;
	int j, x;
	
	
	for(x= 0; x < 5; x++ ){
	
	for(j= 0; j < 5; j++ ){
	if(ACK[j] == 1){
		printf("Successful Transmission\n");
		if(Curr_BW <= Wm){
			if( Curr_BW == Wo){
				Back_off_Win_Size = Wo;
				printf("BackOff Window Size is = %d \n", Back_off_Win_Size);
				
				Backoff_time = Back_off_Win_Size * slot_time;
				printf("=>  backoff time is  : %d  \n",Backoff_time);
			}
			else{
				Back_off_Win_Size = Curr_BW / 2;
								printf("BackOff Window Size is = %d \n", Back_off_Win_Size);
								
								Backoff_time = Back_off_Win_Size * slot_time;
				printf("=>  backoff time is  : %d  \n",Backoff_time);
			}
		}
		else{
			Back_off_Win_Size = Curr_BW - Wo;
							printf("BackOff Window Size is = %d \n", Back_off_Win_Size);
							
							Backoff_time = Back_off_Win_Size * slot_time;
				printf("=>  backoff time is  : %d  \n",Backoff_time);
			
		}
	}
	else{
		if( Curr_BW < Wm){
			Back_off_Win_Size = Curr_BW * 2;
							printf("BackOff Window Size is = %d \n", Back_off_Win_Size);
							
							Backoff_time = Back_off_Win_Size * slot_time;
				printf("=>  backoff time is  : %d  \n",Backoff_time);
			
		}
		else{
			printf("Frame Lost Due To Collision or interference");
		
		if( Back_off_Win_Size == Wn){
			Back_off_Win_Size= Wn;
			
			Backoff_time = Back_off_Win_Size * slot_time;
				printf("=>  backoff time is  : %d  \n",Backoff_time);
		}
		else{
			Back_off_Win_Size= Curr_BW + Wo;
							printf("BackOff Window Size is = %d \n", Back_off_Win_Size);
							
							Backoff_time = Back_off_Win_Size * slot_time;
				printf("=>  backoff time is  : %d  \n",Backoff_time);
		
		}
	}
}

Backoff_time = Back_off_Win_Size * slot_time;
Total_Backoff_time = Total_Backoff_time + Backoff_time;



}
printf("\n");
printf("=>  Total Back_off time for frame %d is :  %d \n", x+1 ,Total_Backoff_time);
printf("\n\n");

Total_Backoff_time = 0;
Back_off_Win_Size = 0;
Data_Signals(ACK);


}

}


int main()
{
    
    
	int Wm, Wo = 32, Wn = 1024, Curr_BW;
	int ACK[5];
	int slot_time;
	// Wm is Threshold Back-off Window Size
	//Wn is Max Back-off Window Size
	// Wo is initial Back-off Window Size
	printf("Enter the Curr_BW  :  ");
	scanf("%d" , &Curr_BW);
	
	printf("Enter the Threshld backoff win size  :  ");
	scanf("%d" , &Wm);	
	
	printf("Enter the Slot_time :  ");
	scanf("%d" , &slot_time);
	
	
	Data_Signals(ACK);
	
	Slow_Start_Algo(Wm, Wo, Wn, Curr_BW, ACK, slot_time);
	
	return 0;
    
    
}

