package n101bstTrees;

import n100treeRepresentation.Node;

/**
 *
 * @author vasu
 */

public class BST {
    private Node root;
    
    // insert a node into the binary search tree
    public void insert(int key)    {
        // create a new node
        Node temp = new Node(key);
        
        // is root empty
        if (getRoot() == null)   {
            this.setRoot(temp);
            return;
        }
        
        // find the correct position
	Node pos, parent;
	pos = this.root;
	parent = null;
	while (pos != null)	{
            parent = pos;
            
            // add 1 to every node alaong the path
            parent.setNum(parent.getNum() + 1);
            
            if (key < pos.getKey())	{
                pos = pos.getLc();
            }
            else    {
                pos = pos.getRc();
            }
	}

	// insert as child of parent
	if (key < parent.getKey())
            parent.setLc(temp);
	else
            parent.setRc(temp);
        
        // set parent
        temp.setPr(parent);
    }
    
    // delete from a BST
    // this delete procedure replaces the entire node and not just the values
    public void delete(int key)	{
	Node node = this.root;
	
        // find the key in the tree
	while (node.getKey() != key)	{
            node.setNum(node.getNum() - 1);
            
            if (key < node.getKey())
                node = node.getLc();
            else
                node = node.getRc();

            if (node == null)	{
                System.out.printf("NODE NOT FOUND!\n");
                return;
            }
	}

	deleteNode(node);
    }

    private void deleteNode(Node node)	{
	if (node.getLc() == null)
            transplant(node, node.getRc());
	else if (node.getRc() == null)  {
            transplant(node, node.getLc());
        }
        else	{
            // find inorder successor
            Node suc = node.getRc();
            suc.setNum(suc.getNum() - 1);
            while (suc.getLc() != null)	{
                suc = suc.getLc();
                suc.setNum(suc.getNum() - 1);
            }
            if (suc.getPr() != node)	{
                transplant(suc, suc.getRc());
                // because there is no left child
                suc.setRc(node.getRc());
                suc.getRc().setPr(suc);
            }
            transplant(node, suc);
            suc.setLc(node.getLc());
            suc.getLc().setPr(suc);
            
            // set num of node 2
            suc.setNum(1);
            // is left child? is required?
            if (suc.getLc() != null)
                suc.setNum(suc.getNum() + suc.getLc().getNum());
            // is right child?
            if (suc.getRc() != null)
                suc.setNum(suc.getNum() + suc.getRc().getNum());
        }
}

    // this procedure replaces node1 with node2 - just the parents
    private void transplant(Node node1, Node node2)	{
	if (node1.getPr() == null)
            root = node2;
	else if (node1 == node1.getPr().getLc())
            node1.getPr().setLc(node2);
	else
            node1.getPr().setRc(node2);
	
	if (node2 != null)
            node2.setPr(node1.getPr());
    }
    
    public int findRank(int ele)	{
        // we initialize rank as one so no need to add 1 for the ele node
        int rank = 1;
        Node node = this.root;

        while (node != null)	{
            if (node.getKey() == ele)	{
                if (node.getRc() != null)
                    rank += node.getRc().getNum();
                return rank;
            }
            else if (ele < node.getKey())	{
                if (node.getRc() != null)
                    rank += node.getRc().getNum();
                rank += 1;
                node = node.getLc();
            }
            else if (ele > node.getKey())	{
                node = node.getRc();
            }
        }

        return -1;
    }
    
    // print tree methods
    private int findHeight(Node node)	{
	if (node == null)	
            return -1;
	int left = findHeight(node.getLc()), right = findHeight(node.getRc());
	return (1 + Math.max(left, right));
    }
    
    private void fillLevel(Node node, int[] levelOrder, int[] numOrder, int pos, int max_pos)	{
	if (node == null)	{
            if (pos <= max_pos)	{
                levelOrder[pos] = -1;
                numOrder[pos] = 0;
                fillLevel(null, levelOrder, numOrder, pos*2 + 1, max_pos);
                fillLevel(null, levelOrder, numOrder, pos*2 + 2, max_pos);
            }
            else
                return;
	}
	else	{
	levelOrder[pos] = node.getKey();
        numOrder[pos] = node.getNum();
	fillLevel(node.getLc(), levelOrder, numOrder, pos*2 + 1, max_pos);
	fillLevel(node.getRc(), levelOrder, numOrder, pos*2 + 2, max_pos);
	}
    }
    
    public void treePrint()	{
	int height = findHeight(root);
	if (height > 5)	{
            System.out.println("Tree size to big to fit on screen");
            return;
	}
        else if (height == -1)  {
            System.out.println("Tree Empty!!!");
            return;
        }

	int no_nodes = (int)Math.pow(2, height + 1) - 1;

	// find level order traversal
	int[] levelOrder = new int[no_nodes];
        int[] numOrder = new int[no_nodes];
	fillLevel(root, levelOrder, numOrder, 0, no_nodes - 1);
	
	int mid, cn, n_ch, ch, i, ne;
	
	mid = 4 * (int)Math.pow(2, height);
	cn = 0; 
	n_ch = 1;
	ch = height;
	
        int temp;
        
	while (ch >= 0)	{
            temp = cn;
            
            for (i = 0 ; i < n_ch ; i++)	{
                if (levelOrder[cn] != -1)	{
                    if (i == 0) // for first node at this height
                        System.out.printf("%" + mid/2 + "d", levelOrder[cn++]);
                    else
                        System.out.printf("%" + mid + "d", levelOrder[cn++]);
                }
                else	{
                    cn++;
                    if (i == 0)
                        System.out.printf("%" + mid/2 + "s", "-");
                    else
                        System.out.printf("%" + mid + "s", "-");
                }
            }
            
            // restoring old value of cn
            cn = temp;
            
            System.out.println("");
            for (i = 0 ; i < n_ch ; i++)	{
                if (levelOrder[cn] != 0)	{
                    if (i == 0) // for first node at this height
                        System.out.printf("%" + mid/2 + "d", numOrder[cn++]);
                    else
                        System.out.printf("%" + mid + "d", numOrder[cn++]);
                }
                else	{
                    cn++;
                    if (i == 0)
                        System.out.printf("%" + mid/2 + "s", "-");
                    else
                        System.out.printf("%" + mid + "s", "-");
                }
            }

            // adding appropriate height for edges and edges
            int es, en;
            es = 2;
            en = mid - 2;
            for(i = 0 ; i < (int)Math.pow(2, ch - 1) ; i++)	{
                System.out.printf("\n");
                ne = 2 * n_ch;
                // first edge
                System.out.printf("%" + (mid/2 - i*2 - 1) + "c", '-');
                // remaining
                ne--;
                while (ne > 0)	{
                    System.out.printf("%" + es + "c", '-');
                    ne--;
                    if (ne > 0)
                        System.out.printf("%" + en + "c", '-');	
                    ne--; 
                }
                es += 4;
                en -= 4;
            }
            System.out.printf("\n");

            mid /= 2;
            n_ch *= 2;
            ch--;
	}
    }

    /**
     * @return the root
     */
    public Node getRoot() {
        return root;
    }

    /**
     * @param root the root to set
     */
    public void setRoot(Node root) {
        this.root = root;
    }
}
