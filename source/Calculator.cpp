#include <iostream>

template <typename A, typename B, typename C, typename D>
class CalculatorBase
{
	public: 
	CalculatorBase() { }
	~CalculatorBase() { }

	A add(A a, A b);
	
	
	B sub(B a, B b);
	
	
	C mul(C a, C b);


	D div(D a, D b);

};

template<typename A, typename B, typename C, typename D>
A CalculatorBase<A, B, C, D>::add(A a, A b)
{
	return a + b;
}


template<typename A, typename B, typename C, typename D>
B CalculatorBase<A, B, C, D>::sub(B a, B b)
{
	return a - b;
}

template<typename A, typename B, typename C, typename D>
C CalculatorBase<A, B, C, D>::mul(C a, C b)
{
	return a * b;
}



template<typename A, typename B, typename C, typename D>
D CalculatorBase<A, B, C, D>::div(D a, D b)
{
	return a/b;
}


int main(int argc, char **argv)
{

	CalculatorBase<int, int, double, double> calc;

	std::cout << calc.add(10, 10) << std::endl;
	std::cout << calc.sub(10, 10) << std::endl;
	std::cout << calc.mul(10, 10) << std::endl;
	std::cout << calc.div(10, 10) << std::endl;	
	return 0;
}
