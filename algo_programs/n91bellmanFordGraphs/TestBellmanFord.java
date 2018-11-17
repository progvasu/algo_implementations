package n91bellmanFordGraphs;

import n88graphRepresentation.Graph;
import n88graphRepresentation.Edge;

import java.util.Arrays;
import java.util.List;

/**
 *
 * @author vasu
 */

public class TestBellmanFord {
    public static void main(String[] args)  {
        Graph graph = new Graph(5, 8);
    
        // input list of edges
        List<Edge> edges = Arrays.asList(new Edge(0, 1, -1), new Edge(0, 2, 4), new Edge(1, 4, 2), 
                new Edge(1, 3, 2), new Edge(1, 2, 3), new Edge(3, 1, 1), new Edge(3, 2, 5),
                new Edge(4, 3, -3));
        
        // Example - 2
        
        
        
        graph.addEdges(edges);
        graph.printWeightedGraph();
        
        BellmanFord obj = new BellmanFord(graph);
        
        obj.computeSSSP(0);
    }
}
