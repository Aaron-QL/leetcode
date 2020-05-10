/**
 * Definition for singly-linked list.
 */

 public class ListNode {
     int val;
     ListNode next;
     ListNode(int x) { val = x; }
 }

 class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
         ListNode dummyHead = new ListNode(0);
         ListNode p = l1, q = l2, cur = dummyHead;

         int x, y, sum, carry = 0;
         while (p != null || q != null) {
             x = p == null ? 0 : p.val;
             y = q == null ? 0 : q.val;
             sum = x + y + carry;
             carry = sum / 10;
             cur.next = new ListNode(sum % 10);
             cur = cur.next;
             if (p != null) {
                 p = p.next;
             }
             if (q != null) {
                 q = q.next;
             }
         }
         if (carry > 0) {
             cur.next = new ListNode(carry);
         }
         return dummyHead.next;
     }
 }