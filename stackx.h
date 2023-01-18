#ifndef STACKX_H
#define STACKX_H
#include <iostream>
#include <cstdint>
/*

	StackX: A basic fixed size stack object template. Initialize with StackX<datatype, iteratortype> stackname(integer size)
	Example: 1kb signed 8-bit stack with a 16 bit unsigned iterator
		StackX<int8_t, uint16_t> s8b(0x400);

*/
template <typename T, typename U>
class StackX {
	private:
		T* data;
		U sp; // stack pointer
		U mx; // Max, the size of the stack's allocated memory
	public:
		StackX(U sz){
			data = new T [sz]; // initialize sz sized array of type T
			sp = 0; mx = sz;
		}
		StackX(T * target, U sz){
			data = target;
			sp = 0; mx = sz;
		}
		~StackX(){
			delete[] data;
		}
		
		void push(T v){
			if(sp < mx){
				data[sp] = v; sp++;
			} else { std::cout << "Error: Stack full\n";}
		}
		
		T pop(){
			if(sp > 0){
				sp--;
				return data[sp];
			} else { std::cout << "Error: Stack empty\n"; return 0;}
		}
		
		T top(){
			return data[sp-1];
		}
		
		void dump(){
			for(int i = 0; i < sp; i++)
				std::cout << i << ": " << static_cast<int>(data[i]) << "\n";
		}
		
		
};

#endif