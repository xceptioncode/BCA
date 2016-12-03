//Author: Shubham Raj (@xceptioncode)

#include <vector>     // for vector
#include <string>     // for string related functions
#include <sstream>    // for stringstream
#include <iostream>   // cin, cout etc
#include <stdlib.h>   // for atoi & atof
#include <algorithm>  // for transform function
#include <math.h>     // for fmod

using namespace std;
int precision=4;

string detect(int s){return (s<=1 ? " number." : " numbers.");}  // For perfection in output [number or numbers]

int main()
{
    char str[100];
    cout<<"Enter 'exit' to quit the interpreter or 'help' for list of commands.\n"<<endl;
    for(;;){
    cout.precision(precision);
    cout<<"X Interpreter> ";
    cin.getline(str, 100);
    string buf; // buffer string
    stringstream temp(str), ss(str); // string stream - dual copy
    vector<string> tokens; // vector to hold splitted token

    if (!(temp>>buf)){cout<<"Invalid input. Enter Help for list of commands.\n"<<endl; continue;} // To handle runtime error caused by invalid input
    while (ss >> buf){
            tokens.push_back(buf);
    }
    transform(tokens[0].begin(), tokens[0].end(), tokens[0].begin(), ::tolower); // Convert to lower case for characters

    if (tokens[0] == "add"){
            if (tokens.size() < 3){cout<<"It was not specified how to add " <<tokens.size()-1<<" number."<<endl;}else{
            double sum=0;
            for (int i=1;i<tokens.size(); i++)
            {
                 sum+=atof(tokens[i].c_str()); //extract double
            }
            cout<<"Output: "<<fixed<<sum<<endl;
            }
    }else if (tokens[0] == "sub"){
            if (tokens.size() > 3 || tokens.size() < 3){cout<<"It was not specified how to subtract " <<tokens.size()-1<<detect(tokens.size()-1)<<endl;} else {

                cout<<"Output: "<<fixed<<atof(tokens[1].c_str()) - atof(tokens[2].c_str())<<endl; //extract double
            }
    }else if (tokens[0] == "mul"){
            if (tokens.size() < 3){cout<<"It was not specified how to multiply " <<tokens.size()-1<<" number."<<endl;}else{
            double mul=1;
            for (int i=1;i<tokens.size(); i++)
            {
                 mul*=atof(tokens[i].c_str()); //extract double
            }
            cout<<"Output: "<<fixed<<mul<<endl;
            }
    }else if (tokens[0] == "div"){
            if (tokens.size() > 3 || tokens.size() < 3){cout<<"It was not specified how to divide " <<tokens.size()-1<<detect(tokens.size()-1)<<endl;} else {

                cout<<"Output: "<<fixed<<atof(tokens[1].c_str()) / atof(tokens[2].c_str())<<endl; //extract double
            }
    }else if (tokens[0] == "mod"){
            if (tokens.size() > 3 || tokens.size() < 3){cout<<"It was not specified how to find modulus of " <<tokens.size()-1<<detect(tokens.size()-1)<<endl;} else {

                cout<<"Output: "<<fixed<<fmod(atof(tokens[1].c_str()), atof(tokens[2].c_str()))<<endl; //extract double
            }
    }else if (tokens[0] == "lshift"){
            if (tokens.size() > 3 || tokens.size() < 3){cout<<"It was not specified how to perform left shift on " <<tokens.size()-1<<detect(tokens.size()-1)<<endl;} else {

                cout<<"Output: "<<(atoi(tokens[1].c_str()) << atoi(tokens[2].c_str()))<<endl; //extract only integer.
            }
    }else if (tokens[0] == "rshift"){
            if (tokens.size() > 3 || tokens.size() < 3){cout<<"It was not specified how to perform right shift on " <<tokens.size()-1<<detect(tokens.size()-1)<<endl;} else {

                cout<<"Output: "<<(atoi(tokens[1].c_str()) >> atoi(tokens[2].c_str()))<<endl; //extract only integer.
            }
    }else if (tokens[0] == "exit"){cout<<"Thanks for using the interpreter. Good Bye! :) \nPress enter to exit .. "<<endl; cin.get(); exit(0);}
    else if (tokens[0] == "help") {
            cout<<"[!] Disclaimer: This program is coded by Shubham Raj (@xceptioncode). \n\t\tEmail: xshubhamraj@gmail.com"<<endl;
            cout<<"\nCommands: \n";
            cout<<"Add    : For Addition"<<endl;
            cout<<"Sub    : For Subtraction"<<endl;
            cout<<"Mul    : For Multiplication"<<endl;
            cout<<"Div    : For Division"<<endl;
            cout<<"Mod    : For Modulus Operation"<<endl;
            cout<<"Lshift : For Left Shift Operation"<<endl;
            cout<<"Rshift : For Right Shift Operation"<<endl;
            cout<<"Setp   : Set Decimal Point Precision [default 4]"<<endl;
            cout<<"Exit   : Exit Program"<<endl;
    }else if (tokens[0] == "setp"){
            if (tokens.size()>2 || tokens.size()<2) {cout<<"Invalid syntax. Correct syntax for setp is: setp number   [ex: setp 6]"<<endl;}
            else {precision = atoi(tokens[1].c_str());}
    }
    else {cout<<"'" <<tokens[0]<<"' is an invalid command. Enter Help for list of commands."<<endl;}
    cout<<"\n";
}
}

