package n94dijkstrasGraphs;

import java.util.PriorityQueue;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;
import n88graphRepresentation.Vertex;
import n88graphRepresentation.VertexPriorityComparator;

/**
 *
 * @author vasu
 */
public class Dijkstra {
    Graph graph;
    
    Dijkstra (Graph graph)    {
        this.graph = graph;
    }
    
    public int[] computeSSSP(int source)  {
        // need to initialize state of all vertices back
        graph.reInitializeVertexs();
        
        // temp vertex holder
        Vertex temp_s, temp_d;
        
        // resultant shortest distance array
        int pos = 0;
        int[] visitOrder = new int[graph.getN()];
        
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
            // add to visit list
            visitOrder[pos++] = temp_s.getVert_no();
            
            // for all outgoing edges/adjacent vertexs of that vertex
            for (Edge edge : graph.getEdgeList(temp_s.getVert_no()))   {
                // get destination vertex
                temp_d = graph.getVertex(edge.getDest());
                
                // if color is red the vertex has never been visited
                if (temp_d.getColor() == 'R') {
                    // update priority
                    temp_d.setPriority(temp_s.getPriority() + edge.getWeight());
                    // change color to blue
                    temp_d.setColor('B');
                    // set parent
                    temp_d.setParent(temp_s.getVert_no());
                    // add to priority queue
                    pq.add(temp_d);
                }
                
                // color was blue - it means the vertex is already there in the priority queue
                else if (temp_d.getColor() == 'B')  {
                    if (temp_d.getPriority() > (temp_s.getPriority() + edge.getWeight()))   {
                        // we update priority of the destination vertex
                        // remove it and adding it again to the PQ
                        pq.remove(temp_d);
                        // updating priority
                        temp_d.setPriority(temp_s.getPriority() + edge.getWeight());
                        // updating parent
                        temp_d.setParent(temp_s.getVert_no());
                        // adding back to PQ
                        pq.add(temp_d);
                    }
                }
            }
        }
       
        // print visitOrder
        printVisitOrder(visitOrder);
        
        // print path from source to all other vertices
        printPathToAll(source);
        
        return visitOrder;
    }
    
    public void printVisitOrder(int[] order)   {
        int i = 0;
        System.out.printf("\nVertex Visit Order from %d(%d):", order[i], graph.getVertex(i).getPriority());
        for (i = 1 ; i < order.length ; i++)   {
            System.out.printf("%2d(%d)", order[i], graph.getVertex(order[i]).getPriority());
        }
        System.out.println("");
    }
    
    public void printPathToAll(int source)  {
        System.out.println("\nShortest Paths from " +  source + ": ");
        
        // paths are stored in the parent variable in Vertex object
        for (int i = 0 ; i < graph.getN() ; i++)    {
            if (i == source)
                continue;
            
            System.out.print("Path to " + i + ": " + source);
            printPathToOne(source, i);
            System.out.println("");
        }
    }
    
    public void printPathToOne(int source, int dest)    {
        if (graph.getVertex(dest).getParent() != source)
            printPathToOne(source, graph.getVertex(dest).getParent());
        System.out.print(" --> " + dest);
    }
}
