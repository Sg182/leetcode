'''You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
     Add the two numbers and return the sum as a linked list.'''

#Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        start = ListNode(0)
        carry = 0
        current = start
        
        while l1 or l2 or carry:
            sum = carry
            
            if l1:
                sum = sum + l1.val
                l1 = l1.next

            if l2:
                sum = sum + l2.val
                l2 = l2.next

            carry = sum//10
            current.next = ListNode(sum%10)  #To add the value of the digit (other than the carry on) e.g 13%10 = 3 
            current = current.next
             
        return start.next
            

             