package n108beautifulNodes;

import com.sun.javafx.util.TempState;
import java.util.ArrayList;
import java.util.List;
import n101bstTrees.BST;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;
import n88graphRepresentation.Vertex;

/**
 *
 * @author vasu
 */

public class ModiDFSRecur {
    private Graph graph;
    private int time;
    private List<Integer> visitOrder;
    private BST tree;
    private int noBFN;
    
    ModiDFSRecur(Graph graph)    {
        this.graph = graph;
        this.time = 0;
        this.visitOrder = new ArrayList<>(graph.getN());
        this.tree = new BST();
        this.noBFN = 0;
    }
    
    // this will capture the DFS in visitOrder
    public int computeDFSRecur(int source)   {
        // need to initilize state of all vertices back
        graph.reInitializeVertexs();
        this.time = 1;
        this.visitOrder = new ArrayList<>(graph.getN());
        
        // start by visiting source vertex
        DFSVisit(source);   
        
        return this.noBFN;
    }
    
    private void DFSVisit(int vertex)    {
        Vertex temp_s = graph.getVertex(vertex), temp_d;
        temp_s.setColor('B');
        temp_s.setDtime(time);
        time += 1;
        
        // insert into the tree
        tree.insert(temp_s.getWeight());
        
        noBFN += (tree.findRank(temp_s.getWeight()) - 1);
        
        // visit vertex's reachable from this vertex
        // for all outgoing edges/adjacent vertexs of that vertex
        for (Edge edge : graph.getEdgeList(temp_s.getVert_no()))   {
            temp_d = graph.getVertex(edge.getDest());
            if (temp_d.getColor() == 'R')   {
                temp_d.setParent(temp_s.getVert_no());
                DFSVisit(temp_d.getVert_no());
            }
        }
        
        // finished visiting vertex
        temp_s.setColor('G');
        temp_s.setFtime(time);
        time += 1;
        visitOrder.add(temp_s.getVert_no());
        tree.delete(temp_s.getWeight());
    }
}
