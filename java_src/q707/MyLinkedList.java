package q707;

public class MyLinkedList {
    private class ListNode {
        int val;
        ListNode prev;
        ListNode next;
        ListNode(int x) {
            this.val = x;
        }
        ListNode(int x, ListNode prev, ListNode next) {
            this.val = x;
            this.prev = prev;
            this.next = next;
        }
    }

    private ListNode head;
    private ListNode tail;
    private int size = 0;
    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = new ListNode(-1);
        tail = head;
        size = 0;
    }

    public boolean empty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        ListNode node = getNodeAt(index);
        if (node == null) {
            return -1;
        }
        return node.val;
    }

    public void addNode(ListNode prevNode, int val) {
        ListNode nextNode = prevNode.next;
        ListNode newNode = new ListNode(val, prevNode, nextNode);

        prevNode.next = newNode;
        if (nextNode != null) {
            nextNode.prev = newNode;
        }
        size++;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        ListNode listNode = new ListNode(val);
        if (empty()) {
            tail = listNode;
        } else {
            listNode.next = head;
            head.prev = listNode;
        }
        head = listNode;
        size++;
    }

    public void deleteAtHead() {
        if (empty()) {
            return;
        }
        if (size == 1) {
            head = null;
            tail = null;
        } else {
            head = head.next;
            head.prev = null;
        }
        size--;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        ListNode listNode = new ListNode(val);
        if (empty()) {
            head = listNode;
        } else {
            tail.next = listNode;
            listNode.prev = tail;
        }
        tail = listNode;
        size++;
    }

    public void deleteAtTail() {
        if (empty()) {
            return;
        }
        if (size == 1) {
            head = null;
            tail = null;
        } else {
            tail = tail.prev;
            tail.next = null;
        }
        size--;
    }

    public ListNode getNodeAt(int index){
        if (index < 0 || index >= size) {
            return null;
        }
        if ((size / 2) <= index) {
            ListNode node = tail;
            int moves = size - 1 - index;
            for (int i = 0; i < moves; i++) {
                node = node.prev;
            }
            return node;
        } else {
            ListNode node = head.next;
            for (int i = 0; i < index; i++) {
                node = node.next;
            }
            return node;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
            ListNode prev = getNodeAt(index - 1);
            ListNode forw = prev.next;
            ListNode curr = new ListNode(val, prev, forw);
            prev.next = curr;
            forw.prev = curr;
            size++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        if (index == 0) {
            deleteAtHead();
        } else if (index == (size - 1)) {
            deleteAtTail();
        } else {
            ListNode prev = getNodeAt(index - 1);
            ListNode forw = prev.next.next;
            prev.next = forw;
            forw.prev = prev;
            size--;
        }
    }
}
