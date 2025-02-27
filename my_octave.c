//Copyright Peiu Andreea 314CAb 2023-2024
#include <stdio.h>
#include <stdlib.h>

#define MOD 10007

typedef struct {
	int rows;
	int cols;
	int **data;
	int sum;
} mstruct;

void free_matrix(int **a, int rows)
{
	for (int i = 0; i < rows; ++i)
		free(a[i]);

	free(a);
}

void free_struct(mstruct *mat)
{
	for (int i = 0; i < mat->rows; ++i)
		free(mat->data[i]);
	free(mat->data);
	free(mat);
}

void swap_elem(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int **alloc_matrix(int m, int n)
{
	int **data = (int **)calloc(m, sizeof(int *));

	// Alocăm spațiu pentru fiecare linie în parte
	for (int i = 0; i < m; i++) {
		// Alocam spatiu cu calloc
		data[i] = (int *)calloc(n, sizeof(int));
	}

	return data;
}

void deallocate_matrix(mstruct *a, int index)
{
	for (int j = 0; j < a[index].rows; ++j)
		free(a[index].data[j]);

	free(a[index].data);
}

void read_matrix(int m, int n, int *index, mstruct *a)
{
	a[*index].rows = m;
	a[*index].cols = n;
	a[*index].data = alloc_matrix(m, n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[*index].data[i][j]);
}

void check_size(mstruct **a, int *size, int *capacity)
{
	// Dacă vectorul este plin, îl extindem
	if (*size == *capacity) {
		// Dublăm capacitatea
		*capacity = *capacity * 2;

		mstruct *tmp = (mstruct *)realloc(*a, *capacity * sizeof(mstruct));
		if (!tmp) {
			fprintf(stderr, "realloc() failed\n");
			return;
		}
		*a = tmp;
	} else if (*size < *capacity / 2) {
		*capacity = *capacity / 2;

		mstruct *tmp = (mstruct *)realloc(*a, *capacity * sizeof(mstruct));
		if (!tmp) {
			fprintf(stderr, "realloc() failed\n");
			return;
		}
		*a = tmp;
	}
}

mstruct *resizeable_array(mstruct **a, int *size, int m, int n)
{
	read_matrix(m, n, size, *a);
	(*size)++;

	return *a;
}

void print_matrix(int index, mstruct *a, int size)
{
	if (index >= 0 && index < size) {
		for (int i = 0; i < a[index].rows; i++) {
			for (int j = 0; j < a[index].cols; j++)
				printf("%d ", a[index].data[i][j]);
			printf("\n");
		}
	} else {
		printf("No matrix with the given index\n");
	}
}

void multiply_matrix(int i1, int i2, int *size, mstruct *a)
{
	if (i1 >= *size || i2 >= *size || i1 < 0 || i2 < 0) {
		printf("No matrix with the given index\n");
	} else if (a[i1].cols != a[i2].rows) {
		printf("Cannot perform matrix multiplication\n");
	} else {
		a[*size].rows = a[i1].rows;
		a[*size].cols = a[i2].cols;
		a[*size].data = alloc_matrix(a[i1].rows, a[i2].cols);

		// Perform matrix multiplication
		for (int i = 0; i < a[i1].rows; i++) {
			for (int j = 0; j < a[i2].cols; j++) {
				// am sters elem=0
				for (int k = 0; k < a[i1].cols; k++)
					a[*size].data[i][j] += (a[i1].data[i][k] *
											a[i2].data[k][j]) %
										   MOD;

				a[*size].data[i][j] = a[*size].data[i][j] % MOD;
				if (a[*size].data[i][j] < 0)
					a[*size].data[i][j] += MOD;
			}
		}
		*size = *size + 1;
	}
}

void swap_struct(mstruct *a, mstruct *b)
{
	mstruct aux = *a;
	*a = *b;
	*b = aux;
}

void transpunere_matrix(mstruct *a, int index, int size)
{
	if (index >= 0 && index < size) {
		mstruct new;
		int **transpusa = alloc_matrix(a[index].cols, a[index].rows);

		for (int i = 0; i < a[index].rows; i++)
			for (int j = 0; j < a[index].cols; j++)
				transpusa[j][i] = a[index].data[i][j];
		new.data = transpusa;
		new.rows = a[index].cols;
		new.cols = a[index].rows;

		deallocate_matrix(a, index);
		a[index] = new;
	} else {
		printf("No matrix with the given index\n");
	}
}

void sum(mstruct *a, int size)
{
	for (int k = 0; k < size; k++) {
		int s = 0;
		for (int i = 0; i < a[k].rows; i++)
			for (int j = 0; j < a[k].cols; j++)
				s = (s + a[k].data[i][j]) % MOD;
		// s = s % MOD;
		if (s < 0)
			s = s + MOD;
		a[k].sum = s;
	}
}

void sort_matrix(int size, mstruct *a)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (a[i].sum > a[j].sum)
				swap_struct(&a[i], &a[j]);
}

