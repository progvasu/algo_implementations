package n96dfsRecursiveGraphs;

import java.util.ArrayList;
import java.util.List;
import n88graphRepresentation.Edge;
import n88graphRepresentation.Graph;
import n88graphRepresentation.Vertex;

/**
 *
 * @author vasu
 */

public class DFSRecur {
    private Graph graph;
    private int time;
    private List<Integer> visitOrder;
    
    DFSRecur(Graph graph)    {
        this.graph = graph;
        this.time = 0;
        this.visitOrder = new ArrayList<>(graph.getN());
    }
    
    // this will capture the DFS in visitOrder
    public void computeDFSRecur(int source)   {
        // need to initilize state of all vertices back
        graph.reInitializeVertexs();
        this.time = 1;
        this.visitOrder = new ArrayList<>(graph.getN());
        
        // start by visiting source vertex
        DFSVisit(source);
        
        // if any vertex is left visiting
//        for (Vertex vert : graph.getAllVertexs())   {
//            if (vert.getColor() == 'R') {
//                DFSVisit(vert.getVert_no());
//            }
//        }
        
        printDFSTraversal(source);
    }
    
    private void DFSVisit(int vertex)    {
        Vertex temp_s = graph.getVertex(vertex), temp_d;
        temp_s.setColor('B');
        temp_s.setDtime(time);
        time += 1;
        
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
    }
    
    private void printDFSTraversal(int source) {
        System.out.print("DFS Traversal from " + source + "(" + graph.getVertex(source).getDtime() + "/" + graph.getVertex(source).getFtime() + ")" + ":");
        for (int i = visitOrder.size() - 2 ; i >= 0 ; i--)   {
            System.out.printf("%3d(%d/%d)", visitOrder.get(i), graph.getVertex(visitOrder.get(i)).getDtime(), graph.getVertex(visitOrder.get(i)).getFtime());
        }
        System.out.println("");
    }
}
