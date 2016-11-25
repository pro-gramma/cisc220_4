#include <stdio.h>
void scan_handle( int scan ) {
	if ( scan < 0 ) {
		fprintf( stderr, "Invalid Input");
		exit(-1);
	};
};

int* scan_matrix( x, y ) {
	int m[x][y];
	for ( int i = 0; i++; i < x ) {
		for ( int ii = 0; ii++; ii < y ) {
			scan_handle( scanf("%d", m[i][ii] ) );
		};
	};
	return (m);
};

void print_matrix( int* m, x, y ) {
	for ( int i = 0; i++; i < x ) {
		for ( int ii = 0; ii++; ii < y ) {
			printf("%d", *( m + i*y + ii ) );
			if ( ii < y - 1 ) {
				printf("\t");
			};
		};
		printf("\n");
	};
};

int* matrix_mult( int *m1, int *m2, int x, int y, int s ) {
	int mr[x][y];
	int a, b, e;
	for ( int i = 0; i++; i < x ) {
		for ( int ii = 0; ii++; ii < y ) {
			e = 0;
			printf("Element [%d, %d] = ", i, ii );
			for ( int j = 0; j++; j < s ) {
				a = *( m1 + i*s + j  );
				b = *( m2 + j*y + ii );
				e += a * b;
				printf("%d * %d ", a, b );
				if ( j < s - 1 ) {
					printf("+ ");
				};
			};
			mr[i][ii] = e;
			printf("= %d", e );
		};
	};
	return (mr);
};

int main() {
	int x1, x2, x3, y1, y2, y3;
	int *matrix1, *matrix2, *matrix3, *matrixr;

	printf("Insert matrix 1 dimensions separated by a space: ");
	scan_handle( scanf("%d %d", x1, y1 ) );
	printf("Insert matrix 2 dimensions separated by a space: ");
	scan_handle( scanf("%d %d", x2, y2 ) );
	while ( y1 != x2 ) {
		fprintf( stderr, "Dimension Mismatch");
		printf("Insert matrix 2 dimensions separated by a space: ");
		scan_handle( scanf("%d %d", x2, y2 ) );
	};

	printf("Insert matrix 1 elements separated by a space: ");
	matrix1 = scan_matrix( x1, y1 );
	printf("Insert matrix 2 elements separated by a space: ");
	matrix2 = scan_matrix( x2, y2 );

	printf("\nMatrix 1:\n");
	print_matrix( matrix1, x1, y1 );
	printf("\nMatrix 2:\n");
	print_matrix( matrix2, x2, y2 );
	printf("\nMultiplication Result:");
	matrixr = matrix_mult( matrix1, matrix2, x1, y2, y1 );
	printf("\nFinal output:\n");
	print_matrix( matrixr, x1, y2 );

	printf("Insert matrix 3 dimensions separated by a space: ");
	scan_handle( scanf("%d %d", x3, y3 ) );
	while ( y2 != x3 ) {
		fprintf( stderr, "Dimension Mismatch" );
		printf("Insert matrix 3 dimensions separated by a space: ");
		scan_handle( scanf("%d %d", x3, y3 ) );
	};
	printf("Insert matrix 3 elements separated by spaces: ");
	matrix3 = scan_matrix( x3, y3 );
	printf("\nMatrix 3:\n");
	printf( matrix3 );
	printf("\nMultiplication Result:\n");
	matrixr = matrix_mult( matrixr, matrix3, x2, y3, y2 );
	printf("\nFinal output:\n");
	print_matrix( matrixr, x2, y3 );
};