int *alloc_array(int l)
{
	int *array = (int *)malloc(l * sizeof(int));
	if (!array) {
		fprintf(stderr, "malloc() failed\n");
		// Handle the error if needed
	}
	return array;
}

void redim(mstruct *a, int index, int l, int c, int index_row[],
		   int index_col[])
{
	mstruct new;
	int **copie = alloc_matrix(l, c);

	for (int i = 0; i < l; i++)
		for (int j = 0; j < c; j++)
			copie[i][j] = a[index].data[index_row[i]][index_col[j]];
	new.data = copie;
	new.rows = l;
	new.cols = c;

	// todo deallocate a[index] inainte de asta
	deallocate_matrix(a, index);
	a[index] = new;
}

void multiply(mstruct *a, mstruct *b)
{
	int **result = alloc_matrix(a->rows, b->cols);

	for (int i = 0; i < a->rows; i++) {
		for (int j = 0; j < b->cols; j++) {
			// am sters elem =0
			for (int k = 0; k < a->cols; k++)
				result[i][j] = (result[i][j] + a->data[i][k] *
												   b->data[k][j]) %
							   MOD;
			if (result[i][j] < 0)
				result[i][j] += MOD;
		}
	}

	// Eliberăm memoria alocată pentru matricea a
	free_matrix(a->data, a->rows);

	// Actualizăm matricea a cu rezultatul înmulțirii
	a->data = result;
	a->cols = b->cols;
}

void ridic_log_matrici(mstruct *lista, int index, int p, int size)
{
	if (index < 0 || index >= size)
		printf("No matrix with the given index\n");
	else if (p < 0)
		printf("Power should be positive\n");
	else if (lista[index].rows != lista[index].cols)
		printf("Cannot perform matrix multiplication\n");

	if (index >= 0 && index < size && p >= 0 &&
		lista[index].rows == lista[index].cols) {
		mstruct result;
		result.rows = lista[index].rows;
		result.cols = lista[index].cols;
		result.data = alloc_matrix(result.rows, result.cols);

		for (int i = 0; i < result.rows; i++)
			for (int j = 0; j < result.cols; j++)
				if (i == j)
					result.data[i][j] = 1;
				else
					result.data[i][j] = 0;

		// Ridicarea la putere
		while (p > 0) {
			if (p % 2 == 1)
				multiply(&result, &lista[index]);
			multiply(&lista[index], &lista[index]);
			p /= 2;
		}

		// Eliberăm memoria alocată pentru matricea lista[index]
		free_matrix(lista[index].data, lista[index].rows);
		lista[index] = result;
	}
}

// functie pentru eliberarea memoriei unei vector de structuri
void free_array(mstruct *a, int size)
{
	for (int i = 0; i < size; i++)
		free_struct(&a[i]);
	free(a);
}

