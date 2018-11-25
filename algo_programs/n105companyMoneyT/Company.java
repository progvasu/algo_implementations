package n105companyMoneyT;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author vasu
 */

public class Company {
    private char name;
    private int owed;
    private List<Character> paid_to;
    
    public Company(char name, int owed)    {
        this.name = name;
        this.owed = owed;
        this.paid_to = new ArrayList<>();
        this.paid_to.add(name);
    }
    
    public int getSizePaidTo()  {
        return paid_to.size();
    }
    
    public void addPaidTo(char cmp)  {
        paid_to.add(cmp);
    }
    
    public boolean alreadyPaid(char cmp) {
        return paid_to.contains(cmp);
    }
    
    /**
     * @return the owed
     */
    public int getOwed() {
        return owed;
    }

    /**
     * @param owed the owed to set
     */
    public void setOwed(int owed) {
        this.owed = owed;
    }

    /**
     * @return the name
     */
    public char getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(char name) {
        this.name = name;
    }
    
}
