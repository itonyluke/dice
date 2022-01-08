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

// structure to hold sums
typedef struct s_s
{
	float two;
	float three;
	float four;
	float five;
	float six;
	float seven;
	float eight;
	float nine;
	float ten;
	float eleven;
	float twelve;
}				t_s;

// initializes variables to zero
static void initialize_to_zero(t_s &s, unsigned int (&possibility)[36])
{
	s.two = 0;
	s.three = 0;
	s.four = 0;
	s.five = 0;
	s.six = 0;
	s.seven = 0;
	s.eight = 0;
	s.nine = 0;
	s.ten = 0;
	s.eleven = 0;
	s.twelve = 0;

	for (unsigned int i = 0; i < 36; i++)
		possibility[i] = 0;
}

// calculates sample space
static void calculate_sample_space(unsigned int (&possibility)[36])
{
	unsigned int i = 0;
	unsigned int j = 1;
	unsigned int k = 1;

	while (i < 36)
	{
		while (j <= 6)
		{
			k = 1;
			while (k <= 6)
			{
				possibility[i] = j + k;
				k++;
				i++;
			}
			j++;
		}
	}
}

// calculates how many sums are there
static void how_many_sums_are_there(t_s &s, unsigned int (&possibility)[36])
{
	for (unsigned int i = 0; i < 36; i++)
	{
		if (possibility[i] == 2)
			s.two++;
		else if (possibility[i] == 3)
			s.three++;
		else if (possibility[i] == 4)
			s.four++;
		else if (possibility[i] == 5)
			s.five++;
		else if (possibility[i] == 6)
			s.six++;
		else if (possibility[i] == 7)
			s.seven++;
		else if (possibility[i] == 8)
			s.eight++;
		else if (possibility[i] == 9)
			s.nine++;
		else if (possibility[i] == 10)
			s.ten++;
		else if (possibility[i] == 11)
			s.eleven++;
		else if (possibility[i] == 12)
			s.twelve++;
	}
}

// outputs the results
static void output_results(float (&probability)[11])
{
	unsigned int l = 0;

	std::cout << "Roll a ...\t";
	std::cout << "Probalility" << std::endl;
	for (unsigned int i = 2; i <= 12; i++)
	{
		std::cout << std::setw(10) << i << "\t";
		while (l < 11)
		{
			std::cout << std::setw(10) << probability[l] << " %" << std::endl;
			l++;
			break ;
		}
	}
}

int main(void)
{
	t_s				s;
	float			probability[11];
	float			thirty_six = 36;
	unsigned int	possibility[36];

	initialize_to_zero(s, possibility);
	calculate_sample_space(possibility);
	how_many_sums_are_there(s, possibility);

	probability[0] = (s.two / thirty_six) * 100;
	probability[1] = (s.three / thirty_six) * 100;
	probability[2] = (s.four / thirty_six) * 100;
	probability[3] = (s.five / thirty_six) * 100;
	probability[4] = (s.six / thirty_six) * 100;
	probability[5] = (s.seven / thirty_six) * 100;
	probability[6] = (s.eight / thirty_six) * 100;
	probability[7] = (s.nine / thirty_six) * 100;
	probability[8] = (s.ten / thirty_six) * 100;
	probability[9] = (s.eleven / thirty_six) * 100;
	probability[10] = (s.twelve / thirty_six) * 100;

	output_results(probability);

	return (0);
}
