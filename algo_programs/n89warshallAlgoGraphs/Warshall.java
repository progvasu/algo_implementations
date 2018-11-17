package n89warshallAlgoGraphs;

// here we need just the adjacency matrix representation so not using out
// graph classes
// AM captures everything

/**
 *
 * @author vasu
 */

public class Warshall {
    public int[][] computeTraversal (int graph[][]) {
        // initialization for direct graphs
        int result[][] = graph;
        
        int n = graph.length;
        
        for(int k = 0 ; k < n ; k++)    {
            for(int i = 0 ; i < n ; i++)    {
                for (int j = 0 ; j < n ; j++)   {
                    if (result[i][j] == 0 && result[i][k] == 1 && result[k][j] == 1)
                        result[i][j] = 1;
                }
            }
            
//            printResult(result);
        }
        
        return result;
    }
    
    public void printResult (int result[][])    {
        System.out.println("Result Matrix: ");
        
        for(int[] row : result)    {
            // loop through all columns of current row 
            for(int x : row) 
                System.out.print(x + " ");
            System.out.println();
        }
    }
}
