#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

double remap(double v) //rimappa da [1,5] a [-1,2]
{
    double vremapped = ((v-1)*(0.75))-1;
    return vremapped;
}

int main()
{
    string nameFile = "data.csv";
    ifstream fstr(nameFile);
    if (fstr.fail())
    {
        cerr << "File not found" << endl;
        return 1;
    }

    string outputFile = "result.csv"; //oppure posso fare ofstream ostr("result.csv")
    ofstream ostr(outputFile);        // con commento superiore sostituisco entrambe le righe
    ostr << "# N mean" << endl;

    double sum = 0;
    int N = 0;
    double val;

    while(fstr >> val)
    {
        N++;
        val = remap(val); //per riscalare i valori
        sum += val;
        double mean = sum/N;
        ostr << N << " " << scientific << setprecision(15) << mean << endl;
    }

    fstr.close();
    ostr.close();
    return 0;
}
