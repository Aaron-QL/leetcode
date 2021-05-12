package en

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
    cur := head
    for cur.Next != nil {
    	revNode := cur.Next
    	cur.Next = revNode.Next
    	revNode.Next = head
    	head = revNode
	}
	return head
}
//leetcode submit region end(Prohibit modification and deletion)