void sum_matrix(mstruct a, mstruct b, mstruct *result, int index)
{
	mstruct new;
	int **copie = alloc_matrix(a.rows, a.cols);

	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			copie[i][j] = (a.data[i][j] + b.data[i][j]) % MOD;
			if (copie[i][j] < 0)
				copie[i][j] += MOD;
		}
	}
	new.data = copie;
	new.rows = a.rows;
	new.cols = a.cols;
	deallocate_matrix(result, index);
	result[index] = new;
}

void dif_matrix(mstruct a, mstruct b, mstruct *result, int index)
{
	mstruct new;
	int **copie = alloc_matrix(a.rows, a.cols);

	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			copie[i][j] = (a.data[i][j] - b.data[i][j]) % MOD;
			if (copie[i][j] < 0)
				copie[i][j] += MOD;
		}
	}
	new.data = copie;
	new.rows = a.rows;
	new.cols = a.cols;
	deallocate_matrix(result, index);
	result[index] = new;
}

mstruct strassen(mstruct a, mstruct b, int dim)
{
	mstruct final;
	final.data = alloc_matrix(dim, dim);
	final.rows = dim;
	final.cols = dim;

	if (dim == 1) {
		final.data[0][0] = (a.data[0][0] * b.data[0][0]) % MOD;
		if (final.data[0][0] < 0)
			final.data[0][0] += MOD;
		return final;
	}
	dim = dim / 2;
	mstruct *result = calloc(21, sizeof(mstruct));

	for (int i = 0; i < 8; i++) {
		result[i].rows = dim;
		result[i].cols = dim;
		result[i].data = alloc_matrix(dim, dim);
	}

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			result[0].data[i][j] = a.data[i][j];
			result[1].data[i][j] = a.data[i][j + dim];
			result[2].data[i][j] = a.data[i + dim][j];
			result[3].data[i][j] = a.data[i + dim][j + dim];
			result[4].data[i][j] = b.data[i][j];
			result[5].data[i][j] = b.data[i][j + dim];
			result[6].data[i][j] = b.data[i + dim][j];
			result[7].data[i][j] = b.data[i + dim][j + dim];
		}
	}

	// pentru M1
	sum_matrix(result[0], result[3], result, 19);		// A1+A4
	sum_matrix(result[4], result[7], result, 20);		// B1+B4
	result[12] = strassen(result[19], result[20], dim); // M1=(A1+A4)*(B1+B4)
	// pentru M2
	sum_matrix(result[2], result[3], result, 19);	   // A3+A4
	result[13] = strassen(result[19], result[4], dim); // M2=(A3+A4)*B1
	// pentru M3
	dif_matrix(result[5], result[7], result, 19);	   // B2-B4
	result[14] = strassen(result[0], result[19], dim); // M3=A1*(B2-B4)
	// pentru M4
	dif_matrix(result[6], result[4], result, 19);	   // B3-B1
	result[15] = strassen(result[3], result[19], dim); // M4=A4*(B3-B1)
	// pentru M5
	sum_matrix(result[0], result[1], result, 19);	   // A1+A2
	result[16] = strassen(result[19], result[7], dim); // M5=(A1+A2)*B4
	// pentru M6
	dif_matrix(result[2], result[0], result, 19);		// A3-A1
	sum_matrix(result[4], result[5], result, 20);		// B1+B2
	result[17] = strassen(result[19], result[20], dim); // M6=(A3-A1)*(B1+B2)
	// pentru M7
	dif_matrix(result[1], result[3], result, 19);		// A2-A4
	sum_matrix(result[6], result[7], result, 20);		// B3+B4
	result[18] = strassen(result[19], result[20], dim); // M7=(A2-A4)*(B3+B4)
	sum_matrix(result[12], result[15], result, 8);		// pentru C1 M1+M4
	dif_matrix(result[8], result[16], result, 8);		// M1+M4-M5
	sum_matrix(result[8], result[18], result, 8);		// M1+M4-M5+M7
	sum_matrix(result[14], result[16], result, 9);		// pentru C2 M3+M5
	sum_matrix(result[13], result[15], result, 10);		// pentru C3 M2+M4
	dif_matrix(result[12], result[13], result, 11);		// pentru C4 M1-M2
	sum_matrix(result[11], result[14], result, 11);		// M1-M2+M3
	sum_matrix(result[11], result[17], result, 11);		// M1-M2+M3+M6

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			final.data[i][j] = result[8].data[i][j];
			final.data[i][j + dim] = result[9].data[i][j];
			final.data[i + dim][j] = result[10].data[i][j];
			final.data[i + dim][j + dim] = result[11].data[i][j];
		}
	}
	for (int i = 0; i < 21; i++)
		free_matrix(result[i].data, dim);
	free(result);
	return final;
}

