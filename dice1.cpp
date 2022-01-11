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
//static void calculate_sample_space(unsigned int sample_space)
//{
//	unsigned int i = 0;
//	unsigned int j = 1;
//	unsigned int k = 1;
//	unsigned int possibility[sample_space];
//
//	while (i < 36)
//	{
//		while (j <= 6)
//		{
//			k = 1;
//			while (k <= 6)
//			{
//				possibility[i] = j + k;
//				k++;
//				i++;
//			}
//			j++;
//		}
//	}
//}
//
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
void prompt_usage()
{
	std::cout << "Usage:\n./a.out <number of dice> <number of sides>" << std::endl;
	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	unsigned int ex = 0;
	if (argc == 1)
	{
		(void) argv;
//		t_s				s;
//		float			probability[11];
//		float			sample_space = 36;
		std::vector<unsigned int> possibility;
//		unsigned int	possibility[(int)sample_space];


//		initialize_to_zero(s, sample_space);
//		std::cout << possibility.size() << std::endl;
//		std::cout << possibility.size() << std::endl;

		possibility.push_back(1);
		possibility.push_back(2);
		possibility.push_back(3);
		for (unsigned int i = 0; i < possibility.size(); i++)
			std::cout << possibility.at(i) << std::endl;
//		calculate_sample_space(sample_space);
//		how_many_sums_are_there(s, sample_space);
//
//		probability[0] = (s.two / sample_space) * 100;
//		probability[1] = (s.three / sample_space) * 100;
//		probability[2] = (s.four / sample_space) * 100;
//		probability[3] = (s.five / sample_space) * 100;
//		probability[4] = (s.six / sample_space) * 100;
//		probability[5] = (s.seven / sample_space) * 100;
//		probability[6] = (s.eight / sample_space) * 100;
//		probability[7] = (s.nine / sample_space) * 100;
//		probability[8] = (s.ten / sample_space) * 100;
//		probability[9] = (s.eleven / sample_space) * 100;
//		probability[10] = (s.twelve / sample_space) * 100;
//
//		output_results(11);
	}
	else if (argc == 3)
	{
		(void)argv;
		std::vector<unsigned int> options;
		unsigned long long			number_of_dice, number_of_sides, probability_size, sample_space;

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
	}
	else
		prompt_usage();

	return (0);
}
