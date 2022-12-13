#include "openfile.h"


//function for back propagation learning algorithm
void bp_learning(int p, float LearnRate, int numInputs, int numHidden, int numOutputs)
{
    int i, k;
    float sumDOW[numHidden+1], deltaH[numHidden+1];
    float deltaWeightIH[numInputs][numHidden], deltaWeightHO[numHidden+1][numOutputs];


    for (k = 0; k < numOutputs; k++) {
        for (i = 0; i < numHidden+1; i++) {
            deltaWeightHO[i][k] = 0.0;
            //printf("\nweightsHO[%d][%d]: %f", i, k, weightsHO[i][k]);
        }
    }
    for (k = 0; k < numHidden; k++) {
        for (i = 0; i < numInputs; i++) {
            deltaWeightIH[i][k] = 0.0;
            //printf("weightsIH[%d][%d]: %f\t", i, k, weightsIH[i][k]);
            }
        }

    for (i = 0; i < numHidden+1; i++) {
        sumDOW[i] = 0.0;
    }
    for (i = 0; i < numHidden+1; i++) {
        deltaH[i] = 0.0;
    }

    //back-propagate errors to hidden layer
    for (i = 0; i < numHidden+1; i++)  {
            for (k = 0; k < numOutputs; k++) {
                //printf("\ncheck weightsHO: %f", weightsHO[i][k]);
                //printf("\ncheck deltaO: %f", deltaO[k]);
                sumDOW[i] = sumDOW[i] + weightsHO[i][k] * deltaO[k];
        }
        //printf("\nsumDOW = %f", sumDOW[i]);
    }

        for (i = 1; i < numHidden+1; i++) {
            deltaH[i] = sumDOW[i] * hidden[p][i] * (1.0 - hidden[p][i]);
            //printf("\ndeltaH = %f", deltaH[i]);
        }

    for (k = 0; k < numHidden; k++) {
        for (i = 0; i < numInputs; i++) {
            deltaWeightIH[i][k] = LearnRate * deltaH[k+1] * input_data[p][i];   //calculate weight change for weights going from input to hidden
            weightsIH[i][k] = weightsIH[i][k] + deltaWeightIH[i][k];            //update weights going from input to hidden
            //printf("\nnew weightsIH[%d][%d] = %f", i, k, weightsIH[i][k]);
        }

    }
    for (k = 0; k < numOutputs; k++)  {
        for (i = 0; i < numHidden+1; i++) {
            deltaWeightHO[i][k] = LearnRate * deltaO[k] * hidden[p][i]; //calculate weight change for weights going from hidden to output
            weightsHO[i][k] = weightsHO[i][k] + deltaWeightHO[i][k]; //update weights going from hidden to output
            //printf("\nnew weightsHO[%d][%d] = %f", i, k, weightsHO[i][k]);
        }
    }
}//end of bp_learning()

//function to report accuracy of network
float report_accuracy(int numPatterns, int numOutputs)
{
    float acc, out, hits = 0.0, misses = 0.0;
    int numPat = numPatterns, numOut = numOutputs;
    int p, k;

    for (k = 0; k < numOut; k++) {
        for (p = 0; p < numPat; p++) {

            if (output[p][k] <= 0.209999) {
                out = 0.0;
                if(Targets[p][k] == out) {
                    hits = hits + 1.0;
                    acc = (hits / (float)numPat) * 100.0;
                }
                else {
                    misses = misses + 1.0;
                    acc = (hits / (float)numPat) * 100.0;
                }
            }
            else if (output[p][k] >= 0.8) {
                out = 1.0;
                if (Targets[p][k] == out) {
                    hits = hits + 1.0;
                    acc = (hits / (float)numPat) * 100.0;
                }
                else {
                    misses = misses + 1.0;
                    acc = (hits / (float)numPat) * 100.0;
                }
            }
             else {
                misses = misses + 1.0;                  //keep track of misses
                acc = (hits / (float)numPat) * 100.0;   //accuracy of network in percentage of hits
            }
        }
    }
    return acc;
}

