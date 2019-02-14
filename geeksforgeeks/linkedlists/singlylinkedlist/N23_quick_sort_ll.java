import java.util.*;
import java.lang.*;
class Node 
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}
class N23_quick_sort_ll
{
    static Node head;
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0) 
        {
            int n = sc.nextInt();
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            addToTheLast(head);
            
            for(int i = 1; i< n; i++)
            {
                int a = sc.nextInt();
                addToTheLast(new Node(a));
            }
            
            GfG gfg = new GfG();
            Node node = gfg.quickSort(head);
            
            printList(node);
            System.out.println();
        }
    }
    public static void printList(Node head)
    {
        while(head != null)
        {
            System.out.print(head.data + " ");
            head = head.next;
        }
    }
    
    public static void addToTheLast(Node node) 
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
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/


/*node class of the linked list
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
    
}*/
// you have to complete this function
class GfG   {
    public static Node quickSort(Node node) {
        Node last = node;
        
        while (last.next != null)
            last = last.next;
            
        Node return_node = quick(node, last);
        
        return return_node;
    }
    
    public static Node quick(Node head, Node tail) {
        // print input sequence
        Node temp2 = head;
        while (temp2 != null)   {
            System.out.print(temp2.data + " ");
            temp2 = temp2.next;
        }
        System.out.println();
        
        // just one element
        if (head == tail)
            return head;
            
        // partition the list taking last node as pivot
        // if the node ele is less that pivot leave it there
        // otherwise move it at the end
        Node head1 = head;
        Node head2;
        Node tail1 = head;
        Node tail2 = tail;
        Node temp = head;
        
        while (tail1 != tail)    {
            if (tail1.data <= tail.data)    {
                temp = tail1;
                tail1 = tail1.next;
            }
            else    {
                // move tail1 node at the end
                tail2.next = tail1;
                // remove tail1 from the list
                if (tail1 == head1)  {
                    tail1 = tail1.next;
                    temp = tail1;
                    head1 = tail1;
                }
                else    {
                    // no need to move temp
                    temp.next = tail1.next;
                    tail1 = temp.next;    
                }
                tail2 = tail2.next;
                tail2.next = null;
            }
        }

        // set head2
        head2 = tail.next;
        // set tail1
        tail1 = head1;
        while (head1 != tail && tail1.next != tail)
            tail1 = tail1.next;

        // testing
        // print list 1 and list2
        // temp = head1;
        // while (temp != tail)
        //     System.out.print(temp.data + " ");
        // System.out.println();
        // temp = head2;
        // while (temp != null)
        //     System.out.print(temp.data + " ");
        
        // recur
        Node ret1 = null;
        if (head1 != tail)  {
            tail1.next = null;
            ret1 = quick(head1, tail1);
        }
        Node ret2 = null;
        if (head2 != null)  {
            tail2.next = null;
            ret2 = quick(head2, tail2);
        }
            
        if (ret1 == null)   {
            head = tail;
        }
        else    {
            head = ret1;
            // and set the tail to tail
            temp = head;
            while (temp.next != null)   {
                temp = temp.next;
            }
            temp.next = tail;
        }
            
        tail.next = ret2;
        
        return head;
    }
}