# CSE330: Operating Systems 

Please follow the below steps to test your Project-2. 

- Download the zip of this git repository.
- Unzip the repository.
- Copy your kernel module code (producer_consumer.c) to this repository.
- Run the test.sh script with the test arguments. 

bash test.sh < Number of processes to be spawned> < Buffer Size > < Number of Producer > < Number of Consumer > < Number of lines to be displayed from the dmesg >

## Test Cases:

- Test Case 1: 
  - ./test.sh 10 5 1 0 25 
- Test Case 2: 
  - ./test.sh 10 5 0 1 25
- Test Case 3: 
  - ./test.sh 10 50 1 1 25
- Test Case 4: 
  - ./test.sh 100 50 1 1 25
- Test Case 5: 
  - ./test.sh 1000 50 1 1 100


## Note: 
- Please do not make any changes in provided test code to pass the test cases.
- You can use print statements in case you want to debug and understand the logic of the test code.
- Please get in touch with the TAs if you face issues in using the test scripts.
