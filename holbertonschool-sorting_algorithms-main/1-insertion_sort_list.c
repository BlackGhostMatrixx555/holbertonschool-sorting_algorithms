#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers
* in ascending order using the Insertion sort algorithm.
* @list: Double pointer to the head of the list.
*
* Description: Swaps the nodes themselves, not the integer values.
* Prints the list after each swap.
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *next_iter, *prev_node;

/* Vérifications de sécurité classiques */
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

/* On commence au 2ème élément (le 1er est déjà "trié" s'il est seul) */
current = (*list)->next;

while (current != NULL)
{
/* On sauvegarde le prochain élément à traiter car 'current' va bouger */
next_iter = current->next;

/* Tant qu'on n'est pas au début ET que l'élément d'avant est plus grand */
while (current->prev != NULL && current->prev->n > current->n)
{
/* On identifie le nœud qui est juste avant (le plus grand) */
prev_node = current->prev;

/* --- DÉBUT DE LA CHIRURGIE (SWAP) --- */

/* 1. On branche le 'next' du précédent sur le 'next' du courant */
prev_node->next = current->next;

/* 2. Si le courant n'était pas le dernier, on met à jour le 'prev' de son suivant */
if (current->next != NULL)
current->next->prev = prev_node;

/* 3. On branche le 'next' du courant sur le précédent (il passe devant) */
current->next = prev_node;
			
/* 4. On met à jour le 'prev' du courant */
current->prev = prev_node->prev;
			
/* 5. On met à jour le 'prev' de l'ancien précédent */
prev_node->prev = current;

/* 6. Si 'current' a encore un parent, on met à jour le 'next' de ce parent */
if (current->prev != NULL)
current->prev->next = current;
else
*list = current; /* Si plus de parent, 'current' devient la tête (Head) */

/* --- FIN DE LA CHIRURGIE --- */

/* Le sujet demande d'imprimer après CHAQUE échange interne */
print_list(*list);
}
		
/* On passe à l'élément suivant qu'on avait sauvegardé au début */
current = next_iter;
}
}
