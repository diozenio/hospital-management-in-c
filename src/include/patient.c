#include "patient.h"

int getPatientSeverity(enum PatientSeverity severity)
{
    switch (severity)
    {
    case LOW:
        return 1;
    case MEDIUM:
        return 2;
    case HIGH:
        return 3;
    case CRITICAL:
        return 4;
    default:
        return 0;
    }
}

enum PatientSeverity getPatientSeverityByNumber(int severity)
{
    switch (severity)
    {
    case 1:
        return LOW;
    case 2:
        return MEDIUM;
    case 3:
        return HIGH;
    case 4:
        return CRITICAL;
    default:
        return NO_DAMAGE;
    }
}

void save_patient(Patient *patient)
{
    char *data = (char *)malloc(sizeof(char));

    char severity_data[2];
    sprintf(severity_data, "%d", getPatientSeverity(patient->severity));

    sprintf(data, "%d;%s;%s;%s\n", patient->id, patient->cpf, patient->name, severity_data);
    write_file("src/bin/patients.txt", data);
    free(data);
}

Patient *createPatient()
{
    Patient *patient = (Patient *)malloc(sizeof(Patient));
    separator();

    printf("Digite o CPF do paciente: ");
    scanf("%s", patient->cpf);
    getchar();

    printf("Digite o nome completo do paciente: ");
    fgets(patient->name, sizeof(patient->name), stdin);
    patient->name[strcspn(patient->name, "\n")] = 0;

    printf("Digite o índice numérico que corresponde à gravidade do paciente: [1] - Baixa, [2] - Média, [3] - Alta ou [4] Crítica: ");
    int severity;
    scanf("%d", &severity);
    patient->severity = getPatientSeverityByNumber(severity);

    patient->id = generate_random_id();

    save_patient(patient);
    return patient;
}

void printPatient(Patient *patient)
{
    printf("ID: %d\n", patient->id);
    printf("CPF: %s\n", patient->cpf);
    printf("Nome: %s\n", patient->name);
    printf("Gravidade: %i\n", getPatientSeverity(patient->severity));
}

void parsePatient(char *patientData, Patient *patient)
{
    char *token = strtok(patientData, ";");
    patient->id = atoi(token);

    token = strtok(NULL, ";");
    strcpy(patient->cpf, token);

    token = strtok(NULL, ";");
    strcpy(patient->name, token);

    token = strtok(NULL, ";");
    patient->severity = getPatientSeverityByNumber(atoi(token));
}

Patient *findPatientByCpf(char *cpf)
{
    char *data = read_file("src/bin/patients.txt");
    char *token = strtok(data, "\n");
    while (token != NULL)
    {
        Patient *patient = (Patient *)malloc(sizeof(Patient));
        char *severity = (char *)malloc(sizeof(char));
        parsePatient(token, patient);
        free(severity);
        if (strcmp(patient->cpf, cpf) == 0)
        {
            return patient;
        }
        token = strtok(NULL, "\n");
    }
    return NULL;
}