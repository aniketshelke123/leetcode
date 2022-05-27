
import java.util.function.Function;
import java.util.Optional;

class Pair<T> {
	    private T first;
		    private T second;

			    Pair(T first, T second) {
					        this.first = first;
							        this.second = second;
									    }

				    T getFirst() {
						        return this.first;
								    }

					    T getSecond() {
							        return this.second;
									    }

						    <R> Pair<R> map(Function<? super T, ? extends R> f) {
								        return new Pair<R>(f.apply(this.first), f.apply(this.second));
										    }
}

class Monad {
	    public static void main(String[] args) {
			        System.out.println("Hello, world!");
					    }

		    split: String -> Optional<Pair<String>>
			    // parse: Pair<String> -> Optional<Pair<Integer>>
			        // divide: Pair<Integer> -> Optional<Integer>

			            public static Optional<Pair<String>> splitByComma(String input) {
			                    String[] pair = input.split("\\s*,\\s*");
			                            return pair.length == 2 ? Optional.of(new Pair<String>(pair[0].strip(), pair[1].strip())) : Optional.empty();
			                                }

			                                    public static Optional<Pair<Integer>> parse(Pair<String> stringPair) {
			                                            Optional<Pair<Integer>> pair;

			                                                    try {
			                                                                pair = Optional.of(stringPair.map(Integer::parseInt));
			                                                                        } catch (NumberFormatException e) {
			                                                                                    pair = Optional.empty();
			                                                                                            }

			                                                                                                    return pair;
			                                                                                                        }

			                                                                                                            public static Optional<Integer> divide(Pair<Integer> numberPair) { // 18 0
			                                                                                                                    Integer divisor = numberPair.getSecond();
			                                                                                                                            return divisor != 0 ? Optional.of(numberPair.getFirst() / divisor) : Optional.empty();
			                                                                                                                                }

			                                                                                                                                    public static Optional<Integer> solve(String input) {
			                                                                                                                                            return splitByComma(input)      // Optional<Pair<String>> -> Optiona<R>
			                                                                                                                                                        .flatMap(Monad::parse)      // Pair<String> -> Optional<Pair<Integer>>
			                                                                                                                                                                    .flatMap(Monad::divide);    // Pair<Integer> -> Optional<Intger>
			                                                                                                                                                                        }
			                                                                                                                                                                        }
