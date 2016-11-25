/*James Neverson 10193581*/
#include <stdio.h>
#include <string.h>
char* safestrcat( char *a, char *b ) {
	char* catstr[sizeof(a)+sizeof(b)];
	strcopy( catstr, a );
	strat( catstr, b );
	return (catstr);
};

int substring( char *source, int from, int n, char *target ) {
	if ( from + n < 0 || from + n > strlen( source ) ) {
		return (-1);
	};
	source += from;
	strncopy( target, source, n );
	return (0);
};
