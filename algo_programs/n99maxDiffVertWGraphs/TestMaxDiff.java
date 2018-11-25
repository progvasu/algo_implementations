package n99maxDiffVertWGraphs;

import java.util.Arrays;
import java.util.List;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;
import n88graphRepresentation.Vertex;

/**
 *
 * @author vasu
 */

public class TestMaxDiff {
    public static void main(String[] args)  {
        // every vertex must have a weight so we use priorities of a vertex as weights
        
        // we solve first using DFS then we use modified version of Floyd Warshall
        
        // input directed graph
        // we use trees because then checking is much easier
        
        // Example
//        Graph graph = new Graph(9, 8);
//        // input list of edges
//        List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(0, 2), new Edge(1, 3), 
//                new Edge(1, 4), new Edge(2, 5), new Edge(2, 6), new Edge(4, 7), new Edge(5, 8));
        
        Graph graph = new Graph(5, 6);
        // input list of edges
        List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(0, 3), new Edge(0, 4), 
                new Edge(1, 2), new Edge(1, 4), new Edge(3, 4));
        
        graph.addEdges(edges);
        graph.printGraph();
        
        // setting weights of vertices
        int[] prior = new int[]{5, 2, 30, 4, 1};
        for (int i = 0 ; i < graph.getN() ; i++)   {
            graph.getVertex(i).setWeight(prior[i]);
        }
        
        MaxDiff obj = new MaxDiff(graph);
        
        // getting max vertex with the max diff from a single vertex
        // int vert = obj.getMaxVertDFS(0);
        // this works
        
        // calling DFS for all the pairs
        // abstracting it in the class itself
        obj.findMaxDiffPair();     
        
        // Using Modified Version of Floyd Warshall
        // abstracting in the class itself
        obj.findMaxDiffPairFW();
    }
}
