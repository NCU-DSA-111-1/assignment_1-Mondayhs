# Neural-Network-framework-using-Backpropogation-in-C


## File structure
```bash
assignment_1-Mondayhs/
        ├──bin/         # binary file which can execute
        │   
        ├──obj/         # object file which can be linked
        │ 
        ├──inc/         # header file
        │   └── ...
        ├──src/         # C code
        │   └── ...
        │
        ├──build.sh     # bash script
        ├──Makefile     # make file
        ├──assignment#1.1.docx     # 
        ├──assignment#1.1.pdf
        └──README.md    # this file 
        
```


## Compile
```sh
sudo chmod +x build.sh
./build.sh
```

## Run
```sh
cd bin
./main --name name1 name2       # Run
```


## Usage

Enter the number of Layers in Neural Network: 3 <br />
Enter number of neurons in layer[1]:  2 <br />
Enter number of neurons in layer[2]:  3 <br />
Enter number of neurons in layer[3]:  1 <br />

<br />
Created Layer: 1 <br />
Number of Neurons in Layer 1: 2 <br />
Neuron 1 in Layer 1 created <br />
Neuron 2 in Layer 1 created <br />

Created Layer: 2 <br />
Number of Neurons in Layer 2: 4 <br />
Neuron 1 in Layer 2 created <br />
Neuron 2 in Layer 2 created <br />
Neuron 3 in Layer 2 created <br />
Neuron 4 in Layer 2 created <br />

Created Layer: 3 <br />
Number of Neurons in Layer 3: 1 <br />
Neuron 1 in Layer 3 created <br />

<br />
Initializing weights... <br />
0:w[0][0]: 0.766243  <br />
1:w[0][0]: 0.250295  <br />
2:w[0][0]: 0.706896  <br />
3:w[0][0]: 0.793307  <br />
0:w[0][1]: 0.114556  <br />
1:w[0][1]: 0.344917  <br />
2:w[0][1]: 0.025145  <br />
3:w[0][1]: 0.607074  <br />
0:w[1][0]: 0.095798  <br />
0:w[1][1]: 0.732832  <br />
0:w[1][2]: 0.204670  <br />
0:w[1][3]: 0.757424  <br />
<br />
Enter the learning rate (Usually 0.15):  0.15 <br />
<br />
Enter the number of training examples:  4 <br />
Enter the Inputs for training example[0]:  0 0 <br />
Enter the Inputs for training example[1]:  0 1 <br />
Enter the Inputs for training example[2]:  1 0 <br />
Enter the Inputs for training example[3]:  1 1 <br />
<br />
Enter the Desired Outputs (Labels) for training example[0]:  0 <br />
Enter the Desired Outputs (Labels) for training example[1]:  1 <br />
Enter the Desired Outputs (Labels) for training example[2]:  1 <br />
Enter the Desired Outputs (Labels) for training example[3]:  0 <br />
<br />
Enter input to test: 0 0 <br />
Output: 0 <br />
Enter input to test: 0 1 <br />
Output: 1 <br />
Enter input to test: 1 0 <br />
Output: 1 <br />
Enter input to test: 1 1 <br />
Output: 0 <br />








<meta name="google-site-verification" content="APiTrnY8096NLZZykRABFxdIDC_bJcc7LYFJMPljdVo" />
