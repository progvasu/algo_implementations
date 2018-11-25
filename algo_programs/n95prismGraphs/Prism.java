package n95prismGraphs;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;
import n88graphRepresentation.Vertex;
import n88graphRepresentation.VertexPriorityComparator;

/**
 *
 * @author vasu
 */

public class Prism {
    Graph graph;
    
    Prism (Graph graph)    {
        this.graph = graph;
    }
    
    public List<Edge> computeMST(int source)  {
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
       
        // print visitOrder
        printMST(resultMST);
        
        // printing using implicit reperesenation in Vertex Objext
        printMSTExplicit();
        
        return resultMST;
    }
    
    public void printMST(List<Edge> edges)  {
        System.out.println("\nEdges in the minimum spanning tree: ");
        for (Edge edge : edges) {
            System.out.println(edge.getSrc() + " - " + edge.getDest() + " = " + edge.getWeight());
        }
    }
    
    public void printMSTExplicit()  {
        System.out.println("\nEdges in the minimum spanning tree - implict way: ");
        for (Vertex vert : graph.getAllVertexs()) {
            System.out.println(vert.getVert_no() + " - " + vert.getParent() + " = " + vert.getPriority());
        }
    }
}
