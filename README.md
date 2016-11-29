# Encoder Library For BeagleBone Black

This Library can be used to directly use to measure the encoder ticks, when connected to the eQEP Module of the BeagleBone Black.
The Library uses memory mapping, and thus reads directly from the memory registers, instead of reading from the files.
This makes the library very fast and effecient to be used in robotic systems.

### Usage

To Use the lirary in a C++ program running on BeagleBone Black just import the  _"encoder.h"_ and create a object of the encoder class as follows :

```C++
 encoder enc(2);              // 2 refers to the EQEP module to which encoder is connected
 long ticks = enc.read()     // reads the encoder ticks
```

  
