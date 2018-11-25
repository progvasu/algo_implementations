package n99maxDiffVertWGraphs;

import java.util.Stack;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;
import n88graphRepresentation.Vertex;

/**
 *
 * @author vasu
 */

public class MaxDiff {
    Graph graph;
    
    public MaxDiff(Graph graph)   {
        this.graph = graph;
    }
    
    private int getMaxVertDFS(int source)    {
        // returning source means all other reachable vertexes were of less
        // priorities
        int max_vert = source, max_diff = -99999;
        
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
                
                // we will visit this vertex completly next
                
                // comparing its weight with the source vertex and figuring out the max
                if (temp.getWeight() - graph.getVertex(source).getWeight() > max_diff)  {
                    max_diff = temp.getWeight() - graph.getVertex(source).getWeight();
                    max_vert = temp.getVert_no();
                }
                
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
        
        return max_vert;
    }
    
    public void findMaxDiffPair()   {
        int max_vert = -1, max_diff = -99999, max_src = -1;
        int temp_vert, temp_diff;
        
        // calling for every vertex
        for (Vertex vert : graph.getAllVertexs())   {
            temp_vert = getMaxVertDFS(vert.getVert_no());
            temp_diff = graph.getVertex(temp_vert).getWeight() - vert.getWeight();
            
            if (temp_diff > max_diff)   {
                max_diff = temp_diff;
                max_vert = temp_vert;
                max_src = vert.getVert_no();
            }
        }
        
        System.out.println("Maximum Difference Pair " + max_src + " - " + max_vert + ": " + max_diff);
    }
    
    public void findMaxDiffPairFW() {
        
    }
}
