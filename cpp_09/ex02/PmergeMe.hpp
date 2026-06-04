#pragma once
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sys/time.h>
#include <deque>
#include <vector>
#include <algorithm>
#include "./colors.hpp"

struct Core {
	std::vector<int>	vec;
	std::deque<int>		deq;
};

struct s_pairs
{
	int big;
	int small;
};



int parse(Core& C, std::string raw);
std::string multiple_args(int ac,char ** av);

void process_vec(std::vector<int> vec);
void process_deq(std::deque<int> vec);

std::vector<int> FJ(std::vector<int> vec);
std::deque<int> FJ(std::deque<int> vec);

bool a_inf_to_b(int a,int b);
bool a_sup_to_b(int a,int b);
int biggest (int a, int b);
