/*
 * DOUBLY CIRCULAR LINKED LIST
 *
 * It combines the two variants covered today:
 *   - from the doubly linked list: every node has both next and prev,
 *     so the list can be walked in either direction.
 *   - from the circular list: there is no NULL end. The last node's
 *     next points back to the head, and the head's prev points to
 *     the last node.
 *
 * Node layout is the same as a doubly linked list:
 *     struct dnode { int data; struct dnode *next; struct dnode *prev; };
 * Only the pointer rules change (no pointer is ever NULL in a
 * non-empty list).
 *
 * INVARIANTS (true for every node n in a non-empty list):
 *     n->next->prev == n
 *     n->prev->next == n
 *
 * SPECIAL CASES:
 *   - Empty list:  head == NULL (the only NULL in the whole design).
 *   - One node:    node->next == node and node->prev == node.
 *
 * WHAT GETS EASIER:
 *   - The tail is head->prev, so insert-at-end is O(1) with no
 *     walk to the last node (the circular singly list needed O(n)).
 *   - Deleting a node needs no head or tail special case in the
 *     unlinking step:
 *         n->prev->next = n->next;
 *         n->next->prev = n->prev;
 *     (only update head if n was the head, and set head = NULL
 *     when deleting the last remaining node).
 *   - Backward traversal starts at head->prev and goes to prev.
 *
 * WHAT STAYS TRICKY:
 *   - Traversal must still use do...while (current != head), not
 *     while (current != NULL), or it loops forever (task 6).
 *   - Insert and delete must update FOUR pointers (two per
 *     neighbour) instead of two. Forgetting one silently breaks
 *     the reverse direction.
 *   - Inserting into an empty list must set next and prev of the
 *     new node to itself, otherwise the circle is not closed.
 *
 * TRADE-OFF: extra memory for prev on every node, and more pointer
 * updates, in exchange for O(1) access to both ends and traversal
 * in both directions from anywhere.
 *
 * TYPICAL USES: round-robin schedulers, music or image playlists
 * that repeat, browser-style "next/previous" carousels, and the
 * circular buffers behind an LRU-style cache.
 */