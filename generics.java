

public class Main{
	public static void main(String [] args){

		System.out.println("*** Generic repositories" );
		Repository<Integer> fifteen = new Repository<>(15);
		// fifteen.value = 15;

		Repository<Double> hundered= new Repository<Double>(393.93);
		// hundered.value = 100.29;

		System.out.println("\nInteger repository : " + fifteen.value);

		System.out.println("\n Double repository : " + hundered.value);
	}
}

class Repository<T>{
	public T value;

	public Repository(T value){
		this.value = value;
	}

	public T getValue(){
		return value;
	}
	public void setValue(T value){
		this.value = value;
	}

	@Override 
	public String toString(){
		return String.format("Repository contains : %s", value);
	}
}


