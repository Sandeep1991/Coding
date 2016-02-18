"""
class Solution(object):
    def mergeTwoLists(self,l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None:
		return l2
	if l2 == None:
		return l1
        new_list = []
        cnt = 0
        cnt1 = 0
        #print len(l1)
        while l1 and l2:
            if l1[0] < l2[0]:
                new_list.append(l1.pop(0))
            else:
                new_list.append(l2.pop(0))
        new_list = new_list + l1 + l2
        return new_list
"""
#The above solution works only for inputs given as arrays not as linked list
#The leet code challenge was to perform on the linked list:



class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        head = None
        runner = None
        while l1 and l2:
            if not head:
                if l1.val <= l2.val:
                    head = l1
                    runner = head
                    l1 = l1.next
                else:
                    head = l2
                    runner = head
                    l2 = l2.next
            else:
                if l1.val <= l2.val:
                    runner.next = l1
                    runner = runner.next
                    l1 = l1.next
                else:
                    runner.next = l2
                    runner = runner.next
                    l2 = l2.next
        if l1:
            runner.next = l1
        if l2:
            runner.next = l2
        return head















        
        
        
        
