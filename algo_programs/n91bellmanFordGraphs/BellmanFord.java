package n91bellmanFordGraphs;

import n88graphRepresentation.Graph;
import n88graphRepresentation.Edge;

/**
 *
 * @author vasu
 */

public class BellmanFord {
    Graph graph;
    
    BellmanFord(Graph g)   {
        this.graph = g;
    }
    
    public void computeSSSP(int source)   {
        int[] result = new int[graph.getN()];
        int[] predr = new int[graph.getN()];
                
        // intially all distances are infinity and parent NULL = -1 assume
        for (int i = 0 ; i < graph.getN() ; i++)    {
            result[i] = 999;
            predr[i] = -1;
        }
        
        // distance from source to source is zero
        result[source] = 0;
        // parent is node itself
        predr[source] = source;
        
        // base case - intialize direct edges
        for (Edge edge : graph.getEdgeList(source))     {
            result[edge.getDest()] = edge.getWeight();
            predr[edge.getDest()] = source;
        }
        
        // source, dest and weight of an edge
        int u, v, w;
        
        // induction - relazing edges k times
        for (int k = 1 ; k < graph.getN() ; k++)    {
            for (Edge edge : graph.getAllEdges())   {
                u = edge.getSrc();
                v = edge.getDest();
                w = edge.getWeight();
                
                if (result[u] + w < result[v])  {
                    result[v] = result[u] + w;
                    predr[v] = u;
                }
            }
        }
        
        // printing shortest path distance to every other node
        printSSSPDistance(source, result);
        
        // printing shortest path
        for (int i = 0 ; i < graph.getN() ; i++)    {
            System.out.print("\nPath to " + i + ": " + source);
            printSSSPPath(source, i, predr);
        }
        System.out.println("");
    }
    
    private void printSSSPDistance(int source, int[] result)    {
        System.out.println("\nShortest Path from " + source + " to every other vertex:");
        for (int i = 0 ; i < graph.getN() ; i++)    {
            System.out.printf("%4s", i);
        }
        System.out.println("");
        for (int i = 0 ; i < graph.getN() ; i++)    {
            if (result[i] != 999)
                System.out.printf("%4s", result[i]);
            else
                System.out.printf("%4s", "--");
        }
        System.out.println("");
    }
    
    private void printSSSPPath(int source, int destn, int[] predr)  {
        if (predr[destn] == -1) {
            System.out.println("\nNo Path Exists");
        }
        else if (predr[destn] != destn) {
            printSSSPPath(source, predr[destn], predr);
            // print path in correct order from the recursive stack
            System.out.print(" --> " + destn);
        }
    }
}