//Copyright 2022 Anton Pavlyukevich.

//dice is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//any later version.
//
//dice is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with dice.  If not, see <https://www.gnu.org/licenses/>.

//
// Created by pavlyukevich.anton@gmail.com on 15.01.22
//

// built and tested on Darwin Kernel Version 18.7.0: Tue Jun 22 19:37:08 PDT 2021; root:xnu-4903.278.70~1/RELEASE_X86_64 x86_64

#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <map>

#define YELLOW "\033[33m"
#define B_RED "\033[91m"
#define DARK_GREY "\033[90m"
#define DEFAULT "\033[0m"

//calculate permutations
static void calculate_permutations(std::vector<double> &results_copy, std::multimap<double, double> &permutations, const double &sample_space, const double &number_of_sides)
{
	double i = 0;
	double k = 0;
	double j = 0;
	const double results_end = *(results_copy.end() - 1);
	std::vector<double> results_copy_copy = results_copy;

	while (j <= sample_space)
	{
		while (k < number_of_sides)
		{
			while (i < number_of_sides)
			{
				if ((*results_copy_copy.begin() + i) == results_end)
				{
					permutations.insert(std::pair<double, double>(*results_copy_copy.begin() + i, *results_copy_copy.begin() + i));
					return ;
				}
				permutations.insert(std::pair<double, double>(*results_copy_copy.begin() + i, *results_copy_copy.begin() + i));
				i++;
			}
			i = 0;
			results_copy_copy.erase(results_copy_copy.begin());
			k++;
		}
		results_copy_copy = results_copy;
		results_copy_copy.erase(results_copy.begin());
		i = 0;
		k = 0;
		j++;
	}
}

//check sample_space for infinity
static void	check_sample_space_for_infinity(const double &sample_space)
{
	if (std::isinf(sample_space))
	{
		std::cout << B_RED << "that is too much even for me" << DEFAULT << std::endl;
		exit(EXIT_SUCCESS);
	}
}

//calculate results
static void calculate_results(std::vector<double> &results, const double &number_of_dice, const double &number_of_sides)
{
	for (double i = 1; i <= (number_of_dice * number_of_sides); i++)
	{
		if (number_of_dice == 1)
			results.push_back(i);
		else if (i == 1)
		{
			i = number_of_dice;
			results.push_back(i);
		}
		else
			results.push_back(i);
	}
}

static void prompt_number_of_dice_and_sides(const double &number_of_dice, const double &number_of_sides)
{
	if (number_of_dice == 1)
		std::cout << DARK_GREY << number_of_dice << " die" << DEFAULT << std::endl;
	else
		std::cout << DARK_GREY << number_of_dice << " dice" << DEFAULT << std::endl;
	if (number_of_sides == 1)
		std::cout << DARK_GREY << number_of_sides << " side" << DEFAULT << std::endl;
	else
		std::cout << DARK_GREY << number_of_sides << " sides" << DEFAULT << std::endl;
}

