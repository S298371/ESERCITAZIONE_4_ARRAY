#include "Utils.hpp"
#include "iostream"
#include "iomanip"
#include "fstream"
#include "sstream"
#include<vector>

using namespace std;

bool ImportVectors(const string& inputFilePath,size_t& n,size_t& S, vector <float> &v1, vector <float> &v2 ){

    // Open File
    int count=0;
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    //S
    string line;

    while (!file.eof())
    {
        getline(file, line);
        vector <string> elementi;
        stringstream ss (line);
        string elemento;
        while (getline(ss,elemento,';')){
            //cout << elemento<<endl;
            elementi.push_back(elemento);
        }
        istringstream convertS;
        convertS.str(elementi[1]);
        convertS >> S;
        break;
    }
    //n
    while(!file.eof()){
        getline(file,line);
        vector <string> elementi;
        stringstream ss (line);
        string elemento;
        while (getline(ss,elemento,';')){
            //cout << elemento<<endl;
            elementi.push_back(elemento);
        }
        istringstream convertN;
        convertN.str(elementi[1]);
        convertN >> n;
        break;
    }
    cout<<"S = "<<S<<endl;
    cout<<"n = "<<n<<endl;
    //salto la linea con w;r
    while(!file.eof()){
        getline(file,line);
        break;
    }
//creo i due vettori

    float convertV1;
    float convertV2;
    while(count<n){
            getline(file,line);
            stringstream ss (line);
            string elemento;
            vector <string> elementi;
            while (getline(ss,elemento,';')){
                elementi.push_back(elemento);
            }
            istringstream(elementi[0]) >> convertV1;
            v1.push_back(convertV1);
            istringstream(elementi[1]) >> convertV2;
            v2.push_back(convertV2);
            count++;
    }
        cout<<"w= [ ";
        for (unsigned int i = 0; i < n; i++)
            cout<<v1[i]<<" ";
        cout<<"]"<<endl;

        cout<<"r= [ ";
        for (unsigned int i = 0; i < n; i++)
            cout<<v2[i]<<" ";
        cout<<"]"<<endl;
        file.close();
        return true;
}

float RateReturn(const size_t n, vector <float> &v1,  vector<float> &v2){
    float rate = 0;
    for (unsigned int i = 0; i < n; i++)
        rate += v1[i] * v2[i];
    return rate;
}

float FinalValue(const float rate,const size_t S){
    float V = 0;
    V=rate*S+S;
    return V;
}

bool ExportResult(const string outputFilePath,
                  const size_t S,
                  const size_t n,
                  vector <float>  v1,
                  vector <float>  v2,
                  const float rate,
                  const float  V){

    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }
    file << "S= "<<S<<endl;
    file << "n= "<<n<<endl;
    file << "w= [";
    for (unsigned int i=0; i<n; i++){
        file<<v1[i]<<" ";
    }
    file <<"]"<<endl;
    file << "r= [";
    for (unsigned int i=0; i<n; i++){
        file<<v2[i]<<" ";
    }
    file << "]"<<endl;
    file <<"Rate of return of the portfolio: "<<rate<<endl;
    file<<"V: "<<V<<endl;
    file.close();
    return true;
}
