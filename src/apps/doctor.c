#include "doctor.h"

typedef struct
{
    Queue *waitingTreatment;
    Queue *hospitalizedPatients;
} TreatmentData;

void treat_patient(void *data)
{
    TreatmentData *treatmentData = (TreatmentData *)data;

    Queue *waitingTreatment = treatmentData->waitingTreatment;
    Queue *hospitalizedPatients = treatmentData->hospitalizedPatients;

    if (isEmpty(waitingTreatment))
    {
        separator();
        printf("Não há pacientes para serem atendidos.");
        separator();
        pause_system();
        return;
    }

    Patient *patient = dequeue(waitingTreatment);
    separator();
    printf("Paciente %s sendo atendido...\n", patient->name);
    sleep_system(3);

    int hospitalize = 0;
    printf("Deseja hospitalizar o paciente? [1] - Sim, [0] - Não: ");
    scanf("%d", &hospitalize);
    getchar();

    if (hospitalize)
    {
        enqueue(hospitalizedPatients, *patient);
        separator();
        printf("Paciente %s hospitalizado com sucesso.\n", patient->name);
        separator();
        pause_system();
    }
}

void view_untreated_patients(void *queue)
{
    printQueue((Queue *)queue);
}

void update_hospitalized_patient(void *hospitalizedQueue)
{
    int hasHospitalizedPatients = !isEmpty((Queue *)hospitalizedQueue);
    if (!hasHospitalizedPatients)
    {
        separator();
        printf("Não há pacientes hospitalizados.");
        separator();
        pause_system();
        return;
    }

    Queue *hospitalizedPatients = (Queue *)hospitalizedQueue;

    printf("Digite o CPF do paciente que deseja atualizar: ");
    char cpf[100];
    scanf("%s", cpf);
    getchar();

    Node *temp = hospitalizedPatients->front;
    while (temp != NULL)
    {
        Patient *patient = &temp->data;
        if (strcmp(patient->cpf, cpf) == 0)
        {
            printf("Digite o índice numérico que corresponde à gravidade do paciente: [0] - Sem danos, [1] - Baixa, [2] - Média, [3] - Alta ou [4] Crítica: ");
            int severity;
            scanf("%d", &severity);
            if (severity == 0)
            {
                Patient *patient = dequeue(hospitalizedPatients);
                printf("Paciente %s teve alta.\n", patient->name);
                pause_system();
                free(patient);
                return;
            }

            patient->severity = getPatientSeverityByNumber(severity);
            break;
        }
        temp = temp->next;
    }

    separator();
    printf("Paciente não encontrado.");
    separator();
    pause_system();
}

void view_hospitalized_patients(void *hospitalizedPatients)
{
    printQueue((Queue *)hospitalizedPatients);
}

void doctor_app(User *user)
{
    Patient *patients = getAllPatients();
    Queue *waitingTreatment = createQueue();
    Queue *hospitalizedPatients = createQueue();

    if (patients != NULL)
    {
        for (int i = 0; patients[i].id != 0; i++)
        {
            enqueue(waitingTreatment, patients[i]);
        }

        orderQueue(waitingTreatment);
    }

    TreatmentData treatmentData = {waitingTreatment, hospitalizedPatients};

    option options[] = {
        {"Atender paciente", treat_patient, &treatmentData},
        {"Visualizar fila de pacientes", view_untreated_patients, waitingTreatment},
        {"Visualizar pacientes hospitalizados", view_hospitalized_patients, hospitalizedPatients},
        {"Atualizar paciente hospitalizado", update_hospitalized_patient, hospitalizedPatients}};

    char *welcomeMessage = createWelcomeMessage(user->name);

    option exitOption = {"Deslogar", NULL, NULL};

    menu(welcomeMessage, options, 4, &exitOption);

    free(welcomeMessage);
    free(patients);
    free(waitingTreatment);
    free(hospitalizedPatients);
}
