#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
int main(int argc, char *argv[])
{
    string line;
    string input_file_name;
    string Output_file_name;
    vector<int> array_of_integer;
    int a;
    double sum=0;
    int quanity=0;
    double arithmetic_mean;
    double dispersion;

    double sum_of_deviations=0;

    if (argc==2)
    {
        input_file_name=argv[1];
    }
    else
    {
        cout<<"Enter path to file"<<endl;
        cin>>input_file_name;

    }
    if (argc==3)
    {
        Output_file_name=argv[2];
    }
    else
    {
        cout<<"Enter the address where you want to save the data"<<endl;
        cin>>Output_file_name;
    }
    ifstream in;
    in.open(input_file_name);
    while (getline(in,line))
    {
        cout<<line<<endl;
        a=stoi(line);
        array_of_integer.push_back(a);
        sum=sum+a;
        quanity=quanity+1;

    }
    in.close();
    cout<<"................."<<endl;
    cout<<" Sum="<<endl;
    cout<<"Quanity="<<endl;

    arithmetic_mean=sum/quanity;
    dispersion=sum_of_deviations/quanity;

    cout<<"................."<<endl;
    cout<<"Arithmetic mean="<<arithmetic_mean<<endl;
    cout<<"Dispersion ="<<dispersion<<endl;

    ofstream out;
    out.open(Output_file_name);
    out<<"Arithmetic mean="<<arithmetic_mean<<endl;
    out<<"Dispersion ="<<dispersion<<endl;
    out.close();
    return 0;
}

