

         Dynamic Array Bag	LinkedListBag	Ordered Array Bag
Add	        O(1)	                 O(1)               O(n)
Contains	O(n)	                 O(n)               O(logn)
Remove	    O(n)	                 O(n) 	            O(n)


Short Answers 

1.	What is the algorithmic complexity of the binary search algorithm? O(logn)

2.	Using your answer to the previous question, what is the algorithmic complex of the method contains for an OrderedArrayBag? O(logn)

3.	What is the algorithmic complexity of the method addAt? O(n)

4.	Using your answer to the previous question, what is the algorithmic complexity of the method add for an OrderedArrayBag? O(n)

5.	What is the complexity of the method removeAt? of the method remove? O(n)



/*Assume you have access to all existing dynArr functions */
/* _binarySearch is also included in dynArr.c now as an internal function! */
int _binarySearch(TYPE *data, int size, TYPE testValue);


/* These are the new functions to take advantage of the ordered dynamic array 
   and available to the end user , so they will be declared in the .h file */

int dyArrayBinarySearch (struct dyArray * da, TYPE testValue) {
   return _binarySearch (da->data, da->size, testValue); }

void orderedArrayAdd (struct dyArray *da, TYPE newElement) {
   int index = _binarySearch(da->data, da->size, newElement);
   dyArrayAddAt (da, index, newElement);  /* takes care of resize if necessary*/
}


   /* you must complete the following */

 int orderedArrayContains (struct dyArray *da, TYPE testElement) {

   if (dyArrayBinarySearch(da,testElement)) {
       return 1;
   } else {
       return 0;
   }
}

 void orderedArrayRemove (struct dyArray *da, TYPE testElement) {
    int index = dyArrayBinarySearch(da,testElement);
    if (index > -1) {
        for (int i = (da->size - 1); i > index; i--) {
            da->data[i-1] = da->data[i];
        }
    }
}

