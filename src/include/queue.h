#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "database.h"

typedef struct Node {
  Patient data;
  struct Node* next;
} Node;

typedef struct {
  Node* front;
  Node* rear;
} Queue;

Node* createNode(Patient data);
Queue* createQueue();
void enqueue(Queue* queue, Patient data);
Patient* dequeue(Queue* queue);
void printQueue(Queue* queue);
int isEmpty(Queue* queue);
void orderQueue(Queue* queue);

#endif
