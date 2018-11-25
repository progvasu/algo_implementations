package n108beautifulNodes;

import java.util.Arrays;
import java.util.List;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;

/**
 *
 * @author vasu
 */

public class CountBN {
    public static void main(String[] args) {
        // input will be a tree
        Graph graph = new Graph(7, 6);
        
        // add edges
        List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(0, 4), new Edge(1, 2), 
                new Edge(1, 3), new Edge(4, 5), new Edge(5, 6));
        
        graph.addEdges(edges);
        graph.printGraph();
        
        // setting weights of vertices
        int[] prior = new int[]{12, 24, 5, 8, 14, 13, 6};
        for (int i = 0 ; i < graph.getN() ; i++)   {
            graph.getVertex(i).setWeight(prior[i]);
        }
        
        ModiDFSRecur obj = new ModiDFSRecur(graph);
        
        // we do modified DFS
        System.out.println("No BN: " + obj.computeDFSRecur(0));
    }
}
