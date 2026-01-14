#include "./easyfind.hpp"

int main(void)
{
	{
		int arr[] = {10, 30, 20, 50, 20};
		std::vector<int> nums(arr, arr + 5);
	
		std::vector<int>:: iterator it;
		it = easyfind(nums, 20);
		int id = std::distance(nums.begin(), it);
		std::cout << "Index: " << id << std::endl;
		std::cout << "Value: " << *it << std::endl;
		std::cout << std::endl << std::endl;
	}

	{
		char arr[] = {'a', 't', 'l', 'e', 'l'};
		std::vector<char> nums(arr, arr + 5);
	
		std::vector<char>:: iterator it;
		it = easyfind(nums, 'l');
		int id = std::distance(nums.begin(), it);
		std::cout << "Index: " << id << std::endl;
		std::cout << "Value: " << *it << std::endl;
		std::cout << std::endl << std::endl;
	}

	{
		float arr[] = {10.4, 30.5, 20.4, 50.8, 20.4};
		std::vector<float> nums(arr, arr + 5);
	
		std::vector<float>:: iterator it;
		try {
			it = easyfind(nums, 20.4);
			int id = std::distance(nums.begin(), it);
			std::cout << "Index: " << id << std::endl;
			std::cout << "Value: " << *it << std::endl;
			std::cout << std::endl << std::endl;
		} catch (const E_NotFound& e){
			std::cout << "Error: " << e.what() << std::endl;
			//crash because 4.2f != 4.2f, i would have to use std::find_if to ensure this work for floats and doubles
		}
	}
}
