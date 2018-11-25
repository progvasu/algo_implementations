package n105companyMoneyT;

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author vasu
 */

public class TransferMinX {
    public static void main(String[] args) {
        // input - 1
//        int[] owe = new int[]{20, -15, -5};
        
        // input - 2
        int[] owe = new int[]{-10, -35, 30, 15};
        
        List<Company> pos_owed = new ArrayList<>();
        List<Company> neg_owed = new ArrayList<>();
        
        // create company classes and move them to their respective lists
        // since positive values will never become negative
        // we sort the companies into positive (including zero) and negative
        // also finding the max positive amount
        
        char name = 'A';
        int max_owed = -999;
        for (int amt : owe) {
            if (amt >= 0)   {
                pos_owed.add(new Company(name, amt));
                // find max
                if (amt >= max_owed)
                    max_owed = amt;
            }
            else    {
                neg_owed.add(new Company(name, amt));
            }
            
            name += 1;
        }
        
        // sorting companies
        Collections.sort(pos_owed, new CompanyAmtSorter());
        Collections.sort(neg_owed, new CompanyAmtSorter());
        // reverse the order for neg_owed
        Collections.reverse(neg_owed);
        
        // printing initial state
        System.out.println("Positive Owed: ");
        for(Company cmp : pos_owed)
            System.out.printf("%4s", cmp.getName());
        System.out.println("");
        for(Company cmp : pos_owed)
            System.out.printf("%4d", cmp.getOwed());
        System.out.println("\n");
        
        System.out.println("Negative Owed: ");
        for(Company cmp : neg_owed)
            System.out.printf("%4s", cmp.getName());
        System.out.println("");
        for(Company cmp : neg_owed)
            System.out.printf("%4d", cmp.getOwed());
        System.out.println("\n");
        
        // Greedy Approach
        int x = 11;
        // pos_trans are only for positive numbers
        // initially
        int pos_trans = ((pos_owed.size() + 1) * pos_owed.size()) / 2;
        
        Company most_pos, most_neg = null, sec_pos;
        int amt_to_pay;
        
        // Try for x
        // What should be the stopping criteria
        // All companies exhausted their transactions?
        while(true)    {
            // stopping criteria - 1 - Success
            // Negative List is Empty
            if (neg_owed.isEmpty()) {
                System.out.println("Amount can be payed using x: " + x);
                break;
            }
            
            // stopping criteria - 2 - Failure
            // all possible transactions exhausted
//            if (pos_trans == 0 && !neg_owed.isEmpty())  {
//                System.out.println("Amount cannot be payed using x: " + x);
//                break;
//            }
            
            // make transactions using x
            // we pick one company from pos_owed and start paying negative companies
            // if money still owed after paying negative companies we start paying
            // the positve companies from the next company in the list
            // we keep track of companies payed in Company class
            
            most_pos = pos_owed.get(0);
            
            // loop through negative companies until mos_pos runs out of owed
            // or the negative list exhausts
            while (most_pos.getOwed() > 0 && !neg_owed.isEmpty())   {
                // find amt to pay the first company in the list
                if (most_pos.getOwed() >= x)
                    amt_to_pay = x;
                else
                    amt_to_pay = most_pos.getOwed();
                
                // get the most negative company which has not been paid before
                most_neg = null;
                for (Company cmp : neg_owed)    {
                    if (!most_pos.alreadyPaid(cmp.getName()))   {
                        most_neg = cmp;
                        break;
                    }
                }
                // if not able to find any such company then break
                if (most_neg == null)
                    break;
            
                // pay it
                most_neg.setOwed(most_neg.getOwed() + amt_to_pay);
                // deduct from most_pos
                most_pos.setOwed(most_pos.getOwed() - amt_to_pay);
                
                // add the companies to each others list
                most_pos.addPaidTo(most_neg.getName());
                most_neg.addPaidTo(most_pos.getName());
                
                // now is most_neg owed becomes positive?
                if (most_neg.getOwed() >= 0)    {
                    // remove from neg_owed list
                    neg_owed.remove(most_neg);
                    // add to positive list
                    pos_owed.add(most_neg);
                }
                
                // sort these again
                // sorting companies
                Collections.sort(pos_owed, new CompanyAmtSorter());
                Collections.sort(neg_owed, new CompanyAmtSorter());
                // reverse the order for neg_owed
                Collections.reverse(neg_owed);
                
                // recompute the possible trials
                pos_trans = 0;
                for (Company cmp : pos_owed)    {
                    pos_trans += (owe.length - cmp.getSizePaidTo());
                }
                for (Company cmp : neg_owed)    {
                    pos_trans -= (owe.length - cmp.getSizePaidTo());
                }
                pos_trans /= 2;
            }
            // here the negative list exhausts!
            
            // print state
            System.out.println("Positive Owed: ");
            for(Company cmp : pos_owed)
                System.out.printf("%4s", cmp.getName());
            System.out.println("");
            for(Company cmp : pos_owed)
                System.out.printf("%4d", cmp.getOwed());
            System.out.println("\n");

            System.out.println("Negative Owed: ");
            for(Company cmp : neg_owed)
                System.out.printf("%4s", cmp.getName());
            System.out.println("");
            for(Company cmp : neg_owed)
                System.out.printf("%4d", cmp.getOwed());
            System.out.println("\n");
            
            // if some amt is left we now pay it to positive companies
            // untill we pay all the amt if some amt left then no solution
            for(int i = 0 ; i < pos_owed.size() ; i++) {
                // if zero break
                if (most_pos.getOwed() == 0)
                    break;
                
                // find amt to pay the first company in the list
                if (most_pos.getOwed() >= x)
                    amt_to_pay = x;
                else
                    amt_to_pay = most_pos.getOwed();
                
                sec_pos = pos_owed.get(i);
                // pay the company if trans possible
                if (most_pos.alreadyPaid(sec_pos.getName()))
                    continue;
                
                sec_pos.setOwed(sec_pos.getOwed() + amt_to_pay);
                // deduct from most_pos
                
                most_pos.setOwed(most_pos.getOwed() - amt_to_pay);
                
                // add the companies to each others list
                most_pos.addPaidTo(sec_pos.getName());
                sec_pos.addPaidTo(most_pos.getName());
            }
            
            if (most_pos.getOwed() != 0)    {
                System.out.println("Not Possible Using " + x);
                break;
            }
            
            // sort these again
            // sorting companies
            Collections.sort(pos_owed, new CompanyAmtSorter());
            
            // print state
            System.out.println("Positive Owed: ");
            for(Company cmp : pos_owed)
                System.out.printf("%4s", cmp.getName());
            System.out.println("");
            for(Company cmp : pos_owed)
                System.out.printf("%4d", cmp.getOwed());
            System.out.println("\n");

            System.out.println("Negative Owed: ");
            for(Company cmp : neg_owed)
                System.out.printf("%4s", cmp.getName());
            System.out.println("");
            for(Company cmp : neg_owed)
                System.out.printf("%4d", cmp.getOwed());
            System.out.println("\n");
        }
    }
}
