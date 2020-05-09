package main

/**
 * Definition for singly-linked list.
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    init := ListNode{}
    carry := 0
    cur := &init
    for l1 != nil || l2 != nil {
        x, y := 0, 0
        if l1 != nil {
            x = l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            y = l2.Val
            l2 = l2.Next
        }
        sum := x + y + carry
        cur.Next = &ListNode{sum % 10, nil}
        cur = cur.Next
        carry = sum / 10
    }
    if carry > 0 {
        cur.Next = &ListNode{1, nil}
    }
    return init.Next
}
