//This is an application for creating automated final.qlp file
#include <iostream>
#include <fstream> //for writing to a file
using namespace std;
int main() {
    ofstream myfile; //Defining file name
    myfile.open ("final.qlp"); //Opening the file
    int i=1; //for the x coordinate of the board
    int j=1;  //for the y coordinate of the board
    int k=3; //k value

    myfile<< "MINIMIZE"<<endl;
    myfile<< "-x1 -2x2 +2x3 +x4"<<endl;
    myfile<< "SUBJECT TO"<<endl;
    myfile<< "#Existential Constrains"<<endl;
    myfile<< " "<<endl;

    myfile<<"#First Constraint Set of Existential Player (36 Constraints)"<<endl;

    for(int a=1 ; a<37;a++)
    {
        //Printing
        myfile<< "E_constraint" + to_string(a) +": ";
        myfile<<"B" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k-1)+ " + ";
        myfile<<"A" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k)+ " <= 1"<< endl;

        k=k+2; //Increase k value in each step, k ∈ {3,5,7,9}

        if (k==10 || k==11) // Since k ∈ {3,5,7,9}
        {
            k=3; //Resetting K value
            j=j+1; //Increasing J value
            myfile<<endl;
        }
        if (j==4)
        {
            j=1; //Resetting j value since board size is 3x3
            i=i+1; //Increasing i Value in each three step
        }
    }

    myfile<<"#Second Constraint Set of Existential Player (36 Constraints)"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1;  //for the y coordinate of the board
    k=3; //k value
    int a=36;

    for (int b=1 ;b<37; b++)
    {
        //Printing
        myfile<< "E_constraint" + to_string(a+b) +": ";
        myfile<<"A" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k-2)+ " + ";
        myfile<<"A" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k)+ " <= 1"<< endl;

        k=k+2; //Increase k value in each step, k ∈ {3,5,7,9}

        if (k==10 || k==11) // Since k ∈ {3,5,7,9}
        {
            k=3; //Resetting K value
            j=j+1; //Increasing J value
            myfile<<endl;
        }
        if (j==4)
        {
            j=1; //Resetting j value since board size is 3x3
            i=i+1; //Increasing i Value in each three step
        }
    }


    myfile<<"#Third Constraint Set Ai_j_k"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1;  //for the y coordinate of the board
    k=1; //k value
    a=36;
    int b=36;


    for (int c=1 ;c<6; c++) {
        myfile << "E_constraint" + to_string(a + b + c) + ": ";

        for (int d = 1; d < 3; d++) {

            for (e=1;
                myfile << "A" + to_string(i) + "_" + to_string(j) + "_" + to_string(k) + " + ";
                i= i+1;
                j= j+1;

            if (i==4 || j==4)
            {
                i=1;
                j=1;

            }
        }
        myfile<<endl;
    }

    //k=k+2; //Increase k value in each step, k ∈ {3,5,7,9}





    myfile.close();
    cout<<"Writing is successful!"<<endl;
    return 0;
}