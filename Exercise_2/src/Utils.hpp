#pragma once
#include "iostream"
#include <vector>
using namespace std;


bool ImportVectors(const string& inputFilePath,size_t& n,size_t& S,vector <float> &v1,vector <float> &v2);

float RateReturn(const size_t n, vector <float> &v1, vector <float> &v2);

float FinalValue(const float rate, const size_t S);

bool ExportResult(const string outputFilePath,
                  const size_t S,
                  const size_t n,
                  vector <float>  v1,
                  vector <float>  v2,
                  const float rate,
                  const float  V);
