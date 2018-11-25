package n105companyMoneyT;

import java.util.Comparator;

/**
 *
 * @author vasu
 */

public class CompanyAmtSorter implements Comparator<Company>{
    // sorts in reverse order
    @Override
    public int compare(Company o1, Company o2) {
        if(o1.getOwed() < o2.getOwed())
            return 1;
        else if (o1.getOwed() > o2.getOwed())
            return -1;
        else
            return 0;
    }   
}
