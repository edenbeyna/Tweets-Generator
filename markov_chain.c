#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "markov_chain.h"

void free_markov_chain (MarkovChain **markov_chain)
{
  Node *head = (*markov_chain)->database->first;
  while (head != NULL)
  {
    (*markov_chain)->free_fun (head->data->data);
    free (head->data->counter_list);
    free (head->data);
    Node *next = head->next;
    free (head);
    head = next;
  }
}

Node *get_node_from_database (MarkovChain *markov_chain, void *data_ptr)
{
  Node *head = markov_chain->database->first;
  while (head != NULL)
  {
    if (markov_chain->comp_fun (head->data->data, data_ptr) == 0)
    {
      return head;
    }
    head = head->next;
  }
  return NULL;
}

