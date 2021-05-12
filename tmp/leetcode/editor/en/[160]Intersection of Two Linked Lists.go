package en

//leetcode submit region begin(Prohibit modification and deletion)
type ListNode struct {
     Val int
     Next *ListNode
 }
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	ha, hb := headA, headB
	for ha != hb {
		if ha != nil {
			ha = ha.Next
		} else {
			ha = headB
		}
		if hb != nil {
			hb = hb.Next
		} else {
			hb = headA
		}
	}
	return ha
}
//leetcode submit region end(Prohibit modification and deletion)
