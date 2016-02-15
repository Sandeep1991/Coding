#Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

#You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.


class  Solution (Object) :
    def  oddEvenList (self, head) :
        """
        : Type head: ListNode
        : Rtype: ListNode
        """
        if head is  None : return head
        odd = oddHead = head
        even = evenHead = head.next
        while even and even.next:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next
        odd.next = evenHead
        return oddHead
mySolution = Solution()
