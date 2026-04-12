#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap of two elements.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* On avance la limite du tableau trié case par case */
	for (i = 0; i < size - 1; i++)
	{
		/* On suppose que l'élément actuel est le minimum */
		min_idx = i;

		/* On cherche un élément plus petit dans le reste du tableau */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		/* Si on a trouvé un élément plus petit que l'actuel, on échange */
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			/* Affichage requis après l'échange */
			print_array(array, size);
		}
	}
}
