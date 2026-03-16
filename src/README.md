// the Feistel cipher
// XORs part of a data input, then uses that result to XOR the other part

// F(R, y) is the ROUND function, where R = right part of the data block and y = encryption key
// An example of F(R, y) is F(R, y) = (R * y) % (2^(32) - 1)
// then we could do something like R2 = L1 XOR F(R1, y1)

