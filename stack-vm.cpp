#include "stack-vm.h"

//  instruction format:
	//header = 2 bit, body = 30 bits

	//Header:
	// 0 = positive int
	// 1 = premitive instruction (it will be executable instruct.)
	// 2 = neg int 
	// 3 = undefined

StackVM::StackVM(){
	memory.reserve(1000000);
}
i32 StackVM::getType(i32 instructions){
	i32 type = 0xc0000000;
	type = (type & instructions)>>30; //every instruction has 2 bit reserved to explain what type of instruction it is
	return type;
}
i32 StackVM::getData(i32 instructions) {
	i32 data = 0x3fffffff;
	data = data & instructions;
	return data;
}
void StackVM::fetch(){
	programCounter++;
}
void StackVM::decode(){
	typ = getType(memory[programCounter]); //we are getting instruct from memory and getting its type
	dat = getData(memory[programCounter]); //we are getting instruct from memory and getting its data

}
void StackVM::execute(){
	if (typ == 0 or typ == 2){
		stackPointer++;
		memory[stackPointer] = dat; //our stack will start at 0 and will grow upward
	}
	else
	{
		doPremitive(); // contorl mechanism is cpu alternative for this fucniton
	}
}
void StackVM::doPremitive(){
	switch(dat){
		case 0: //halt
			cout<<"halt\n";
			running = 0;
			break;
		case 1: //add
			cout<<"add "<<memory[stackPointer-1] << " " << memory[stackPointer] <<endl;
			memory[stackPointer - 1] = memory[stackPointer-1]+memory[stackPointer];
			break; //pop numbers add push sum

	}
}

void StackVM::run(){
	programCounter -= 1; //so first time we fetch count will be what we want
	while(running == 1)
	{
		fetch();
		decode();
		execute();
		cout<<"tos: "<<memory[stackPointer] <<endl;
	}
}

void StackVM::loadPrograms(std::vector<i32> v){
	for(i32 i=0;i<v.size();i++)
	{
		memory[programCounter+i] = v[i]; //itlaods prog into our memory
	}
}