#ifndef STACK_VM_H
#define STACK_VM_H

#include <iostream>
#include <vector>
using namespace std;

typedef int32_t i32;
class StackVM{
	i32 programCounter =100;
	i32 stackPointer = 0;
	vector<i32> memory; //our memory whic virtual cpu will access
	i32 typ = 0,dat=0, running =1; //some resistors for simp-licity

	i32 getType(i32 instructions);
	i32 getData(i32 instructions);
	void fetch ();
	void decode();
	void execute();
	void doPremitive();

	public:
	StackVM();
	void run();
	void loadPrograms(vector<i32> v); //intialise memory

};

#endif