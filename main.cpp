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
    int count1, count2, count3; //Counter for Existential Constraints
    int cnt1, cnt2, cnt3; //Count for Universal Constraints
    int cntA1, cntA2, cntA3; //Count for Auxiliary  Constraints

    myfile<< "MINIMIZE"<<endl;
    myfile<< "-x1 -2x2 +2x3 +x4"<<endl;
    myfile<< "SUBJECT TO"<<endl;
    myfile<< "#Existential Constrains"<<endl;
    myfile<< " "<<endl;

 /*
  * First Existential Constraint Set
*/

    myfile<<"#First Constraint Set of Existential Player (36 Constraints)"<<endl;

    for(int count1=1 ; count1<37;count1++)
    {
        //Printing
        myfile<< "E_constraint" + to_string(count1) +": ";
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
    count1=36;

    for (int count2=1 ;count2<37; count2++)
    {
        //Printing
        myfile<< "E_constraint" + to_string(count1+count2) +": ";
        myfile<<"A" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k-2)+ " + ";
        myfile<<"A" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k)+ " <= 0"<< endl;

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
    count1=36;
    count2=36;

    for (int count3=1 ;count3<6; count3++) {
        myfile << "E_constraint" + to_string(count1+ count2+ count3) + ": ";
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
  * =====================================================================
  * =====================================================================
  * First Universal Constraint Set
*/
    myfile<< " "<<endl;
    myfile<< " "<<endl;
    myfile<< "#========================================================================================================="<<endl;
    myfile<< "#========================================================================================================="<<endl;
    myfile<< "#========================================================================================================="<<endl;
    myfile<< " "<<endl;
    myfile<< " "<<endl;
    myfile<< "#Universal Constraints"<<endl;
    myfile<< " "<<endl;
    myfile<<"#First Constraint Set of Universal Player (36 Constraints)"<<endl;
    myfile<< endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=2; //k value

    for(int cnt1=1 ; cnt1<37;cnt1++)
    {
        //Printing
        myfile<< "U_constraint" + to_string(cnt1) +": ";
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
    cnt1=36;

    for (int cnt2=1 ;cnt2<28; cnt2++)
    {
        //Printing
        myfile<< "U_constraint" + to_string(cnt1+cnt2) +": ";
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
    cnt1=36;
    cnt2=27;

    for (int cnt3=1 ;cnt3<5; cnt3++) {
        myfile << "U_constraint" + to_string(cnt1 + cnt2 + cnt3) + ": ";
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


/*
 *=====================================================================
 *=====================================================================
 * First Auxiliary Variables Set
 *
*/
    myfile<<endl;
    myfile<<endl;
    myfile<< "#========================================================================================================="<<endl;
    myfile<< "#========================================================================================================="<<endl;
    myfile<< "#========================================================================================================="<<endl;
    myfile<<endl;
    myfile<<"#First Auxiliary Constraint Set, (6.17)"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=1; //k value

    for (int cntA1 = 1; cntA1 < 6; cntA1++) {
        myfile << "A_constraint" + to_string(cntA1) + ": ";
        for (int d = 0; d < 3; d++) {
            for (int e = 0; e < 3; e++) {
                if (e == 2 && d == 2) {
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k);
                } else
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";
            }
        }
        myfile << " >= "  "3*(h_" + to_string(i) + "__" + to_string(k) + ")";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i=i+1;
        myfile << endl;
    }
//    A_constraint1: A1_1_1 + A2_1_1 + A3_1_1 + A1_2_1 + A2_2_1 + A3_2_1 + A1_3_1 + A2_3_1 + A3_3_1 >= 3*(h_1__1)
//    A_constraint2: A1_1_3 + A2_1_3 + A3_1_3 + A1_2_3 + A2_2_3 + A3_2_3 + A1_3_3 + A2_3_3 + A3_3_3 >= 3*(h_1__3)
//    A_constraint3: A1_1_5 + A2_1_5 + A3_1_5 + A1_2_5 + A2_2_5 + A3_2_5 + A1_3_5 + A2_3_5 + A3_3_5 >= 3*(h_1__5)
//    A_constraint4: A1_1_7 + A2_1_7 + A3_1_7 + A1_2_7 + A2_2_7 + A3_2_7 + A1_3_7 + A2_3_7 + A3_3_7 >= 3*(h_1__7)
//    A_constraint5: A1_1_9 + A2_1_9 + A3_1_9 + A1_2_9 + A2_2_9 + A3_2_9 + A1_3_9 + A2_3_9 + A3_3_9 >= 3*(h_1__9)
//




    myfile.close();
    cout<<"Writing is successful!"<<endl;
    return 0;
}