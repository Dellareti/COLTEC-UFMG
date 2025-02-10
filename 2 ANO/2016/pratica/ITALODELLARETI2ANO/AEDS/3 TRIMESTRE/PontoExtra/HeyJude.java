import java.util.Scanner;
public class TheBeatles {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		System.out.println("Hey Jude: ");
		
		String option = input.next();
		
		switch (option)
             {
                 case "dont":
                    String Enjoy = input.next();
					switch (Enjoy){
						
						case "MakeItBad":
						System.out.println("\n take a sad song and make it better ");
						break;
						
						case "BeAfraid":
						System.out.println("\n you were made to go out and get her ");
						break;
						
						case "LetMeDown":
						System.out.println("\n you have found her,now go and get her ");
						break;
					}
					
                     break;
                 
				 
				 
				 case "RememberTo":
					  
					  System.out.println("\n let her into your heart ");
					  System.out.println("\n le her under your skin ");
					  
                     break;
                 
				 case "ThenYou":
                    String TheSilence = input.next();
					switch (TheSilence){
						
						case "CanStart":
						System.out.println("\n to make it better ");
						break;
						
						case "Begin":
						System.out.println("\n to make it better ");
						break;
						
						
					}
					 
                      break;
                 
             }
	    }
					System.out.println("\n  better better better better better waaaaaaa ");
					
					// na na na na na na na na na na na na na ...
			
		
		
 }