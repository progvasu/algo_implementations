package n88graphRepresentation;

import java.util.Comparator;

/**
 *
 * @author vasu
 */
public class VertexPriorityComparator implements Comparator<Vertex>{

    @Override
    public int compare(Vertex o1, Vertex o2) {
        if(o1.getPriority() > o2.getPriority())
            return 1;
        else if (o1.getPriority() < o2.getPriority())
            return -1;
        else
            return 0;
    }        
}
