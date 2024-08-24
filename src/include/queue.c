#include "queue.h"

Node* createNode(Patient data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

Queue* createQueue() {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->front = queue->rear = NULL;
  return queue;
}

void enqueue(Queue* queue, Patient data) {
  Node* newNode = createNode(data);

  if (queue->rear == NULL) {
    queue->front = queue->rear = newNode;
    return;
  }

  queue->rear->next = newNode;
  queue->rear = newNode;
}

Patient* dequeue(Queue* queue) {
  if (isEmpty(queue)) {
    separator();
    printf("A fila está vazia.");
    separator();
    pause_system();
    return NULL;
  }

  Node *temp = queue->front;
  Patient *data = malloc(sizeof(Patient));
  *data = temp->data;
  queue->front = queue->front->next;

  if (queue->front == NULL) {
    queue->rear = NULL;
  }

  free(temp);
  return data;
}

void printQueue(Queue* queue) {
  Node* temp = queue->front;
  int i = 1;

  if(isEmpty(queue)) {
    separator();
    printf("A fila está vazia.");
    separator();
    pause_system();
    return;
  }

  while (temp != NULL) {
    Patient patient = temp->data;
    clear_screen();
    separator();
    printf("Paciente %d", i++);
    separator();
    printPatient(&patient);
    separator();
    pause_system();
    temp = temp->next;
  }
}

int isEmpty(Queue* queue) {
  return queue->front == NULL;
}

void orderQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        pause_system();
        return;
    }

    int size = 0;
    Node* temp = queue->front;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    Patient* patients = (Patient*)malloc(size * sizeof(Patient));

    temp = queue->front;
    for (int i = 0; i < size; i++) {
        patients[i] = temp->data;
        temp = temp->next;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (getPatientSeverity(patients[j].severity) < getPatientSeverity(patients[j + 1].severity)) {
                Patient tempPatient = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = tempPatient;
            }
        }
    }

    while (!isEmpty(queue)) {
        dequeue(queue);
    }

    for (int i = 0; i < size; i++) {
        enqueue(queue, patients[i]);
    }

    free(patients);
}


