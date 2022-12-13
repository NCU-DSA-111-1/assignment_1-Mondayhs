#include "def.h"


void write_output_data( int  epoch, float  error )
{
    /* Variable to store user content */
    // int * epo;
    // float * error2;

    /* File pointer to hold reference to our file */
    FILE * fPtr;

    // epo = (int*) malloc(epoch * sizeof(int));
    // error2 = (float*) malloc(error * sizeof(float));

    /* 
     * Open file in w (write) mode. 
     * "" is complete path to create file
     */
    fPtr = fopen( DATA_PATH , "w");


    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }


 


    /* Write data to file */
    // fwrite( & epo, sizeof(int), 1 ,fPtr);
    // fwrite( & error2, sizeof(float), 1 ,fPtr);
    fprintf( fPtr," %-5d %f \n",epoch,error);
    

    /* Close file to save file data */
    fclose(fPtr);


    /* Success message */
    //printf("File created and saved successfully. :) \n");


    
}