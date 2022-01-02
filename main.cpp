/*This is an application for creating automated final.qlp file
* The .qlp file is used to solve Tic-Tac-Toe game using Yasol Solver
*/


/* Explanation of the values defined:
* Let k ∈ {1, . . . , 9} indicated the number of the current turn.
* If k is odd it is an existential player’s turn, and if k is even it is the universal player’s turn.
*/

/*
The existential player assigns the variables Ak ∈ {0, 1}3×3 and the universal player assigns Bk ∈ {0,1}3×3 in the k-th turn.
 Aki,j = 1 indicates that cell (i,j) is filled with a piece from the existential player after turn k.
*/



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

 /*
  * First Existential Constraint Set
*/

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


/*
 * Second Existential Constraint Set
*/

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

/*
 * Third Existential Constraint Set
*/

    myfile<<"#Third Constraint Set of Existential Player (Ai_j_k, 5 Constraints)"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=1; //k value
    a=36;
    int b=36;

    for (int c=1 ;c<6; c++) {
        myfile << "E_constraint" + to_string(a + b + c) + ": ";
        for (int d = 0; d<3; d++) {
            for (int e=0; e<3; e++) {

                if (e==2 && d==2)
                {
                    myfile << "A" + to_string(i+e) + "_" + to_string(j+d) + "_" + to_string(k);
                }
                else
                myfile << "A" + to_string(i+e) + "_" + to_string(j+d) + "_" + to_string(k) + " + ";
            }
        }
        myfile <<" = "+ to_string(k)+"/2 + 1 ";
        k=k+2;     //Increase k value in each step, k ∈ {3,5,7,9}
        myfile<<endl;
    }


 /*
  * First Universal Constraint Set
*/

    myfile<< "#Universal Constraints"<<endl;
    myfile<< " "<<endl;
    myfile<<"#First Constraint Set of Universal Player (36 Constraints)"<<endl;
    myfile<< endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=2; //k value

    for(int a=1 ; a<37;a++)
    {
        //Printing
        myfile<< "U_constraint" + to_string(a) +": ";
        myfile<<"A" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k-1)+ " + ";
        myfile<<"B" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k)+ " <= 1"<< endl;

        k=k+2; //Increase k value in each step, k ∈ {3,5,7,9}

        if (k==10 || k==11) // Since k ∈ {3,5,7,9}
        {
            k=2; //Resetting K value
            j=j+1; //Increasing J value
            myfile<<endl;
        }
        if (j==4)
        {
            j=1; //Resetting j value since board size is 3x3
            i=i+1; //Increasing i Value in each three step
        }
    }

/*
 * Second Universal Constraint Set
*/

    myfile<<"#Second Constraint Set of Universal Player (27 Constraints)"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1;  //for the y coordinate of the board
    k=4; //k value
    a=36;

    for (int b=1 ;b<28; b++)
    {
        //Printing
        myfile<< "E_constraint" + to_string(a+b) +": ";
        myfile<<"B" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k-2)+ " - ";
        myfile<<"B" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k)+ " <= 0 "<< endl;

        k=k+2; //Increase k value in each step, k ∈ {3,5,7,9}

        if (k==10 || k==11) // Since k ∈ {3,5,7,9}
        {
            k=4; //Resetting K value
            j=j+1; //Increasing J value
            myfile<<endl;
        }
        if (j==4)
        {
            j=1; //Resetting j value since board size is 3x3
            i=i+1; //Increasing i Value in each three step
        }
    }


/*
 * Third Universal Constraint Set
*/

    myfile<<"#Third Constraint Set of Universal Player (Ai_j_k, 4 Constraints)"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=2; //k value
    a=36;
    b=27;

    for (int c=1 ;c<5; c++) {
        myfile << "E_constraint" + to_string(a + b + c) + ": ";
        for (int d = 0; d<3; d++) {
            for (int e=0; e<3; e++) {

                if (e==2 && d==2)
                {
                    myfile << "B" + to_string(i+e) + "_" + to_string(j+d) + "_" + to_string(k);
                }
                else
                    myfile << "B" + to_string(i+e) + "_" + to_string(j+d) + "_" + to_string(k) + " + ";
            }
        }
        myfile <<" = "+ to_string(k)+"/2";
        k=k+2;     //Increase k value in each step, k ∈ {2,4,6,8}
        myfile<<endl;
    }










    myfile.close();
    cout<<"Writing is successful!"<<endl;
    return 0;
}