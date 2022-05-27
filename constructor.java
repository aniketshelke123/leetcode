

public class main{
	public static void main(String [] args){

		Road_toll rt1 = new Road_toll("sedan", 4);

		/*
		rt1.type = "Sadan";
		rt1.tiresCount = 4;
		rt1.CalculateToll();
		*/
	}
}
public class Road_toll{
	String type;
	int tiresCount;

	public Road_toll(String type, int tiresCount){ // constructor
		this.type = type;
		this.tiresCount = tiresCount;
	}

	public void CalculateToll(){
		if (tiresCount == 2){
			System.out.println("your toll amount is 0");
		} else if (tiresCount == 4){
			System.out.println("your toll amount is 10");
		}
		else if(tiresCount > 4){
			System.out.println("Your toll amount is 20");
		
		} else{
			System.out.println("Incorrect tire count");
		}
	} 
}

