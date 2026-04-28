#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Patient.h"

using namespace System;
using namespace std;

void RegPac() {
    system("CLS");

    cout << "Registrar paciente: " << endl;
    ofstream PacList("Patient.txt", ios::app);

    if (PacList.is_open()) {
        string ID;
        string Name;
        string Lastname;
        string Speciality;
        string Location;

        cout << "1. Enter DNI: ";
        cin >> ID;
        cout << "2. Enter Name: ";
        cin >> Name;
        cout << "3. Enter Lastname: ";
        cin >> Lastname;
        cout << "4. Enter Speciality: ";
        cin >> Speciality;
        cout << "Locations:" << endl;
        cout << "   Location San Borja  (SanBorja): " << endl;
        cout << "   Location San Miguel (SanMiguel): " << endl;
        cout << "   Location Santiago de Surco (SantiagoDeSurco):" << endl;
        cout << "   Location Miraflores: " << endl << endl;
        cout << "   Warning: Do not write spaces... Example: SanBorja" << endl;
        cout << "5. Enter Location: ";
        cin >> Location;

        Patient<string>* patient = new Patient<string>(ID, Name, Lastname, Speciality, Location);

        while (patient->getLocation() != "SanBorja" && patient->getLocation() != "SanMiguel" && patient->getLocation() != "SantiagoDeSurco" && patient->getLocation() != "Miraflores") {
            cout << "Error: The location doesn't exist";
            _sleep(2500);
            RegPac();
        }

        PacList << patient->getName() << " " << patient->getLastname() << " | DNI: " << patient->getID() << " | Speciality: " << patient->getSpeciality() << " | Location: " << patient->getLocation() << endl;

        PacList.close();
        cout << "Patient registered successfully" << endl;
    }
    else cerr << "Error: Couldn't write to the file" << endl;
}

void ShowAllPac() {
    ifstream PacList("Patient.txt");
    string Line;
    int i = 1;

    if (PacList.is_open()) {
        while (getline(PacList, Line)) {
            cout << i << ". " << Line << endl;
            i++;
        }
        PacList.close();
    }
    else cerr << "Error: The patient list doesn't exist" << endl;
}

void ShowLocation() {
    system("CLS");
    cout << "Show patients by location: " << endl;
    cout << "   Location San Borja: " << endl;
    cout << "   Location San Miguel: " << endl;
    cout << "   Location Santiago de Surco: " << endl;
    cout << "   Location Miraflores: " << endl << endl;
    ifstream PacList("Patient.txt");
    string word;
    string target;
    string Line;

    cout << "   Warning: Do not write spaces... Example: SanBorja" << endl;
    cout << "Enter a location to search: ";
    cin >> target;
    cout << "Patients in the location " << target << ": " << endl;

    while (target != "SanBorja" && target != "SanMiguel" && target != "SantiagoDeSurco" && target != "Miraflores") {
        cout << "Error: The location doesn't exist";
        _sleep(2500);
        ShowLocation();
    }

    if (PacList.is_open()) {
        bool found = false;
        while (getline(PacList, Line)) {
            if (Line.find(target) != string::npos) {
                cout << "- " << Line << endl;
                found = true;
            }
        }
        if (found == false) cout << "No se encontraron pacientes en la sede";
        PacList.close();
    }
    else cout << "Error: La lista de pacientes no existe" << endl;
}

void CountSpec() {
    ifstream PacList("Patient.txt");
    string Line;
    string Speciality;
    int Cardiology = 0;
    int InternalMedicine = 0;
    int Pediatrics = 0;
    int Dermatology = 0;
    int Gynecology = 0;
    int Endocrinology = 0;
    int Pulmonology = 0;
    int Psychiatry = 0;

    if (PacList.is_open()) {
        while (PacList >> Speciality) {
            if (Speciality == "Cardiology" || Speciality == "Cardiologia") Cardiology++;
            if (Speciality == "InternalMedicine" || Speciality == "MedicinaInterna") InternalMedicine++;
            if (Speciality == "Pediatrics" || Speciality == "Pediatria") Pediatrics++;
            if (Speciality == "Dermatology" || Speciality == "Dermatologia") Dermatology++;
            if (Speciality == "Gynecology" || Speciality == "Ginecologia") Gynecology++;
            if (Speciality == "Endocrinology" || Speciality == "Endocrinologia") Endocrinology++;
            if (Speciality == "Pulmonology" || Speciality == "Neumologia") Pulmonology++;
            if (Speciality == "Psychiatry" || Speciality == "Psiquiatria") Psychiatry++;
        }
        cout << "Cardiology: " << Cardiology << endl;
        cout << "Internal Medicine: " << InternalMedicine << endl;
        cout << "Pediatrics: " << Pediatrics << endl;
        cout << "Dermatology: " << Dermatology << endl;
        cout << "Gynecology: " << Gynecology << endl;
        cout << "Endocrinology: " << Endocrinology << endl;
        cout << "Pulmonology: " << Pulmonology << endl;
        cout << "Psychiatry: " << Psychiatry << endl;

        PacList.close();
    }
    else cout << "Error: The patient list doesn't exist" << endl;
}

int main()
{
    int opt;

    do {
        system("CLS");
        cout << "1. Enter patient" << endl;
        cout << "2. Show all registered patients" << endl;
        cout << "3. Show patients by location" << endl;
        cout << "4. Show number of patients by speciality" << endl;
        cout << "5. Exit" << endl;

        cout << "Select an option: ";
        cin >> opt;

        switch (opt) {
        case 1:
            RegPac();
            break;
        case 2:
            system("CLS");
            cout << "Show complete list of patients: " << endl;
            ShowAllPac();
            break;
        case 3:
            ShowLocation();
            break;
        case 4:
            system("CLS");
            cout << " Show number of patients by speciality: " << endl;
            CountSpec();
            break;
        case 5:
            system("CLS");
            cout << "Press any key to exit";
            break;
        default:
            system("CLS");
            cout << "Error: Invalid Option" << endl << endl;
            opt = 0;
            cout << "Press any key to return to the main menu";
            break;
        }

        system("pause");
    } while (opt < 5);

    return 0;
}
