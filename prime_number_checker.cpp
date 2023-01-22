#include<iostream>
#include<cmath>

bool is_prime_all(int);
bool is_prime_half(int);
bool is_prime_square_root(int);



int main() {

	float numbers_amount_all = 0;
	float numbers_amount_half = 0;
	float numbers_amount_square_root = 0;
	int numbers_to_check = 10000;

	// std::cout << numbers_amount << "\n" << &numbers_amount << "\n" << *numbers_amount_ptr << "\n" << numbers_amount_ptr << "\n";

	int input = 0;

	while (input < 1 || input > numbers_to_check)
	{
		std::cout << "Provide a number between 1 - " << numbers_to_check << " to see if it's a prime number: ";
		std::cin >> input;

		if (input > 0 && input <= numbers_to_check)
		{
			break;
		}
		
		std::cout << "Error: the input must be between 1 and " << numbers_to_check << "!" << std::endl;
	}

	// std::cout << "got through";

	if (is_prime_all(input))
	{
		std::cout << "Number " << input << " is a prime number! :)))" <<std::endl;

	}

	else
	{

		std::cout << "Number " << input << " is not a prime number :(" << std::endl;
	}

	for (int i = 0; i < numbers_to_check; i++)
	{
		if (is_prime_all(i))
		{
			std::cout << i << " ";
			numbers_amount_all++;
		}
	}
	std::cout << std::endl << "Amount of prime numbers: " << numbers_amount_all
		<< ", which is " << (numbers_amount_all / numbers_to_check * 100) << "% of all checked numbers." << std::endl;


	for (int i = 0; i < numbers_to_check; i++)
	{
		if (is_prime_half(i))
		{
			std::cout << i << " ";
			numbers_amount_half++;
		}
	}
	std::cout << std::endl << "Amount of prime numbers: " << numbers_amount_half
		<< ", which is " << (numbers_amount_half / numbers_to_check * 100) << "% of all checked numbers." << std::endl;


	for (int i = 0; i < numbers_to_check; i++)
	{
		if (is_prime_square_root(i))
		{
			std::cout << i << " ";
			numbers_amount_square_root++;
		}
	}
	std::cout << std::endl << "Amount of prime numbers: " << numbers_amount_square_root
		<< ", which is " << (numbers_amount_square_root / numbers_to_check * 100) << "% of all checked numbers." << std::endl;



	return 0;
}





bool is_prime_all(int num_f) { // test by dividing with every number from 2 to (num_f - 1)



	if (num_f > 1)
	{
		for (int i = 2; i < num_f; i++)
		{
			if (num_f % i == 0)
			{
				return false;
			}

		}
		return true;
	}


	return false;
}





bool is_prime_half(int num_f) { // test by dividing with every number from 2 to (num_f / 2)
								// num_f is X * Y, and if X is more than (num_f / 2), Y must be less than 2, which wouldn't affect num_f being a prime number

	if (num_f > 1)
	{
		for (int i = 2; i <= (num_f/2); i++)
		{
			if (num_f % i == 0)
			{
				return false;
			}

		}
		return true;
	}


	return false;
}





bool is_prime_square_root(int num_f) { // test by dividing with every number from 2 to (square root of num_f)
										// num_f is A * B, so either a or be must be less or equal to the square root of num_f
										// because sqrt(num_f) * sqrt(num_f) = num_f
										// thus givin A values only up to sqrt(num_f) gives every possible value of B that matters (meaning fractions don't matter either way)
										// MOST EFFICIENT BECAUSE CHECKED AGAINST LEAST AMOUNT OF VALUES

	if (num_f > 1)
	{
		for (int i = 2; i <= sqrt(num_f); i++)
		{
			if (num_f % i == 0)
			{
				return false;
			}

		}
		return true;
	}


	return false;
}