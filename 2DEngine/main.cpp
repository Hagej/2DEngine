#include <iostream>
#include <GLFW/glfw3.h>


int main() {
	
	if (!glfwInit())
		std::cout << "Error" << std::endl;
	else
		std::cout << "Success!" << std::endl;


	system("PAUSE");


	return 0;


}