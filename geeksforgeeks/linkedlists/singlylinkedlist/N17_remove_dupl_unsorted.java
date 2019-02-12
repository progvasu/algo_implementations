{
/* package whatever; // don't place package name! */
import java.util.*;
class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }
class N17_remove_dupl_unsorted
{
    Node head;  
	public void addToTheLast(Node node) 
	{
	  if (head == null) 
	  {
	   head = node;
	  } else 
	  {
	   Node temp = head;
	   while (temp.next != null)
		temp = temp.next;
	   temp.next = node;
	  }
	}
      void printList()
    {
        Node temp = head;
        while (temp != null)
        {
           System.out.print(temp.data+" ");
           temp = temp.next;
        }  
        System.out.println();
    }
	
	/* Drier program to test above functions */
	public static void main(String args[])
    {
       
        
        /* Constructed Linked List is 1->2->3->4->5->6->
           7->8->8->9->null */
         Scanner sc = new Scanner(System.in);
		 int t=sc.nextInt();
		  
		 while(t>0)
         {
			int n = sc.nextInt();
			Remove_Duplicate_From_LL llist = new Remove_Duplicate_From_LL();
			int a1=sc.nextInt();
			Node head= new Node(a1);
            llist.addToTheLast(head);
            for (int i = 1; i < n; i++) 
			{
				int a = sc.nextInt(); 
				llist.addToTheLast(new Node(a));
			}
		//llist.printList();	
        GfG g = new GfG();
		llist.head = g.removeDuplicates(llist.head);
		llist.printList();
		
        t--;		
        }
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of linked list is the following
class Node
{
    int data;
    Node next;
    Node(int d) {data = d; next = null; }
}
*/
class GfG
{
    Node removeDuplicates(Node head)
    {
        if (head == null)
            return head;
            
        HashSet<Integer> set = new HashSet<>();
        
        // since first element cant already exist!
        Node prev = head, curr = head.next;
        set.add(head.data);
        
        while (curr != null)    {
            // if element already exist in the set
            if (set.add(curr.data) == false)    {
                prev.next = curr.next;
            }
            else    {
                prev = curr;
            }
            
            curr = curr.next;
        }
        
        return head;
    }
}
