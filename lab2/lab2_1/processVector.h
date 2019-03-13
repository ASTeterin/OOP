#pragma once
#include "pch.h"
#include <iostream>
#include <vector>


void ProcessVector(std::vector<double> &v);
void PrintVector(std::vector<double> const& v);
bool ReadVector(std::istream &inputStream, std::vector<double> &v);
double MinElementVector(std::vector<double> const& v);
void Sort(std::vector<double> &v);