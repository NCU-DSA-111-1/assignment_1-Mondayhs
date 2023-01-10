#ifndef FUN_H
#define FUN_H

#define EPOCH 20000     // Train times

int num_layers;         // number of Layers
int *num_neurons;       // number of neurons in laye
float alpha;            // the learning rate 
float **input;
float **desired_outputs;
int num_training_ex;    // number of training examples
// int n=1;                // in compute_cost()


int init();
void  get_inputs();
void get_desired_outputs();
void feed_input(int i);
int create_architecture();
int initialize_weights(void);
int initialize_weights(void);
void train_neural_net(void);
void update_weights(void);
void forward_prop(void);
void back_prop(int p);
void test_nn(void); 
int dinit(void);

#endif
