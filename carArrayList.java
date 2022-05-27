import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Main{
	public static void main(String[] args){
		ArrayList<Car> carList = new ArrayList<>();

		carList.add(new Car("Honda", "Civic", 21000.0));
		carList.add(new Car("Toyota", "Camry", 29000.0));
		carList.add(new Car("BMW", "Audi", 49000.0));

		System.out.println("Car list: " + carList.toString());
	}
}

public class Car{
	private String make;
	private String model;
	private Double price;

	public Car(String make, String model, Double price){
		this.make = make;
		this.model = model;
		this.price = price;

	}
	public String getMake(){
		return make;
	}
	public String getModel(){
		return model;
	}
	public Double getPrice(){
		return price;
	}

	@Override
	public String toString(){
		return String.format("Make: %s, Model: %s, price: %s", make, model, price);
	}
}
