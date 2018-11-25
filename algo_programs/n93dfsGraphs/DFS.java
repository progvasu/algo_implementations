package n93dfsGraphs;

import java.util.Stack;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;
import n88graphRepresentation.Vertex;

/**
 *
 * @author vasu
 */

public class DFS {
    Graph graph;
    
    DFS(Graph graph)    {
        this.graph = graph;
    }
    
    // this will return the order in which verices are traversed
    public int[] computeDFS(int source)   {
        // need to initilize state of all vertices back
        graph.reInitializeVertexs();
        
        // temp vertex holder
        Vertex temp;
        
        // result order array
        int pos = 0;
        int[] visitOrder = new int[graph.getN()];
    
        Stack<Vertex> st = new Stack<>();
        
        // initialization
        // all vertices are initially red
        // get vertex 'source'
        temp = graph.getVertex(source);
        // 'color' to blue
        temp.setColor('B');
        // parent is set to vertex itself
        temp.setParent(source);
        // add vertex to queue
        st.push(temp);
        
        // while stack not empty
        while(!st.isEmpty())    {
            temp = st.pop();
            // if color not green
            if (temp.getColor() != 'G') {
                // change color to green
                temp.setColor('G');
                
                // add to visited array
                visitOrder[pos++] = temp.getVert_no();
                
                // for all outgoing edges of that vertex
                for (Edge edge : graph.getEdgeList(temp.getVert_no()))   {
                    // if vertex is not yet completely visited
                    // get destination vertex
                    temp = graph.getVertex(edge.getDest());
                    if(temp.getColor() != 'G')  {
                        // change color to blue
                        temp.setColor('B');
                        // set parent
                        temp.setParent(edge.getSrc());
                        // add to queue
                        st.push(temp);
                    }
                }
            }
        }
        
        // print the order in which vertices are visited
        printDFSOrder(visitOrder);
        
        return visitOrder;
    }
    
    public void printDFSOrder(int[] order)   {
        int i = 0;
        System.out.printf("DFS traveral from %d: ", order[i]);
        for (i = 1 ; i < order.length ; i++)   {
            System.out.printf("%3d", order[i]);
        }
        System.out.println("");
    }
}
