#ifndef SET_H /* make sure C compiler sees declarations only once */
#define SET_H

extern const void * Set; /* global variable */

void * add (void * set, const void * element); /* adds element to set, returns whatever was added or already present */
void * find(const void * set, const void * element); /* looks for element in set, returns whatever is present or NULL pointer */
void * drop(void * set, const void * element); /* locates an element, removes it from set, returns what was removed */ 
int contains (const void * set, const void * element); /* converts the result of find() into a truth value */

/* using void pointers to give ability to pass anything to functions */
/* sacrificing security for information hiding */

/* const void * points to memory that should not be modified */

#endif

