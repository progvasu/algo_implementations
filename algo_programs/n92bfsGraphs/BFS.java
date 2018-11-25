package n92bfsGraphs;

import java.util.LinkedList;
import java.util.Queue;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;
import n88graphRepresentation.Vertex;

/**
 *
 * @author vasu
 */

public class BFS {
    Graph graph;
    
    BFS(Graph g)    {
        this.graph = g;
    }
    
    // this will return the order in which verices are traversed
    public int[] computeBFS(int source)   {
        // need to initilize state of all vertices back
        graph.reInitializeVertexs();
        
        // temporary vertex holder
        Vertex temp;
        
        // result order array
        int pos = 0;
        int[] visitOrder = new int[graph.getN()];
        
        Queue<Vertex> q = new LinkedList<>();
        
        // initialization
        // all vertices are initially red
        // get vertex 'source'
        temp = graph.getVertex(source);
        // 'color' to blue
        temp.setColor('B');
        // parent is set to vertex itself
        temp.setParent(source);
        // add vertex to queue
        q.add(temp);
        
        // while queue not empty
        while(!q.isEmpty())  {
            // get vertex from queue
            temp = q.remove();
            
            // change color to green - vertex visited completely
            temp.setColor('G');
            
            // add vertex to visit order
            visitOrder[pos++] = temp.getVert_no();
        
            // for all outgoing edges of that vertex
            for (Edge edge : graph.getEdgeList(temp.getVert_no()))   {
                // if vertex never visited
                // get destination vertex
                temp = graph.getVertex(edge.getDest());
                if(temp.getColor() == 'R')  {
                    // change color to blue
                    temp.setColor('B');
                    // set parent
                    temp.setParent(edge.getSrc());
                    // add to queue
                    q.add(temp);
                }
            }
        }
        
        // print the order in which vertices are visited
        printBFSOrder(visitOrder);
        
        // return visitOrder - not storing the order in class
        return visitOrder;
    }
    
    public void printBFSOrder(int[] order)   {
        int i = 0;
        System.out.printf("BFS traveral from %d: ", order[i]);
        for (i = 1 ; i < order.length ; i++)   {
            System.out.printf("%3d", order[i]);
        }
        System.out.println("");
    }
}
