void swap (struct dyArray * v, int i, int j) {  /* swap elements i j */
      TYPE temp = dyArrayGet(v, i);  
      dyArrayPut(v, i, dyArrayGet(v, j)); 
      dyArrayPut(v, j, temp); 
   }

int indexSmallest (struct dyArray * v, int i, int j) {   
      /* return index of smallest element */
if (LT(dyArrayGet(v, i), dyArrayGet(v, j))  
         return i;
      return j;
   }
TYPE heapGetFirst (struct dyArray *heap) {   
      assert(dyArraySize(heap) > 0);    
return dyArrayGet(heap, 0);  
   }
void heapRemoveFirst(struct dyArray *heap) {
      int last = dyArraySize(heap)-1;
      assert(dyArraySize(heap) > 0);    /* make sure we have at least one element */
                    /* Copy the last element to the first  position */
      dyArrayPut(heap, 0, dyArrayrGet(heap, last)); 
      dyArrayRemoveAt(heap, last);       /* Remove last element.*/
      adjustHeap(heap, last, 0);/* Rebuild heap */
   }

void adjustHeap(struct dyArray * heap, int max, int pos) {

    int leftIdx = pos * 2 + 1;
    int rightIdx = pos * 2 + 2;

 

    if (leftIdx < max){
        if(leftIdx == max){
            max = leftIdx;
        }
        else{
            if(heap[leftIdx] <= heap[rightIdx])
            max = rightIdx;
            else
            max = leftIdx
        }

    }


   else if (heap[pos] <= heap[max]){
       swap(heap, pos, max);
       adjustHeap(dyArray, max, pos)
    }
}


void heapAdd(struct dyArray * heap, TYPE newValue) {

    int parent;

    int pos = dyArraySize(heap);
    dyArrayAdd(heap, newValue);

    while(pos != 0){
        parent = (pos - 1) / 2;
        if(compare(dyArrayGet(heap, pos),dyArrayGet(heap, parent)) === - 1){
            swap(heap,parent,pos);
            pos = parent;
        } else return;
    }
}