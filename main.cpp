//This is an application for creating automated final.qlp file
#include <iostream>
#include <fstream> //for writing to a file

using namespace std;
int main() {
    ofstream myfile;
    myfile.open ("final.qlp");
    int x=1; //for the x coordinate
    int y=1;  //for the y
    int z1=2; //for the z
    int z2=3; //for the z

    myfile<< "MINIMIZE"<<endl;
    myfile<< "-x1 -2x2 +2x3 +x4"<<endl;
    myfile<< "SUBJECT TO"<<endl;
    myfile<< "#Existential Constratins"<<endl;
    myfile<< " "<<endl;

    for (int i=1 ; i<73;i++) //To Print All Equations
    {
        myfile<< "E_constraint" + to_string(i) +": ";
        myfile<<"B" + to_string(x)+ "_"+to_string(y)+ "_"+to_string(z1);
        myfile<<" + ";
        myfile<<"B" + to_string(x)+ "_"+to_string(y)+ "_"+to_string(z2);
        myfile<<" <= ";
        myfile<<"1"<<endl;
            z1=z1+2;
            z2=z2+2;

            if (z1==10)
                {
                    y=y+1;
                    z1=2;
                    myfile<<endl;
                }
            if (z2==11)
                {
                    z2=3;
                }
            if (y==4)
                {
                     y=1;
                    x=x+1;
                }
    }
    myfile.close();
    cout<<"Writing is successful!"<<endl;
    return 0;
}