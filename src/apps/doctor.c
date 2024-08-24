#include "doctor.h"

void treat_patient(void* waitingTreatment, void* hospitalizedPatients) {
  if(isEmpty((Queue*)waitingTreatment)) {
    separator();
    printf("Não há pacientes para serem atendidos.");
    separator();
    pause_system();
    return;
  }
  Patient* patient = dequeue((Queue*)waitingTreatment);
  separator();
  printf("Paciente %s sendo atendido...\n", patient->name);
  sleep_system(3);
  
  int hospitalize = 0;
  printf("Deseja hospitalizar o paciente? [1] - Sim, [0] - Não: ");
  scanf("%d", &hospitalize);
  getchar();

  if(hospitalize) {
    enqueue((Queue*)hospitalizedPatients, *patient);
    separator();
    printf("Paciente %s hospitalizado com sucesso.\n", patient->name);
    separator();
    pause_system();
  }
}

void view_untreated_patients(void* queue) {
  printQueue((Queue*)queue);
}

void view_hospitalized_patients(void* hospitalizedPatients) {
  printQueue((Queue*)hospitalizedPatients);
}

void doctor_app(User* user) {
  Patient* patients = getAllPatients();
  Queue* waitingTreatment = createQueue();
  Queue* hospitalizedPatients = createQueue();

  if(patients != NULL) {
    for (int i = 0; patients[i].id != 0; i++) {
      enqueue(waitingTreatment, patients[i]);
    }

    orderQueue(waitingTreatment);
  }

  option options[] = {
    {"Atender paciente", treat_patient, waitingTreatment},
    {"Visualizar fila de pacientes", view_untreated_patients, waitingTreatment},
    {"Visualizar pacientes hospitalizados", view_hospitalized_patients, hospitalizedPatients}
  };

  char *welcomeMessage = createWelcomeMessage(user->name);

  option exitOption = {"Deslogar", NULL, NULL};

  menu(welcomeMessage, options, 3, &exitOption);

  free(welcomeMessage);
  free(patients);
  free(waitingTreatment);
}