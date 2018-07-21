#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
//#include "dynamicArray.c"
typedef DynArr dynArray;


//https://oregonstate.instructure.com/courses/1714048/assignments/7297143?module_item_id=18107800

void dynArrayRemoveAt (struct dynArray * dy, int index);

struct dynArrayIterator {
   struct dynArray * da;
   int currentIndex; 
};

void dynArrayIteratorInit (struct dynArray *da, struct dynArrayIterator *itr) {
   

	assert(da);
	itr->da = da;
	itr->currentIndex = 0;


}

int dynArrayIteratorHasNext (struct dynArrayIterator *itr) {


	assert(itr);									// Verify that iterator isn't null.
	assert(itr->currentIndex >= 0);					// Verify that the current index isn't negative.

	//return(itr->currentIndex < itr->da->size);	// Alternative return statement.
	return(itr->currentIndex < sizeDynArr(itr->da));// Current value < size of the array.


}

TYPE dynArrayIteratorNext (struct dynArrayIterator *itr) {


	assert(itr);									// Verify that the iterator isn't null.
	assert(itr->currentIndex >= 0);					// Verify that the current index isn't < 0.
	assert(dynArrayIteratorHasNext(itr));
	return (itr->da->data[itr->currentIndex++]);	// Return the current index, then update the pointer to the currentIndex.


}

void dynArrayIteratorRemove (struct dynArrayIterator *itr) {


	removeAtDynArr(itr->da, itr->currentIndex);
	if (itr->currentIndex > 0) {
		itr->currentIndex--;
	}


}

int main() {

	return 0;
}