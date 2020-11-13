# Minor_Project_1

1. **Implementation of Improved_Binary_backoff =>**

2. **Implementation of Slow Start Backoff Algorithm =>**
  * Randomly generating 1  data set of 5 frames and calculating back_off time.
 
    * [Slow_Start_BackOff_Algo](https://github.com/kushagra67414/Minor_Project_1/blob/main/Slow%20Start%20Algorithm/case-1/Slow_Start_BackOff_Algo.c)


      * here we have take slot time, Threshold and Current backoff time form user.
      * And, inital Backoff window size ( 32 ) and Maximum Backoff window size ( 1024 ) is fixed.
  
    * [Slow_Start_BackOff_Algo_2](https://github.com/kushagra67414/Minor_Project_1/blob/main/Slow%20Start%20Algorithm/case-1/Slow_Start_BackOff_Algo_2.c)
 
      * same as above but here we have taken variables in float and slot_time equals to 0.00000166 micro secs.
      * Because if randomly Contention window tends to be 33.5, the integer variable will read it as 33 and it will affect Backoff time a lot.
   
  * FILE HANDLING:  
    
    * here we are using file handling. Calculating Backoff time of randomly generated bits i.e 500 bits, 1000 bits, 5000 bits, 20,000 bits etc etc.
    
   [Source code click here](https://github.com/kushagra67414/Minor_Project_1/blob/main/Slow%20Start%20Algorithm/case-2/Slow_Start_using_File_handling_1.3.c)
   
   
3. **Binary Exponential Backoff algorithm =>**

  * In this algorithm, when the node attempts to send the data unsuccessfully seven times, the function CW() is invoke to set contention window to minimum.
  which reduce the probabilty of the unsuccessful frame to transmit successfully and for the upcoming nodes if they get unsuccessed.


4. **Enhanced Binary Exponential Backoff algorithm =>**

 * This Algorithm solves the Fairness problem up to the maximun point.
 * [Click here for the Source Code](https://github.com/kushagra67414/Minor_Project_1/blob/main/Enhanced%20Binary%20Exponential%20Backoff%20algorithm/Enhanced_Binary_Exponential.c)
 
