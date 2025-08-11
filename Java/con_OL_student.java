class Student {
   
     String Name;
     String Roll;
     int Marks;
     
     Student(String Name){
     
	this.Name = Name;
	System.out.println(Name+" he was Lateral Student!");     
     }
     
     Student(String Name, String Roll){
     
        this.Name = Name;
        this.Roll = Roll;
        System.out.println(Name+" He didn't wrote exam...");
     }     
     
     Student(String Name, String Roll, int Marks){
       
        this.Name = Name;
        this.Roll = Roll;
        this.Marks = Marks;
        System.out.println(Name+" Scored "+Marks+" Marks");
     
     }
     
  public static void main(String args[]){
  
  Student S1 = new Student("Sai charan", "013", 97);
  Student S2 = new Student("Sathis", "L01");
  Student S3 = new Student("Nithin");
  Student S4 = new Student("Venu", "L01");
  
  }
}
