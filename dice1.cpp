//Copyright 2022 Anton Pavlyukevich.

//dice is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//dice is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with dice.  If not, see <https://www.gnu.org/licenses/>.

//
// Created by pavlyukevich.anton@gmail.com on 08.01.22
//

// built and tested on Darwin Kernel Version 18.7.0: Tue Jun 22 19:37:08 PDT 2021; root:xnu-4903.278.70~1/RELEASE_X86_64 x86_64

#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>

//// structure to hold sums
//typedef struct s_s
//{
//	float two;
//	float three;
//	float four;
//	float five;
//	float six;
//	float seven;
//	float eight;
//	float nine;
//	float ten;
//	float eleven;
//	float twelve;
//}				t_s;
//
//// initializes variables to zero
//static void initialize_to_zero(t_s &s, unsigned int sample_space)
//{
//	unsigned int possibility[sample_space];
//	s.two = 0;
//	s.three = 0;
//	s.four = 0;
//	s.five = 0;
//	s.six = 0;
//	s.seven = 0;
//	s.eight = 0;
//	s.nine = 0;
//	s.ten = 0;
//	s.eleven = 0;
//	s.twelve = 0;
//
//	for (unsigned int i = 0; i < 36; i++)
//		possibility[i] = 0;
//}
//

//// calculates sample space
static void calculate_sample_space(std::vector<unsigned int> &possibilities, std::vector<unsigned int> &options, unsigned int &number_of_dice, unsigned long long &sample_space, unsigned int &number_of_sides)
{
	unsigned int i = 0;
	unsigned int j = 1;
	unsigned int hold = 0;
	std::vector<unsigned int> arr;
	(void)possibilities;
	(void)sample_space;
	(void)options;


	unsigned int a = 0;
	if (number_of_dice == 1)
		arr.push_back(a);
	else if (number_of_dice > 1)
	{
		a = 1;
		while (a <= number_of_dice * number_of_sides - 1)
		{
			arr.push_back(a);
			a++;
		}
		arr.push_back(a);
	}
//	a = 0;
//	for (std::vector<unsigned int>::iterator arr_it= arr.begin(); arr_it< arr.end(); ++arr_it)
//	{
//		std::cout << "arr[" << a << "] = " << *arr_it<< " " << std::endl;
//		a++;
//	}
	std::vector<unsigned int>::iterator arr_it = arr.begin();
	while (i < sample_space)
	{
		if (i < 7)
			arr_it = arr.begin();
		else
		{
////			a++;
////			std::cout << "arr.begin() = " << *arr.begin() << std::endl;
			arr.erase(arr.begin());
//////			std::cout << "arr.begin() = " << *arr.begin() << std::endl;
//////			std::cout << "arr.end() = " << *arr.end() << std::endl;
			a++;
			arr.push_back(a);
			arr_it = arr.begin();
//			arr_it = arr.begin();
//			a = 0;
//			for (std::vector<unsigned int>::iterator arr_it= arr.begin(); arr_it< arr.end(); ++arr_it)
//			{
//				std::cout << "arr[" << a << "] = " << *arr_it<< " " << std::endl;
//				a++;
//				}
//			exit(EXIT_SUCCESS);
		}
		while (arr_it < arr.end())
		{
			while (*arr_it <= number_of_sides)
			{
				if (number_of_dice == 1)
					j = 1;
				else
					j = number_of_dice - 1;
				while (j < number_of_sides + number_of_dice - 1)
				{
					try
					{
						hold = j + *arr_it;
						possibilities.push_back(hold);
					}
					catch (std::out_of_range)
					{
						std::cout << "oops" << std::endl;
						exit(EXIT_FAILURE);
					}
					try
					{
						std::cout << possibilities.at(i) << " ";
					}
					catch (std::out_of_range)
					{
						std::cout << "oops" << std::endl;
						exit(EXIT_FAILURE);
					}
					j++;
					i++;
				}
				if (number_of_dice == 1)
				{
					std::cout << std::endl;
					break;
				}
				arr_it++;
				std::cout << std::endl;
			}
			arr_it++;
		}
		arr_it++;
	}

	//// calculates how many sums are there
	//static void how_many_sums_are_there(t_s &s, unsigned int sample_space)
	//{
	//	unsigned int possibility[sample_space];
	//	for (unsigned int i = 0; i < 36; i++)
	//	{
	//		if (possibility[i] == 2)
	//			s.two++;
	//		else if (possibility[i] == 3)
	//			s.three++;
	//		else if (possibility[i] == 4)
	//			s.four++;
	//		else if (possibility[i] == 5)
	//			s.five++;
	//		else if (possibility[i] == 6)
	//			s.six++;
	//		else if (possibility[i] == 7)
	//			s.seven++;
	//		else if (possibility[i] == 8)
	//			s.eight++;
	//		else if (possibility[i] == 9)
	//			s.nine++;
	//		else if (possibility[i] == 10)
	//			s.ten++;
	//		else if (possibility[i] == 11)
	//			s.eleven++;
	//		else if (possibility[i] == 12)
	//			s.twelve++;
	//	}
	//}
	//
	//// outputs the results
	//static void output_results(unsigned int probability_size)
	//{
	//	float probability[(unsigned int)probability_size];
	//	unsigned int l = 0;
	//
	//	std::cout << "Roll a ...\t";
	//	std::cout << "Probalility" << std::endl;
	//	for (unsigned int i = 2; i <= 12; i++)
	//	{
	//		std::cout << std::setw(10) << i << "\t";
	//		while (l < probability_size)
	//		{
	//			std::cout << std::setw(10) << probability[l] << " %" << std::endl;
	//			l++;
	//			break ;
	//		}
	//	}
	//}

	//
}
void prompt_usage()
{
	std::cout << "Usage:\n./a.out <number of dice> <number of sides>" << std::endl;
	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	unsigned int ex = 0;
	if (argc == 3)
	{
		(void)argv;
		std::vector<unsigned int> options;
		std::vector<unsigned int> possibilities;
		unsigned long long int		sample_space;
		unsigned int				number_of_sides, number_of_dice, probability_size;

		try
		{
			number_of_dice = std::stoi(argv[1]);
			number_of_sides = std::stoi(argv[2]);
		}
		catch (const std::invalid_argument &exc)
		{
			ex++;
			std::cout << "#" << ex << " " << exc.what() << std::endl;
		}
		sample_space = pow(number_of_sides, number_of_dice);
		if (sample_space == 0)
		{
			std::cout << "that is too much even for me" << std::endl;
			exit(EXIT_SUCCESS);
		}
		std::cout << "number_of_dice =\t"<< number_of_dice << "\n" << "number_of_sides =\t"<< number_of_sides << std::endl;
		probability_size = number_of_dice * number_of_sides - 1;
		std::cout << "probability_size =\t"<< probability_size << std::endl;
		std::cout << "sample_space =\t\t"<< sample_space << std::endl;
		for (unsigned int i = 1; i <= (number_of_sides * number_of_dice); i++)
		{
			if (number_of_dice == 1)
				options.push_back(i);
			else if (i == 1)
			{
				i = number_of_dice;
				options.push_back(i);
			}
			else
				options.push_back(i);
		}
		std::cout << "options.size() =\t"<< options.size() << std::endl;
		for (std::vector<unsigned int>::iterator it = options.begin(); it < options.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		calculate_sample_space(possibilities, options, number_of_dice, sample_space, number_of_sides);
	}
	else
		prompt_usage();

	return (0);
}
