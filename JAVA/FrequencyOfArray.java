class FrequencyOfArray{


	public static void main(String args[]){
	
	    int arr[]={1, 1, 2, 3, 4, 5, 6, 5, 4, 3, 3, 6, 5, 5, 2};
	    
	    for(int i=0; i<arr.length; i++){
	        for(int j =0; j<arr.length; j++){
	           if(arr[i]<arr[j]){
	           
	              int temp = arr[i];
	              arr[i] =arr[j];
	              arr[j] = temp;
	           }
	        }
	    }
		
			    
	    
	    
	}


}
