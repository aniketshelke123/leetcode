

public class String_search_operations{

	public static void main(String[] args){

		/*
		 * contains
		 * starts with
		 * ends with 
		 * Index of 
		 * last index of
		 */

		String str1 = "I love Java love and Selenium";
		String str2 = "java";

		// check str2 is present in str1
		System.out.println(str1.contains(str2));// case sensitive
		//or
		System.out.println(str1.toLowerCase().contains(str2.toLowerCase()));

		// Starts with
		System.out.println(str1.startsWith("I"));

		//ENds with
		System.out.println(str1.endsWith("Selenium"));

		// Index Of
		System.out.println(str1.indexOf("love"));
		// multiple same word 
		System.out.println(str1.indexOf("love", 6)); // starts search after 6th index

		// Last index of
		System.out.println(str1.lastIndexOf("love"));// seraches  from back end
	}
}
