#include "stack-vm.cpp"

int main(){
	StackVM vm;
	vector<i32> prog{3,4,0x40000001,0x40000000};
	vm.loadPrograms(prog);
	vm.run();
	return 0;
}