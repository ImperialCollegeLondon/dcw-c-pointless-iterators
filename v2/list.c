#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "list.h"

listp list_init( const char *value )
{
    listp l = malloc(sizeof(*l));
    assert( l != NULL );

    nodep p = malloc(sizeof(*p));
    assert( p != NULL );

    assert( strlen(value) < LISTNAMELEN );
    strcpy(p->value, value);
    p->next = NULL;

    l->first = p;
    l->last = p;

    return l;
}


listp list_push( listp l, const char *value )
{
    if( l == NULL )
    {
        l = list_init(value);
        return l;
    }

    nodep e = malloc(sizeof(*e));
    assert( e != NULL );

    strcpy(e->value, value);
    e->next = NULL;

    l->last->next = e;
    l->last = e;

    return l;
}

nodep list_first( listp l )
{
    assert( l->first != NULL );
    return l->first;
}

char *list_head( nodep p )
{
    assert( p != NULL );
    return p->value;
}

nodep list_tail( nodep p )
{
    return p->next;
}

nodep list_search(listp l, const char *value)
{
    assert( l != NULL );
    nodep p = l->first;

    if( p == NULL )
    {
        printf( "WARN: Can't find any value on an empty listp.\n");
        return NULL;
    }

    for( ; p != NULL; p = p->next )
    {
        if( strcmp(p->value, value) == 0 )
	{
            return p;
        }
    }

    return NULL;
}


void list_foreach( listp l, listcallback cb, void *v )
{
    assert( cb != NULL );
    nodep p = l->first;
    for( ; p != NULL; p = p->next )
    {
	(*cb)( p->value, v );
    }
}


void list_free( listp l )
{
    nodep n=l->first;
    while( n != NULL )
    {
        nodep p = n;
        n = n->next;
        free(p);
    }
    free( l );
}
