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
static void calculate_sample_space(std::vector<unsigned int> &options, std::vector<unsigned int> &possibilities, unsigned long long &sample_space, unsigned int &number_of_sides)
{
	unsigned int i = 0;
	unsigned int k = 0;
	unsigned int j = 0;
	unsigned int options_end = *(options.end() - 1);

	std::vector<unsigned int> options_copy = options;
	while (j < sample_space)
	{
		while (k < number_of_sides)
		{
			while (i < number_of_sides)
			{
				if ((*options_copy.begin() + i) == options_end)
				{
					possibilities.push_back(*options_copy.begin() + i);
					return ;
				}
				possibilities.push_back(*options_copy.begin() + i);
				i++;
			}
//			std::cout << std::endl;
			i = 0;
			options_copy.erase(options_copy.begin());
			k++;
		}
		options_copy = options;
		options_copy.erase(options.begin());
		i = 0;
		k = 0;
		j++;
	}
}

//static void how_many_sums_are_there(std::vector<unsigned int> &possibilities, std::vector<unsigned int> &options, unsigned int &sample_space)
//{
//	for (unsigned int i = 0; i < sample_space; i++)
//	{
//		for (unsigned int j = 0; j < options.size(); j++)
//		{
//			if (possibilities.at(i) == options.at(j))
//
//
//		}
//	}
//}

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
		calculate_sample_space(options, possibilities, sample_space, number_of_sides);

		std::vector<unsigned int>::iterator it = possibilities.begin();
		while (it < possibilities.end())
		{
			std::cout.flush() << *it << " ";
			it++;
		}
	}
	else
		prompt_usage();

	return (0);
}
