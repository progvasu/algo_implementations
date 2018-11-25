package n88graphRepresentation;

/**
 *
 * @author vasu
 */

public class Vertex {
    private int vert_no;
    private char color;
    private int parent;
    private int priority;
    private int dtime;
    private int ftime;
    private int weight;
            
    Vertex(int vert_no, char color)    {
        this.vert_no = vert_no;
        this.color = color;
        this.parent = vert_no;
        this.priority = 99999;  // to represent infinity
        this.dtime = -1;    // never discovered
        this.ftime = -1;    // never finished discovering
        this.weight = 0;
    }
    
    public void reInitialize()  {
        this.color = 'R';
        this.parent = this.vert_no;
        this.priority = 99999;
        this.dtime = -1;
        this.ftime = -1;
        // not reinitializing weights - keeping them constant - for changeable 
        // weights we use priorities instead
    }
            
    /**
     * @return the color
     */
    public char getColor() {
        return color;
    }

    /**
     * @param color the color to set
     */
    public void setColor(char color) {
        this.color = color;
    }

    /**
     * @return the vert_no
     */
    public int getVert_no() {
        return vert_no;
    }

    /**
     * @param vert_no the vert_no to set
     */
    private void setVert_no(int vert_no) {
        this.vert_no = vert_no;
    }

    /**
     * @return the parent
     */
    public int getParent() {
        return parent;
    }

    /**
     * @param parent the parent to set
     */
    public void setParent(int parent) {
        this.parent = parent;
    }

    /**
     * @return the priority
     */
    public int getPriority() {
        return priority;
    }

    /**
     * @param priority the priority to set
     */
    public void setPriority(int priority) {
        this.priority = priority;
    }

    /**
     * @return the dtime
     */
    public int getDtime() {
        return dtime;
    }

    /**
     * @param dtime the dtime to set
     */
    public void setDtime(int dtime) {
        this.dtime = dtime;
    }

    /**
     * @return the ftime
     */
    public int getFtime() {
        return ftime;
    }

    /**
     * @param ftime the ftime to set
     */
    public void setFtime(int ftime) {
        this.ftime = ftime;
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
    public void setWeight(int weight) {
        this.weight = weight;
    }
}
