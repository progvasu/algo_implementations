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
        Graph graph = new Graph(6, 6);

        // input list of edges
        List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(0, 2), new Edge(1, 2), 
                new Edge(2, 0), new Edge(2, 3), new Edge(3, 3));

        graph.addEdges(edges);
        graph.printGraph();
    }
}
