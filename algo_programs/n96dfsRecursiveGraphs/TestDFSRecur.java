package n96dfsRecursiveGraphs;

import java.util.Arrays;
import java.util.List;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;

/**
 *
 * @author vasu
 */

public class TestDFSRecur {
    public static void main(String[] args)  {
        // Example - 1 - Directed
        Graph graph = new Graph(5, 7);
        // input list of edges
        List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(0, 3), new Edge(1, 2), 
                new Edge(1, 3), new Edge(3, 4), new Edge(4, 1), new Edge(4, 2));
        
        // Example - 2 - Directed
//        Graph graph = new Graph(4, 6);
//        // input list of edges
//        List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(0, 2), new Edge(1, 2), 
//                new Edge(2, 0), new Edge(2, 3), new Edge(3, 3));
        
        // Example - 3 - Undirected
//         Graph graph = new Graph(6, 8);
//        // input list of edges
//        List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(1, 3), new Edge(3, 5), 
//                new Edge(5, 4), new Edge(4, 2), new Edge(2, 0), new Edge(3, 4), new Edge(1, 4));

        graph.addEdges(edges);
        graph.printGraph();
        
        DFSRecur obj = new DFSRecur(graph);
        
        // DFS traversal from every vertex
        for (int i = 0 ; i < graph.getN() ; i++)    {
            obj.computeDFSRecur(i);
        }
    }
    
}
