//import java.util.scanner;
class OddPrime {

	boolean odd(int num){
	    if(num % 2 == 0)
	    	return false;
	    else
	    	return true;	
	}
	
	boolean prime(int num){
	    for(int i = 2; i <= num/2; i++){
	    
	    	if(num%i == 0)
	    	   return false;
	    }
	    return true;
	}
	
	
     public static void main(String args[]){
     	 int arr[] = {2, 3, 4, 5, 6, 7, 8, 9};
     	 int n = arr.length;
         OddPrime O = new OddPrime();
          
         for(int i = 0; i < n; i++){
             
             if(O.odd(arr[i]) && O.prime(arr[i])){
             	  
             	  System.out.print(arr[i]+"\t");
             	  
             }
         } 
     }
}
