#include <iostream>
#include "SinX.h"
#include <windows.h>
#include <iostream>
#include <ctime>
#include "gtest/gtest.h"
#include <cmath>

int dRand(){
	return 500 - std::rand() % 1000;
} 


void RandomArg()
{
	int Arg;
	Arg = dRand();
	std::cout << "Sin(" << Arg << ") = " << SinX(Arg) << std::endl << std::endl;
}


TEST(testRandomArg, testSinX){
	const double PI = 3.1415926535;
	int Arg;
	Arg = dRand();
	std::cout << std::endl << "Arg = " << Arg << std::endl << std::endl;
	ASSERT_NEAR(SinX(Arg), sin((Arg % 360) * PI / 180), 0.0001) << "Îøèáêà";
}	

int main(int argc, char** argv)
{
	
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	std::cout << "Tests" << std::endl << std::endl;
	RandomArg();
	
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}