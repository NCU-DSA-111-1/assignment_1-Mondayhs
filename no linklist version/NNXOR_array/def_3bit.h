#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define INPUTS 4    //number of inputs for training set, includes three inputs and one target
#define IN_FILE "XOR-data_3bit.txt"  //input data (i.e. patterns) file 


#define NUMPAT 8 //number of patterns
#define NUMIN  4 //number of inputs (includes the bias)
#define NUMHID 4 //number of neurons in hidden layer
#define NUMOUT 1 //number of neurons in output layer
#define MIN -0.5
#define MAX 0.5
#define randn() (((double)rand()/((double)RAND_MAX + 1)) * (MAX - MIN)) + MIN

#define TIMES 10000


#define DATA_STORE_PATH "/Users/zhouchou/Desktop/DS/109605503_assignment_1/analyze/xor_3bit.csv"

float input_data[NUMPAT][INPUTS];
float weight_data[NUMHID][NUMIN];
float targets[NUMPAT];


float Targets[NUMPAT][NUMOUT]; //same as targets array, but modified to work with network
float hidden[NUMPAT][NUMHID+1];
float deltaO[NUMOUT];
float weightsIH[NUMIN][NUMHID], weightsHO[NUMHID+1][NUMOUT];
float output[NUMPAT][NUMOUT];