#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;

int main()
{
    string inputFileName = "./data.csv";
    string outputFileName= "./result.txt";
    size_t n = 0;
    size_t S = 0;
    float rate;
    float V;
    vector <float> v1;
    vector <float> v2;


    if (!ImportVectors(inputFileName, n, S, v1, v2))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else{
         rate = RateReturn(n, v1, v2);
                       cout<< "Rate of return of the portfolio: "<< rate << endl;
         V=FinalValue(rate,S);
                       cout<<"V: "<<V<<endl;

    }
    if(!ExportResult(outputFileName,S,n,v1,v2,rate,V)){
        cerr<<"Something goes wrong with export"<<endl;
        return -1;
    }
    else{
        cout<<"Import successful in result.txt"<<endl;
    }
    }
