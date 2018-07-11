#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "list.h"

listp list_init( const char *value )
{
    listp l = malloc(sizeof(*l));
    assert( l != NULL );

    assert( strlen(value) < LISTNAMELEN );
    strcpy(l->value, value);
    l->next = NULL;

    return l;
}


listp list_push( listp l, const char *value )
{ 
    if( l == NULL )
    {
        l = list_init(value);
        return l;
    }

    // find last node on listp, hmm.. inefficient..
    listp last;
    for( last = l; last->next != NULL; last = last->next )
    {
    }

    listp e = malloc(sizeof(*e));
    assert( e != NULL );

    strcpy(e->value, value);
    e->next = NULL;

    last->next = e;

    return l;
}

char *list_head( listp l )
{
    return l->value;
}

listp list_tail( listp l )
{
    return l->next;
}

listp list_search( listp l, const char *value )
{
    if( l == NULL )
    {
        printf( "WARN: Can't find any value on an empty listp.\n");
        return NULL;
    }

    for( ; l != NULL; l = l->next )
    {
        if( strcmp(l->value, value) == 0 )
	{
            return l;
        }
    }

    return NULL;
}


void list_foreach( listp l, listcallback cb, void *v )
{
    assert( cb != NULL );
    for( ; l != NULL; l = l->next )
    {
	(*cb)( l->value, v );
    }
}


void list_free( listp  l)
{
    while( l != NULL )
    {
        listp p = l;
        l = l->next;
        free(p);
    }
}
