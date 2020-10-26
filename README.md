# Minor_Project_1

1. Implementation of Improved_Binary_backoff.

2. Implementation of Slow Start Backoff Algorithm.

  1. Randomly generating 1  data set of 5 frames and calculating back_off time.
 
   ```
   A. [Slow_Start_BackOff_Algo](https://github.com/kushagra67414/Minor_Project_1/blob/main/Slow%20Start%20Algorithm/case-1/Slow_Start_BackOff_Algo.c)


   * here we have take slot time, Threshold and Current backoff time form user.
   * And, inital Backoff window size ( 32 ) and Maximum Backoff window size ( 1024 ) is fixed.
  
 B. [Slow_Start_BackOff_Algo_2](https://github.com/kushagra67414/Minor_Project_1/blob/main/Slow%20Start%20Algorithm/case-1/Slow_Start_BackOff_Algo_2.c)
 
   * same as above but here we have taken variables in float and slot_time equals to 0.00000166 micro secs.
   * Because if randomly Contention window tends to be 33.5, the integer variable will read it as 33 and it will affect Backoff time a lot.
   ```
   
 2. FILE HANDLING:  
   ```
   * here we are using file handling. Calculating Backoff time of randomly generated bits i.e 500 bits, 1000 bits, 5000 bits, 20,000 bits etc etc.
   [Source code click here](https://github.com/kushagra67414/Minor_Project_1/blob/main/Slow%20Start%20Algorithm/case-2/Slow_Start_using_File_handling_1.3.c)
   ```
   
