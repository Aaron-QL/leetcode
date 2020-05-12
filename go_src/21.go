/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    r := &ListNode{}
    cur := r
    for l1 != nil && l2 != nil {
        if l1.Val < l2.Val {
            cur.Next = &ListNode{Val: l1.Val}
            l1 = l1.Next
        } else {
            cur.Next = &ListNode{Val: l2.Val}
            l2 = l2.Next
        }
        cur = cur.Next
    }
    for l1 != nil {
        cur.Next = &ListNode{Val: l1.Val}
        l1 = l1.Next
        cur = cur.Next
    }
    for l2 != nil {
        cur.Next = &ListNode{Val: l2.Val}
        l2 = l2.Next
        cur = cur.Next
    }
    return r.Next
}
