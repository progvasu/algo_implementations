package n101bstTrees;

/**
 *
 * @author vasu
 */

public class TestBST {
    public static void main(String[] args)  {   
        BST obj = new BST();
        
        obj.insert(10);
        obj.insert(5);
        obj.insert(25);
        obj.insert(1);
        obj.insert(3);
        obj.insert(45);
        obj.insert(34);
        obj.insert(23);
        
        obj.treePrint();
    
//        obj.delete(10);
//        obj.delete(5);
//        obj.delete(25);
//        obj.delete(1);
//        obj.delete(3);
//        obj.delete(45);
//        obj.delete(34);
//        obj.delete(23);
        
//        obj.treePrint();
        
        System.out.println("Rank: " + obj.findRank(10));
        System.out.println("Rank: " + obj.findRank(5));
        System.out.println("Rank: " + obj.findRank(25));
        System.out.println("Rank: " + obj.findRank(1));
        System.out.println("Rank: " + obj.findRank(3));
        System.out.println("Rank: " + obj.findRank(45));
        System.out.println("Rank: " + obj.findRank(34));
        System.out.println("Rank: " + obj.findRank(23));
    }
}
