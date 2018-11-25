package n97isUniqueMSTGraphs;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Set;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;
import n88graphRepresentation.Vertex;
import n88graphRepresentation.VertexPriorityComparator;

/**
 *
 * @author vasu
 */

public class UniqueMST {
    Graph graph;
    int weightMST;

    public UniqueMST(Graph graph) {
        this.graph = graph;
        this.weightMST = -1;
    }
    
    public boolean isUnique()   {
        boolean result = true;
        
        // initial check 
        // if all the edge weights in the graph are unique then MST is unique
        Set<Integer> setWeights = new HashSet<>();
                
        for (Edge edge : graph.getAllEdges())   {
            if (!setWeights.add(edge.getWeight()))  {
                result = false;
                break;
            }
        }
        
        // check if further analysis required?
        if (!result)
            // Now the graph may or may not have a unique MST
            System.out.println("\nEdge weights are not unique - May not have a unique MST");
        else    {
            System.out.println("\nHas a unique MST");
            return result;
        }
        
        // further checking
        // finding a MST then deleting the edge from original graph which has duplicate weights
        // and running the algorithm again
        
        // finding initial MST
        List<Edge> org_MST = findMST(0);
            
        // for every edge in MST
        for(Edge edge_mst : org_MST)   {
            // for all the edges in the graph is there an edge with the same weight in the graph
            for(Edge edge_graph : graph.getAllEdges())   {
                // check for same weight edge
                if (edge_mst.getWeight() == edge_graph.getWeight()) {
                    // did we find the same edge :-p - skip it
                    if (edge_mst.getSrc() == edge_graph.getSrc() && edge_mst.getDest() == edge_graph.getDest())
                        continue;
                    // create a new graph with the edge_graph removed
                    Graph temp_graph = new Graph(graph.getN(), graph.getM());
                    // creating a copy of
                }
            }
        }
        
        return result;
    }
    
    private List<Edge> findMST(int source)  {
        // any vertex could be source
        
        // need to initialize state of all vertices back
        graph.reInitializeVertexs();
        
        // temp vertex holder
        Vertex temp_s, temp_d;
        
        // resultant minimum spanning tree
        List<Edge> resultMST = new ArrayList<>();
        
        // initializinf priority queue
        PriorityQueue<Vertex> pq = new PriorityQueue<>(graph.getN(), new VertexPriorityComparator());
        
        // initialization
        // all vertices are initially red and priorities are infinity
        // get vertex 'source'
        temp_s = graph.getVertex(source);
        // 'color' to blue
        temp_s.setColor('B');
        // 'priority' to zero
        temp_s.setPriority(0);
        // 'parent' is set to vertex itself
        temp_s.setParent(source);
        // add vertex to queue
        pq.add(temp_s);
        
        // loop till priority queue not empty
        while(!pq.isEmpty())    {
            // remove min priority element
            temp_s = pq.remove();
            // chnage it's color to Gree
            temp_s.setColor('G');
            // add to edge list
            // !!! Could also go through the entire vertex list and keep on printing 
            // parent-vertex and vertex and the priority
            // but we make the result explicit here - we print both in the end !!!
            resultMST.add(new Edge(temp_s.getVert_no(), temp_s.getParent(), temp_s.getPriority()));
            
            // for all outgoing edges/adjacent vertexs of that vertex
            for (Edge edge : graph.getEdgeList(temp_s.getVert_no()))   {
                // get destination vertex
                temp_d = graph.getVertex(edge.getDest());
                
                // if color is red the vertex has never been visited
                if (temp_d.getColor() == 'R') {
                    // update priority
                    temp_d.setPriority(edge.getWeight());
                    // change color to blue
                    temp_d.setColor('B');
                    // set parent
                    temp_d.setParent(temp_s.getVert_no());
                    // add to priority queue
                    pq.add(temp_d);
                }
                
                // color was blue - it means the vertex is already there in the priority queue
                else if (temp_d.getColor() == 'B')  {
                    if (temp_d.getPriority() > edge.getWeight())   {
                        // we update priority of the destination vertex
                        // remove it and adding it again to the PQ
                        pq.remove(temp_d);
                        // updating priority
                        temp_d.setPriority(edge.getWeight());
                        // updating parent
                        temp_d.setParent(temp_s.getVert_no());
                        // adding back to PQ
                        pq.add(temp_d);
                    }
                }
            }
        }
       
        return resultMST;
    }
}
