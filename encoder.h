#ifndef encoder_H
#define encoder_H
#include <stdio.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define QPOSCNT      0x0000
#define EQEP0_BASE   0x48300180
#define EQEP1_BASE   0x48302180
#define EQEP2_BASE   0x48304180

class encoder{
	unsigned long * eqep_addr;
	public:
	encoder(int num);
	long int read();
	void set(long int value);
	
}; 
#endif
