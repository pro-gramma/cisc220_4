/*James Neverson 10193581*/ 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main( int argc, char* argv[] ) {
	int last, next;
	char *wp;
	FILE *fp = fopen( argv[0], "r+");
	while ( ! feof(fp) ) {
		last = ftell(fp);
		fscanf( fp, "%s", wp );
		next = ftell(fp);
		fseek( fp, last+1, SEEK_SET );
		fprintf( fp, "%c", toupper( *wp ));
		fseek( fp, next, SEEK_SET );
	};
	fseek( fp, 0, SEEK_SET );
	fgets( buff, 255, fp );
	printf("%s\n", buff );
	fclose(fp);
	return (0);
};
