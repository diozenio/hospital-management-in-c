#ifndef PATIENT_H
#define PATIENT_H

#include "../utils/generate_random_id.h"
#include "../utils/menu.h"
#include "../utils/system_functions.h"
#include "database.h"
#include <stdio.h>
#include <stdlib.h>

enum PatientSeverity
{
    NO_DAMAGE,
    LOW,
    MEDIUM,
    HIGH,
    CRITICAL,
};

typedef struct
{
    int id;
    char cpf[12];
    char name[100];
    enum PatientSeverity severity;
} Patient;

Patient *createPatient();
void deletePatient(Patient *patient);
Patient *findPatientByCpf(char *cpf);
Patient *getAllPatients();

int getPatientSeverity(enum PatientSeverity severity);
void printPatient(Patient *patient);
void editPatientSeverity(Patient *patient);

#endif