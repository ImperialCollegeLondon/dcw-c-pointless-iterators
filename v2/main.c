#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "list.h"


static char *words[] =
{
    "something",
    "campos",
    "nunes",
    "rafael",
    NULL
};

static void checkwords( listp mylist )
{
    size_t i = 0;
    for( nodep p = list_first(mylist); p != NULL; p = list_tail(p) )
    {
        char *word = list_head(p);
        if( strcmp(words[i], word) == 0 )
	{
		printf("OK %s\n", word);
	} else
	{
		printf("FAIL expected %s, found %s\n", words[i], word);
	}
	i++;
    }
}

// checkword callback: v is a disguised int *, call it wdno, words[*wdno] is
// the current expected word this time, increment (*wdno) each time.
static void checkword_cb( const char *value, void *v )
{
	int *wdno = v;
	char *expected = words[*wdno];
	assert( expected != NULL );
	(*wdno)++;
        if( strcmp(expected, value) == 0 )
	{
		printf("OK %s\n", value);
	} else
	{
		printf("FAIL expected %s, found %s\n", expected, value);
	}
}

static void checkwords_via_foreach( listp mylist )
{
	int i = 0;
	list_foreach( mylist, checkword_cb, (void *)&i );
}

int main( int argc, char **argv )
{
	listp mylist = NULL;
	for( int i=0; words[i] != NULL; i++ )
	{
	    mylist = list_push( mylist, words[i] );
	}

	checkwords( mylist );
	checkwords_via_foreach( mylist );

	list_free( mylist );

	return 0;
}
