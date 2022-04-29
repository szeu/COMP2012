#include "GymStudent.h"
#include <iostream>

using namespace std;

// TODO: complete the constructor of GymStudent
GymStudent::GymStudent(const string& name, const string& gender) : GymPerson(name, gender){}

// TODO: complete GymStudent::join_session
void GymStudent::join_session(const GymSession* sess) {
    if(num_of_session >= MAX_NUM_OF_SESS)
        cout << "Failed to join " << sess->get_area()<< " at "<<sess->get_period() << ". Reached the maximum number of sessions allowed. "<< endl;
    else{
        session_list[num_of_session] = sess;
        num_of_session++;
    }
    return;
}
void GymStudent::print() const {
    cout << "GymStudent " << get_name() << ", Gender: " << get_gender() <<endl;
    cout<< "Joined sessions: " <<endl;
    for(int i = 0 ; i < num_of_session ; i ++ ) {
        cout << "Period: " << session_list[i]->get_period() << ", Area: " << session_list[i]->get_area() << endl;
    }
    cout<<endl; 
}