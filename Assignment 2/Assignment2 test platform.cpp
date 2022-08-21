#include<iostream>

#include<fstream>

#include<iomanip>

using namespace std;

//structure representing one quarterback's record

struct quarterback{

              string firstname;

              string lastname;

              int attempts;

              int completions;

              int yards_passing;

              int touchdowns;

              int interceptions;

};

//method to read data from an opened file, fill the quarterback array, return the

//number of records read

int readData(ifstream &inFile, quarterback *array){

              string input;

              int index=0;

              //looping as long as there is a record to read.Assuming file is in valid format

              while(inFile>>input){

                           //firstname read successfully, so reading remaining info

                           quarterback qb; //creating a quarterback

                           qb.firstname=input; //setting first name

                           //reading remaining info to qb in order

                           inFile>>qb.lastname;

                           inFile>>qb.attempts;

                           inFile>>qb.completions;

                           inFile>>qb.yards_passing;

                           inFile>>qb.touchdowns;

                           inFile>>qb.interceptions;

                           //adding to array

                           array[index]=qb;

                           //updating index/count

                           index++;

              }

              //returning number of records read

              return index;

}

//method to find the percentage of completetion of a quarterback

double computePercentage(quarterback qb){

              double percent=0;

              //dividing completions by attempts ony if attempts>0

              if(qb.attempts>0){

                           percent=(double)qb.completions/qb.attempts;

              }

              return percent;

}

//method to find the rating of a quarterback

double quarterbackRating(quarterback qb){

              if(qb.attempts==0){

                           //rating is 0 if attempts is 0

                           return 0;

              }



              double rating=0;

              //finding rating using given formula

              rating=(double)(3.0*qb.completions+qb.yards_passing+10*qb.touchdowns)/(qb.attempts+8*qb.interceptions);

              return rating;

}

//method to display data of all quarterbacks in the array in proper format

void displayData(quarterback array[], int count){

              cout<<left;         //aligning outputs to left

              //displaying header info

              cout<<setw(20)<<"Quarterback"<<setw(6)<<"Att."<<setw(6)<<"Comp."<<setw(6)<<"Pct."<<setw(6)

              <<"Yards"<<setw(6)<<"TD"<<setw(6)<<"Int."<<setw(6)<<"Rating"<<endl;

              //looping through array, printing all info

              for(int i=0;i<count;i++){

                           cout<<setw(20)<<array[i].firstname+" "+array[i].lastname<<setw(6)<<array[i].attempts

                            <<setw(6)<<array[i].completions<<setw(6)<<setprecision(1)<<fixed<<computePercentage(array[i])

                            <<setw(6)<<array[i].yards_passing<<setw(6)<<array[i].touchdowns<<setw(6)<<array[i].interceptions

                            <<setw(6)<<setprecision(2)<<fixed<<quarterbackRating(array[i])<<endl;

              }

}

int main(){

              //input file name

              string filename="football-in.txt";

              //opening file for reading

              ifstream inFile(filename.c_str());

              if(!inFile){

                           //error

                           cout<<"football-in.txt file not found!"<<endl;

                           return 0;

              }

              //creating array

              quarterback array[100];

              //reading data, storing number of records read

              int count=readData(inFile,array);

              //closing input file

              inFile.close();

              //displaying data

              displayData(array,count);

              return 0;

}
