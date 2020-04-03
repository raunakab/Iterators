#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>



class A {
	public:
		A();
		A(A const & other);
		~A();
};

A::A() { printf("dflt.\n"); return; }
A::A(A const & other) { printf("copy.\n"); return; }
A::~A() { printf("dstr.\n"); return; }



template<class T> T other() {
	return *(new T());
}

template<class T> T something(T const & t) {
	printf("Instantiating a new object, T ret, by copying T const & t.\n");
	T * const ret = new T(t);

	printf("Returning the new object, T ret.\n");
	return *ret;
}



int main() {
//	printf("Instantiating a default object, A a.\n");
//	A a;

//	printf("Instantiating a new object, A b, by using the result of calling something<A>(a).\n");
//	A b(something<A>(a));

	A a(other<A>());

	return 0;
}
