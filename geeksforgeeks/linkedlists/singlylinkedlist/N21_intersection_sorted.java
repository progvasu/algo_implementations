import java.util.Scanner;
import java.util.*; 

class Node  { 
  int data;
    Node next;
    Node(int d) {
      data = d; 
      next = null; 
    }
}

public class N21_intersection_sorted {
  Node head;  
  
  public void addToTheLast(Node node) {
    if (head == null) {
      head = node;
    } 
    else {
      Node temp = head;
      while (temp.next != null)
        temp = temp.next;
      temp.next = node;
    }
  }

  /* Function to print linked list */
  public void printList(Node head)
  {
    Node temp = head;
  
    if(temp == null)
      System.out.print("NO");
    else  {
      while (temp != null)  {
        System.out.print(temp.data+" ");
        temp = temp.next;
      }  
    }
  }
  
  /* Drier program to test above functions */
  public static void main(String args[])  {
    Scanner sc = new Scanner(System.in);
    int t=sc.nextInt();
    
    while(t>0)  {
      N21_intersection_sorted llist1 = new N21_intersection_sorted();
      N21_intersection_sorted llist2 = new N21_intersection_sorted();
      
      int n1 = sc.nextInt();
      int n2 = sc.nextInt();
    
      int a1=sc.nextInt();
      Node head1= new Node(a1);
      llist1.addToTheLast(head1);
            
      for (int i = 1; i < n1; i++) {
        int a = sc.nextInt(); 
        llist1.addToTheLast(new Node(a));
      }
        
      int b1=sc.nextInt();
      Node head2 = new Node(b1);
      llist2.addToTheLast(head2);
           
      for (int i = 1; i < n2; i++) {
        int b = sc.nextInt(); 
        llist2.addToTheLast(new Node(b));
      }
      
      GfG obj = new GfG();
      obj.getIntersection(llist1.head,llist2.head);
      
      llist2.printList(obj.llist3.head);
      System.out.println();
      t--;
    } // end of while
  } // end of main
} // end of main Intersect class

class GfG
{
    N21_intersection_sorted llist3 = new N21_intersection_sorted();

    void getIntersection(Node head1, Node head2)
    {   
        llist3.head = null;
        
        Node temp1 = head1;
        Node temp2 = head2;
        Node temp = null;
        
        while (temp1 != null && temp2 != null)  {
          // System.out.println("temp1: " + temp1.data + " temp2: " + temp2.data);
          if (temp1.data == temp2.data) {
              if (llist3.head == null)  {
                  llist3.head = temp1;
                  temp = llist3.head;
                  temp.next = null;
              }
              else    {
                  temp.next = temp1;
                  // System.out.println(temp.data);
                  temp = temp.next;
                  temp.next = null;
              }
              temp1 = temp1.next;
              temp2 = temp2.next;
          }
          else {
              if (temp1.data < temp2.data)
                  temp1 = temp1.next;
              else
                  temp2 = temp2.next;
          }
        }
    }
}