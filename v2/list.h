#ifndef LIST_H
#define LIST_H

#define LISTNAMELEN 64

typedef struct node_s *nodep;	// nodep: a pointer to a node in a list
struct node_s {
    char value[LISTNAMELEN];
    nodep next;
};

typedef struct list_s *listp; // a listp is a pointer to a list, i.e. a list!
struct list_s {
    nodep first;
    nodep last;
};

// A listcallback is used for list_foreach..
typedef void (*listcallback)( const char *value, void * );

// Creates a new list and returns a pointer to it.
extern listp list_init(const char *);

// Pushes a node to the end of the list returning the altered list.
extern listp list_push(listp, const char *);

// Finds a specific word in a node on the list and returns a node pointer to it.
extern nodep list_search(listp, const char *);

// Returns the pointer to the first node of the given list.
extern nodep list_first(listp);

// Returns the head value of the given node.
extern char *list_head(nodep);

// Returns the tail of the the given node.
extern nodep list_tail(nodep);

// Iterate over a list <l>, calling the callback <cb> function for each
// value in l, passing that function the element value and v, a generic pointer
// that can store any value in it (or none).
extern void list_foreach( listp l, listcallback cb, void *v );

// Frees a list of values.
extern void list_free(listp);

#endif // LIST_H
