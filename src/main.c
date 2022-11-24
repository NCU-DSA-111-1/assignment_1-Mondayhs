#include "backprop.h"
#include "layer.h"
#include "neuron.h"
#include "fun.h"

#define EPOCH 20000     // Train times


int main(void)
{
    int i;

    srand(time(0));

    printf("Enter the number of Layers in Neural Network:\n");
    scanf("%d",&num_layers);

    num_neurons = (int*) malloc(num_layers * sizeof(int));      //分配指定size個位元組的記憶體空間
    memset(num_neurons,0,num_layers *sizeof(int));

    // Get number of neurons per layer
    for(i=0;i<num_layers;i++)
    {
        printf("Enter number of neurons in layer[%d]: \n",i+1);
        scanf("%d",&num_neurons[i]);
    }

    printf("\n");

    // Initialize the neural network module
    if(init()!= SUCCESS_INIT)
    {
        printf("Error in Initialization...\n");
        exit(0);
    }

    printf("Enter the learning rate (Usually 0.15): \n");
    scanf("%f",&alpha);
    printf("\n");

    printf("Enter the number of training examples: \n");
    scanf("%d",&num_training_ex);
    printf("\n");

    input = (float**) malloc(num_training_ex * sizeof(float*));     // 分配所有行的首地址 
    for(i=0;i<num_training_ex;i++)      // 按行分配每一列 
    {
        input[i] = (float*)malloc(num_neurons[0] * sizeof(float));
    }

    desired_outputs = (float**) malloc(num_training_ex* sizeof(float*));
    for(i=0;i<num_training_ex;i++)
    {
        desired_outputs[i] = (float*)malloc(num_neurons[num_layers-1] * sizeof(float));
    }


    // Get Training Examples
    get_inputs();

    // Get Output Labels
    get_desired_outputs();

    train_neural_net();
    test_nn();

    if(dinit()!= SUCCESS_DINIT)
    {
        printf("Error in Dinitialization...\n");
    }

    return 0;
}


