import java.util.*;  
public class lab1 {
    static void myMethod() {
        
            System.out.println("1/Enter a full sentence");
            
            System.out.println("2/Print out all sentences entered so far in the given order");
            
            System.out.println("3/ Print out all sentences entered thus far in the reverse order.");
            
            System.out.println("4/Print out the number of sentences that have been entered so far.");
            
            System.out.println("5/Print out the number of characters in all sentences combined.");
            
            System.out.println("6/Calculate the total number of vowels contained in all stored sentences.");
            
            System.out.println("7/Perform search for a given word using case sensitive comparisons.");
            
            System.out.println("8/Perform search for a given word using case insensitive comparisons.");
            
            System.out.println("9/End program.");
  }
    
    public static void main(String[] args) {
       
        String ten[] = new String[10];
        
        Scanner sc = new Scanner(System.in);
                
        int i = 0;
        
        int counter = 0; 
        
        String sentence;
        
        while(i!=9){
            
            myMethod();
            
            i = sc.nextInt();
            
            if(i == 1)
                
            {
                
                if(counter == 9)
                    
                {
                    System.out.println("Reject");
                    
                    continue;
                    
                }
                
               sc.nextLine();
                
               sentence = sc.nextLine();
               
               ten[counter] = sentence;
               
               counter++;
               
            }
            
            if(i == 2)
                
            {
                for(int k = 0; k< counter; k++)
                    
                {
                    
                    System.out.println(ten[k]);
                    
                }
            }
            
            if(i == 3)
                
            {
                
                for(int k = counter-1; k>=0; k--)
                    
                {
                    
                    System.out.println(ten[k]);
                    
                }
                
            }
            
            if(i == 4)
                
            {
                
                System.out.println(counter);
               
            }
            
            if(i == 5)
                
            {
                
                int charCounter = 0;
                
                for(int j = 0; j<counter; j++)
                    
                {
                
                    charCounter+= ten[j].length();
                    
                }
                
                System.out.println(charCounter);
                
            }
            
            if(i == 6)
                
            {
                
                int vowelCounter = 0;
                
                for(int j = 0; j<counter; j++)
                {
                    
                    for(int k = 0; k<ten[j].length(); k++)
                    
                    {
                        
                        if(ten[j].charAt(k)== 'A' || ten[j].charAt(k)== 'a' || ten[j].charAt(k)== 'E' || ten[j].charAt(k)== 'e' || ten[j].charAt(k)== 'I' || ten[j].charAt(k)== 'i' || ten[j].charAt(k)== 'O'|| ten[j].charAt(k)== 'o' || ten[j].charAt(k)== 'U' || ten[j].charAt(k)== 'u')
                        
                        {
                            
                            vowelCounter++;
                            
                        }
                        
                    }
                        
                    
                }
                
                System.out.println(vowelCounter);
               
            }
            if(i == 7)
                
            {
                String word;
                
                System.out.println("Enter a word");
                
                sc.nextLine();
                
               word = sc.nextLine();
               
               for(int k = 0; k<counter; k++)
               {
                   
                   if(ten[k].contains(word))
                   {
                       
                       System.out.println(ten[k]);
                       
                   }
                   
               }
                
                
            }
            if(i == 8)
            
            {
                
                String word;
                
                System.out.println("Enter a word");
                
                sc.nextLine();
                
                word = sc.nextLine();
                
                for(int k =0; k<counter; k++)
                
                {
                
                    if(ten[k].toLowerCase().contains(word.toLowerCase()))
                    
                    {
                        
                      System.out.println(ten[k]);
                        
                    }
                    
                }
                
            }
                    
        }
        
        sc.close();
    }
    
}
