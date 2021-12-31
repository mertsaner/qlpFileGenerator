//This is an application for creating automated .qlp files
#include <iostream>
#include <string>

using namespace std;
int main() {
    cout << "Program Started!" << endl;
    int x=1; //for the x
    int y=1;  //for the y
    int z1=2; //for the z
    int z2=3; //for the z

    cout<< "MINIMIZE"<<endl;
    cout<< "-x1 -2x2 +2x3 +x4"<<endl;

    cout<< "SUBJECT TO"<<endl;
    cout<< "#Existential Constratins"<<endl;

    cout<< " "<<endl;


    for (int i=1 ; i<73;i++) //To Print All Equations
    {


        cout<< "E_constraint" + to_string(i) +": ";
            cout<<"B" + to_string(x)+ "_"+to_string(y)+ "_"+to_string(z1);
            cout<<" + ";
            cout<<"B" + to_string(x)+ "_"+to_string(y)+ "_"+to_string(z2);
            cout<<" <= ";
            cout<<"1"<<endl;
            z1=z1+2;
            z2=z2+2;

//B1_1_2 + A1_1_3 <= 1

            if (z1==10)
                {
                    y=y+1;
                    z1=2;
                    cout<<endl;
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
    return 0;
}
/*MINIMIZE
-x1 -2x2 +2x3 +x4
        SUBJECT TO
#Existential Constratins
#First Constraint Set (36 Constraints)
E_Constraint1: B1_1_2 + A1_1_3 <= 1  #for each k value one constraints  #k=3
E_Constraint2: B1_1_4 + A1_1_5 <= 1  #k=5
E_Constraint3: B1_1_6 + A1_1_7 <= 1  #k=7
E_Constraint4: B1_1_8 + A1_1_9 <= 1  #k=9

E_Constraint4: B1_2_2 + A1_2_3 <= 1  #for each k value one constraints
E_Constraint5: B1_2_4 + A1_2_5 <= 1
E_Constraint7: B1_2_6 + A1_2_7 <= 1
E_Constraint8: B1_2_8 + A1_2_9 <= 1

E_Constraint9: B1_3_2 + A1_3_3 <= 1  #for each k value one constraints
E_Constraint10: B1_3_4 + A1_3_5 <= 1
E_Constraint11: B1_3_6 + A1_3_7 <= 1
E_Constraint12: B1_3_8 + A1_3_9 <= 1 */