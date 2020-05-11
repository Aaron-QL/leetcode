/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    p, q := head, head
    for n > 0 {
        p = p.Next
        n--
    }
    if p == nil {
        return q.Next
    }
    for p.Next != nil {
        p = p.Next
        q = q.Next
    }
    q.Next = q.Next.Next
    return head
}
