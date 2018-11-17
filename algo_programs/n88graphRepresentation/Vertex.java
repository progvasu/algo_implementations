package n88graphRepresentation;

/**
 *
 * @author vasu
 */

public class Vertex {
    private int vert_no;
    private char color;
    private int parent;
            
    Vertex(int vert_no, char color)    {
        this.vert_no = vert_no;
        this.color = color;
        this.parent = vert_no;
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
    private void setColor(char color) {
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
}
