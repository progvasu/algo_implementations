package n92bfsGraphs;

import java.util.Arrays;
import java.util.List;

import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;

/**
 *
 * @author vasu
 */

public class TestBFS {
    public static void main(String[] args)  {
        // Example - 1 - Directed
//        Graph graph = new Graph(4, 6);
//        // input list of edges
//        List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(0, 2), new Edge(1, 2), 
//                new Edge(2, 0), new Edge(2, 3), new Edge(3, 3));

        // Example - 2 - Undirected
//        Graph graph = new Graph(6, 8);
//        // input list of edges
//        List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(1, 3), new Edge(3, 5), 
//                new Edge(5, 4), new Edge(4, 2), new Edge(2, 0), new Edge(3, 4), new Edge(1, 4));

        // Example - 3 - Directed
//        Graph graph = new Graph(6, 6);
//        // input list of edges
//        List<Edge> edges = Arrays.asList(new Edge(0, 2), new Edge(1, 3), new Edge(2, 3), 
//                new Edge(2, 4), new Edge(3, 5), new Edge(4, 5));

        // Example - 4 - Unidrected
        Graph graph = new Graph(8, 10);
        // input list of edges
        List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(0, 2), new Edge(2, 3), 
                new Edge(3, 4), new Edge(3, 5), new Edge(4, 5), new Edge(4, 6), new Edge(5, 6),
                new Edge(5, 7), new Edge(6, 7));
        
        graph.addEdgesUndirected(edges);
        graph.printGraph();
        
        BFS obj = new BFS(graph);
        
        // BFS traversal from vertex 2
        int result[] = obj.computeBFS(2);
        
        // BFS traversal from vertex 0
        int result2[] = obj.computeBFS(0);
    }
}
