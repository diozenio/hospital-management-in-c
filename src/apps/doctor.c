#include "doctor.h"

void treat_patient(void* queue) {
  if(isEmpty((Queue*)queue)) {
    separator();
    printf("Não há pacientes para serem atendidos.");
    separator();
    pause_system();
    return;
  }
  Patient* patient = dequeue((Queue*)queue);
  separator();
  printf("Paciente %s sendo atendido...\n", patient->name);
  sleep_system(3);
}

void view_untreated_patients(void* queue) {
  printQueue((Queue*)queue);
}

void doctor_app(){
  Patient* patients = getAllPatients();
  Queue* queue = createQueue();

  if(patients != NULL) {
    for (int i = 0; patients[i].id != 0; i++) {
      enqueue(queue, patients[i]);
    }

    orderQueue(queue);
  }

  option options[] = {
    {"Atender paciente", treat_patient, queue},
    {"Visualizar fila de pacientes", view_untreated_patients, queue},
  };

  option exitOption = {"Deslogar", NULL, NULL};

  menu("Bem vindo", options, 2, &exitOption);
}