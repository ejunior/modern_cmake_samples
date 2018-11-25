//
// Created by José Edmilson V. dos Santos Jr. on 2018-11-05.
//
#include <fstream>
#include <iostream>

int ___runmefirst(){
    std::cout << "initializing...\n";
    auto input = new std::ifstream("sample_input2.txt");
    std::cin.rdbuf(input->rdbuf());

    auto output = new std::ofstream("out.txt");
    std::cout.rdbuf(output->rdbuf());

    return 0;
}

int __var = ___runmefirst();

#include "main.cpp"

int ___runme4last(){
    std::cout << "closing...\n";
    return 0;
}
int ___out = ___runme4last();