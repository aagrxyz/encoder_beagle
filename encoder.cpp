#include <iostream>
#include "encoder.h"
using namespace std;

encoder::encoder(int num)
{
	int fd;
	unsigned long *map_base;
	unsigned long target;
	if(num==0)target=EQEP0_BASE;
	else if(num==1)target=EQEP1_BASE;
	else if(num==2)target=EQEP2_BASE;
	long eqep_pos;
	unsigned long map_size = getpagesize();
 	unsigned long map_mask = map_size-1;

 //O_SYNC makes the memory uncacheable
 if ((fd = open("/dev/mem", O_RDWR | O_SYNC))==-1) {
   cout<<"Could not open /dev/mem\n";
   exit(-1);
 }
// cout<<("opened /dev/mem\n");
 
 //&~map_mask truncates the address to the base of the 4K Page
 map_base=(unsigned long *)(mmap(0, map_size, PROT_READ|PROT_WRITE,MAP_SHARED,fd, target&~map_mask));
//	cout<<map_base<<endl;
 if(map_base == (void *) -1) {
 cout<<("Unable to mmap eqep\n");
 exit(-1);
 }

 //&map_mask adds the position within the page to the address, this is 0x180 for eEQP0
 //0x180 is replaced with 0x60 as in C++ address addition depends on datatype of pointer
 //unlike C addition happens in byte. 
	eqep_addr = (map_base) +0x60;
	//Uncomment next two lines to check the address of mapping
//	printf("0x%X\n",target&map_mask);
//	cout<<eqep_addr<<endl;
//	cout<<"mapping is done at encoder num "<<num<<endl;
  close(fd);
}

long int encoder::read(){
	return *((long int*)eqep_addr);
}
void encoder::set(long int value){
	*((long int*)eqep_addr)=value;
}
