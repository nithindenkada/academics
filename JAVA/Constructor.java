class Con_Student {
     	String Name;
     	String Roll;
	Con_Student(String name, String roll){
		this.Name = name;
		this.Roll = roll;
		System.out.println(name+" with roll Number "+roll);
	}

    public static void main(String[] args) {
	
	Con_Student S1 = new Con_Student("Nithin", "L01");
    }
}
