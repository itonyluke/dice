//Copyright 2022 Anton Pavliukevich.

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
// Created by pavliukevich.anton@gmail.com on 15.01.22
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <limits>

#define YELLOW    "\033[33m"
#define B_RED     "\033[91m"
#define DARK_GREY "\033[90m"
#define DEFAULT   "\033[0m"

static void check_sample_space_overflow(double sample_space)
{
	if (sample_space > (double)std::numeric_limits<long long>::max())
	{
		std::cout << B_RED << "that is too much even for me" << DEFAULT << std::endl;
		exit(EXIT_SUCCESS);
	}
}

static void prompt_number_of_dice_and_sides(int number_of_dice, int number_of_sides)
{
	std::cout << DARK_GREY << number_of_dice << (number_of_dice == 1 ? " die"  : " dice") << DEFAULT << std::endl;
	std::cout << DARK_GREY << number_of_sides << (number_of_sides == 1 ? " side" : " sides") << DEFAULT << std::endl;
}

// Count the number of ways to roll each possible sum using dynamic programming.
// Starting from 1 way to reach sum 0, each die adds faces 1..number_of_sides.
static void calculate_permutations(int number_of_dice, int number_of_sides, std::map<int, long long> &permutations)
{
	const int max_sum = number_of_dice * number_of_sides;
	std::vector<long long> ways(max_sum + 1, 0);
	ways[0] = 1;

	for (int d = 0; d < number_of_dice; d++)
	{
		std::vector<long long> next(max_sum + 1, 0);
		for (int s = 0; s <= max_sum; s++)
		{
			if (ways[s] == 0)
				continue;
			for (int face = 1; face <= number_of_sides; face++)
			{
				if (s + face <= max_sum)
					next[s + face] += ways[s];
			}
		}
		ways = next;
	}

	for (int sum = number_of_dice; sum <= max_sum; sum++)
		permutations[sum] = ways[sum];
}

static void output_probabilities(const std::map<int, long long> &permutations, double sample_space)
{
	std::cout << "Roll a ...\t" << "Probability" << std::endl;
	std::cout << std::fixed << std::setprecision(4);
	for (const auto &entry : permutations)
		std::cout << std::setw(10) << entry.first << "\t" << (entry.second / sample_space) * 100 << " %" << std::endl;
}

static void prompt_usage()
{
	std::cout << YELLOW << "Usage:\n./a.out <number of dice> <number of sides>" << DEFAULT << std::endl;
	exit(EXIT_SUCCESS);
}

int main(const int argc, const char **argv)
{
	if (argc == 3)
	{
		int number_of_dice = 0, number_of_sides = 0;
		try
		{
			number_of_dice  = std::stoi(argv[1]);
			number_of_sides = std::stoi(argv[2]);
		}
		catch (const std::exception &ex)
		{
			std::cout << ex.what() << std::endl;
			return 1;
		}

		if (number_of_dice <= 0 || number_of_sides <= 0)
		{
			std::cout << YELLOW << "well, one of the arguments is zero or negative, what do you expect?" << DEFAULT << std::endl;
			return 0;
		}

		const double sample_space = std::pow((double)number_of_sides, (double)number_of_dice);
		check_sample_space_overflow(sample_space);

		prompt_number_of_dice_and_sides(number_of_dice, number_of_sides);

		std::map<int, long long> permutations;
		calculate_permutations(number_of_dice, number_of_sides, permutations);
		output_probabilities(permutations, sample_space);
	}
	else
		prompt_usage();
	return 0;
}
