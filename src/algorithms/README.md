// the FEISTEL cipher

// by default, takes half of data block and encrypts it using a unique function
// then, takes that encrypted half and XORs it with the other half
// repeated a certain amount of times

// the Round Function: a math function with two parameters - data to encrypt, and a key
// the key is the "random seed" for the function. the data is encrypted through the function

// PREREQUISITES: develop Round Function, key generator, one key for each round
// STEP 1: convert input data to binary (convert bitset to string)
// STEP 2: split the binary into two halves (each half is a string)
// STEP 3: perform the Round Function on the right half (convert half to binary then perform)
// STEP 4: XOR the right half onto the left half
// STEP 5: the "next" right half is that result. the "next" left half is the exact same right half at the start of the previous round
// repeat steps 3-5 until all rounds have been completed