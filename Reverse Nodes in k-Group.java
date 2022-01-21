Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
         ListNode help = new ListNode(-1);
        help.next = head;
        ListNode pointer = help;
        
        while (pointer != null) {
            ListNode node = pointer;
            for (int i = 0; i < k && node != null; i++) node = node.next;
            if (node == null) break;
            
            ListNode prev = null, curr = pointer.next;
            for (int i = 0; i < k; i++) {
                ListNode next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
            }
            
            ListNode tail = pointer.next;
            tail.next = curr;
            pointer.next = prev;
            pointer = tail;
        }
        
        return help.next;
    }
}
