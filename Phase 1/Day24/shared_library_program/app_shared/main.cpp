#include <iostream>
#include "./../math_util_api/math_utils.h"

int main(){
	int a = 5 , b = 3;
	std::cout << "sum: " << add(a,b) <<std::endl;
	std::cout << "Difference: " << subtract(a,b) << std::endl;
	return 0;
}
