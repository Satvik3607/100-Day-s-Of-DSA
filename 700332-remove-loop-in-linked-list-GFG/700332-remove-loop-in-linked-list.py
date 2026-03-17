class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def removeLoop(self, head):
        if not head or not head.next:
            return

        slow = head
        fast = head

        # Step 1: Detect cycle
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                break
        else:
            return  # No loop

        # Step 2: Find start of loop
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next

        # Step 3: Find last node of loop
        ptr = fast
        while ptr.next != slow:
            ptr = ptr.next

        # Step 4: Break loop
        ptr.next = None