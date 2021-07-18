
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(int argc, char *argv[])
{
    string line;
    string Input_file_name;
    string Output_file_name;
    vector<double> array_of_integer;
    double a;
    double sum=0;
    int quanity=0;
    double arithmetic_mean;
    double dispersion;
    double b;
    double sum_of_deviations=0;


    if (argc==2)
    {
        Input_file_name=argv[1];
    }
    else
    {
        cout<<"Enter path to file"<<endl;
        cin>>Input_file_name;
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
    in.open(Input_file_name);
    while (getline(in,line))
    {
        cout<<line<<endl;
        a=stoi(line);
        array_of_integer.push_back(a);
        sum=sum+a;
        quanity=quanity+1;
    }
    in.close();


    cout<<" "<<endl;
    cout<<"Sum = "<<sum<<endl;
    cout<<"Quanity = "<<quanity<<endl;


    arithmetic_mean=sum/quanity;


    for (int i=0; i<array_of_integer.size(); i++)
    {
        b=pow(array_of_integer.at(i)-arithmetic_mean,2);
        sum_of_deviations=sum_of_deviations+b;
    }
    dispersion=sum_of_deviations/quanity;


    cout<<" "<<endl;
    cout<<"Arithmetic = "<<arithmetic_mean<<endl;
    cout<<"Dispersion = "<<dispersion<<endl;


    ofstream out;
    out.open(Output_file_name);
    out<<"Arithmetic = "<<arithmetic_mean<<endl;
    out<<"Dispersion = "<<dispersion<<endl;
    out.close();
    return 0;
}
