#include "nurse.h"

void create_patient(void* queue) {
  Patient* patient = createPatient();
  enqueue((Queue*)queue, *patient);
  orderQueue(queue);
}

void print_queue(void* queue) {
  printQueue((Queue*)queue);
}

void nurse_app(User* user) {
  Patient* patients = getAllPatients();
  Queue* queue = createQueue();

  if(patients != NULL) {
    for (int i = 0; patients[i].id != 0; i++) {
      enqueue(queue, patients[i]);
    }

    orderQueue(queue);
  }

  option options[] = {
    {"Encaminhar um novo paciente", create_patient, queue},
    {"Visualizar fila de pacientes", print_queue, queue},
     };

  char *welcomeMessage = createWelcomeMessage(user->name);

  option exitOption = {"Deslogar", NULL, NULL};

  menu(welcomeMessage, options, 2, &exitOption);
  
  free(welcomeMessage);
  free(patients);
  free(queue);
}