void function_d(mstruct *a, int i, int size)
{
	if (i < size && i >= 0)
		printf("%d %d\n", a[i].rows, a[i].cols);
	else
		printf("No matrix with the given index\n");
}

void function_f(mstruct *a, int *size, int index)
{
	for (int i = index; i < *size - 1; i++)
		a[i] = a[i + 1];
	(*size)--;
}

int main(void)
{
	int size = 0, index, i, m = 0, n = 0, l, c, i1, i2, putere, capacity = 1;
	char caract;
	int start = 1;
	mstruct *a = (mstruct *)malloc(capacity * sizeof(mstruct));
	while (start != 0) {
		scanf(" %c", &caract);
		switch (caract) {
		case 'L':
			scanf("%d%d", &m, &n);
			check_size(&a, &size, &capacity);
			a = resizeable_array(&a, &size, m, n); break;
		case 'D':
			scanf("%d", &i);
			function_d(a, i, size); break;
		case 'P':
			scanf("%d", &index);
			print_matrix(index, a, size); break;
		case 'M':
			scanf("%d%d", &i1, &i2);
			check_size(&a, &size, &capacity);
			multiply_matrix(i1, i2, &size, a); break;
		case 'T':
			scanf("%d", &index);
			transpunere_matrix(a, index, size); break;
		case 'F':
			scanf("%d", &index);
			if (index >= 0 && index < size) {
				deallocate_matrix(a, index);
				function_f(a, &size, index);
				check_size(&a, &size, &capacity);
			} else {
				printf("No matrix with the given index\n");
			}
			break;
		case 'O':
			sum(a, size);
			sort_matrix(size, a); break;
		case 'C':
			scanf("%d", &index), scanf("%d", &l);
			int *index_row = alloc_array(l);
			for (int i = 0; i < l; i++)
				scanf("%d", &index_row[i]);
			scanf("%d", &c);
			int *index_col = alloc_array(c);
			for (int j = 0; j < c; j++)
				scanf("%d", &index_col[j]);
			if (index >= 0 && index < size)
				redim(a, index, l, c, index_row, index_col);
			else
				printf("No matrix with the given index\n");
			free(index_row), free(index_col); break;
		case 'R':
			scanf("%d%d", &index, &putere);
			ridic_log_matrici(a, index, putere, size); break;
		case 'Q':
			for (int i = 0; i < size; i++)
				deallocate_matrix(a, i);
			free(a);
			start = 0; break;
		case 'S':
			scanf("%d%d", &i1, &i2);
			if (i1 < 0 || i1 >= size || i2 < 0 || i2 >= size) {
				printf("No matrix with the given index\n");
			} else if (a[i1].cols != a[i2].rows) {
				printf("Cannot perform matrix multiplication\n");
			} else {
				check_size(&a, &size, &capacity);
				a[size].rows = a[i1].rows;
				a[size].cols = a[i2].cols;
				a[size] = strassen(a[i1], a[i2], a[i1].rows);
				size++;
			}
			break;
		default:
			printf("Unrecognized command\n"); break;
		}
	}
	return 0;
}
