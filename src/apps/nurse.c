#include "nurse.h"

void create_patient(void* queue) {
  Patient* patient = createPatient();
  enqueue((Queue*)queue, *patient);
  orderQueue(queue);
}

void print_queue(void* queue) {
  printQueue((Queue*)queue);
}

void nurse_app() {
  Patient* patients = getAllPatients();
  Queue* queue = createQueue();

  for (int i = 0; patients[i].id != 0; i++) {
    enqueue(queue, patients[i]);
  }

  orderQueue(queue);

  option options[] = {
    {"Encaminhar um novo paciente", create_patient, queue},
    {"Visualizar fila de pacientes", print_queue, queue},
     };

  option exitOption = {"Deslogar", NULL, NULL};

  menu("Bem vindo", options, 2, &exitOption);
}