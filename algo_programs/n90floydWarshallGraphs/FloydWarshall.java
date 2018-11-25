package n90floydWarshallGraphs;

/**
 *
 * @author vasu
 */

public class FloydWarshall {
    int graph[][];
    int result[][];
    int next[][];
    int numSP[][];
    
    public FloydWarshall(int AM[][]) {
        this.graph = AM;
        this.result = new int[graph.length][graph.length];
        this.next = new int[graph.length][graph.length];
        this.numSP = new int[graph.length][graph.length];
        
        // Also initializing number of shortest paths
        // Need to initializa pred to -1 otherwise ir considers zero as the next vertex
        for (int i = 0 ; i < graph.length ; i++)
            for (int j = 0 ; j < graph.length ; j++)    {
                if (graph[i][j] == 99)
                    next[i][j] = -1;
                else    {
                    next[i][j] = i;
                    numSP[i][j] = 1;
                }
            }
    }
    
    public void computeShortestPaths() {
        result = graph;
        
        int n = result.length;
        
        // induction
        for(int k = 0 ; k < n ; k++)    {
            for(int i = 0 ; i < n ; i++)    {
                for (int j = 0 ; j < n ; j++)   {
                    if (result[i][k] + result[k][j] < result[i][j]) {
                        result[i][j] = result[i][k] + result[k][j];
                        // previous node rather than any intermediate node
                        next[i][j] = next[k][j];
                        // number of shortest paths
                        numSP[i][j] = (numSP[i][k] * numSP[k][j]);
                    }
                    else if (result[i][k] + result[k][j] == result[i][j])   {
                        numSP[i][j] += (numSP[i][k] * numSP[k][j]);
                    }
                }
            }
        }
        
    }
    
    public void printResult ()    {
        System.out.println("Distance Matrix: ");
        
        // first row vertex numbers
        System.out.printf("%3s", " ");
        for(int i = 0 ; i < result.length ; i++)
            System.out.printf("%3d", i);
        System.out.println("");
        for(int i = 0 ; i < result.length ; i++)   {
            System.out.printf("%3d", i);
            for(int j = 0 ; j < result.length ; j++)   {
                System.out.printf("%3d", result[i][j]);
            }
            System.out.println("");
        }
        System.out.println("");
        
        System.out.println("\nParent Matrix: ");
        
        // first row vertex numbers
        System.out.printf("%3s", " ");
        for(int i = 0 ; i < next.length ; i++)
            System.out.printf("%3d", i);
        System.out.println("");
        for(int i = 0 ; i < next.length ; i++)   {
            System.out.printf("%3d", i);
            for(int j = 0 ; j < next.length ; j++)   {
                System.out.printf("%3d", next[i][j]);
            }
            System.out.println("");
        }
        System.out.println("");
        
        System.out.println("\nNumber of SP Paths Matrix: ");
        
        for(int[] row : numSP)    {
            // loop through all columns of current row 
            for(int x : row) 
                System.out.printf("%5d", x);
            System.out.println();
        }
    }
    
    public void printPathBetween(int start, int end)    {
        System.out.print("\nPath between " + start + " and " + end + ": ");
        printPath(start, end);
        System.out.println();
    }
    
    private void printPath(int start, int end)   {
        if (start == end)
            System.out.print(start);
        else if (next[start][end] == -1)
            System.out.println("No Path Exists!!!");
        else    {
            printPath(start, next[start][end]);
            System.out.print(" ---> " + end);
        }
    }
}
