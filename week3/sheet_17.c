#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TYPE int

struct link {					// Single link.
	TYPE value;					// Data contained by this link.
	struct link * next;			// Pointer to the next link.
};

struct linkedListStack {
	struct link *firstLink;		// Initialize routine sets to zero/NULL.
};

void linkedListStackInit(struct linkedListStack * s)
{
	s->firstLink = 0;
}

void linkedListStackPush(struct linkedListStack *s, TYPE d) {
	struct link * newLink = (struct link *) malloc(sizeof(struct link));
	assert(newLink != 0);

		//add value to the new link
   newLink->value = d;
  
  		//connect the link to the stack
   newLink->next = s->fistLink;
  
  		//redirect the first link pointer to the new head
   s->firstLink = newLink;
}

TYPE linkedListStackTop(struct linkedListStack *s) {
	/* Fix me */
	assert(!linkedListStackIsEmpty(s));
	return s->firstLink->value;
}

void linkedListStackPop(struct linkedListStack *s) {
	assert(!linkedListStackIsEmpty(s));
			//store the new head address
	struct link* tempPtr;
	tempPtr = s->fistLink->next;
  		
  		//free the old head memory
  	free(s->firstLink);
  		
  		//point to the new head
  	s->firstLink = tempPtr;
  
 		//set temp to null
  	tempPtr = 0;
}

int linkedListStackIsEmpty(struct linkedListStack *s) {
	return s->firstLink == 0;
}


void linkedListStackFree(struct linkedListStack *s)
{
	while (!linkedListStackIsEmpty(s)) {
        linkedListStackPop(s);
    }
}

int main() {

	return 0;
}
