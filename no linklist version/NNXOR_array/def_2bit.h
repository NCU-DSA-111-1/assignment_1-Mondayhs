#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define INPUTS 3    //number of inputs for training set, includes inputs and one target
#define IN_FILE "XOR-data.txt"  //input data (i.e. patterns) file 
//#define IN_FILE "XOR-data_3bit.txt"

#define NUMPAT 4 //number of patterns
#define NUMIN  3 //number of inputs (includes the bias)
#define NUMHID 4 //number of neurons in hidden layer
#define NUMOUT 1 //number of neurons in output layer
#define MIN -0.5
#define MAX 0.5
#define randn() (((double)rand()/((double)RAND_MAX + 1)) * (MAX - MIN)) + MIN

#define TIMES 3000

#define DATA_STORE_PATH "/Users/zhouchou/Desktop/DS/109605503_assignment_1/analyze/xor_2bit.csv"

float input_data[NUMPAT][INPUTS];
float weight_data[NUMHID][NUMIN];
float targets[NUMPAT];


float Targets[NUMPAT][NUMOUT]; //same as targets array, but modified to work with network
float hidden[NUMPAT][NUMHID+1];
float deltaO[NUMOUT];
float weightsIH[NUMIN][NUMHID], weightsHO[NUMHID+1][NUMOUT];
float output[NUMPAT][NUMOUT];