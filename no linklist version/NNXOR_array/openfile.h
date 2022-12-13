//#include "def_2bit.h"
#include "def_3bit.h"

// function to read XOR data file contents
void read_input_data()
{
    FILE *fp;
    fp = fopen(IN_FILE, "r");   //open text file

    if (fp == NULL) {
        printf("Error while opening the inputs data file.\n");
    }
    else {
    int i,k;
    char read_in[150];
    float conv_in;


    fscanf(fp, "%*[^\n]");      //skip first line of text file
    
    for (i = 0; i < NUMPAT; i++){
        for (k = 0; k <= INPUTS; k++){

        //add bias to all patterns (i.e. lines)

        if (k == 0) {
            input_data[i][k] = 1;           //add bias to first element of each pattern
            //printf("bias: %f", input_data[i][k]);
        }

        // store targets
        else if (k == INPUTS) {
            fscanf(fp, "%s", read_in);      //read single string up to the whitespace
            conv_in = atof(read_in);        //convert from character to floating point integer
            //print_input_data(i, k, conv_in);
            targets[i] = conv_in;
            //printf(" t%d: %f\n", i, targets[i]);
        }
        else {
            fscanf(fp, "%s", read_in);      //read single string up to the whitespace
            conv_in = atof(read_in);        //convert from character to floating point integer
            //print_input_data(i, k, conv_in);
            input_data[i][k] = conv_in;
            //printf(" input[%d][%d]: %f", i, k, input_data[i][k]);
            }
        }

    }
    }
    fclose(fp);
}