
//https://oregonstate.instructure.com/courses/1714048/assignments/7297144?module_item_id=18107801

struct linkedListIterator {
   struct linkedList * lst;
   struct dLink * currentLink;
}

void linkedListIteratorInit (struct linkedList  *lst, struct linkedListIterator * itr) {
    itr->lst = lst;
    itr->currentLink = lst->frontSentinel;
}

void _removeLink (struct linkedList  *lst, struct dLink * lnk);

int linkedListIteratorHasNext (struct linkedListIterator *itr) {


    int linkedListIteratorHasNext(struct linkedListIterator *itr) {
        if (itr->currentLink->next != itr->lst->backSentinel) {
            itr->currentLink = itr->lst->next;
            return 1;
        }
        else {
            return 0;
        }


}

TYPE linkedListIteratorNext (struct linkedListIterator *itr) {
	return itr->currentLink->value;

}

/* think about the next one carefully. Draw a picture. What should itr->currentLink 
be pointing to after the remove operation? */

void linkedListIteratorRemove (struct linkedListIterator *itr) {
   
	struct dlink* tmp = itr->currentLink;
	itr->currentLink = itr->currentLink->prev;
	_removeLink(itr->lst, tmp);

}
