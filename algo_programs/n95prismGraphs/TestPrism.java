package n95prismGraphs;

import java.util.Arrays;
import java.util.List;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;

/**
 *
 * @author vasu
 */

public class TestPrism {
    public static void main(String[] args)  {
        // ONLY FOR UNDIRECTED GRAPHS
    
        // Example - 1
//        Graph graph = new Graph(6, 7);
//        // input list of edges
//        List<Edge> edges = Arrays.asList(new Edge(0, 2, 6), new Edge(0, 4, 4), new Edge(4, 3, 4), 
//                new Edge(3, 2, 2), new Edge(1, 2, 7), new Edge(1, 5, 9), new Edge(2, 5, 3));

        // Example - 2
        Graph graph = new Graph(9, 14);
        // input list of edges
        List<Edge> edges = Arrays.asList(new Edge(0, 1, 4), new Edge(0, 7, 8), new Edge(1, 7, 11), 
                new Edge(1, 2, 8), new Edge(7, 8, 7), new Edge(7, 6, 1), new Edge(2, 8, 2), 
                new Edge(8, 6, 6), new Edge(3, 2, 7), new Edge(2, 5, 4), new Edge(6, 5, 2), 
                new Edge(5, 3, 14), new Edge(3, 4, 9), new Edge(4, 5, 10));
        
        graph.addEdgesUndirected(edges);
        graph.printWeightedGraph();
        
        Prism obj = new Prism(graph);
        
        obj.computeMST(0);
    }
}
