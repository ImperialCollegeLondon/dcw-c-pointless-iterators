#ifndef LIST_H
#define LIST_H

#define LISTNAMELEN 64

typedef struct list_s *listp; // a listp is a pointer to a list, i.e. a list!
struct list_s {
    char value[LISTNAMELEN];
    listp next;
};


// A listcallback is used for list_foreach..
typedef void (*listcallback)( const char *value, void * );

// Creates a new 1-element list and returns a pointer to it.
extern listp list_init(const char *);

// Pushes a node to the end of the list returning the altered list.
extern listp list_push(listp, const char *);

// Finds a specific word in the list and returns a pointer to it.
extern listp list_search(listp, const char *);

// Returns the head value of the list passed as parameter.
extern char *list_head(listp);

// Returns the tail of the list passed as parameter.
extern listp list_tail(listp);

// Iterate over a list <l>, calling the callback <cb> function for each
// value in l, passing that function the element value and v, a generic pointer
// that can store any value in it (or none).
extern void list_foreach( listp l, listcallback cb, void *v );

// Frees a list of values.
extern void list_free(listp);

#endif // LIST_H
