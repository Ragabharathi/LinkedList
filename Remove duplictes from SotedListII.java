Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode help=new ListNode(0);
        ListNode tail=help;
        while(head!=null){
           if(head.next==null || head.val!=head.next.val){
             tail.next=head;
               tail=tail.next;
           }
            while(head.next!=null && head.val==head.next.val)head=head.next;
            head=head.next;
        }
        tail.next=null;
        return help.next;
    }
}
