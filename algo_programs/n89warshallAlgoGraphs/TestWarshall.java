package n89warshallAlgoGraphs;

/**
 *
 * @author vasu
 */

public class TestWarshall {
    public static void main(String[] args) {
//        int graph[][] = new int[][]{    {1, 1, 0, 1}, 
//                                        {0, 1, 1, 0}, 
//                                        {0, 0, 1, 1}, 
//                                        {0, 0, 0, 1}    };
//      
        // Another Example - 2
//        int graph[][] = new int[][]{    {1, 1, 1, 0},
//                                        {0, 1, 1, 0},
//                                        {1, 0, 1, 1},
//                                        {0, 0, 0, 1}    };
        
        // Another Example - 3
//        int graph[][] = new int[][]{    {0, 0, 1, 0},
//                                        {1, 0, 0, 1},
//                                        {0, 0, 0, 0},
//                                        {0, 1, 0, 0}        };
                
        // Another Example - 3
        int graph[][] = new int[][]{    {0, 1, 0, 0},
                                        {0, 0, 0, 1},
                                        {0, 0, 0, 0},
                                        {1, 0, 1, 0}    };
                
        Warshall obj = new Warshall();
        
        int result[][] = obj.computeTraversal(graph);
        obj.printResult(result);
    }
}
