/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        int size=sc.nextInt();
       HashMap<String,Integer> map=new HashMap<>();
      for(int i=0;i<size;i++)
      {
        int x=sc.nextInt();
        int y=sc.nextInt();
        int val=sc.nextInt();
        String temp=x+" "+y;  
        map.put(temp,val);
      }
      int x=sc.nextInt();
      int y=sc.nextInt();
      String t=x+" "+y;
      if(map.containsKey(t)) {
        System.out.print(x+" "+y+" "+map.get(t)+" "+"1");
          System.out.println();
      }
      int down=0;
        int up=0;
        int left=0;
        int right=0;
        int lim_x=1;
        int lim_y=1;
      while(x<m && x>=0 && y<n && y>=0)
      {
        int start=0;
        while(x<m && start<lim_x)
        {   
          start++;
          x++;
          String temp=x+" "+y;  
            if(map.containsKey(temp)) {
              System.out.print(x+" "+y+" "+map.get(temp)+" "+"1");
                System.out.println();
            }
              down++;        
        }
        lim_x++;
          start=0;
      while(y<n && start<lim_y)
      { 
        start++;  
        y++;
        String temp=x+" "+y;  
        if(map.containsKey(temp)) {
          System.out.print(x+" "+y+" "+map.get(temp)+" "+"2");
            System.out.println();
        }
       
        right++;
        }
      lim_y++;
      
      start=0;
      while(x>=0 && start<lim_x)
       {   start++;
           x--;
        String temp=x+" "+y;  
          if(map.containsKey(temp)) {
            System.out.print(x+" "+y+" "+map.get(temp)+" "+"3");
            System.out.println();
          }
         
           up++;
              
       }
      lim_x++;
      start=0;
      while(y>=0 && start<lim_y)
      {   start++;
           y--;
        String temp=x+" "+y;  
          if(map.containsKey(temp)) {
            System.out.print(x+" "+y+" "+map.get(temp)+" "+"4");
              System.out.println();
          }
          
            left++;      
      }
      lim_y++;
    }
  }
}