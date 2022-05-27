
import java.util.HashSet;

public class Main{
	public static void main(String[] args){

		HashSet<String> carSet = new HashSet<>();

		carSet.add("Volvo");
		carSet.add("BMW");
		carSet.add("FOrd");
		carSet.add("Mazda");

		System.out.println("car set: " + carSet);

		carSet.add("AUDI");
		carSet.add("Mazda");

		System.out.println("car set: " + carSet);
		
		carSet.remove("AUDI");
		carSet.remove("FOrd");

		System.out.println("car set: " + carSet);

	}
}
