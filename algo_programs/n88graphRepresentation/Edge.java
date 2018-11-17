package n88graphRepresentation;

/**
 *
 * @author vasu
 */

// data structre for edges - both weighted and unweighted edges
public class Edge {
    private int src;
    private int dest;
    private int weight;
        
    public Edge(int src, int dest) {
        this.src = src;
        this.dest = dest;
        this.weight = 0;
    }
        
    public Edge(int src, int dest, int weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }

    /**
     * @return the src
     */
    public int getSrc() {
        return src;
    }

    /**
     * @param src the src to set
     */
    private void setSrc(int src) {
        this.src = src;
    }

    /**
     * @return the dest
     */
    public int getDest() {
        return dest;
    }

    /**
     * @param dest the dest to set
     */
    private void setDest(int dest) {
        this.dest = dest;
    }

    /**
     * @return the weight
     */
    public int getWeight() {
        return weight;
    }

    /**
     * @param weight the weight to set
     */
    private void setWeight(int weight) {
        this.weight = weight;
    }
}