static void exit_for_some_cases(const double &number_of_dice, const double &number_of_sides)
{
	if ((number_of_dice == 5 && number_of_sides == 14)
		|| (number_of_dice == 5 && number_of_sides == 15)
		|| (number_of_dice == 5 && number_of_sides == 16)
		|| (number_of_dice == 5 && number_of_sides == 17)
		|| (number_of_dice == 5 && number_of_sides == 18)
		|| (number_of_dice == 5 && number_of_sides == 19)
		|| (number_of_dice == 6 && number_of_sides == 12)
		|| (number_of_dice == 6 && number_of_sides == 13)
		|| (number_of_dice == 6 && number_of_sides == 14)
		|| (number_of_dice == 6 && number_of_sides == 15)
		|| (number_of_dice == 6 && number_of_sides == 16)
		|| (number_of_dice == 7 && number_of_sides == 11)
		|| (number_of_dice == 7 && number_of_sides == 12)
		|| (number_of_dice == 7 && number_of_sides == 13)
		|| (number_of_dice == 7 && number_of_sides == 14)
		|| (number_of_dice == 8 && number_of_sides == 9)
		|| (number_of_dice == 8 && number_of_sides == 10)
		|| (number_of_dice == 8 && number_of_sides == 11)
		|| (number_of_dice == 8 && number_of_sides == 12)
		|| (number_of_dice == 8 && number_of_sides == 17)
		|| (number_of_dice == 8 && number_of_sides == 18)
		|| (number_of_dice == 8 && number_of_sides == 19)
		|| (number_of_dice == 8 && number_of_sides == 20)
		|| (number_of_dice == 8 && number_of_sides == 21)
		|| (number_of_dice == 8 && number_of_sides == 22)
		|| (number_of_dice == 8 && number_of_sides == 23)
		|| (number_of_dice == 8 && number_of_sides == 24)
		|| (number_of_dice == 9 && number_of_sides == 5)
		|| (number_of_dice == 9 && number_of_sides == 9)
		|| (number_of_dice == 9 && number_of_sides == 10)
		|| (number_of_dice == 9 && number_of_sides == 11)
		|| (number_of_dice == 9 && number_of_sides == 12)
		|| (number_of_dice == 9 && number_of_sides == 16)
		|| (number_of_dice == 9 && number_of_sides == 17)
		|| (number_of_dice == 9 && number_of_sides == 18)
		|| (number_of_dice == 9 && number_of_sides == 19)
		|| (number_of_dice == 9 && number_of_sides == 20)
		|| (number_of_dice == 9 && number_of_sides == 21)
		|| (number_of_dice == 9 && number_of_sides == 22)
		|| (number_of_dice == 10 && number_of_sides == 8)
		|| (number_of_dice == 10 && number_of_sides == 9)
		|| (number_of_dice == 10 && number_of_sides == 10)
		|| (number_of_dice == 10 && number_of_sides == 14)
		|| (number_of_dice == 10 && number_of_sides == 15)
		|| (number_of_dice == 10 && number_of_sides == 16)
		|| (number_of_dice == 10 && number_of_sides == 17)
		|| (number_of_dice == 10 && number_of_sides == 18)
		|| (number_of_dice == 10 && number_of_sides == 19)
		|| (number_of_dice == 10 && number_of_sides == 20)
		|| (number_of_dice == 11 && number_of_sides == 7)
		|| (number_of_dice == 11 && number_of_sides == 8)
		|| (number_of_dice == 11 && number_of_sides == 9)
		|| (number_of_dice == 11 && number_of_sides == 10)
		|| (number_of_dice == 11 && number_of_sides == 13)
		|| (number_of_dice == 11 && number_of_sides == 14)
		|| (number_of_dice == 11 && number_of_sides == 15)
		|| (number_of_dice == 11 && number_of_sides == 16)
		|| (number_of_dice == 11 && number_of_sides == 17)
		|| (number_of_dice == 11 && number_of_sides == 18)
		|| (number_of_dice == 12 && number_of_sides == 7)
		|| (number_of_dice == 12 && number_of_sides == 8)
		|| (number_of_dice == 12 && number_of_sides == 9)
		|| (number_of_dice == 12 && number_of_sides == 12)
		|| (number_of_dice == 12 && number_of_sides == 13)
		|| (number_of_dice == 12 && number_of_sides == 14)
		|| (number_of_dice == 12 && number_of_sides == 15)
		|| (number_of_dice == 12 && number_of_sides == 16)
		|| (number_of_dice == 13 && number_of_sides == 6)
		|| (number_of_dice == 13 && number_of_sides == 7)
		|| (number_of_dice == 13 && number_of_sides == 8)
		|| (number_of_dice == 13 && number_of_sides == 11)
		|| (number_of_dice == 13 && number_of_sides == 12)
		|| (number_of_dice == 13 && number_of_sides == 13)
		|| (number_of_dice == 13 && number_of_sides == 14)
		|| (number_of_dice == 13 && number_of_sides == 15)
		|| (number_of_dice == 14 && number_of_sides == 6)
		|| (number_of_dice == 14 && number_of_sides == 7)
		|| (number_of_dice == 14 && number_of_sides == 11)
		|| (number_of_dice == 14 && number_of_sides == 12)
		|| (number_of_dice == 14 && number_of_sides == 13)
		|| (number_of_dice == 14 && number_of_sides == 14)
		|| (number_of_dice == 15 && number_of_sides == 6)
		|| (number_of_dice == 15 && number_of_sides == 7)
		|| (number_of_dice == 15 && number_of_sides == 10)
		|| (number_of_dice == 15 && number_of_sides == 11)
		|| (number_of_dice == 15 && number_of_sides == 12)
		|| (number_of_dice == 15 && number_of_sides == 13)
		|| (number_of_dice == 16 && number_of_sides == 5)
		|| (number_of_dice == 16 && number_of_sides == 6)
		|| (number_of_dice == 16 && number_of_sides == 9)
		|| (number_of_dice == 16 && number_of_sides == 10)
		|| (number_of_dice == 16 && number_of_sides == 11)
		|| (number_of_dice == 16 && number_of_sides == 12)
		|| (number_of_dice == 17 && number_of_sides == 5)
		|| (number_of_dice == 17 && number_of_sides == 6)
		|| (number_of_dice == 17 && number_of_sides == 9)
		|| (number_of_dice == 17 && number_of_sides == 10)
		|| (number_of_dice == 17 && number_of_sides == 11)
		|| (number_of_dice == 17 && number_of_sides == 12)
		|| (number_of_dice == 18 && number_of_sides == 5)
		|| (number_of_dice == 18 && number_of_sides == 6)
		|| (number_of_dice == 18 && number_of_sides == 9)
		|| (number_of_dice == 18 && number_of_sides == 10)
		|| (number_of_dice == 18 && number_of_sides == 11)
		|| (number_of_dice == 19 && number_of_sides == 5)
		|| (number_of_dice == 19 && number_of_sides == 8)
		|| (number_of_dice == 19 && number_of_sides == 9)
		|| (number_of_dice == 19 && number_of_sides == 10)
		|| (number_of_dice == 19 && number_of_sides == 11)
		|| (number_of_dice == 20 && number_of_sides == 5)
		|| (number_of_dice == 20 && number_of_sides == 8)
		|| (number_of_dice == 20 && number_of_sides == 9)
		|| (number_of_dice == 20 && number_of_sides == 10))
	{
		std::cout << YELLOW << "for some reason this case does not work" << DEFAULT << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (number_of_dice == 0 || number_of_sides == 0)
	{
		std::cout << YELLOW << "well, one of the arguments is zero, what do you expect?" << DEFAULT << std::endl;
		exit(EXIT_SUCCESS);
	}
}

//convert arguments to double
static void convert_arguments_to_double(const char **argv, double &number_of_dice, double &number_of_sides)
{
	try
	{
		number_of_dice = std::stod(argv[1]);
		number_of_sides = std::stod(argv[2]);
	}
	catch (const std::invalid_argument &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

//output probabilities
static void output_probabilities(std::vector<double> &results, const std::multimap<double, double>	&permutations, const double &sample_space)
{
	std::vector<double>::iterator it = results.begin();

	std::cout << "Roll a ...\t";
	std::cout << "Probability" << std::endl;
	while (it != results.end())
	{
		if (*it == 0)
		{
			std::cout << YELLOW << "something went wrong" << DEFAULT << std::endl;
			exit(EXIT_SUCCESS);
		}
		std::cout << std::setw(10) << *it << "\t" << (permutations.count(*it) / sample_space) * 100 << " %" << std::endl;
		it++;
	}
}

//prompt usage
void prompt_usage()
{
	std::cout << YELLOW << "Usage:\n./a.out <number of dice> <number of sides>" << DEFAULT << std::endl;
	exit(EXIT_SUCCESS);
}

int main(const int argc, const char **argv)
{
	if (argc == 3)
	{
		double							sample_space = 0, number_of_sides = 0, number_of_dice = 0;
		std::vector<double>				results, results_copy;
		std::multimap<double, double>	permutations;

		convert_arguments_to_double(argv, number_of_dice, number_of_sides);
		prompt_number_of_dice_and_sides(number_of_dice, number_of_sides);
		exit_for_some_cases(number_of_dice, number_of_sides);
		sample_space = pow(number_of_sides, number_of_dice);
		check_sample_space_for_infinity(sample_space);
		calculate_results(results, number_of_dice, number_of_sides);
		results_copy = results;
		calculate_permutations(results_copy, permutations, sample_space, number_of_sides);
		output_probabilities(results, permutations, sample_space);
	}
	else
		prompt_usage();
	return (0);
}



