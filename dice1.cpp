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
#include <map>
#include <cmath>

//// calculates sample space
static void calculate_sample_space(std::vector<float> &options, std::multimap<float, float> &possibilities, float &sample_space, float &number_of_sides)
{
	float i = 0;
	float k = 0;
	float j = 0;
	float options_end = *(options.end() - 1);
	std::vector<float> options_copy = options;

	while (j <= sample_space)
	{
		while (k < number_of_sides)
		{
			while (i < number_of_sides)
			{
				if ((*options_copy.begin() + i) == options_end)
				{
					possibilities.insert(std::pair<float, float>(*options_copy.begin() + i, *options_copy.begin() + i));
					return ;
				}
				possibilities.insert(std::pair<float, float>(*options_copy.begin() + i, *options_copy.begin() + i));
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

void prompt_usage()
{
	std::cout << "Usage:\n./a.out <number of dice> <number of sides>" << std::endl;
	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		unsigned int				ex = 0;
		float						sample_space = 0, number_of_sides = 0, number_of_dice = 0;
		std::vector<float>			options, options_copy;
		std::multimap<float, float>	possibilities;

		try
		{
			number_of_dice = std::stof(argv[1]);
			number_of_sides = std::stof(argv[2]);
		}
		catch (const std::invalid_argument &exc)
		{
			ex++;
			std::cout << "#" << ex << " " << exc.what() << std::endl;
		}
		if (number_of_dice == 3 && number_of_sides == 2)
		{
			std::cout << "for some reason I get a segmentation fault in this case" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (number_of_dice == 3 && number_of_sides == 3)
		{
			std::cout << "for some reason I abort in this case" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (number_of_dice == 12 && number_of_sides == 12)
		{
			std::cout << "for some reason I get a segmentation fault in this case" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (number_of_dice == 11 && number_of_sides == 13)
		{
			std::cout << "for some reason I get a segmentation fault in this case" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (number_of_dice == 12 && number_of_sides == 13)
		{
			std::cout << "for some reason I get a segmentation fault in this case" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (number_of_dice == 13 && number_of_sides == 13)
		{
			std::cout << "for some reason I get a segmentation fault in this case" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (number_of_dice == 13 && number_of_sides == 12)
		{
			std::cout << "for some reason I get a segmentation fault in this case" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (number_of_dice == 14 && number_of_sides == 13)
		{
			std::cout << "for some reason I get a segmentation fault in this case" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (number_of_dice == 13 && number_of_sides == 14)
		{
			std::cout << "for some reason I get a segmentation fault in this case" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (number_of_dice > 16 && number_of_sides > 16)
		{
			std::cout << "that is too much even for me" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (number_of_dice == 16 && number_of_sides > 16)
		{
			std::cout << "that is too much even for me" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (number_of_dice > 16 && number_of_sides == 16)
		{
			std::cout << "that is too much even for me" << std::endl;
			return (EXIT_FAILURE);
		}
		sample_space = pow(number_of_sides, number_of_dice);
		if (std::isinf(sample_space))
		{
			std::cout << "that is too much even for me" << std::endl;
			exit(EXIT_SUCCESS);
		}
		for (float i = 1; i <= (number_of_sides * number_of_dice); i++)
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
		options_copy = options;
//		std::cout << "options.size() =\t"<< options_copy.size() << std::endl;
		for (std::vector<float>::iterator it = options_copy.begin(); it < options_copy.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		calculate_sample_space(options_copy, possibilities, sample_space, number_of_sides);

		std::vector<float>::iterator it = options.begin();
		std::cout << "Roll a ...\t";
		std::cout << "Probability" << std::endl;
		while (it != options.end())
		{
			if (*it == 0)
				exit(EXIT_FAILURE);
			std::cout << std::setw(10) << *it << "\t" << (possibilities.count(*it) / sample_space) * 100 << " %" << std::endl;
			it++;
		}
	}
	else
		prompt_usage();

	return (0);
}
