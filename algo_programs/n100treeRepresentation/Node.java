package n100treeRepresentation;

/**
 *
 * @author vasu
 */

public class Node {
    private int key;
    private Node lc;
    private Node rc;
    private Node pr;
    private int num;

    public Node(int key)   {
        this.key = key;
        this.lc = null;
        this.rc = null;
        this.pr = null;
        // for the node itself
        this.num = 1;
    }
    
    /**
     * @return the key
     */
    public int getKey() {
        return key;
    }

    /**
     * @param key the key to set
     */
    public void setKey(int key) {
        this.key = key;
    }

    /**
     * @return the lc
     */
    public Node getLc() {
        return lc;
    }

    /**
     * @param lc the lc to set
     */
    public void setLc(Node lc) {
        this.lc = lc;
    }

    /**
     * @return the rc
     */
    public Node getRc() {
        return rc;
    }

    /**
     * @param rc the rc to set
     */
    public void setRc(Node rc) {
        this.rc = rc;
    }

    /**
     * @return the pr
     */
    public Node getPr() {
        return pr;
    }

    /**
     * @param pr the pr to set
     */
    public void setPr(Node pr) {
        this.pr = pr;
    }

    /**
     * @return the num
     */
    public int getNum() {
        return num;
    }

    /**
     * @param num the num to set
     */
    public void setNum(int num) {
        this.num = num;
    }
}
