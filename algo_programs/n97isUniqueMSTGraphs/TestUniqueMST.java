package n97isUniqueMSTGraphs;

import java.util.Arrays;
import java.util.List;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;

/**
 *
 * @author vasu
 */

public class TestUniqueMST {
    public static void main(String[] args)  {
        
        Graph graph = new Graph(6, 6);
        // input list of edges
        List<Edge> edges = Arrays.asList(new Edge(0, 1, 1), new Edge(1, 2, 1), new Edge(2, 3, 1), 
                new Edge(3, 4, 1), new Edge(4, 5, 1), new Edge(5, 0, 1));
        
        graph.addEdgesUndirected(edges);
        graph.printWeightedGraph();
        
        UniqueMST obj = new UniqueMST(graph);
        
        obj.isUnique();
    }
}
