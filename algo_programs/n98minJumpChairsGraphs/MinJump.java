package n98minJumpChairsGraphs;

import java.util.ArrayList;
import java.util.List;
import n88graphRepresentation.Graph;
import n88graphRepresentation.Edge;
import n90floydWarshallGraphs.FloydWarshall;

/**
 *
 * @author vasu
 */

public class MinJump {
    Graph graph;
    
    MinJump(int no_chairs, int[] ai)    {
        graph = new Graph(no_chairs, ai.length * 2);
        
        List<Edge> edges = new ArrayList<>(); 
        int end_vertex;
        
        for(int i = 0 ; i < ai.length ; i++) {
            // forward move
            end_vertex = (i + ai[i]) % ai.length;
            // add a new edge
            edges.add(new Edge(i, end_vertex));
            
            // backward move
            end_vertex = (i - ai[i]);
            if (end_vertex < 0)
                end_vertex += ai.length;
            // add backward edge
            edges.add(new Edge(i, end_vertex));
        }
        
        graph.addEdges(edges);
        graph.printGraph();
    }
    
    // floyd warshall
    public void computeMinDist()    {
        int[][] min_dist;
        
        // calling FL
        FloydWarshall obj = new FloydWarshall(graph.getAM());
        
        // print AM
        graph.printGraphAM();
        
        obj.computeShortestPaths();
        obj.printResult();
    }
}
