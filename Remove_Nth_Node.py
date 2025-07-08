# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """

        ''' HEAD means the start pointer'''
        temp = head
        length = 0

        while(temp):
            temp = temp.next
            length +=1

        #To remove the first node (n=length)
        if n == length:
            head = head.next       #This makes the Head to point to the second node
            
            return head

        temp = head
        for _ in range(1,length - n):
            temp = temp.next           # The (length - n)th node

        temp.next = temp.next.next

        return head


        