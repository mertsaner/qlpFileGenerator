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
    int count1=0, count2=0, count3=0; //Counter for Existential Constraints
    int cnt1=0, cnt2, cnt3=0; //Count for Universal Constraints
    int cntA1=0, cntA2=0, cntA3=0, cntA4=0, cntA5=0, cntA6=0; //Count for Auxiliary  Constraints
    int i2=1; //Right hand side of the equation 6.17

    int z;
    myfile<< "MINIMIZE"<<endl;
    myfile<< "-x1 -2x2 +2x3 +x4"<<endl;
    myfile<< "SUBJECT TO"<<endl;
    myfile<< "#Existential Constrains"<<endl;
    myfile<< " "<<endl;

 /*
  * First Existential Constraint Set
*/

    myfile<<"#First Constraint Set of Existential Player (36 Constraints)"<<endl;

    for(count1=1 ; count1<37;count1++)
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

    for (count2=1 ;count2<37; count2++)
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

    for (count3=1 ;count3<6; count3++) { //Constraint Number Counter
        myfile << "E_constraint" + to_string(count1+ count2+ count3) + ": ";
        for (int d = 0; d<3; d++) { //Two nested For loops Represents increase in i  and j value
            for (int e=0; e<3; e++) {

                if (e==2 && d==2) //This Helps to delete last sum symbol at the end of the equation
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

    for(cnt1=1 ; cnt1<37;cnt1++)
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

    for (cnt2=1 ;cnt2<28; cnt2++)
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

    for (cnt3=1 ;cnt3<5; cnt3++) {  //Constraint Number Counter
        myfile << "U_constraint" + to_string(cnt1 + cnt2 + cnt3) + ": ";
        for (int d = 0; d<3; d++) { //Two nested For loops Represents increase in i  and j value
            for (int e=0; e<3; e++) {

                if (e==2 && d==2) //This Helps to delete last sum symbol at the end of the equation
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
    myfile<<"#First Set of First Auxiliary Constraint Set, (6.17)"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=1; //k value
    i2=1; //Right hand side of the equation


    for (cntA1 = 1; cntA1 < 4; cntA1++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1) + ": ";
        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
            for (int e = 0; e < 3; e++) {
                if (e == 2 && d == 2) {
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k);
                } else
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";
            }
        }
        myfile << " >= "  "3*(h_" + to_string(i2) + "___" + to_string(k) + ")";
      //  k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
      i2++;
        myfile << endl;
    }


    myfile<<endl;
    myfile<<"#Second Set of First Auxiliary Constraint Set, (6.17)"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=3; //k value
    i2=1; //Right hand side of the equation

    for (cntA2 = 1; cntA2 < 4; cntA2++) { //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1+cntA2) + ": ";
        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
            for (int e = 0; e < 3; e++) {
                if (e == 2 && d == 2) { //This Helps to delete last sum symbol at the end of the equation
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k);
                } else
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";
            }
        }
        myfile << " >= "  "3*(h_" + to_string(i2) + "___" + to_string(k) + ")";
      //  k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i2++;
        myfile << endl;
    }

    myfile<<endl;
    myfile<<"Third Set of First Auxiliary Constraint Set, (6.17)"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=5; //k value
    i2=1; //Right hand side of the equation
    for (cntA3 = 1; cntA3 < 4; cntA3++) { //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1+cntA2+cntA3) + ": ";
        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
            for (int e = 0; e < 3; e++) {
                if (e == 2 && d == 2) { //This Helps to delete last sum symbol at the end of the equation
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k);
                } else
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";
            }
        }
        myfile << " >= "  "3*(h_" + to_string(i2) + "___" + to_string(k) + ")";
    //    k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i2++;
        myfile << endl;
    }

    myfile<<endl;
    myfile<<"Fourth Set of First Auxiliary Constraint Set, (6.17)"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=7; //k value
    i2=1; //Right hand side of the equation
    for (cntA4 = 1; cntA4 < 4; cntA4++) { //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1+cntA2+cntA3+cntA4) + ": ";
        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i and j value
            for (int e = 0; e < 3; e++) {
                if (e == 2 && d == 2) { //This Helps to delete last sum symbol at the end of the equation
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k);
                } else
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";
            }
        }
        myfile << " >= "  "3*(h_" + to_string(i2) + "___" + to_string(k) + ")";
        //    k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i2++;
        myfile << endl;
    }


    myfile<<endl;
    myfile<<"Fifth Set of First Auxiliary Constraint Set, (6.17)"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=9; //k value
    i2=1; //Right hand side of the equation
    for (int cntA5 = 1; cntA5 < 4; cntA5++) { //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1 + cntA2 + cntA3 + cntA4 + cntA5) + ": ";
        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
            for (int e = 0; e < 3; e++) {
                if (e == 2 && d == 2) { //This Helps to delete last sum symbol at the end of the equation
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k);
                } else
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";
            }
        }
        myfile << " >= "  "3*(h_" + to_string(i2) + "___" + to_string(k) + ")";
        //    k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i2++;
        myfile << endl;
    }

    myfile<<endl;
    myfile<<endl;
    myfile<< "#========================================================================================================="<<endl;
    myfile<< "#========================================================================================================="<<endl;
    myfile<< "#========================================================================================================="<<endl;
    myfile<<endl;
    myfile<<"First Set of Second Auxiliary Constraint Set, (6.18)"<<endl;
    myfile<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=1; //k value
    i2=1; //Right hand side of the equation
    for (int cntA6 = 1; cntA6 < 6; cntA6++) { //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA6) + ": ";
        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
            for (int e = 0; e < 3; e++) {
                if (e == 2 && d == 2) { //This Helps to delete last sum symbol at the end of the equation
                    myfile << "v" + to_string(i + e) + "_" + "_" + to_string(k);
                } else
                    myfile << "h" + to_string(i + e) + "_" + "_" + to_string(k) + " + ";
            }
        }
        myfile << " >= "  "w_" + to_string(k);
           k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
       // i2++;
        myfile << endl;
    }


















    myfile.close();
    cout<<"Writing is successful!"<<endl;
    return 0;
}