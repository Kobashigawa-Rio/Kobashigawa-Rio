#pragma once

using namespace std;

template<typename T>
class Patient {
private:
    T ID;
    T Name;
    T Lastname;
    T Speciality;
    T Location;
public:
    Patient() {};
    Patient(T id, T name, T lastname, T speciality, T location) : ID(id), Name(name), Lastname(lastname), Speciality(speciality), Location(location) {};
    ~Patient();
    T getID() { return ID; };
    T getName() { return Name; };
    T getLastname() { return Lastname; };
    T getSpeciality() { return Speciality; };
    T getLocation() { return Location; };
};
