package n88graphRepresentation;

import java.util.Arrays;
import java.util.List;

/**
 *
 * @author vasu
 */

public class TestGraph {
    public static void main(String[] args)  {
        // input list of edges
        List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(1, 2), new Edge(2, 0), new Edge(2, 1),
                new Edge(3, 2), new Edge(4, 5), new Edge(5, 4));
        
        // create a new graph
        Graph graph = new Graph(6, 7);
        
        // add edges
        graph.addEdges(edges);
        
        // print graph
        graph.printGraph();
        
        System.out.println("");
        
        // print graph - weighted
        graph.printWeightedGraph();
    }
}
