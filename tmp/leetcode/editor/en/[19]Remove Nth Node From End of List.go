package en

//leetcode submit region begin(Prohibit modification and deletion)

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	delIndex := &ListNode{Val: 0, Next: head}
	current := delIndex
    for i := n; i >= 0; i-- {
    	current = current.Next
	}
	for current != nil {
		current = current.Next
		delIndex = delIndex.Next
	}
	delIndex.Next = delIndex.Next.Next
	return head
}
//leetcode submit region end(Prohibit modification and deletion)