//function to simulate network
void simulate_net()
{
  
    int i, k, p, epoch;
    int numPatterns = NUMPAT, numInputs = NUMIN, numHidden = NUMHID, numOutputs = NUMOUT;
    float error, LearnRate = 0.7, acc;
    float sumH[numPatterns][numHidden];
    float sumO[numPatterns][numOutputs];

    FILE * fPtr;
    fPtr = fopen( DATA_STORE_PATH , "w");

    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    for (k = 0; k < numHidden; k++) {
        for (i = 0; i < numInputs; i++) {
            //deltaWeightIH[i][k] = 0.0;
            weightsIH[i][k] = randn();          //random weights for input to hidden layer
            printf("\nweightsIH[%d][%d]: %f", i, k, weightsIH[i][k]);
            }
        }

    for (k = 0; k < numOutputs; k++) {
        for (i = 0; i < numInputs; i++) {
            weightsHO[i][k] = randn();          //random weights for hidden layer to output layer
            printf("\nweightsHO[%d][%d]: %f", i, k, weightsHO[i][k]);
        }
    }

    for (k = 0; k < numOutputs; k++) {
        for (i = 0; i < numPatterns; i++) {
            Targets[i][k] = targets[i];
            //printf("\n\nTargets[%d][%d]: %f", i, k, Targets[i][k]);
        }
    }

    for (epoch = 1; epoch <= TIMES ; epoch++) {
        error = 0.0;
        for (p = 0; p < numPatterns; p++) { //repeat for all training patterns

            for (k = 0; k < numHidden; k++) {
                sumH[p][k] = 0.0;
                for (i = 0; i < numInputs; i++) {
                    //printf("\n(before) sumH: %f", sumH[p][k]);
                    sumH[p][k] = sumH[p][k] + input_data[p][i] * weightsIH[i][k]; //sum of outputs at hidden layer, bias included in input_data
                }
                //printf("\n(after) sumH: %f", sumH[p][k]);
                if (k == 0) {
                    hidden[p][k] = 1.0; //add bias at hidden layer
                }
                hidden[p][k+1] = 1.0 / (1.0 + exp(-sumH[p][k]));    //sigmoidal outputs at hidden layer
                //printf("\nhidden: %f", hidden[p][k+1]);
            }
            for (k = 0; k < numOutputs; k++) {
                sumO[p][k] = 0.0;
                for (i = 0; i < numHidden+1; i++) {
                    sumO[p][k] = sumO[p][k] + hidden[p][i] * weightsHO[i][k];   //sum of outputs at output layer
                }
                //printf("\nsumO: %f", sumO[p][k]);
                output[p][k] = 1.0 / (1.0 + exp(-sumO[p][k]));                  //sigmoidal output at output layer
                
                //printf("\noutput: %f", Targets[p][k]-output[p][k]);
                error = error + 0.5 * (Targets[p][k] - output[p][k]) * (Targets[p][k] - output[p][k]); //calculate error
                
                // if(error>1){
                //     printf("\nepoch %-5d :  Error = %f", epoch, error);
                // }
                
                deltaO[k] = (Targets[p][k] - output[p][k]) * output[p][k] * (1.0 - output[p][k]);
                //printf("\ndeltaO: %f", deltaO[k]);
            }
            
            //printf("\nepoch %-5d :  Error = %f", epoch, error);
            
            bp_learning(p, LearnRate, numInputs, numHidden, numOutputs);        //function for back propagation learning algorithm
        
        }//end of training patterns

    
        if (epoch%10 == 0) {
            //printf("\nepoch %-5d :  Error = %f", epoch, error);
            fprintf( fPtr," %d,%f\n",epoch,error);
        }
    

        if (error < 0.05) {         //stop learning if error is less than 0.05
            break;
        }

    }//end of epoch
    fclose(fPtr);

    acc = report_accuracy(numPatterns, numOutputs);

    printf("\n\n\tNetwork Results\t ( epoch= %d  )\n\nPat\t", TIMES );
    
    for (i = 1; i < numInputs; i++) {
        printf("Input%-4d\t", i);
    }
    for (k = 1; k <= numOutputs; k++) {
        printf("Targets\t\tOutputs\t");
    }
    for (p = 0; p < numPatterns; p++) {
        printf("\n%d\t", p);            // Pat
        for (i = 1; i < numInputs; i++) {
            printf("%f\t", input_data[p][i]);
        }
        for(k = 0; k < numOutputs; k++) {

            printf("%f\t%f\t", Targets[p][k], output[p][k]);
            
        }
    }
    printf("\n\n\tAccuracy = %f%%\n", acc);


}//end of simulate_net()
